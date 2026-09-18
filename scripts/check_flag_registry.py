#!/usr/bin/env python3
"""Validate the append-only custom flag registry."""

from __future__ import annotations

import re
import sys
from pathlib import Path


DEFINE_RE = re.compile(r"^#define\s+(\w+)\s+(.+?)\s*(?://.*)?$")
CUSTOM_RE = re.compile(
    r"^#define\s+(FLAG_\w+)\s+\(CUSTOM_FLAGS_START\s*\+\s*0x([0-9A-Fa-f]+)\)"
)
QUEST_RE = re.compile(r"^FLAG_QUEST_.+_(?:STARTED|COMPLETED)$")
LEDGER_RE = re.compile(r"^0x([0-9A-Fa-f]+)\s+(FLAG_\w+)$")


def read_int_define(defines: dict[str, str], name: str) -> int:
    try:
        return int(defines[name], 0)
    except (KeyError, ValueError) as exc:
        raise ValueError(f"{name} must be a plain integer define") from exc


def main() -> int:
    path = Path(sys.argv[1] if len(sys.argv) > 1 else "include/constants/flags.h")
    ledger_path = Path(
        sys.argv[2] if len(sys.argv) > 2 else "scripts/custom_flag_registry.txt"
    )
    lines = path.read_text(encoding="utf-8").splitlines()
    ledger_lines = ledger_path.read_text(encoding="utf-8").splitlines()
    defines: dict[str, str] = {}
    custom_entries: list[tuple[str, int]] = []
    ledger_entries: list[tuple[str, int]] = []

    for line in lines:
        match = DEFINE_RE.match(line)
        if match:
            defines[match.group(1)] = match.group(2).strip()

        match = CUSTOM_RE.match(line)
        if match:
            custom_entries.append((match.group(1), int(match.group(2), 16)))

    for line in ledger_lines:
        if not line or line.startswith("#"):
            continue
        match = LEDGER_RE.match(line)
        if not match:
            print(f"flag audit: malformed ledger row: {line}", file=sys.stderr)
            return 1
        ledger_entries.append((match.group(2), int(match.group(1), 16)))

    try:
        start = read_int_define(defines, "CUSTOM_FLAGS_START")
        count = read_int_define(defines, "CUSTOM_FLAGS_COUNT")
        allocated = read_int_define(defines, "CUSTOM_FLAGS_ALLOCATED")
        special_start = read_int_define(defines, "SPECIAL_FLAGS_START")
    except ValueError as exc:
        print(f"flag audit: {exc}", file=sys.stderr)
        return 1

    errors: list[str] = []
    by_offset: dict[int, list[str]] = {}
    custom_names = {name for name, _ in custom_entries}

    for name, offset in custom_entries:
        by_offset.setdefault(offset, []).append(name)
        if offset >= count:
            errors.append(f"{name} uses offset 0x{offset:X}, outside the custom bank")

    for offset, names in sorted(by_offset.items()):
        if len(names) > 1:
            errors.append(f"custom offset 0x{offset:03X} is reused by {', '.join(names)}")

    if allocated != len(ledger_entries):
        errors.append(
            f"CUSTOM_FLAGS_ALLOCATED={allocated}, but the append-only ledger has "
            f"{len(ledger_entries)} entries"
        )

    for expected_offset, (ledger_name, ledger_offset) in enumerate(ledger_entries):
        if ledger_offset != expected_offset:
            errors.append(
                f"ledger row for {ledger_name} uses 0x{ledger_offset:03X}; "
                f"expected append-only offset 0x{expected_offset:03X}"
            )
            continue

        header_names = by_offset.get(ledger_offset, [])
        if header_names != [ledger_name]:
            found = ", ".join(header_names) if header_names else "nothing"
            errors.append(
                f"ledger reserves 0x{ledger_offset:03X} for {ledger_name}, "
                f"but flags.h assigns {found}"
            )

    expected_offsets = set(range(allocated))
    actual_offsets = set(by_offset)
    for offset in sorted(expected_offsets - actual_offsets):
        errors.append(
            f"allocated custom offset 0x{offset:03X} is missing; keep removed IDs as FLAG_CUSTOM_RETIRED_*"
        )
    for offset in sorted(actual_offsets - expected_offsets):
        errors.append(
            f"custom offset 0x{offset:03X} is not covered by CUSTOM_FLAGS_ALLOCATED={allocated}"
        )

    quest_names = {name for name in defines if QUEST_RE.match(name)}
    for name in sorted(quest_names - custom_names):
        errors.append(f"{name} must use a protected CUSTOM_FLAGS_START offset")

    if count % 8:
        errors.append("CUSTOM_FLAGS_COUNT must be byte-aligned")
    if allocated > count:
        errors.append("CUSTOM_FLAGS_ALLOCATED exceeds CUSTOM_FLAGS_COUNT")
    if start + count > special_start:
        errors.append("custom flag bank overlaps special flags")

    if errors:
        for error in errors:
            print(f"flag audit: {error}", file=sys.stderr)
        return 1

    print(
        f"flag audit: {allocated}/{count} protected IDs allocated; "
        f"next ID is 0x{start + allocated:04X}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
