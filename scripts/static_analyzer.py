#!/usr/bin/env python3

import argparse
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
SUPPORT_DIR = REPO_ROOT / "data" / "juliet" / "testcasesupport"


def run_cppcheck(c_file: Path, define_name: str) -> str:
    """
    Run cppcheck on a single C file with the provided preprocessor define name.
    `define_name` must be either 'OMITGOOD' or 'OMITBAD'.
    Returns the diagnostics output as a string.
    """
    define_flag = f"-D{define_name}"

    cmd = [
        "cppcheck",
        "--enable=warning",  # Focus on actual bugs, not style/portability
        "--std=c11",
        f"-I{SUPPORT_DIR}",
        define_flag,
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


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run cppcheck on a Juliet C test file with optional OMIT flag"
    )
    parser.add_argument(
        "c_file",
        type=Path,
        help="Path to the C source file to analyze",
    )
    parser.add_argument(
        "--define",
        "-D",
        dest="define",
        choices=["OMITGOOD", "OMITBAD"],
        default="OMITGOOD",
        help=(
            "Which OMIT define to pass to cppcheck."
            " Use 'OMITGOOD' or 'OMITBAD' (default: OMITGOOD)."
            " Example: --define OMITBAD"
        ),
    )

    return parser.parse_args()


if __name__ == "__main__":
    args = parse_args()

    c_file_path: Path = args.c_file
    define_flag: str = args.define

    if not c_file_path.exists():
        print(f"[ERROR] File not found: {c_file_path}", file=sys.stderr)
        sys.exit(1)

    print(f"Running cppcheck on: {c_file_path} with define {define_flag}")
    diagnostics = run_cppcheck(c_file_path, define_flag)
    print("\n=== DIAGNOSTICS ===")
    print(diagnostics)
