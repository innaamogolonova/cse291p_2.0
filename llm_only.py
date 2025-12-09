#!/usr/bin/env python3
# only the LLM without static analyzer hints, evaluated by strong LLM judge

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
JULIET_DIR = REPO_ROOT / "data" / "juliet" / "omitbad"
OUTPUT_DIR = REPO_ROOT / "data" / "results" / "llm_only_fixes"

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
    from llm.interface import OpenAILLMClient, LLMConfig

    # Final verdict on LLM code after MAX_ITERATIONS
    verdict = 1

    print(f"\n{'='*60}")
    print(f"Processing: {test_file.name}")
    print(f"{'='*60}")

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
    iteration = 0
    fix_result = None

    while iteration < MAX_ITERATIONS:
        iteration += 1
        print(f"\n{'='*60}")
        print(f"=== Iteration {iteration}/{MAX_ITERATIONS} ===")
        print(f"{'='*60}")

        print(f"\n=== Calling LLM to generate fix ===")
        try:
            fix_result = llm_client.suggest_fix(
                source_code=current_code,
                diagnostics="",
            )
            print(f"[SUCCESS] LLM generated a fix")
        except Exception as e:
            print(f"[ERROR] Failed to process with LLM: {e}", file=sys.stderr)
            import traceback
            traceback.print_exc()
            raise  # Re-raise to be caught by main loop

        # Update iteration count in the result
        fix_result.iteration_count = iteration
        fix_result.fixed_code = unwrap_markdown(fix_result.fixed_code)
        current_code = fix_result.fixed_code

        # Call JUDGE LLM
        print(f"\n=== Calling JUDGE LLM ===")
        try:
            judge_result = llm_client.judge_func_eq(
                omitbad_code=omitbad_code,
                fixed_code=current_code,
            )
            print(f"[SUCCESS] JUDGE LLM gave a response {judge_result.verdict[:min(14,len(judge_result.verdict))]}")
        except Exception as e:
            print(f"[ERROR] Failed to process with JUDGE LLM: {e}", file=sys.stderr)
            import traceback
            traceback.print_exc()
            raise  # Re-raise to be caught by main loop

        # Check if JUDGE warnings remain
        if "NOT" in judge_result.verdict:
            verdict = 1
            print(f"[INFO] JUDGE says NOT equivalent, continuing to next iteration...")
        else:
            verdict = 0
            print(f"[SUCCESS] JUDGE says equivalent after {iteration} iteration(s)")
            break

    else:
        # Loop exhausted without eliminating all warnings
        print(f"\n[WARNING] Max iterations ({MAX_ITERATIONS}) reached.")

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

    # Accumulate results and print at end ["success", "failure"]
    stats = [0, 0]
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

        # Maintain files holding files succeeded/failed
        if res == 0:
            stats[0] += 1
            success_wb.append(test_case.name)
        else:
            stats[1] += 1
            failure_wb.append(test_case.name)

    print(f"\n\n{'='*60}")
    print(f"All done! Processed {len(test_cases)} test case(s)")
    print(f"{'='*60}")

    # Printing back results
    print(f"{stats[0]}/{sum(stats)} successfully fixed!")
    print(f"{stats[1]}/{sum(stats)} failed to be fixed...")


if __name__ == "__main__":
    main()
