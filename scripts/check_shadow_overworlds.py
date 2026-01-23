#!/usr/bin/env python3
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parent.parent
RULES = ROOT / "spritesheet_rules.mk"
SHADOW_DIRS = [Path("graphics/pokemon"), Path("graphics/pokemon/pokemon")]

def png_size(path: Path):
    with path.open("rb") as f:
        f.seek(16)
        width = int.from_bytes(f.read(4), "big")
        height = int.from_bytes(f.read(4), "big")
    return width, height

def load_counts():
    if not RULES.exists():
        return {}
    counts = {}
    re_line = re.compile(r"\$\((?:POKEMONGFXDIR)\)/([^/]+(?:/[^/]+)?)/overworld\.4bpp")
    lines = RULES.read_text().splitlines()
    for idx, line in enumerate(lines):
        if "overworld.4bpp" not in line or "/shadow/" in line:
            continue
        match = re_line.search(line)
        if not match:
            continue
        slug = match.group(1)
        cmd = lines[idx + 1] if idx + 1 < len(lines) else ""
        w_match = re.search(r"-mwidth\s+(\d+)", cmd)
        h_match = re.search(r"-mheight\s+(\d+)", cmd)
        if w_match and h_match:
            counts[slug] = (int(w_match.group(1)), int(h_match.group(1)))
    return counts

def find_shadow_overworld(slug: str):
    rel = Path(*slug.split("/"))
    for base in SHADOW_DIRS:
        path = ROOT / base / rel / "shadow" / "overworld.png"
        if path.exists():
            return path
    return None

def main():
    counts = load_counts()
    if not counts:
        print("No overworld rules found.", file=sys.stderr)
        return 1
    mismatches = []
    for slug, (tiles_w, tiles_h) in counts.items():
        target = find_shadow_overworld(slug)
        if not target:
            continue
        try:
            shadow_w, shadow_h = png_size(target)
        except Exception:
            continue
        exp_w, exp_h = tiles_w * 8, tiles_h * 8
        if (shadow_w, shadow_h) != (exp_w, exp_h):
            mismatches.append((slug, (shadow_w, shadow_h), (exp_w, exp_h), str(target)))

    if not mismatches:
        print("All shadow overworld PNGs match their spritesheet rule sizes.")
        return 0

    print("Mismatch between spritesheet rules and shadow overworld PNGs:")
    for slug, shadow_size, expected_size, path in mismatches:
        print(f"- {slug}: shadow {shadow_size} vs expected {expected_size} ({path})")
    return 1


if __name__ == "__main__":
    sys.exit(main())
