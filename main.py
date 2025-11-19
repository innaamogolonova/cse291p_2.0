#!/usr/bin/env python3

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
JULIET_DIR = REPO_ROOT / "data" / "juliet" / "test_cases"
OUTPUT_DIR = REPO_ROOT / "build" / "llm_fixes"


def process_test_case_with_llm(test_file: Path):
    """
    Process a single test case:
    1. Run cppcheck to get diagnostics
    2. Read the source code
    3. Call LLM to generate a fix
    4. Save the fixed code and metadata
    """
    from llm.interface import OpenAILLMClient, LLMConfig
    from scripts.static_analyzer import run_cppcheck

    print(f"\n{'='*60}")
    print(f"Processing: {test_file.name}")
    print(f"{'='*60}")

    # Step 1: Run static analyzer
    print(f"\n=== Running cppcheck on {test_file.name} ===")
    diagnostics = run_cppcheck(test_file)
    print("[DIAGNOSTICS]")
    print(diagnostics)

    # Step 2: Read source code
    print(f"\n=== Reading source code ===")
    source_code = test_file.read_text(encoding="utf-8")

    # Step 3: Initialize LLM client and get fix
    print(f"\n=== Calling LLM to generate fix ===")
    try:
        llm_client = OpenAILLMClient(
            config=LLMConfig(
                model="gpt-4o-mini",
                temperature=0.1,
                max_output_tokens=4096,
            )
        )

        fix_result = llm_client.suggest_fix(
            source_code=source_code,
            diagnostics=diagnostics,
        )

        print(f"[SUCCESS] LLM generated a fix")

        # Step 4: Save the result
        print(f"\n=== Saving fixed code ===")
        saved_paths = fix_result.save(
            source_path=test_file,
            output_root=OUTPUT_DIR,
        )

        print(f"Fixed code saved to: {saved_paths['fixed']}")
        print(f"Metadata saved to: {saved_paths['metadata']}")

    except Exception as e:
        print(f"[ERROR] Failed to process with LLM: {e}", file=sys.stderr)
        import traceback
        traceback.print_exc()
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
