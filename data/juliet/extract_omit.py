#!/usr/bin/env python3
"""Extract OMITGOOD/OMITBAD bodies from Juliet testcases.

For each C file in `data/juliet/test_cases` this script runs:
  gcc -fpreprocessed -dD -E -P <file>

Then it creates two output files per input file:
  - data/juliet/omitgood/<stem>_OMITGOOD.c
  - data/juliet/omitbad/<stem>_OMITBAD.c

Each output file contains the `#include` lines (taken from the original
source) followed by only the body inside the `#ifndef OMITGOOD` /
`#ifndef OMITBAD` block (respectively). All C-style and C++-style comments
are removed.
"""

import subprocess
from pathlib import Path
import sys


ROOT = Path(__file__).resolve().parents[2]
# TEST_CASES_DIR should be <project-root>/data/juliet/test_cases
TEST_CASES_DIR = ROOT / "data" / "juliet" / "test_cases"
OUT_OMITGOOD = ROOT / "data" / "juliet" / "omitgood"
OUT_OMITBAD = ROOT / "data" / "juliet" / "omitbad"

def remove_comments(path: Path) -> str:
  cmd = [
    "gcc",
    "-fpreprocessed",
    "-dD",
    "-E",
    "-P",
    str(path),
  ]
  proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
  if proc.returncode != 0:
    raise RuntimeError(f"gcc failed for {path}: {proc.stderr}")
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


def process_file(c_file: Path) -> None:
  # iterate over all .c files
  lines = remove_comments(c_file).splitlines()
  bad, good = find_blocks(lines)
  bad_path = OUT_OMITBAD / f"{c_file.stem}_OMITBAD.c"
  good_path = OUT_OMITGOOD / f"{c_file.stem}_OMITGOOD.c"
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
  # debug information to help diagnose path issues
  print(f"ROOT = {ROOT}")
  print(f"TEST_CASES_DIR = {TEST_CASES_DIR}")
  print(f"exists: {TEST_CASES_DIR.exists()}")
  print(f"is_dir: {TEST_CASES_DIR.is_dir()}")
  c_files = sorted(TEST_CASES_DIR.glob("*.c"))
  print(f"matched .c files: {[p.name for p in c_files]}")

  for c_file in c_files:
    try:
      print(f"processing {c_file.stem}")
      process_file(c_file)
    except Exception as e:
      print(f"Error processing {c_file}: {e}")
  return 0

if __name__ == "__main__":
  raise SystemExit(main())
