#!/usr/bin/env python3
from pathlib import Path

root = Path(__file__).resolve().parent.parent
odd = []
for pal in root.glob("graphics/pokemon/**/*"):
    if pal.suffix.lower() not in {".pal", ".gbapal"}:
        continue
    if pal.stat().st_size % 2:
        odd.append(pal)
if odd:
    print("Odd-sized palette files:")
    for pal in odd:
        print(f"{pal.stat().st_size:4d} bytes: {pal}")
    raise SystemExit(1)
print("All shadow palettes have even byte counts.")
