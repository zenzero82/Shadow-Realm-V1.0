#!/usr/bin/env python3
import sys
from pathlib import Path


def read_jasc_pal(path: Path):
    lines = path.read_text().strip().splitlines()
    if len(lines) < 3 or lines[0].strip() != "JASC-PAL":
        raise ValueError(f"Invalid JASC palette: {path}")
    count = int(lines[2].strip())
    colors = []
    for line in lines[3:3 + count]:
        parts = line.strip().split()
        if len(parts) != 3:
            raise ValueError(f"Malformed palette entry in {path}: {line}")
        colors.append(tuple(int(p) for p in parts))
    if len(colors) != count:
        raise ValueError(f"Palette size mismatch in {path}")
    return colors


def main() -> int:
    if len(sys.argv) != 5:
        print("Usage: remap_pal_indices.py <data.8bpp> <src.pal> <dst.pal> <offset>", file=sys.stderr)
        return 1

    data_path = Path(sys.argv[1])
    src_pal = Path(sys.argv[2])
    dst_pal = Path(sys.argv[3])
    offset = int(sys.argv[4], 0)

    src_colors = read_jasc_pal(src_pal)
    dst_colors = read_jasc_pal(dst_pal)

    dst_index = {}
    for idx, color in enumerate(dst_colors):
        if color not in dst_index:
            dst_index[color] = idx
    mapping = []
    for color in src_colors:
        if color not in dst_index:
            raise ValueError(f"Color {color} from {src_pal} not found in {dst_pal}")
        mapping.append(dst_index[color])

    data = bytearray(data_path.read_bytes())
    for i, value in enumerate(data):
        if value >= len(mapping):
            raise ValueError(f"Palette index {value} out of range for {src_pal}")
        data[i] = (mapping[value] + offset) & 0xFF

    data_path.write_bytes(data)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
