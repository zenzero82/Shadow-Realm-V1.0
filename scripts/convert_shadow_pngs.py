#!/usr/bin/env python3
from pathlib import Path
from subprocess import run, CalledProcessError
import sys

REPO_ROOT = Path(__file__).resolve().parent.parent
TOOLS_GBAGFX = REPO_ROOT / "tools" / "gbagfx" / "gbagfx"
SPECIAL_SPRITESHEET_OPTIONS = {
    "graphics/pokemon/arceus": ["-mwidth", "8", "-mheight", "8"],
}

if not TOOLS_GBAGFX.exists():
    sys.exit(f"Missing tool: {TOOLS_GBAGFX}")

png_files = sorted(
    REPO_ROOT.glob("graphics/pokemon/**/shadow/*.png"), key=lambda p: str(p).lower()
)
converted = 0
for png in png_files:
    if "Zone.Identifier" in png.name:
        continue
    base = png.with_suffix("")
    target_4bpp = base.with_suffix(".4bpp")
    target_lz = base.with_suffix(".4bpp.lz")

    rel_dir = str(png.parent.relative_to(REPO_ROOT))
    extra_opts = []
    if png.name == "overworld.png":
        for prefix, opts in SPECIAL_SPRITESHEET_OPTIONS.items():
            if rel_dir.startswith(prefix):
                extra_opts = opts
                break

    try:
        run([str(TOOLS_GBAGFX), str(png), str(target_4bpp), *extra_opts], check=True)
        run([str(TOOLS_GBAGFX), str(target_4bpp), str(target_lz)], check=True)
        converted += 1
    except CalledProcessError as e:
        print(f"conversion failed for {png}: {e}", file=sys.stderr)
        sys.exit(1)

print(f"Converted {converted} PNG files to .4bpp(.lz).")
