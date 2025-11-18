#!/usr/bin/env python3

import sys
from pathlib import Path
import runpy

REPO_ROOT = Path(__file__).resolve().parent

def run_static_analyzer():
    """
    Execute scripts/static_analyzer.py directly.
    """
    script_path = REPO_ROOT / "scripts" / "static_analyzer.py"

    if not script_path.exists():
        print(f"[ERROR] static_analyzer.py not found at: {script_path}", file=sys.stderr)
        sys.exit(1)

    runpy.run_path(str(script_path), run_name="__main__")


def main():

    run_static_analyzer()


if __name__ == "__main__":
    main()
