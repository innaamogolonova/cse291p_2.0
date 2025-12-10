#!/usr/bin/env python3

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT))
OUTPUT_DIR = REPO_ROOT / "data" / "results" / "omitbad_fixes"


MAX_ITERATIONS = 5  # Maximum number of fix iterations

def unwrap_markdown(text: str) -> str:
    """Remove markdown fences and source tags if present, otherwise return text unchanged."""
    lines = text.splitlines()
    
    # Remove markdown code fences (```c, ```cpp, etc.)
    if text.startswith("```"):
        if len(lines) >= 2:
            lines = lines[1:-1]  # Remove first and last line
    
    # Remove --- BEGIN SOURCE.C --- and --- END SOURCE.C --- tags
    if lines:
        # Check and remove BEGIN tag (case-insensitive)
        if lines[0].strip().upper().startswith("--- BEGIN"):
            lines = lines[1:]
        
        # Check and remove END tag (case-insensitive)
        if lines and lines[-1].strip().upper().startswith("--- END"):
            lines = lines[:-1]
    
    return "\n".join(lines)

# Returns (verdict, iteration_count) tuple: verdict is 0 when successful fix, -1 when skipped, 1 when failed
def process_test_case_with_llm(test_file: Path) -> tuple[int, int]:
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
        return (-1, 0)

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
        raise  # Re-raise to be caught by caller

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
            raise  # Re-raise to be caught by caller

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
                    omitbad_code=omitbad_code, 
                    fixed_code=current_code,
                )
                print(f"[SUCCESS] JUDGE LLM gave a response {judge_result.verdict[:min(14,len(judge_result.verdict))]}")
            except Exception as e:
                print(f"[ERROR] Failed to process with LLM: {e}", file=sys.stderr)
                import traceback
                traceback.print_exc()
                raise  # Re-raise to be caught by caller

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
    return (verdict, fix_result.iteration_count if fix_result else 0)


def main(argv: list[str] | None = None) -> int:
    """
    Process a single test case file.
    
    Usage: python3 full_implementation.py <path_to_test_case.c>
    """
    argv = argv if argv is not None else sys.argv[1:]
    
    if len(argv) != 1:
        print("Usage: python3 full_implementation.py <path_to_test_case.c>", file=sys.stderr)
        return 1
    
    test_file = Path(argv[0])
    
    if not test_file.exists():
        print(f"[ERROR] Test file does not exist: {test_file}", file=sys.stderr)
        return 1
    
    try:
        verdict, iteration_count = process_test_case_with_llm(test_file)
        print(f"\n[RESULT] Verdict: {verdict}, Iterations: {iteration_count}")
        return 0
    except Exception as e:
        print(f"\n[ERROR] Failed to process {test_file.name}: {e}", file=sys.stderr)
        import traceback
        traceback.print_exc()
        return 1


if __name__ == "__main__":
    sys.exit(main())
