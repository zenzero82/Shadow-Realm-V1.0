#!/usr/bin/env python3
import sys
from pathlib import Path


def main() -> int:
    if len(sys.argv) != 3:
        print("Usage: shift_pal_index.py <file> <offset>", file=sys.stderr)
        return 1

    path = Path(sys.argv[1])
    offset = int(sys.argv[2], 0)

    data = bytearray(path.read_bytes())
    for i, value in enumerate(data):
        if value != 0:
            data[i] = (value + offset) & 0xFF

    path.write_bytes(data)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
