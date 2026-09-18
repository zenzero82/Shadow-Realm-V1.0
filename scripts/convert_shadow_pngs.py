#!/usr/bin/env python3
from pathlib import Path
from subprocess import run, CalledProcessError
import sys

REPO_ROOT = Path(__file__).resolve().parent.parent
TOOLS_GBAGFX = REPO_ROOT / "tools" / "gbagfx" / "gbagfx"
PNG_SIGNATURE = b"\x89PNG\r\n\x1a\n"
SPECIAL_SPRITESHEET_OPTIONS = {
    "graphics/pokemon/arceus": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/articuno": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/blacephalon": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/buzzwole": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/chien_pao": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/dialga": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/enamorus": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/entei": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/giratina": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/goodra/shadow": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/groudon": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/ho_oh": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/hoopa/unbound": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/koraidon": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/kyogre": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/kyurem": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/lugia": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/lunala": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/meloetta": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/melmetal": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/mewtwo": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/meowth/shadow": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/miraidon/shadow": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/moltres": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/metagross/shadow": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/naganadel": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/palkia/shadow": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/rayquaza/shadow": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/regigigas": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/genesect": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/reshiram": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/solgaleo": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/steelix": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/suicune": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/xerneas/shadow": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/yveltal": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/zacian": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/zamazenta": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/zekrom/shadow": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/zygarde": ["-mwidth", "8", "-mheight", "8"],
    "graphics/pokemon/mimikyu": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/pikachu/shadow": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/inteleon/shadow": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/pangoro/shadow": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/skarmory/shadow": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/weavile/shadow": ["-mwidth", "4", "-mheight", "4"],
    "graphics/pokemon/venusaur/shadow": ["-mwidth", "4", "-mheight", "4"],

}

def read_png_dimensions(png_path):
    with png_path.open("rb") as f:
        header = f.read(24)
    if not header.startswith(PNG_SIGNATURE):
        raise ValueError(f"{png_path} is not a PNG")
    width = int.from_bytes(header[16:20], "big")
    height = int.from_bytes(header[20:24], "big")
    return width, height

def get_overworld_options(png_path):
    width, height = read_png_dimensions(png_path)
    frame_width = width // 6 if width % 6 == 0 else width
    tile_width = max(1, frame_width // 8)
    tile_height = max(1, height // 8)
    return ["-mwidth", str(tile_width), "-mheight", str(tile_height)]

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
    target_gbapal = base.with_suffix(".gbapal")

    rel_dir = str(png.parent.relative_to(REPO_ROOT))
    extra_opts = []
    if png.name in ("overworld.png", "overworldf.png"):
        extra_opts = get_overworld_options(png)
        for prefix, opts in SPECIAL_SPRITESHEET_OPTIONS.items():
            if rel_dir.startswith(prefix):
                extra_opts = opts
                break

    try:
        run([str(TOOLS_GBAGFX), str(png), str(target_4bpp), *extra_opts], check=True)
        run([str(TOOLS_GBAGFX), str(target_4bpp), str(target_lz)], check=True)
        if png.name in ("icon.png", "iconf.png"):
            run([str(TOOLS_GBAGFX), str(png), str(target_gbapal)], check=True)
        converted += 1
    except CalledProcessError as e:
        print(f"conversion failed for {png}: {e}", file=sys.stderr)
        sys.exit(1)

print(f"Converted {converted} PNG files to .4bpp(.lz).")
