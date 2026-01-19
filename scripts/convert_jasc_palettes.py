#!/usr/bin/env python3
from pathlib import Path

def convert_jasc(path: Path) -> bool:
    try:
        text = path.read_text().splitlines()
    except UnicodeDecodeError:
        return False
    if len(text) < 3 or text[0].strip() != "JASC-PAL" or text[1].strip() != "0100":
        return False
    try:
        count = int(text[2].strip())
    except ValueError:
        return False
    colors = []
    for line in text[3:3 + count]:
        parts = line.split()
        if len(parts) < 3:
            continue
        r, g, b = (int(v) for v in parts[:3])
        # convert 0-255 to 0-31
        r = max(0, min(31, r >> 3))
        g = max(0, min(31, g >> 3))
        b = max(0, min(31, b >> 3))
        colors.append((b << 10) | (g << 5) | r)
    if not colors:
        return False
    data = bytearray()
    for color in colors:
        data.extend(color.to_bytes(2, "little"))
    path.write_bytes(data)
    return True

if __name__ == "__main__":
    root = Path(__file__).resolve().parent.parent
    converted = []
    for pal in root.glob("graphics/pokemon/**/shadow/*_shadow.pal"):
        if convert_jasc(pal):
            converted.append(pal)
    if converted:
        print("Converted the following JASC-PAL palettes to binary:")
        for pal in converted:
            print(pal)
    else:
        print("No JASC-PAL shadow palettes were found.")
