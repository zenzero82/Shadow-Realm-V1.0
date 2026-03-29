import os
import re
import sys
from pathlib import Path

BASE_DIR = Path('.')
SPECIES_HEADER = BASE_DIR / 'include' / 'constants' / 'species.h'
POKEMON_GRAPHICS = BASE_DIR / 'src' / 'data' / 'graphics' / 'pokemon.h'
SHADOW_LIST = """Absol
Aggron
Alakazam
Annihilape
Araquanid
Arcanine
Arceus
Armarouge
Articuno
Aurorus
Azelf
Baxcalibur
Beartic
Beedrill
Blacephalon
Blastoise
Blaziken
Blissey
Bisharp
Buzzwole
Calyrex 
Camerupt
Celesteela
Centiskorch
Ceruledge
Chandelure
Charizard
Chesnaught
Chien-Pao
Chi-Yu
Clawitzer
Clodsire
Cobalion
Copperajah
Corviknight
Cresselia
Crobat
Darkrai
Decidueye
Deoxys
Delphox
Dialga
Diancie
Donphan
Dragalge
Dragonite
Dragapult
Drampa
Dusknoir
Eelektross
Electivire
Emboar
Empoleon
Enamorus
Entei
Eternatus
Falinks
Feraligatr
Flygon
Flutter Mane
Galvantula
Garchomp
Genesect
Gholdengo
Giratina 
Golisopod
Goodra
Great Tusks
Greninja
Grimmsnarl
Groudon
Guzzlord
Gyarados
Hatterene
Heatran
Ho-Oh
Honchkrow
Hoopa
Houndoom
Hydreigon
Incineroar
Infernape
Inteleon
Iron Bundle
Iron Crown
Iron Hands
Iron Treads
Jirachi
Kartana
Keldeo
Kingdra
Kommo-o
Koraidon
Krookodile
Kyogre
Kyurem
Landorus
Latias
Latios
Lucario
Lunala
Magearna
Magnezone
Malamar
Manaphy
Manectric
Marshadow
Meganium
Melmetal
Meloetta
Mesprit
Meowth
Meowscarada
Mespirit
Mew
Mewtwo
Milotic
Mimikyu
Mimikyu Busted
Miraidon
Moltres
Naganadel
Necrozma
Nidoking
Nihilego
Obstagoon
Palossand
Palkia
Pangoro
Pecharunt
Pheromosa
Pikachu
Primarina
Quaquaval
Raikou
Rayquaza
Regice
Regidrago
Regieleki
Regigigas
Regirock
Registeel
Reuniclus
Reshiram
Rhyperior
Rillaboom
Salamence
Salazzle
Samurott
Sceptile
Scream Tail
Serperior
Shadow Lugia
Sharpedo
Silvally
Skarmory
Skeledirge
Snorlax
Solgaleo
Stakataka
Steelix
Suicune
Swampert
Tapu Bulu
Tapu Fini
Tapu Koko
Tapu Lele
Talonflame
terapagos
Terrakion
Thundurus
Ting-Lu
Tornadus
Torterra
Toxapex
Typhlosion
Tyranitar
Tyrantrum
Uxie
Venusaur
Victini
Vikavolt
Virizion
Volcanion
Volcarona
Walrein
Weavile
Wo-Chien
Xerneas
Xurkitree
Yveltal
Zacian
Zamazenta
Zapdos
Zarude
Zekrom
Zeraora
Zygarde """

graphics_dir = BASE_DIR / "graphics" / "pokemon"


SPECIAL_SHADOW_NAMES = {"great_tusks": "great_tusk", "mespirit": "mesprit"}
SPECIAL_SHADOW_DIRECTORIES = {
    "mimikyu_busted": [graphics_dir / "mimikyu" / "busted" / "shadow"],
}
SPECIAL_SHADOW_NO_OVERWORLD = {"mimikyu_busted"}

def load_overworld_tile_counts():
    path = BASE_DIR / "spritesheet_rules.mk"
    if not path.exists():
        return {}
    pattern = re.compile(
        r"\$\((?:POKEMONGFXDIR)\)/([A-Za-z0-9_]+)(?:/[^/]+)*/overworld\.4bpp"
    )
    lines = path.read_text().splitlines()
    counts = {}
    for i, line in enumerate(lines):
        if "overworld.4bpp" not in line:
            continue
        match = pattern.search(line)
        if not match:
            continue
        slug = match.group(1)
        cmd_line = lines[i + 1] if i + 1 < len(lines) else ""
        width_match = re.search(r"-mwidth\s+(\d+)", cmd_line)
        height_match = re.search(r"-mheight\s+(\d+)", cmd_line)
        if width_match and height_match:
            counts[slug] = (int(width_match.group(1)), int(height_match.group(1)))
    return counts

OVERWORLD_TILE_COUNTS = load_overworld_tile_counts()

species_map = {}
with SPECIES_HEADER.open() as f:
    for line in f:
        line = line.strip()
        if not line.startswith("#define SPECIES_"):
            continue
        parts = line.split()
        if len(parts) < 2:
            continue
        constant = parts[1]
        if not constant.startswith("SPECIES_"):
            continue
        name = constant[len("SPECIES_") :]
        slug = name.lower()
        species_map[slug] = name

content = POKEMON_GRAPHICS.read_text()

def normalize(input_name):
    slug = input_name.lower().strip()
    slug = slug.replace("-", "_").replace(" ", "_")
    slug = slug.replace("'", "")
    slug = slug.replace(".", "_")
    while slug.startswith("shadow_"):
        slug = slug[len("shadow_") :]
    slug = slug.replace("__", "_")
    slug = slug.strip("_")
    return slug

def find_graphics_file(shadow_dir, names, exts=(".4bpp.lz", ".4bpp")):
    for name in names:
        for ext in exts:
            candidate = shadow_dir / f"{name}{ext}"
            if candidate.exists():
                return candidate
    return None

def find_graphics_png(shadow_dir, names):
    for name in names:
        candidate = shadow_dir / f"{name}.png"
        if candidate.exists():
            return candidate
    return None

def png_tile_counts(png_path):
    try:
        with png_path.open("rb") as f:
            f.seek(16)
            width = int.from_bytes(f.read(4), "big")
            height = int.from_bytes(f.read(4), "big")
            frame_width = width // 6 if width % 6 == 0 else width
            return max(1, frame_width // 8), max(1, height // 8)
    except Exception:
        return 4, 4

seen = set()
species_data = []
for raw_name in SHADOW_LIST.strip().splitlines():
    name = raw_name.strip()
    if not name:
        continue
    slug = normalize(name)
    if slug in SPECIAL_SHADOW_NAMES:
        slug = SPECIAL_SHADOW_NAMES[slug]
    base_slug = slug
    while slug not in species_map and slug.endswith("s"):
        slug = slug[:-1]
    if slug not in species_map:
        raise SystemExit(
            f"Unknown species slug '{base_slug}' derived from '{name}'"
        )
    if slug in seen:
        continue
    seen.add(slug)
    species_data.append((name, slug, species_map[slug]))

if "pikachu" not in seen:
    species_data.insert(0, ("Pikachu", "pikachu", species_map["pikachu"]))
else:
    for idx, (_, slug, _) in enumerate(species_data):
        if slug == "pikachu":
            species_data.insert(0, species_data.pop(idx))
            break

def camel_case(species_name):
    return "".join(part.capitalize() for part in species_name.lower().split("_"))

species_entries = []
for raw_name, slug, species_constant in species_data:
    camel = camel_case(species_constant)
    candidates = []
    candidates.extend(SPECIAL_SHADOW_DIRECTORIES.get(slug, []))
    candidates.extend(
        [
            graphics_dir / slug / "shadow",
            graphics_dir / "pokemon" / slug / "shadow",
        ]
    )
    for search_root in (graphics_dir / slug, graphics_dir / "pokemon" / slug):
        if not search_root.exists():
            continue
        for entry in search_root.iterdir():
            if not entry.is_dir() or entry.name == "shadow":
                continue
            shadow_subdir = entry / "shadow"
            if shadow_subdir.exists():
                candidates.append(shadow_subdir)
    path = None
    for candidate in candidates:
        if not candidate.exists():
            continue
        if find_graphics_file(candidate, ("anim_front", "front")):
            path = candidate
            break
    if path is None:
        candidate = graphics_dir / slug / "shadow"
        alt = graphics_dir / "pokemon" / slug / "shadow"
        print(
            f"Warning: shadow assets not found for {slug} in {candidate} or {alt}",
            file=sys.stderr,
        )
        continue
    front_file = find_graphics_file(path, ("anim_front", "front"))
    back_file = find_graphics_file(path, ("back",))
    icon_file = find_graphics_file(path, ("icon",), exts=(".4bpp", ".4bpp.lz"))
    overworld_file = find_graphics_file(path, ("overworld",), exts=(".4bpp", ".4bpp.lz"))
    if slug == "mimikyu_busted":
        extra_shadow = graphics_dir / "mimikyu" / "busted" / "shadow"
        overworld_file = find_graphics_file(extra_shadow, ("overworld",), exts=(".4bpp", ".4bpp.lz"))
    palette_file = None
    palette_candidates = [
        "normal.gbapal",
        "shadow.gbapal",
        f"{slug}_shadow.pal",
    ]
    for candidate in palette_candidates:
        if (path / candidate).exists():
            palette_file = candidate
            break
    palette_path = path / palette_file if palette_file else None
    has_palette = palette_file is not None
    overworld_palette_file = None
    overworld_palette_candidates = [
        "overworld_normal.gbapal",
        "overworld.gbapal",
    ]
    for candidate in overworld_palette_candidates:
        if (path / candidate).exists():
            overworld_palette_file = candidate
            break
    overworld_palette_path = (
        path / overworld_palette_file if overworld_palette_file else None
    )
    has_overworld_palette = overworld_palette_file is not None
    if front_file is None:
        front_file = find_graphics_file(path, ("anim_front", "front"))
    if back_file is None:
        back_file = find_graphics_file(path, ("back",))
    if icon_file is None:
        icon_file = find_graphics_file(path, ("icon",), exts=(".4bpp", ".4bpp.lz"))
    if overworld_file is None:
        overworld_file = find_graphics_file(path, ("overworld",), exts=(".4bpp", ".4bpp.lz"))
    overworld_png = find_graphics_png(path, ("overworld",))
    overworld_tile_counts = OVERWORLD_TILE_COUNTS.get(slug)
    if overworld_tile_counts is None and overworld_png:
        overworld_tile_counts = png_tile_counts(overworld_png)
    if overworld_tile_counts is None:
        overworld_tile_counts = (4, 4)
    requires_overworld = slug not in SPECIAL_SHADOW_NO_OVERWORLD
    if (
        not front_file
        or not back_file
        or not icon_file
        or (requires_overworld and not overworld_file)
    ):
        print(
            f"Warning: required shadow files missing for {slug} in {path}",
            file=sys.stderr,
        )
        continue
    female_front_file = find_graphics_file(path, ("anim_frontf", "frontf"))
    female_back_file = find_graphics_file(path, ("backf",))
    female_icon_file = find_graphics_file(path, ("iconf",), exts=(".4bpp", ".4bpp.lz"))
    female_overworld_file = find_graphics_file(path, ("overworldf",), exts=(".4bpp", ".4bpp.lz"))
    def_exists = f"gMonFrontPic_{camel}Shadow" in content
    species_entries.append(
        {
            "name": raw_name,
            "slug": slug,
            "constant": species_constant,
            "camel": camel,
            "front_file": front_file,
            "back_file": back_file,
            "icon_file": icon_file,
            "overworld_file": overworld_file,
            "overworld_tile_counts": overworld_tile_counts,
            "overworld_palette_file": overworld_palette_file,
            "overworld_palette_path": overworld_palette_path,
            "has_overworld_palette": has_overworld_palette,
            "palette_file": palette_file,
            "has_palette": has_palette,
            "palette_path": palette_path,
            "has_female_forms": bool(female_front_file and female_back_file),
            "female_front_file": female_front_file,
            "female_back_file": female_back_file,
            "has_female_icon": bool(female_icon_file),
            "female_icon_file": female_icon_file,
            "has_female_overworld": bool(female_overworld_file),
            "female_overworld_file": female_overworld_file,
            "definition_exists": def_exists,
        }
    )

def generate_shadow_forms_inc(entries):
    lines = []
    for entry in entries:
        if entry["definition_exists"]:
            continue
        front_path = entry["front_file"].as_posix()
        back_path = entry["back_file"].as_posix()
        camel = entry["camel"]
        lines.append(
            f"const u32 gMonFrontPic_{camel}Shadow[] = INCBIN_U32(\"{front_path}\");"
        )
        lines.append(
            f"const u32 gMonBackPic_{camel}Shadow[] = INCBIN_U32(\"{back_path}\");"
        )
        if entry["has_palette"]:
            pal_path = entry["palette_path"]
            lines.append(
                f"const u16 gMonPalette_{camel}Shadow[] = INCBIN_U16(\"{pal_path.as_posix()}\");"
            )
        lines.append(
            f"const u8 gMonIcon_{camel}Shadow[] = INCBIN_U8(\"{entry['icon_file'].as_posix()}\");"
        )
        if entry["has_female_icon"]:
            lines.append("#if P_GENDER_DIFFERENCES && P_CUSTOM_GENDER_DIFF_ICONS")
            lines.append(
                f"const u8 gMonIcon_{camel}FShadow[] = INCBIN_U8(\"{entry['female_icon_file'].as_posix()}\");"
            )
            lines.append("#endif")
        if entry["has_female_forms"]:
            lines.append("#if P_GENDER_DIFFERENCES")
            lines.append(
                f"const u32 gMonFrontPic_{camel}FShadow[] = INCBIN_U32(\"{entry['female_front_file'].as_posix()}\");"
            )
            lines.append(
                f"const u32 gMonBackPic_{camel}FShadow[] = INCBIN_U32(\"{entry['female_back_file'].as_posix()}\");"
            )
            lines.append("#endif")
        if entry["overworld_file"]:
            lines.append("#if OW_POKEMON_OBJECT_EVENTS")
            lines.append(
                f"const u32 gObjectEventPic_{camel}Shadow[] = INCBIN_COMP(\"{entry['overworld_file'].as_posix()}\");"
            )
            if entry["has_female_overworld"]:
                lines.append("#if P_GENDER_DIFFERENCES")
                lines.append(
                    f"const u32 gObjectEventPic_{camel}FShadow[] = INCBIN_COMP(\"{entry['female_overworld_file'].as_posix()}\");"
                )
                lines.append("#endif")
            lines.append("#endif")
        if entry["has_overworld_palette"]:
            lines.append("#if OW_POKEMON_OBJECT_EVENTS && OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE")
            lines.append(
                f"const u16 gOverworldPalette_{camel}Shadow[] = INCBIN_U16(\"{entry['overworld_palette_path'].as_posix()}\");"
            )
            lines.append("#endif")
        lines.append("")
    return "\n".join(lines)

shadow_forms_inc = generate_shadow_forms_inc(species_entries)

header_lines = [
    "#ifndef GUARD_DATA_GRAPHICS_SHADOW_FORMS_H",
    "#define GUARD_DATA_GRAPHICS_SHADOW_FORMS_H",
    "",
    "#include \"global.h\"",
    "",
]
for entry in species_entries:
    camel = entry["camel"]
    header_lines.append(f"extern const u32 gMonFrontPic_{camel}Shadow[];")
    header_lines.append(f"extern const u32 gMonBackPic_{camel}Shadow[];")
    if entry["has_female_forms"]:
        header_lines.append("#if P_GENDER_DIFFERENCES")
        header_lines.append(f"extern const u32 gMonFrontPic_{camel}FShadow[];")
        header_lines.append(f"extern const u32 gMonBackPic_{camel}FShadow[];")
        header_lines.append("#endif")
    if entry["has_palette"]:
        header_lines.append(f"extern const u16 gMonPalette_{camel}Shadow[];")
    if entry["has_overworld_palette"]:
        header_lines.append("#if OW_POKEMON_OBJECT_EVENTS && OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE")
        header_lines.append(f"extern const u16 gOverworldPalette_{camel}Shadow[];")
        header_lines.append("#endif")
    header_lines.append(f"extern const u8 gMonIcon_{camel}Shadow[];")
    if entry["has_female_icon"]:
        header_lines.append("#if P_GENDER_DIFFERENCES && P_CUSTOM_GENDER_DIFF_ICONS")
        header_lines.append(f"extern const u8 gMonIcon_{camel}FShadow[];")
        header_lines.append("#endif")
    header_lines.append("#if OW_POKEMON_OBJECT_EVENTS")
    header_lines.append(f"extern const u32 gObjectEventPic_{camel}Shadow[];")
    if entry["has_female_overworld"]:
        header_lines.append("#if P_GENDER_DIFFERENCES")
        header_lines.append(f"extern const u32 gObjectEventPic_{camel}FShadow[];")
        header_lines.append("#endif")
    header_lines.append("#endif")
    header_lines.append("")
header_lines.append("#endif // GUARD_DATA_GRAPHICS_SHADOW_FORMS_H")
shadow_forms_header = "\n".join(header_lines)

table_lines = []
for entry in species_entries:
    camel = entry["camel"]
    constant = entry["constant"]
    has_palette = entry["has_palette"]
    table_lines.append("    {")
    table_lines.append(f"        .species = SPECIES_{constant},")
    table_lines.append(f"        .frontPic = gMonFrontPic_{camel}Shadow,")
    table_lines.append(f"        .backPic = gMonBackPic_{camel}Shadow,")
    if entry["has_female_forms"]:
        table_lines.append("#if P_GENDER_DIFFERENCES")
        table_lines.append(
            f"        .frontPicFemale = gMonFrontPic_{camel}FShadow,"
        )
        table_lines.append(f"        .backPicFemale = gMonBackPic_{camel}FShadow,")
        table_lines.append("#endif")
    if has_palette:
        table_lines.append(f"        .palette = gMonPalette_{camel}Shadow,")
    else:
        table_lines.append("        .palette = NULL,")
    table_lines.append(f"        .icon = gMonIcon_{camel}Shadow,")
    if entry["has_female_icon"]:
        table_lines.append("#if P_GENDER_DIFFERENCES && P_CUSTOM_GENDER_DIFF_ICONS")
        table_lines.append(
            f"        .iconFemale = gMonIcon_{camel}FShadow,"
        )
        table_lines.append("#endif")
    table_lines.append("    },")
shadow_forms_table = "\n".join(table_lines)

overworld_lines = ["#if OW_POKEMON_OBJECT_EVENTS"]
for entry in species_entries:
    camel = entry["camel"]
    if not entry["overworld_file"]:
        continue
    overworld_lines.append("")
    overworld_lines.append(
        f"static const struct SpriteFrameImage sPicTable_{camel}Shadow[] = {{"
    )
    tile_x, tile_y = entry.get("overworld_tile_counts", (4, 4))
    overworld_lines.append(
        f"    overworld_ascending_frames(gObjectEventPic_{camel}Shadow, {tile_x}, {tile_y}),"
    )
    overworld_lines.append("};")
    if entry["has_female_overworld"]:
        overworld_lines.append("#if P_GENDER_DIFFERENCES")
        overworld_lines.append(
            f"static const struct SpriteFrameImage sPicTable_{camel}FShadow[] = {{"
        )
        overworld_lines.append(
            f"    overworld_ascending_frames(gObjectEventPic_{camel}FShadow, {tile_x}, {tile_y}),"
        )
        overworld_lines.append("};")
        overworld_lines.append("#endif")

pic_table_lines = ["static const struct SpriteFrameImage *const sShadowOverworldPicTables[NUM_SPECIES] = {"]
female_table_lines = ["#if P_GENDER_DIFFERENCES", "static const struct SpriteFrameImage *const sShadowOverworldPicTables_Female[NUM_SPECIES] = {"]
palette_array_lines = ["#if OW_POKEMON_OBJECT_EVENTS && OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE", "static const u16 *const sShadowOverworldPalettes[NUM_SPECIES] = {"]

for entry in species_entries:
    camel = entry["camel"]
    constant = entry["constant"]
    if not entry["overworld_file"]:
        continue
    pic_table_lines.append(f"    [SPECIES_{constant}] = sPicTable_{camel}Shadow,")
    if entry["has_female_overworld"]:
        female_table_lines.append(f"    [SPECIES_{constant}] = sPicTable_{camel}FShadow,")
    if entry["has_overworld_palette"]:
        palette_array_lines.append(
            f"    [SPECIES_{constant}] = gOverworldPalette_{camel}Shadow,"
        )
    elif entry["has_palette"]:
        palette_array_lines.append(
            f"    [SPECIES_{constant}] = gMonPalette_{camel}Shadow,"
        )

pic_table_lines.append("};")
female_table_lines.append("};")
female_table_lines.append("#endif")
palette_array_lines.append("};")
palette_array_lines.append("#endif")

overworld_lines.extend(
    ["", *pic_table_lines, "", *female_table_lines, "", *palette_array_lines, "#endif"]
)
shadow_forms_overworld = "\n".join(overworld_lines)

OUTPUT_FILES = {
    BASE_DIR / "include" / "data" / "graphics" / "shadow_forms.h": shadow_forms_header,
    BASE_DIR / "src" / "data" / "graphics" / "shadow_forms.inc": shadow_forms_inc,
    BASE_DIR / "src" / "data" / "graphics" / "shadow_forms_table.inc": shadow_forms_table,
    BASE_DIR / "src" / "data" / "graphics" / "shadow_forms_overworld.inc": shadow_forms_overworld,
}
for path, data in OUTPUT_FILES.items():
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(data + "\n")

print("Generated shadow asset helpers for", len(species_entries), "species.")
