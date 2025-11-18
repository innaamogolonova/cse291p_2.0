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

## Steps for Set Up:

- clone repo
- update Makefile with more test cases, if needed
- install cppcheck and other dependencies
- run `python3 main.py`
