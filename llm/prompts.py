# llm/prompts.py
from __future__ import annotations

from textwrap import dedent

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
FEW_SHOT_BAD = REPO_ROOT / "few_shot_examples" / "bad"
FEW_SHOT_GOOD = REPO_ROOT / "few_shot_examples" / "good"
NUM_SHOTS = 5

DEFAULT_SYSTEM_PROMPT = dedent(
    """
    You are a C/C++ security engineer and expert in memory safety.
    You receive a single C/C++ source file that contains a memory-safety bug
    (for example: null pointer dereference, use-after-free, double free,
    buffer overflow, buffer under-read, or similar issues), together with
    diagnostics from a static analyzer.

    Your task:
    - Identify the root cause of the reported issue.
    - Rewrite ONLY the necessary parts of the code to fix the problem under #ifndef OMITBAD.
    - Do NOT modify any code outside of '#ifndef OMITBAD' ... matching '#endif' blocks.
    - Do not modify any code under '#ifndef OMITGOOD' or any other preprocessor regions.
    - Do not change any comments or add new comments; preserve comment text and formatting exactly.
    - Pay attention to existing comments and follow suggestions contained in them when determining the correct fix inside '#ifndef OMITBAD' blocks.
    - Preserve the original program intent and behavior and avoid introducing new warnings or memory issues.
    - If no changes are required within '#ifndef OMITBAD' blocks, return the original source file verbatim.
    - If you cannot comply exactly with these constraints, respond with the single token: REFUSE_TO_MODIFY_OUTSIDE_OMITBAD
    - Return ONLY the full fixed source file (or the single token above), nothing else.
    """
).strip()


def build_fix_user_prompt(
    source_code: str,
    diagnostics: str,
    extra_context: str | None = None,
) -> str:
    """
    Build the user message for the LLM.

    `diagnostics` is whatever your static analyzer returns
    (clang-analyzer output, etc.) serialized as a string.
    """
    parts: list[str] = []

    parts.append(
        dedent(
            """
            The following C/C++ source file contains a memory-safety bug.

            --- STATIC ANALYZER DIAGNOSTICS ---
            {diagnostics}
            --- END DIAGNOSTICS ---

            Here is the complete source file:
            --- BEGIN SOURCE.C ---
            {source}
            --- END SOURCE.C ---

            IMPORTANT INSTRUCTIONS (read carefully):
            1) Only edit text located inside '#ifndef OMITBAD' ... its matching '#endif' blocks.
               Do NOT modify any other lines, including includes, macros, blank lines, indentation, or comments.
            2) Preserve all comments exactly (do not change wording, punctuation, or whitespace inside comments).
               Pay attention to existing comments and follow any suggestions contained in them when making edits inside '#ifndef OMITBAD' blocks.
            3) If no change is necessary inside the '#ifndef OMITBAD' blocks, return the original file verbatim.
            4) If you cannot follow these rules exactly, return only the single token: REFUSE_TO_MODIFY_OUTSIDE_OMITBAD

            Please return the FULL fixed source file (or the single token above). Do not include explanations, markdown, or any extra text.
            """
        ).format(diagnostics=diagnostics.strip() or "(no diagnostics given)",
                 source=source_code)
    )

    if extra_context:
        parts.append(
            "\nAdditional context from the experiment:\n" + extra_context.strip()
        )

    return "\n\n".join(parts).strip()

def load_shot_io(idx: int) -> str:
    out = f"Example #{idx} Input C Source Code with Memory-Safety Violation\n"
    bad_file = FEW_SHOT_BAD / f"{idx:02d}.c"
    good_file = FEW_SHOT_GOOD / f"{idx:02d}.c"
    with open(bad_file, "r", encoding="utf-8") as file:
        out += file.read()
        out += "\n"
    out += f"Example #{idx} Fixed Output C Source Code without Memory-Safety Violation\n"
    with open(good_file, "r", encoding="utf-8") as file:
        out += file.read()
        out += "\n"
    return out

def build_omitbad_fix_user_prompt(
    source_code: str,
    diagnostics: str,
    extra_context: str | None = None,
    num_shots: int = NUM_SHOTS,
) -> str:
    """
    Build the user message for the LLM.

    `diagnostics` is whatever your static analyzer returns
    (clang-analyzer output, etc.) serialized as a string.
    """
    # Construct few-shot IO examples
    few_shot_part = ""
    if num_shots > 0:
        few_shot_part = "The following contains input-output examples of C/C++ source code with memory-safety bugs, and their fixes.\n"
        for idx in range(1, min(5,num_shots)+1):
            few_shot_part += load_shot_io(idx)
    
    parts: list[str] = []

    parts.append(
        dedent(
            """
            {few_shot_part}

            The following C/C++ source file contains a memory-safety bug.

            --- STATIC ANALYZER DIAGNOSTICS ---
            {diagnostics}
            --- END DIAGNOSTICS ---

            Here is the complete source file:
            --- BEGIN SOURCE.C ---
            {source}
            --- END SOURCE.C ---

            Please return the FULL fixed source file without any memory-safety bugs. Do not include explanations, markdown, or any extra text.
            """
        ).format(few_shot_part=few_shot_part,
                 diagnostics=diagnostics.strip() or "(no diagnostics given)",
                 source=source_code)
    )

    if extra_context:
        parts.append(
            "\nAdditional context from the experiment:\n" + extra_context.strip()
        )

    return "\n\n".join(parts).strip()