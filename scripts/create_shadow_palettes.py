import os
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent
GRAPHICS_DIR = BASE_DIR / "graphics" / "pokemon"

DEFAULT_COLORS = [
    0x0000,
    0x0841,
    0x10C3,
    0x18C3,
    0x2104,
    0x2945,
    0x3186,
    0x39C7,
    0x4208,
    0x4A49,
    0x52CA,
    0x5B0B,
    0x631C,
    0x6B5D,
    0x7B9F,
    0x7FFF,
]


def slug_from_path(shadow_dir: Path) -> str:
    rel_parts = shadow_dir.relative_to(GRAPHICS_DIR).parts[:-1]
    if not rel_parts:
        return ""
    if rel_parts[0] == "pokemon":
        rel_parts = rel_parts[1:]
    return "_".join(rel_parts)


def palette_bytes() -> bytes:
    data = bytearray()
    for color in DEFAULT_COLORS:
        data += color.to_bytes(2, "little")
    return bytes(data)


def main() -> int:
    generated = []
    for shadow_dir in GRAPHICS_DIR.rglob("shadow"):
        if not shadow_dir.is_dir():
            continue
        slug = slug_from_path(shadow_dir)
        if not slug:
            continue
        shadow_pal = shadow_dir / f"{slug}_shadow.pal"
        if shadow_pal.exists():
            continue
        shadow_pal.write_bytes(palette_bytes())
        generated.append(shadow_pal)

    if generated:
        print("Created default shadow palettes for:")
        for pal in generated:
            print("  ", pal.relative_to(BASE_DIR))
    else:
        print("No new shadow palettes needed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
