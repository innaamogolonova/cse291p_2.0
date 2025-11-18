# llm/interface.py
from __future__ import annotations

import json
import os
from dataclasses import dataclass
from pathlib import Path
from typing import Protocol, Any

from .prompts import DEFAULT_SYSTEM_PROMPT, build_fix_user_prompt


# -----------------------------
# Data structures
# -----------------------------


@dataclass
class LLMConfig:
    model: str = "gpt-4.1-mini"
    temperature: float = 0.1
    max_output_tokens: int = 2048


@dataclass
class LLMFixResult:
    """Container for an LLM-generated fix and metadata."""

    fixed_code: str
    model: str
    prompt_system: str
    prompt_user: str
    diagnostics: str
    raw_response: dict[str, Any]

    def save(self, source_path: Path, output_root: Path) -> dict[str, Path]:
        """
        Save the fixed code and metadata next to a mirrored directory structure.

        Example:
          source_path  = data/juliet/test_cases/CWE476/foo.c
          output_root  = build/llm_fixes
          fixed_code → build/llm_fixes/CWE476/foo.fixed.c
          metadata   → build/llm_fixes/CWE476/foo.fixed.metadata.json
        """
        source_path = source_path.resolve()
        output_root = output_root.resolve()

        # Heuristic: try to mirror from "test_cases" downward, otherwise keep the file name.
        try:
            rel = source_path.relative_to(
                next(
                    p for p in source_path.parents
                    if p.name == "test_cases"
                )
            )
        except StopIteration:
            rel = Path(source_path.name)

        fixed_rel = rel.with_suffix(rel.suffix + ".fixed.c")
        meta_rel = rel.with_suffix(rel.suffix + ".fixed.metadata.json")

        fixed_path = output_root / fixed_rel
        meta_path = output_root / meta_rel

        fixed_path.parent.mkdir(parents=True, exist_ok=True)
        meta_path.parent.mkdir(parents=True, exist_ok=True)

        fixed_path.write_text(self.fixed_code, encoding="utf-8")

        meta = {
            "source_path": str(source_path),
            "fixed_path": str(fixed_path),
            "model": self.model,
            "diagnostics": self.diagnostics,
            "prompt_system": self.prompt_system,
            "prompt_user": self.prompt_user,
            "raw_response": self.raw_response,
        }
        meta_path.write_text(json.dumps(meta, indent=2), encoding="utf-8")

        return {"fixed": fixed_path, "metadata": meta_path}


# -----------------------------
# Abstract interface
# -----------------------------


class LLMClient(Protocol):
    """Abstract interface for any LLM backend."""

    def suggest_fix(
        self,
        source_code: str,
        diagnostics: str,
        *,
        extra_context: str | None = None,
    ) -> LLMFixResult:
        ...


# -----------------------------
# Concrete OpenAI implementation
# -----------------------------


class OpenAILLMClient:
    """
    Thin wrapper around the OpenAI API that conforms to LLMClient.

    Requires the environment variable OPENAI_API_KEY to be set.
    """

    def __init__(self, config: LLMConfig | None = None) -> None:
        from openai import OpenAI  # type: ignore[import-untyped]

        api_key = os.environ.get("OPENAI_API_KEY")
        if not api_key:
            raise RuntimeError("OPENAI_API_KEY environment variable is not set.")

        self._client = OpenAI(api_key=api_key)
        self._config = config or LLMConfig()

    def suggest_fix(
        self,
        source_code: str,
        diagnostics: str,
        *,
        extra_context: str | None = None,
    ) -> LLMFixResult:
        system_prompt = DEFAULT_SYSTEM_PROMPT
        user_prompt = build_fix_user_prompt(
            source_code=source_code,
            diagnostics=diagnostics,
            extra_context=extra_context,
        )

        # You can swap this to .chat.completions.create if you prefer that API.
        response = self._client.responses.create(
            model=self._config.model,
            temperature=self._config.temperature,
            max_output_tokens=self._config.max_output_tokens,
            input=[
                {
                    "role": "system",
                    "content": system_prompt,
                },
                {
                    "role": "user",
                    "content": user_prompt,
                },
            ],
        )

        # Extract text – adjust depending on which API version you use.
        # Here we assume a single text output.
        output_text = response.output[0].content[0].text  # type: ignore[index]

        return LLMFixResult(
            fixed_code=output_text,
            model=self._config.model,
            prompt_system=system_prompt,
            prompt_user=user_prompt,
            diagnostics=diagnostics,
            raw_response=response.to_dict() if hasattr(response, "to_dict") else {},  # type: ignore[arg-type]
        )
