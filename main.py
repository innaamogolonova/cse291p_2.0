#!/usr/bin/env python3

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
JULIET_DIR = REPO_ROOT / "data" / "juliet" / "omitbad"
OUTPUT_DIR = REPO_ROOT / "data" / "results" / "omitbad_fixes"

MAX_ITERATIONS = 5  # Maximum number of fix iterations

def unwrap_markdown(text: str) -> str:
    """Remove ```c or ```cpp fences if present, otherwise return text unchanged."""
    if text.startswith("```"):
        # Remove the first line and last line
        lines = text.splitlines()
        if len(lines) >= 2:
            return "\n".join(lines[1:-1])
    return text

# Returns 0 when successful fix, otherwise 1
def process_test_case_with_llm(test_file: Path) -> int:
    """
    Process a single test case with iterative fixing:
    1. Run cppcheck to get diagnostics
    2. Read the source code
    3. Call LLM to generate a fix
    4. Run cppcheck on the fixed code
    5. If warnings remain, repeat steps 3-4 (up to MAX_ITERATIONS)
    6. Save the final fixed code and metadata with iteration count
    """
    from llm.interface import OpenAILLMClient, LLMConfig
    from scripts.static_analyzer import run_cppcheck, has_warnings

    # Final verdict on LLM code after MAX_ITERATIONS
    verdict = 1

    print(f"\n{'='*60}")
    print(f"Processing: {test_file.name}")
    print(f"{'='*60}")

    # Step 1: Run static analyzer on original file
    print(f"\n=== Running cppcheck on original file ===")
    diagnostics = run_cppcheck(test_file)
    print("[DIAGNOSTICS]")
    print(diagnostics)

    if not has_warnings(diagnostics):
        print("[INFO] No warnings found in original file. Nothing to fix.")
        return -1

    # Step 2: Read source code
    print(f"\n=== Reading source code ===")
    source_code = test_file.read_text(encoding="utf-8")
    omitbad_code = source_code

    # Step 3: Initialize LLM client
    print(f"\n=== Initializing LLM client ===")
    try:
        llm_client = OpenAILLMClient(
            config=LLMConfig(
                model="gpt-4o-mini",
                temperature=0.1,
                max_output_tokens=4096,
            ),
            judgeconfig=LLMConfig(
                model="gpt-5-nano",
                temperature=0.1,
                max_output_tokens=4096,
            )
        )
    except Exception as e:
        print(f"[ERROR] Failed to initialize LLM client: {e}", file=sys.stderr)
        import traceback
        traceback.print_exc()
        raise  # Re-raise to be caught by main loop

    # Iterative fix loop
    current_code = source_code
    current_diagnostics = diagnostics
    iteration = 0
    fix_result = None

    while iteration < MAX_ITERATIONS:
        iteration += 1
        print(f"\n{'='*60}")
        print(f"=== Iteration {iteration}/{MAX_ITERATIONS} ===")
        print(f"{'='*60}")

        # Call LLM to generate fix
        print(f"\n=== Calling LLM to generate fix ===")
        try:
            fix_result = llm_client.suggest_fix(
                source_code=current_code,
                diagnostics=current_diagnostics,
            )
            print(f"[SUCCESS] LLM generated a fix")
        except Exception as e:
            print(f"[ERROR] Failed to process with LLM: {e}", file=sys.stderr)
            import traceback
            traceback.print_exc()
            raise  # Re-raise to be caught by main loop

        # Update iteration count in the result
        fix_result.iteration_count = iteration

        # Write fixed code to a temporary location for analysis
        print(f"\n=== Running cppcheck on fixed code ===")
        temp_file = test_file.with_suffix(".tmp.c")
        fix_result.fixed_code = unwrap_markdown(fix_result.fixed_code)
        temp_file.write_text(fix_result.fixed_code, encoding="utf-8")

        try:
            # Run static analyzer on fixed code
            new_diagnostics = run_cppcheck(temp_file)
            print("[DIAGNOSTICS AFTER FIX]")
            print(new_diagnostics)

            # Check if SA warnings remain
            if not has_warnings(new_diagnostics):
                print(f"[SUCCESS] No SA warnings remain")
                verdict = 0 # tentatively set to SUCCESS
            else:
                print(f"[INFO] SA Warnings still present, continuing to next iteration...")
                current_code = fix_result.fixed_code
                current_diagnostics = new_diagnostics
        finally:
            # Clean up temporary file
            if temp_file.exists():
                temp_file.unlink()

        # Check if JUDGE warnings remain (if no SA warnings)
        if verdict == 0:
            # Call JUDGE LLM
            print(f"\n=== Calling JUDGE LLM ===")
            try:
                judge_result = llm_client.judge_func_eq(
                    # TODO: Check that source_code is in fact the OMITBAD code initialized outside the iteration loop.
                    omitbad_code=omitbad_code, 
                    fixed_code=current_code,
                )
                print(f"[SUCCESS] JUDGE LLM gave a response {judge_result.verdict[:min(14,len(judge_result.verdict))]}")
            except Exception as e:
                print(f"[ERROR] Failed to process with LLM: {e}", file=sys.stderr)
                import traceback
                traceback.print_exc()
                raise  # Re-raise to be caught by main loop

            # Check if JUDGE warnings remain
            if "NOT" in judge_result.verdict:
                verdict = 1
                print(f"[INFO] JUDGE Warnings still present, continuing to next iteration...")
            else:
                print(f"[SUCCESS] No SA and JUDGE warnings remaining after {iteration} iteration(s)")
                break

    else:
        # Loop exhausted without eliminating all warnings
        print(f"\n[WARNING] Max iterations ({MAX_ITERATIONS}) reached. Some warnings may remain.")

    # Step 4: Save the final result
    if fix_result is not None:
        print(f"\n=== Saving fixed code ===")
        print(f"Total iterations: {fix_result.iteration_count}")
        
        saved_paths = fix_result.save(
            source_path=test_file,
            output_root=OUTPUT_DIR,
        )

        print(f"Fixed code saved to: {saved_paths['fixed']}")
        print(f"Metadata saved to: {saved_paths['metadata']}")
    else:
        print(f"[ERROR] No fix was generated", file=sys.stderr)
        raise RuntimeError("No fix was generated")
    return verdict


def main():
    # Get all C test case files in the test_cases directory
    test_cases = sorted(JULIET_DIR.glob("*.c"))

    # Accumulate results and print at end ["success", "failure", "skipped"]
    stats = [0, 0, 0]
    success_wb = []
    failure_wb = []

    if not test_cases:
        print(f"[ERROR] No test cases found in: {JULIET_DIR}", file=sys.stderr)
        sys.exit(1)
    
    print(f"\n{'='*60}")
    print(f"Found {len(test_cases)} test case(s) to process")
    print(f"{'='*60}")
    
    for idx, test_case in enumerate(test_cases, 1):
        print(f"\n\n{'#'*60}")
        print(f"# Processing test case {idx}/{len(test_cases)}")
        print(f"{'#'*60}")
        
        try:
            res = process_test_case_with_llm(test_case)
        except Exception as e:
            print(f"\n[ERROR] Failed to process {test_case.name}: {e}", file=sys.stderr)
            import traceback
            traceback.print_exc()
            print(f"[INFO] Continuing to next test case...\n")
            continue

        # Maintain files holding files succeeded/failed, and skipped on
        if res == -1: # skip
            stats[2] += 1
        elif res == 0: # success
            stats[0] += 1
            success_wb.append(test_case.name)
        else: # fail
            stats[1] += 1
            failure_wb.append(test_case.name)

    print(f"\n\n{'='*60}")
    print(f"All done! Processed {len(test_cases)} test case(s)")
    print(f"{'='*60}")

    # Printing back results
    print(f"{stats[0]}/{sum(stats)} successfully fixed!")
    print(f"{stats[1]}/{sum(stats)} failed to be fixed...")
    print(f"{stats[2]} cases skipped.")
    with open("success.txt", "w") as f:
        f.write("\n".join(success_wb))
    with open("failure.txt", "w") as f:
        f.write("\n".join(failure_wb))


if __name__ == "__main__":
    main()
