#!/usr/bin/env python3

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
SUPPORT_DIR = REPO_ROOT / "data" / "juliet" / "testcasesupport"


def run_cppcheck(c_file: Path) -> str:
    """
    Run cppcheck on a single C file with OMITGOOD defined.
    Returns the diagnostics output as a string.
    """
    cmd = [
        "cppcheck",
        "--enable=warning",  # Focus on actual bugs, not style/portability
        "--std=c11",
        f"-I{SUPPORT_DIR}",
        "-DOMITGOOD",  # Only analyze the bad implementation
        "--suppress=missingIncludeSystem",  # Suppress missing system includes like <stdio.h>
        "--suppress=missingInclude",  # Suppress missing user includes like "std_testcase.h"
        "--inline-suppr",  # Respect inline suppressions in Juliet test cases
        str(c_file),
    ]

    try:
        result = subprocess.run(cmd, capture_output=True, text=True)
    except FileNotFoundError:
        print(
            "[ERROR] cppcheck not found. Please install it (e.g. 'brew install cppcheck').",
            file=sys.stderr,
        )
        sys.exit(1)

    diagnostics = result.stderr + result.stdout

    return diagnostics


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 scripts/static_analyzer.py <path_to_c_file>", file=sys.stderr)
        print("\nExample:", file=sys.stderr)
        print("  python3 scripts/static_analyzer.py data/juliet/test_cases/CWE476_NULL_Pointer_Dereference__null_check_after_deref_01.c", file=sys.stderr)
        sys.exit(1)

    c_file_path = Path(sys.argv[1])

    if not c_file_path.exists():
        print(f"[ERROR] File not found: {c_file_path}", file=sys.stderr)
        sys.exit(1)

    print(f"Running cppcheck on: {c_file_path}")
    diagnostics = run_cppcheck(c_file_path)
    print("\n=== DIAGNOSTICS ===")
    print(diagnostics)
