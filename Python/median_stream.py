"""
Median Stream utility for Hacktoberfest contribution.

This module implements a MedianStream class that maintains the running median
of a stream of numbers using two heaps (O(log n) per insertion, O(1) median).

Usage (examples):

# Import and use programmatically
from median_stream import MedianStream
m = MedianStream()
m.add(10)
m.add(2)
print(m.median())  # 6.0

# Command-line use: pass numbers as arguments
$ python3 Python/median_stream.py 3 1 4 1 5
Streaming medians: [3, 2.0, 3, 2.0, 3]

# Or pipe numbers (one per line) and it will print the final median
$ printf "1\n2\n3\n" | python3 Python/median_stream.py --stdin
Final median: 2

The file includes a small self-test that runs when executed directly.
"""

from __future__ import annotations

import heapq
import sys
from typing import List, Optional


class MedianStream:
    """Keep track of the median for a stream of numbers.

    Implementation details:
    - "low" is a max-heap implemented by storing negatives (largest of the low half)
    - "high" is a min-heap (smallest of the high half)

    Invariant: len(low) == len(high) or len(low) == len(high) + 1
    """

    def __init__(self) -> None:
        self.low: List[float] = []  # max-heap via negatives
        self.high: List[float] = []  # min-heap

    def add(self, value: float) -> None:
        """Add a numeric value to the stream."""
        if not self.low or value <= -self.low[0]:
            heapq.heappush(self.low, -value)
        else:
            heapq.heappush(self.high, value)
        self._rebalance()

    def _rebalance(self) -> None:
        # Ensure size invariant between heaps
        if len(self.low) > len(self.high) + 1:
            val = -heapq.heappop(self.low)
            heapq.heappush(self.high, val)
        elif len(self.high) > len(self.low):
            val = heapq.heappop(self.high)
            heapq.heappush(self.low, -val)

    def median(self) -> Optional[float]:
        """Return current median. None if no elements added."""
        if not self.low and not self.high:
            return None
        if len(self.low) > len(self.high):
            return float(-self.low[0])
        # even number of items -> average of two middles
        return ( -self.low[0] + self.high[0] ) / 2.0

    def clear(self) -> None:
        """Reset the stream."""
        self.low.clear()
        self.high.clear()

    def __len__(self) -> int:
        return len(self.low) + len(self.high)


def parse_numbers(args: List[str]) -> List[float]:
    """Parse a list of numeric arguments. Accepts numbers separated by commas as well.

    Examples:
      ['1', '2,3', '4'] -> [1.0, 2.0, 3.0, 4.0]
    """
    out: List[float] = []
    for token in args:
        for part in token.split(','):
            part = part.strip()
            if not part:
                continue
            try:
                out.append(float(part))
            except ValueError:
                raise ValueError(f"Invalid numeric value: '{part}'")
    return out


def main(argv: List[str]) -> int:
    import argparse

    parser = argparse.ArgumentParser(
        prog="median_stream",
        description="Compute running median(s) from provided numbers or stdin.",
    )
    parser.add_argument("numbers", nargs="*", help="Numbers (or comma-separated list) to add")
    parser.add_argument("--stdin", action="store_true", help="Read one number per line from stdin")
    parser.add_argument("--stream-output", action="store_true", help="Print medians after each insertion")
    args = parser.parse_args(argv[1:])

    numbers: List[float] = []
    if args.stdin:
        for line in sys.stdin:
            line = line.strip()
            if not line:
                continue
            try:
                numbers.append(float(line))
            except ValueError:
                print(f"warning: skipping invalid line: {line}", file=sys.stderr)
    if args.numbers:
        numbers.extend(parse_numbers(args.numbers))

    if not numbers:
        print("No numbers provided. Example: python3 Python/median_stream.py 3 1 4 1 5")
        return 1

    ms = MedianStream()
    medians: List[float] = []
    for v in numbers:
        ms.add(v)
        med = ms.median()
        medians.append(med if med is not None else 0.0)
        if args.stream_output:
            print(med)

    if args.stream_output:
        return 0

    # Default: print aggregated medians (streaming medians list) and final median
    print("Streaming medians:", medians)
    print("Final median:", ms.median())
    return 0


if __name__ == "__main__":
    # Quick self-test / demonstration
    # Run a couple of simple checks and exit non-zero on failure.
    def _run_quick_tests() -> None:
        m = MedianStream()
        data = [3, 1, 4, 1, 5]
        expected = [3, 2.0, 3, 2.0, 3]
        outs = []
        for x in data:
            m.add(x)
            outs.append(m.median())
        assert outs == expected, f"expected {expected} got {outs}"

        m.clear()
        for x in [1, 2, 3, 4]:
            m.add(x)
        assert m.median() == 2.5

        # negative and floats
        m.clear()
        for x in [-1.5, 0, 1.5]:
            m.add(x)
        assert m.median() == 0.0

    try:
        _run_quick_tests()
    except AssertionError as e:
        print("Self-tests failed:", e, file=sys.stderr)
        sys.exit(2)

    # If tests pass, run main with actual args
    raise SystemExit(main(sys.argv))
