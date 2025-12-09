# cse291p_2.0

CSE291P project with Juliet Test Suite (https://github.com/arichardson/juliet-test-suite-c)

## Tool Workflow:

1. An LLM is fed a buggy .c code and a static analyzer output (from `scripts/static_analyzer.py`) for it and asked to implement a fix
2. The fix is produced and checked by a static analyzer (`scripts/static_analyzer.py`)
3. If no warnings appear, the code is judged by a strong LLM judge for equivalency
4. The code is fixed only if the static analyzer produces no warnings and the judge deems it equivalent, in which case the fixed code is saved
5. If the conditions are not met, steps 1-5 are repeated
6. The tool maxes out after 5 iterations, defined in `main.py`, after which the current version of the fix is saved

## Steps for Set Up:

- clone repo
- install cppcheck and other dependencies
- set up OPENAI_API_KEY and set it as an environment variable `export OPENAI_API_KEY=sk-<your key>`
- run `python3 main.py` to run te full evaluation

## Directory Explanation:

- `data/juliet_test`: the relevant data of 5 test cases used for the initial development of the tool
- `data/results_test`: the test results from development stage
- `data/juliet/test_cases/<CWE#>`: the test cases used for final evaluation, organized by CWE#
- `data/juliet/omitbad/<CWE#>`: cleaned bad implementations of respective cases from `data/juliet/test_cases/<CWE#>`
- `data/juliet/omitgood/<CWE#>`: cleaned good implementations of respective cases from `data/juliet/test_cases/<CWE#>`
- `data/eval`: evaluation results, according to type of implementation run (llm only, no few shot examples, full tool), each sorted by respective CWE#
- `scripts/extract_omit.py`: cleans test_cases; to run "python3 ./scripts/extract_omit.py <CWE#>`
- `scripts/llm_only.py`: runs the tool without any static analyzer input; to run "python3 ./scripts/llm_only.py <CWE#>`
- `scripts/no_few_shot.py`: runs tool without any few shot examples; to run "python3 ./scripts/no_few_shot.py <CWE#>`
