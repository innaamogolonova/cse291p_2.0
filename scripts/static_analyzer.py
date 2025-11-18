#!/usr/bin/env python3

import subprocess
import sys
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
JULIET_DIR = REPO_ROOT / "data" / "juliet" / "test_cases"
SUPPORT_DIR = REPO_ROOT / "third_party" / "juliet" / "testcasesupport"


def find_c_files():
    """Yield all .c files in data/juliet/test_cases."""
    if not JULIET_DIR.exists():
        print(f"[ERROR] Juliet directory not found: {JULIET_DIR}", file=sys.stderr)
        return []

    return sorted(JULIET_DIR.glob("*.c"))


def run_cppcheck_on_file(c_file: Path) -> int:
    """
    Run cppcheck on a single C file.
    Returns the cppcheck exit code.
    """
    print(f"\n=== Analyzing {c_file.relative_to(REPO_ROOT)} ===")

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
        return 1

    if result.stdout:
        print("[STDOUT]")
        print(result.stdout)

    if result.stderr:
        # cppcheck prints warnings to stderr
        print("[STDERR]")
        print(result.stderr, file=sys.stderr)

    return result.returncode


def run_cppcheck_all() -> int:
    """
    Run cppcheck over all Juliet C files we know about.
    Returns 0 if all runs succeeded (no tool failures).
    """
    c_files = find_c_files()
    if not c_files:
        print("[WARN] No C files found under data/juliet/test_cases.")
        return 0

    overall_rc = 0
    for c_file in c_files:
        rc = run_cppcheck_on_file(c_file)
        if rc != 0:
            overall_rc = rc  # track the last non-zero exit code

    return overall_rc


if __name__ == "__main__":
    sys.exit(run_cppcheck_all())
