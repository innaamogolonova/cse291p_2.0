# from scripts.static_analyzer import run_cppcheck, has_warnings
from llm.prompts import load_shot_io
from llm.interface import *
from main import *

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
# JULIET_DIR = REPO_ROOT / "data" / "juliet" / "omitbad"
# OUTPUT_DIR = REPO_ROOT / "data" / "results" / "omitbad_fixes"
EXAMPLES_DIR = REPO_ROOT / "few_shot_examples"

print(f"\n=== Initializing LLM client ===")
try:
    llm_client = OpenAILLMClient(
        config=LLMConfig(
            model="gpt-4o-mini",
            temperature=0.1,
            max_output_tokens=4096,
        ),
        judgeconfig=LLMConfig(
            model="gpt-5-nano",
            temperature=0.1,
            max_output_tokens=4096,
        )
    )
except Exception as e:
    print(f"[ERROR] Failed to initialize LLM client: {e}", file=sys.stderr)
    import traceback
    traceback.print_exc()
    raise  # Re-raise to be caught by main loop

bad_path = EXAMPLES_DIR / "bad" / "01.c"  
try:
    with open(bad_path, 'r', encoding='utf-8') as file:
        bad_code = file.read()
except FileNotFoundError:
    print(f"Error: The file '{bad_path}' was not found.")
except Exception as e:
    print(f"An error occurred: {e}")

good_path = EXAMPLES_DIR / "good" / "01.c"
try:
    with open(good_path, 'r', encoding='utf-8') as file:
        good_code = file.read()
except FileNotFoundError:
    print(f"Error: The file '{good_path}' was not found.")
except Exception as e:
    print(f"An error occurred: {e}")

print(f"{bad_code=}")

print()

print(f"{good_code=}")

judge_result = llm_client.judge_func_eq(bad_code, good_code)
print(f"{judge_result.verdict=}")