#!/usr/bin/env python3
"""
Main orchestration script that runs all three implementations on a given CWE directory.

Usage: python3 main.py <CWE#>
Example: python3 main.py CWE121_Stack_Based_Buffer_Overflow
"""

import sys
import io
import contextlib
from pathlib import Path
from datetime import datetime

REPO_ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(REPO_ROOT))

from scripts.full_implementation import process_test_case_with_llm as process_full
from scripts.llm_only import process_test_case_with_llm as process_llm_only
from scripts.no_few_shot import process_test_case_with_llm as process_no_few_shot


@contextlib.contextmanager
def capture_output():
    """Capture stdout and stderr."""
    old_stdout = sys.stdout
    old_stderr = sys.stderr
    stdout_capture = io.StringIO()
    stderr_capture = io.StringIO()
    
    try:
        sys.stdout = stdout_capture
        sys.stderr = stderr_capture
        yield stdout_capture, stderr_capture
    finally:
        sys.stdout = old_stdout
        sys.stderr = old_stderr


class ImplementationStats:
    """Track statistics for a single implementation."""
    
    def __init__(self, name: str):
        self.name = name
        self.total_files = 0
        self.successful = []
        self.failed = []
        self.skipped = []
        self.iterations = []  # Store iteration counts for all processed files
        self.log_entries = []  # Store log output for each file
    
    def add_result(self, filename: str, verdict: int, iteration_count: int, log_output: str):
        """Add a result for a single file."""
        self.total_files += 1
        self.log_entries.append(f"\n{'='*60}\nFile: {filename}\n{'='*60}\n{log_output}")
        
        if verdict == -1:  # skipped
            self.skipped.append(filename)
        elif verdict == 0:  # success
            self.successful.append(filename)
            self.iterations.append(iteration_count)
        else:  # failure
            self.failed.append(filename)
            self.iterations.append(iteration_count)
    
    def average_iterations(self) -> float:
        """Calculate average iterations across all processed files."""
        return sum(self.iterations) / len(self.iterations) if self.iterations else 0.0
    
    def summary(self) -> str:
        """Generate summary statistics text."""
        total = self.total_files
        success_pct = (len(self.successful) / total * 100) if total > 0 else 0
        failed_pct = (len(self.failed) / total * 100) if total > 0 else 0
        skipped_pct = (len(self.skipped) / total * 100) if total > 0 else 0
        
        return f"""
{self.name} Implementation Results:
{'='*60}
Total files: {total}
Successfully fixed: {len(self.successful)} ({success_pct:.1f}%)
Failed to fix: {len(self.failed)} ({failed_pct:.1f}%)
Skipped: {len(self.skipped)} ({skipped_pct:.1f}%)
Average iterations per file: {self.average_iterations():.2f}

Successful files:
{chr(10).join('  - ' + f for f in self.successful) if self.successful else '  (none)'}

Failed files:
{chr(10).join('  - ' + f for f in self.failed) if self.failed else '  (none)'}

Skipped files:
{chr(10).join('  - ' + f for f in self.skipped) if self.skipped else '  (none)'}
"""


def main(argv: list[str] | None = None) -> int:
    """Main orchestration function."""
    argv = argv if argv is not None else sys.argv[1:]
    
    if len(argv) != 1:
        print("Usage: python3 main.py <CWE#>", file=sys.stderr)
        print("Example: python3 main.py CWE121_Stack_Based_Buffer_Overflow", file=sys.stderr)
        return 1
    
    cwe_num = argv[0]
    
    # Setup paths
    input_dir = REPO_ROOT / "data" / "juliet" / "omitbad" / cwe_num
    eval_dir = REPO_ROOT / "data" / "eval" / cwe_num
    eval_dir.mkdir(parents=True, exist_ok=True)
    
    # Verify input directory exists
    if not input_dir.exists():
        print(f"[ERROR] Input directory does not exist: {input_dir}", file=sys.stderr)
        return 1
    
    # Get all test case files
    test_cases = sorted(input_dir.glob("*.c"))
    
    if not test_cases:
        print(f"[ERROR] No test cases found in: {input_dir}", file=sys.stderr)
        return 1
    
    print(f"\n{'='*60}")
    print(f"Processing CWE: {cwe_num}")
    print(f"Found {len(test_cases)} test case(s)")
    print(f"{'='*60}\n")
    
    # Initialize statistics for each implementation
    implementations = {
        'full': (process_full, ImplementationStats("Full (SA + LLM + Judge)")),
        'llm_only': (process_llm_only, ImplementationStats("LLM Only (No SA)")),
        'no_few_shot': (process_no_few_shot, ImplementationStats("No Few-Shot (SA + LLM + Judge, 0 examples)")),
    }
    
    # Process each file with each implementation
    for idx, test_case in enumerate(test_cases, 1):
        print(f"\n{'#'*60}")
        print(f"# Processing test case {idx}/{len(test_cases)}: {test_case.name}")
        print(f"{'#'*60}")
        
        for impl_name, (process_func, stats) in implementations.items():
            print(f"\n--- Running {stats.name} ---")
            
            # Capture output
            with capture_output() as (stdout_capture, stderr_capture):
                try:
                    verdict, iteration_count = process_func(test_case)
                except Exception as e:
                    print(f"[ERROR] Exception during processing: {e}")
                    import traceback
                    traceback.print_exc()
                    verdict = 1  # Mark as failure
                    iteration_count = 0
            
            # Get captured logs
            log_output = stdout_capture.getvalue() + "\n[STDERR]\n" + stderr_capture.getvalue()
            
            # Record results
            stats.add_result(test_case.name, verdict, iteration_count, log_output)
            
            # Print brief result to console
            if verdict == 0:
                result_str = "SUCCESS"
            elif verdict == -1:
                result_str = "SKIPPED"
            else:
                result_str = "FAILED"
            
            print(f"[{result_str}] {test_case.name} - {stats.name} (iterations: {iteration_count})")
    
    # Save evaluation results
    print(f"\n{'='*60}")
    print("Saving evaluation results...")
    print(f"{'='*60}")
    
    # Write eval.txt
    eval_file = eval_dir / "eval.txt"
    with eval_file.open("w", encoding="utf-8") as f:
        f.write(f"Evaluation Results for {cwe_num}\n")
        f.write(f"Generated: {datetime.now().isoformat()}\n")
        f.write(f"Total test cases: {len(test_cases)}\n")
        f.write("="*60 + "\n\n")
        
        for impl_name, (_, stats) in implementations.items():
            f.write(stats.summary())
            f.write("\n" + "="*60 + "\n\n")
    
    # Write log.txt
    log_file = eval_dir / "log.txt"
    with log_file.open("w", encoding="utf-8") as f:
        f.write(f"Detailed Logs for {cwe_num}\n")
        f.write(f"Generated: {datetime.now().isoformat()}\n")
        f.write("="*60 + "\n\n")
        
        for impl_name, (_, stats) in implementations.items():
            f.write(f"\n{'#'*60}\n")
            f.write(f"# Logs for {stats.name}\n")
            f.write(f"{'#'*60}\n")
            f.write("".join(stats.log_entries))
            f.write("\n\n")
    
    print(f"\n{'='*60}")
    print(f"Evaluation results saved to: {eval_file}")
    print(f"Detailed logs saved to: {log_file}")
    print(f"{'='*60}\n")
    
    # Print summary to console
    print("\n" + "="*60)
    print("SUMMARY")
    print("="*60)
    for impl_name, (_, stats) in implementations.items():
        print(f"\n{stats.name}:")
        print(f"  Success: {len(stats.successful)}/{stats.total_files}")
        print(f"  Failed: {len(stats.failed)}/{stats.total_files}")
        print(f"  Skipped: {len(stats.skipped)}/{stats.total_files}")
        print(f"  Avg iterations: {stats.average_iterations():.2f}")
    
    return 0


if __name__ == "__main__":
    sys.exit(main())
