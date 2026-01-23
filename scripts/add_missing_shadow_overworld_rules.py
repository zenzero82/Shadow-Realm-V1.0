#!/usr/bin/env python3
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parent.parent
RULES_FILE = ROOT / "spritesheet_rules.mk"
GRAPHICS_DIR = ROOT / "graphics" / "pokemon"

def png_tile_counts(path: Path):
    with path.open("rb") as f:
        f.seek(16)
        width = int.from_bytes(f.read(4), "big")
        height = int.from_bytes(f.read(4), "big")
    return max(1, width // 8), max(1, height // 8)

def gather_shadow_dirs():
    paths = []
    for shadow_dir in GRAPHICS_DIR.rglob("shadow"):
        rel = shadow_dir.relative_to(GRAPHICS_DIR)
        if rel.parts[0] == "pokemon":
            continue
        png_path = shadow_dir / "overworld.png"
        if not png_path.exists():
            continue
        slug = "/".join(rel.parts[:-1])
        if not slug:
            continue
        paths.append((slug, png_path))
    return sorted(paths)

def load_existing_rules():
    if not RULES_FILE.exists():
        return set()
    content = RULES_FILE.read_text()
    return set(re.findall(r"\$\((?:POKEMONGFXDIR)\)/([^/]+/[^/]+/shadow)/overworld\.4bpp", content))

def main():
    if not RULES_FILE.exists():
        print("spritesheet_rules.mk missing", file=sys.stderr)
        return 1
    existing = load_existing_rules()
    shadow_dirs = gather_shadow_dirs()
    lines = RULES_FILE.read_text().splitlines()
    additions = []
    for slug, png in shadow_dirs:
        pattern_key = slug.replace("pokemon/", "")
        if slug in existing:
            continue
        tile_w, tile_h = png_tile_counts(png)
        target = f"$(POKEMONGFXDIR)/{slug}/shadow/overworld.4bpp: %.4bpp: %.png"
        additions.extend([
            "",
            target,
            f"\t$(GFX) $< $@ -mwidth {tile_w} -mheight {tile_h}"
        ])
        existing.add(slug)
    if additions:
        if lines and lines[-1].strip() != "":
            lines.append("")
        lines.extend(additions)
        RULES_FILE.write_text("\n".join(lines) + "\n")
    print(f"Added {len(additions)//3} missing shadow overworld rules.")
    return 0

if __name__ == "__main__":
    sys.exit(main())
