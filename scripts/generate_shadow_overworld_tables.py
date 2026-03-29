#!/usr/bin/env python3
"""Regenerates src/data/graphics/shadow_forms_overworld.inc from the shadow PNGs."""

from pathlib import Path
import re

ROOT = Path(__file__).resolve().parent.parent
SHADOW_GRAPHICS = ROOT / "graphics" / "pokemon"
OUTPUT = ROOT / "src" / "data" / "graphics" / "shadow_forms_overworld.inc"
SPECIES_HDR = ROOT / "include" / "constants" / "species.h"
RULES_FILE = ROOT / "spritesheet_rules.mk"
PNG_SIGNATURE = b"\x89PNG\r\n\x1a\n"


def read_png_dimensions(png_path: Path):
    with png_path.open("rb") as f:
        header = f.read(24)
    if not header.startswith(PNG_SIGNATURE):
        raise ValueError(f"{png_path} is not a PNG")
    width = int.from_bytes(header[16:20], "big")
    height = int.from_bytes(header[20:24], "big")
    return width, height


def pascal_case(name: str) -> str:
    return "".join(part.capitalize() for part in name.replace("-", "_").split("_"))


def species_constant(name: str, species_ids):
    sanitized = re.sub(r"[^A-Za-z0-9]+", "_", name).upper()
    candidates = [sanitized]
    parts = sanitized.split("_")
    for i in range(1, len(parts)):
        candidates.append("_".join(parts[:-i]))
        candidates.append("_".join(parts[i:]))
    for cand in candidates:
        key = f"SPECIES_{cand}"
        if key in species_ids:
            return key
    return None


def parse_species_ids():
    numeric = {}
    aliases = {}
    number_pattern = re.compile(r"#define\s+SPECIES_([A-Z0-9_]+)\s+(\d+)")
    alias_pattern = re.compile(r"#define\s+SPECIES_([A-Z0-9_]+)\s+SPECIES_([A-Z0-9_]+)")
    with SPECIES_HDR.open() as f:
        for line in f:
            m = number_pattern.match(line)
            if m:
                numeric[m.group(1)] = int(m.group(2))
                continue
            m = alias_pattern.match(line)
            if m:
                aliases[m.group(1)] = m.group(2)
    resolved = {f"SPECIES_{name}": value for name, value in numeric.items()}
    for alias, target in aliases.items():
        seen = set()
        base = target
        while base in aliases and base not in seen:
            seen.add(base)
            base = aliases[base]
        if base in numeric:
            resolved[f"SPECIES_{alias}"] = numeric[base]
    return resolved


def scan_shadow_species():
    species = {}
    for png in SHADOW_GRAPHICS.glob("**/shadow/overworld.png"):
        if "pokemon/pokemon/" in str(png):
            continue
        rel = png.parent.parent.relative_to(SHADOW_GRAPHICS)
        name = str(rel).replace("/", "_")
        width, height = read_png_dimensions(png)
        rel = png.parent.parent.relative_to(SHADOW_GRAPHICS)
        slug = rel.as_posix()
        data = {
            "name": name,
            "slug": slug,
            "tile_w": max(1, width // 8),
            "tile_h": max(1, height // 8),
        }
        palette_candidates = ["overworld_normal.gbapal", "overworld.gbapal"]
        data["has_overworld_palette"] = any(
            (png.parent / candidate).exists() for candidate in palette_candidates
        )
        female_png = png.parent / "overworldf.png"
        if female_png.exists():
            fw, fh = read_png_dimensions(female_png)
            data["female"] = {
                "tile_w": max(1, fw // 8),
                "tile_h": max(1, fh // 8),
            }
        species[name] = data
    return species


def load_shadow_rule_dimensions():
    dims = {}
    if not RULES_FILE.exists():
        return dims
    rule_pattern = re.compile(r"\$\((?:POKEMONGFXDIR)\)/(.+)/shadow/overworld\.4bpp")
    width_pattern = re.compile(r"-mwidth\s+(\d+)")
    height_pattern = re.compile(r"-mheight\s+(\d+)")
    lines = RULES_FILE.read_text().splitlines()
    for idx, line in enumerate(lines):
        match = rule_pattern.search(line)
        if not match:
            continue
        slug = match.group(1)
        cmd_line = lines[idx + 1] if idx + 1 < len(lines) else ""
        width_match = width_pattern.search(cmd_line)
        height_match = height_pattern.search(cmd_line)
        if width_match and height_match:
            dims[slug] = (int(width_match.group(1)), int(height_match.group(1)))
    return dims


def build_table(entries, species_ids):
    rows = []
    for name, data in entries.items():
        const_name = species_constant(name, species_ids)
        if not const_name or const_name not in species_ids:
            print("Missing const entry for", name, const_name)
            continue
        rows.append((species_ids[const_name], const_name, pascal_case(name), data))
    rows.sort()
    return rows


def main():
    species_ids = parse_species_ids()
    print("Sample constants:", list(species_ids.keys())[:5])
    species_entries = scan_shadow_species()
    rule_dims = load_shadow_rule_dimensions()
    table = build_table(species_entries, species_ids)
    lines = ["#if OW_POKEMON_OBJECT_EVENTS", ""]
    for _, const_name, camel, data in table:
        slug = data["slug"]
        tile_w, tile_h = rule_dims.get(slug, (data["tile_w"], data["tile_h"]))
        lines.append(f"static const struct SpriteFrameImage sPicTable_{camel}Shadow[] = {{")
        lines.append(f"    overworld_ascending_frames(gObjectEventPic_{camel}Shadow, {tile_w}, {tile_h}),")
        lines.append("};")
        lines.append("")
        female = data.get("female")
        if female:
            fw = female["tile_w"]
            fh = female["tile_h"]
            lines.append("#if P_GENDER_DIFFERENCES")
            lines.append(f"static const struct SpriteFrameImage sPicTable_{camel}FShadow[] = {{")
            f_width, f_height = rule_dims.get(slug, (fw, fh))
            lines.append(f"    overworld_ascending_frames(gObjectEventPic_{camel}FShadow, {f_width}, {f_height}),")
            lines.append("};")
            lines.append("#endif")
            lines.append("")
    lines.append("static const struct SpriteFrameImage *const sShadowOverworldPicTables[NUM_SPECIES] = {")
    for _, const_name, camel, _ in table:
        lines.append(f"    [{const_name}] = sPicTable_{camel}Shadow,")
    lines.append("};")
    lines.append("")
    lines.append("#if P_GENDER_DIFFERENCES")
    lines.append("static const struct SpriteFrameImage *const sShadowOverworldPicTables_Female[NUM_SPECIES] = {")
    for _, const_name, camel, data in table:
        if data.get("female"):
            lines.append(f"    [{const_name}] = sPicTable_{camel}FShadow,")
    lines.append("};")
    lines.append("#endif")
    lines.append("")
    lines.append("#if OW_POKEMON_OBJECT_EVENTS && OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE")
    lines.append("static const u16 *const sShadowOverworldPalettes[NUM_SPECIES] = {")
    for _, const_name, camel, data in table:
        if data.get("has_overworld_palette"):
            lines.append(f"    [{const_name}] = gOverworldPalette_{camel}Shadow,")
        else:
            lines.append(f"    [{const_name}] = gMonPalette_{camel}Shadow,")
    lines.append("};")
    lines.append("#endif")
    lines.append("#endif")

    OUTPUT.write_text("\n".join(lines) + "\n")


if __name__ == "__main__":
    main()
