# cse291p_2.0

CSE291P project with Juliet Test Suite

## Tool Workflow: 

1. An LLM is fed a buggy .c code and a static analyzer output (from `scripts/ststic_analyzer.py`) for it and asked to implement a fix
2. The fix is produced and checked by a static analyzer (`scripts/static_analyzer.py`)
3. If no warnings appear, the fixed code is saved in `data/results/test_cases_fixes`
4. If warning sremain, steps 1-4 are repeated
5. The tool maxes out after 5 iterations, defined in `main.py`, after which the current version of the fix is saved in `data/results/test_cases_fixes`

## Steps for Set Up:

- clone repo
- install cppcheck and other dependencies
- set up OPENAI_API_KEY and set it as an environment variable `export OPENAI_API_KEY=sk-<your key>`
- run `python3 main.py`

## Steps Taken So Far:

- copied 5 test cases from the Juliet Test Suite to explore
- copied juliet/testcasesupport which are helpers to run the test cases
- created Makefile: ensures each test case can compile and compiles it into an object in the build folder
  - run `make` to launch Makefile
  - run `make clean` to clean /build
  - update Makefile with more test cases, if needed
- locally cppcheck runs successfully
- created `scripts/static_analyzer.py` file that runs the static analyzer on the test cases
- called static analyzer from `main.py`
- attempting to implement a basic LLM
- fix the cppcheck call to display only relevant info
- deleted Makefile, not needed
- updated scripts/static_analyzer.py to be able to pass both OMITGOOD and OMITBAD flags like so:
  - Default (OMITGOOD):
    - python3 scripts/static_analyzer.py data/juliet/test_cases/CWE121_Stack_Based_Buffer_Overflow\_\_CWE805_char_alloca_loop_12.c
  - Explicitly use OMITBAD:
    - python3 scripts/static_analyzer.py data/juliet/test_cases/CWE121_Stack_Based_Buffer_Overflow\_\_CWE805_char_alloca_loop_12.c --define OMITBAD
    - python3 scripts/static_analyzer.py data/juliet/test_cases/CWE121_Stack_Based_Buffer_Overflow\_\_CWE805_char_alloca_loop_12.c -D OMITBAD
- built a back and forth pipeline with static analyzer and LLM
- expanded to 5 test cases 
