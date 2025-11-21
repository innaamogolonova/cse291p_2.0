# cse291p_2.0

CSE291P project with Juliet Test Suite

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

## Steps for Set Up:

- clone repo
- install cppcheck and other dependencies
- run `python3 main.py`

## Notes:

- not sure if i need the Makefile?
- the OMITGOOD and OMITBAD flags are confusing -> bad implementation still produces warnings so need to figure out how to handle that -> not sure how the two differ
