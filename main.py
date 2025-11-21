#!/usr/bin/env python3

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
JULIET_DIR = REPO_ROOT / "data" / "juliet" / "test_cases"
OUTPUT_DIR = REPO_ROOT / "data" / "results" / "test_cases_fixes"

MAX_ITERATIONS = 5  # Maximum number of fix iterations


def process_test_case_with_llm(test_file: Path):
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
        return

    # Step 2: Read source code
    print(f"\n=== Reading source code ===")
    source_code = test_file.read_text(encoding="utf-8")

    # Step 3: Initialize LLM client
    print(f"\n=== Initializing LLM client ===")
    try:
        llm_client = OpenAILLMClient(
            config=LLMConfig(
                model="gpt-4o-mini",
                temperature=0.1,
                max_output_tokens=4096,
            )
        )
    except Exception as e:
        print(f"[ERROR] Failed to initialize LLM client: {e}", file=sys.stderr)
        import traceback
        traceback.print_exc()
        sys.exit(1)

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
            sys.exit(1)

        # Update iteration count in the result
        fix_result.iteration_count = iteration

        # Write fixed code to a temporary location for analysis
        print(f"\n=== Running cppcheck on fixed code ===")
        temp_file = test_file.with_suffix(".tmp.c")
        temp_file.write_text(fix_result.fixed_code, encoding="utf-8")

        try:
            # Run static analyzer on fixed code
            new_diagnostics = run_cppcheck(temp_file)
            print("[DIAGNOSTICS AFTER FIX]")
            print(new_diagnostics)

            # Check if warnings remain
            if not has_warnings(new_diagnostics):
                print(f"[SUCCESS] No warnings remaining after {iteration} iteration(s)")
                break
            else:
                print(f"[INFO] Warnings still present, continuing to next iteration...")
                current_code = fix_result.fixed_code
                current_diagnostics = new_diagnostics

        finally:
            # Clean up temporary file
            if temp_file.exists():
                temp_file.unlink()

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
        sys.exit(1)


def main():
    # For now, process just one test case
    test_case = JULIET_DIR / "CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_loop_12.c"

    if not test_case.exists():
        print(f"[ERROR] Test case not found: {test_case}", file=sys.stderr)
        sys.exit(1)

    process_test_case_with_llm(test_case)

    print(f"\n{'='*60}")
    print("Done!")
    print(f"{'='*60}")


if __name__ == "__main__":
    main()
