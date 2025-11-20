# llm/prompts.py
from __future__ import annotations

from textwrap import dedent


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
