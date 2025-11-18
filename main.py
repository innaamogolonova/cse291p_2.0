#!/usr/bin/env python3

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
JULIET_DIR = REPO_ROOT / "data" / "juliet" / "test_cases"
SUPPORT_DIR = REPO_ROOT / "third_party" / "juliet" / "testcasesupport"
OUTPUT_DIR = REPO_ROOT / "build" / "llm_fixes"


def run_cppcheck_on_file(c_file: Path) -> str:
    """
    Run cppcheck on a single C file and return the diagnostics as a string.
    """
    print(f"\n=== Running cppcheck on {c_file.name} ===")

    cmd = [
        "cppcheck",
        "--enable=all",
        "--std=c11",
        f"-I{SUPPORT_DIR}",
        "--suppress=missingIncludeSystem",
        str(c_file),
    ]

    print(f"[CMD] {' '.join(cmd)}")

    try:
        result = subprocess.run(cmd, capture_output=True, text=True)
    except FileNotFoundError:
        print(
            "[ERROR] cppcheck not found. Please install it (e.g. 'brew install cppcheck').",
            file=sys.stderr,
        )
        sys.exit(1)

    # Combine stdout and stderr (cppcheck writes diagnostics to stderr)
    diagnostics = result.stderr + result.stdout

    print("[DIAGNOSTICS]")
    print(diagnostics)

    return diagnostics


def process_test_case_with_llm(test_file: Path):
    """
    Process a single test case:
    1. Run cppcheck to get diagnostics
    2. Read the source code
    3. Call LLM to generate a fix
    4. Save the fixed code and metadata
    """
    from llm.interface import OpenAILLMClient, LLMConfig

    print(f"\n{'='*60}")
    print(f"Processing: {test_file.name}")
    print(f"{'='*60}")

    # Step 1: Run static analyzer
    diagnostics = run_cppcheck_on_file(test_file)

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
