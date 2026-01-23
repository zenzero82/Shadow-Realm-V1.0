#!/usr/bin/env python3
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parent.parent
RULES_FILE = ROOT / "spritesheet_rules.mk"
GRAPHICS_DIR = ROOT / "graphics" / "pokemon"

def png_dimensions(path: Path):
    with path.open("rb") as f:
        f.seek(16)
        width = int.from_bytes(f.read(4), "big")
        height = int.from_bytes(f.read(4), "big")
    return width, height

def main():
    if not RULES_FILE.exists():
        print("spritesheet_rules.mk not found", file=sys.stderr)
        return 1
    lines = RULES_FILE.read_text().splitlines()
    updated = 0
    pattern = re.compile(r"\$\((?:POKEMONGFXDIR)\)/(.+)/shadow/overworld\.4bpp")
    for idx, line in enumerate(lines):
        match = pattern.search(line)
        if not match:
            continue
        rel = match.group(1)
        png_path = GRAPHICS_DIR / rel / "shadow" / "overworld.png"
        if not png_path.exists():
            continue
        width, height = png_dimensions(png_path)
        tile_w = max(1, width // 8)
        tile_h = max(1, height // 8)
        cmd_idx = idx + 1
        if cmd_idx >= len(lines):
            continue
        cmd_line = lines[cmd_idx]
        new_cmd = re.sub(r"-mwidth\s+\d+", f"-mwidth {tile_w}", cmd_line)
        new_cmd = re.sub(r"-mheight\s+\d+", f"-mheight {tile_h}", new_cmd)
        if new_cmd != cmd_line:
            lines[cmd_idx] = new_cmd
            updated += 1
    if updated > 0:
        RULES_FILE.write_text("\n".join(lines) + "\n")
    print(f"Updated {updated} shadow overworld rules.")
    return 0

if __name__ == "__main__":
    sys.exit(main())
