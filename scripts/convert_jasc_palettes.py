#!/usr/bin/env python3
from pathlib import Path

def is_jasc(path: Path) -> bool:
    try:
        text = path.read_text().splitlines()
    except UnicodeDecodeError:
        return False
    return len(text) >= 3 and text[0].strip() == "JASC-PAL" and text[1].strip() == "0100"

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

def write_jasc_from_gbapal(pal_path: Path, gbapal_path: Path) -> bool:
    data = gbapal_path.read_bytes()
    if len(data) % 2 != 0:
        return False
    colors = []
    for i in range(0, len(data), 2):
        color = int.from_bytes(data[i:i + 2], "little")
        r = color & 0x1F
        g = (color >> 5) & 0x1F
        b = (color >> 10) & 0x1F
        colors.append((r << 3, g << 3, b << 3))
    lines = ["JASC-PAL", "0100", str(len(colors))]
    lines.extend(f"{r} {g} {b}" for r, g, b in colors)
    pal_path.write_text("\n".join(lines) + "\n")
    return True

if __name__ == "__main__":
    root = Path(__file__).resolve().parent.parent
    converted = []
    for pal in root.glob("graphics/pokemon/**/shadow/*.pal"):
        if pal.name.endswith("_shadow.pal"):
            if convert_jasc(pal):
                converted.append(pal)
            continue
        gbapal = pal.with_suffix(".gbapal")
        if gbapal.exists() and not is_jasc(pal):
            if write_jasc_from_gbapal(pal, gbapal):
                converted.append(pal)
    if converted:
        print("Normalized the following shadow palettes to binary or JASC:")
        for pal in converted:
            print(pal)
    else:
        print("No JASC-PAL shadow palettes were found.")
