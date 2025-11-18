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
    - Rewrite ONLY the necessary parts of the code to fix the problem.
    - Do not change function signatures unless required.
    - Preserve the original program intent and behavior.
    - Avoid introducing new warnings or memory issues.
    - Return ONLY the full fixed source file, nothing else.
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

            Please return the FULL fixed source file, with the bug corrected.
            Do not include explanations, comments, or markdown. Only valid C/C++ code.
            """
        ).format(diagnostics=diagnostics.strip() or "(no diagnostics given)",
                 source=source_code)
    )

    if extra_context:
        parts.append(
            "\nAdditional context from the experiment:\n" + extra_context.strip()
        )

    return "\n\n".join(parts).strip()
