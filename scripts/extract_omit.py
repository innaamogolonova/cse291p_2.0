#!/usr/bin/env python3
"""Extract OMITGOOD/OMITBAD bodies from Juliet testcases.

For each C file in `data/juliet/test_cases/<CWE#>` this script runs:
  gcc -fpreprocessed -dD -E -P <file>

Then it creates two output files per input file:
  - data/juliet/omitgood/<CWE#>/<stem>_OMITGOOD.c
  - data/juliet/omitbad/<CWE#>/<stem>_OMITBAD.c

Each output file contains the `#include` lines (taken from the original
source) followed by only the body inside the `#ifndef OMITGOOD` /
`#ifndef OMITBAD` block (respectively). All C-style and C++-style comments
are removed.

Usage: python3 scripts/extract_omit.py <CWE#>
Example: python3 scripts/extract_omit.py CWE190_Integer_Overflow
"""

import subprocess
from pathlib import Path
import sys


ROOT = Path(__file__).resolve().parent.parent
# TEST_CASES_DIR should be <project-root>/data/juliet/test_cases/<CWE#>
TEST_CASES_DIR = ROOT / "data" / "juliet" / "test_cases"
OUT_OMITGOOD = ROOT / "data" / "juliet" / "omitgood"
OUT_OMITBAD = ROOT / "data" / "juliet" / "omitbad"

def remove_comments(path: Path) -> str:
  """Remove comments from C/C++ source using the preprocessor."""
  # Include path for Juliet testcase support headers
  include_dir = ROOT / "data" / "juliet" / "testcasesupport"
  
  cmd = [
    "gcc-15",
    "-fpreprocessed",
    "-dD",
    "-E",
    "-P",
    f"-I{include_dir}",
    str(path),
  ]
  proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
  if proc.returncode != 0:
    raise RuntimeError(f"gcc-15 failed for {path}: {proc.stderr}")
  return proc.stdout

def find_blocks(lines: list[str]) -> list[list[str]]:
  includes = []
  omitbad = []
  omitgood = []
  omits = [omitbad, omitgood]
  done = [False, False]
  mode = None # 0 = OMITBAD, 1 = OMITGOOD
  for line in lines:
    if done[0] and done[1]:
      break
    line = line.rstrip()
    if "#endif" in line:
      if mode != None:
        done[mode] = True
      mode = None
    elif mode != None:
      omits[mode].append(line)
    elif "#include" in line:
        includes.append(line)
    elif "#ifndef OMITBAD" in line:
      mode = 0
    elif "#ifndef OMITGOOD" in line:
      mode = 1
  return [includes+omitbad, includes+omitgood]


def process_file(c_file: Path, out_omitbad: Path, out_omitgood: Path) -> None:
  # iterate over all .c files
  lines = remove_comments(c_file).splitlines()
  bad, good = find_blocks(lines)
  bad_path = out_omitbad / f"{c_file.stem}_OMITBAD.c"
  good_path = out_omitgood / f"{c_file.stem}_OMITGOOD.c"
  # write back OMITBAD
  with bad_path.open("w", encoding="utf-8") as f:
    for line in bad:
      f.write(line + "\n")
  # write back OMITGOOD
  with good_path.open("w", encoding="utf-8") as f:
    for line in good:
      f.write(line + "\n")

def main(argv: list[str] | None = None) -> int:
  argv = argv if argv is not None else sys.argv[1:]
  
  if len(argv) != 1:
    print("Usage: python3 scripts/extract_omit.py <CWE#>", file=sys.stderr)
    print("Example: python3 scripts/extract_omit.py CWE476", file=sys.stderr)
    return 1
  
  cwe_num = argv[0]
  test_cases_dir = TEST_CASES_DIR / cwe_num
  out_omitgood = OUT_OMITGOOD / cwe_num
  out_omitbad = OUT_OMITBAD / cwe_num
  
  # debug information to help diagnose path issues
  print(f"ROOT = {ROOT}")
  print(f"TEST_CASES_DIR = {test_cases_dir}")
  print(f"exists: {test_cases_dir.exists()}")
  print(f"is_dir: {test_cases_dir.is_dir()}")
  
  if not test_cases_dir.exists():
    print(f"[ERROR] Test cases directory does not exist: {test_cases_dir}", file=sys.stderr)
    return 1
  
  if not test_cases_dir.is_dir():
    print(f"[ERROR] Test cases path is not a directory: {test_cases_dir}", file=sys.stderr)
    return 1
  
  out_omitgood.mkdir(parents=True, exist_ok=True)
  out_omitbad.mkdir(parents=True, exist_ok=True)
  
  c_files = sorted(test_cases_dir.glob("*.c"))
  print(f"matched .c files: {[p.name for p in c_files]}")
  
  if not c_files:
    print(f"[WARNING] No .c files found in {test_cases_dir}")
    return 0

  for c_file in c_files:
    try:
      print(f"processing {c_file.stem}")
      process_file(c_file, out_omitbad, out_omitgood)
    except Exception as e:
      print(f"Error processing {c_file}: {e}")
  return 0

if __name__ == "__main__":
  raise SystemExit(main())
