#!/usr/bin/env python3
"""Render Pyrite Town through the Colosseum SoundFont for one-voice GBA playback.

The source arrangement reaches 16 simultaneous sampled voices, while this
project configures m4a for 8.  Rendering the arrangement ahead of time retains
the complete orchestration and avoids runtime voice stealing.

Set PYRITE_FLUIDSYNTH_LIB when libfluidsynth is not installed system-wide.
"""

from __future__ import annotations

import ctypes
import ctypes.util
import os
import struct
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
SOURCE_MIDI = ROOT / "sound/songs/midi/mus_pyrite.mid"
SOUNDFONT = ROOT / "Colosseum (WIP).sf2"
OUTPUT_WAV = ROOT / "sound/direct_sound_samples/colosseum_pyrite_town.wav"

SAMPLE_RATE = 13379
SYNTH_GAIN = 0.8
LOOP_REPETITIONS = 2


def read_vlq(data: bytes, pos: int) -> tuple[int, int]:
    value = 0
    while True:
        byte = data[pos]
        pos += 1
        value = (value << 7) | (byte & 0x7F)
        if byte < 0x80:
            return value, pos


def write_vlq(value: int) -> bytes:
    output = bytearray([value & 0x7F])
    value >>= 7
    while value:
        output.append(0x80 | (value & 0x7F))
        value >>= 7
    output.reverse()
    return bytes(output)


@dataclass(frozen=True)
class MidiEvent:
    tick: int
    order: int
    data: bytes
    meta_type: int | None = None
    meta_data: bytes = b""


def parse_track(track: bytes) -> list[MidiEvent]:
    events: list[MidiEvent] = []
    pos = tick = order = 0
    running_status: int | None = None
    while pos < len(track):
        delta, pos = read_vlq(track, pos)
        tick += delta
        status = track[pos]
        if status < 0x80:
            if running_status is None:
                raise ValueError("MIDI running status without a prior status")
            status = running_status
        else:
            pos += 1
            if status < 0xF0:
                running_status = status

        if status == 0xFF:
            meta_type = track[pos]
            pos += 1
            size, pos = read_vlq(track, pos)
            payload = track[pos : pos + size]
            pos += size
            raw = b"\xff" + bytes([meta_type]) + write_vlq(size) + payload
            events.append(MidiEvent(tick, order, raw, meta_type, payload))
        elif status in (0xF0, 0xF7):
            size, pos = read_vlq(track, pos)
            payload = track[pos : pos + size]
            pos += size
            events.append(
                MidiEvent(tick, order, bytes([status]) + write_vlq(size) + payload)
            )
        else:
            size = 1 if status & 0xF0 in (0xC0, 0xD0) else 2
            payload = track[pos : pos + size]
            pos += size
            events.append(MidiEvent(tick, order, bytes([status]) + payload))
        order += 1
    return events


def encode_track(events: list[MidiEvent], end_tick: int) -> bytes:
    output = bytearray()
    previous_tick = 0
    for event in sorted(events, key=lambda item: (item.tick, item.order)):
        output.extend(write_vlq(event.tick - previous_tick))
        output.extend(event.data)
        previous_tick = event.tick
    output.extend(write_vlq(end_tick - previous_tick))
    output.extend(b"\xff\x2f\x00")
    return b"MTrk" + struct.pack(">I", len(output)) + output


def load_midi() -> tuple[int, list[list[MidiEvent]]]:
    midi = SOURCE_MIDI.read_bytes()
    if midi[:4] != b"MThd":
        raise ValueError(f"{SOURCE_MIDI} is not a Standard MIDI file")
    header_size = struct.unpack_from(">I", midi, 4)[0]
    track_count = struct.unpack_from(">H", midi, 10)[0]
    division = struct.unpack_from(">H", midi, 12)[0]
    if division & 0x8000:
        raise ValueError("SMPTE MIDI timing is not supported")

    tracks: list[list[MidiEvent]] = []
    pos = 8 + header_size
    for _ in range(track_count):
        if midi[pos : pos + 4] != b"MTrk":
            raise ValueError("Invalid MIDI track chunk")
        size = struct.unpack_from(">I", midi, pos + 4)[0]
        tracks.append(parse_track(midi[pos + 8 : pos + 8 + size]))
        pos += 8 + size
    return division, tracks


def find_loop_and_tempo(
    tracks: list[list[MidiEvent]],
) -> tuple[int, int, int]:
    loop_start = loop_end = None
    tempo = 500_000
    for event in tracks[0]:
        if event.meta_type == 0x51 and event.tick == 0:
            tempo = int.from_bytes(event.meta_data, "big")
        elif event.meta_type == 0x06 and event.meta_data == b"loopStart":
            loop_start = event.tick
        elif event.meta_type == 0x06 and event.meta_data == b"loopEnd":
            loop_end = event.tick
    if loop_start is None or loop_end is None or loop_end <= loop_start:
        raise ValueError("Source MIDI does not contain valid loopStart/loopEnd markers")
    return loop_start, loop_end, tempo


def write_expanded_midi(
    path: Path,
    division: int,
    tracks: list[list[MidiEvent]],
    loop_start: int,
    loop_end: int,
) -> int:
    loop_length = loop_end - loop_start
    final_tick = loop_start + LOOP_REPETITIONS * loop_length
    output_tracks: list[bytes] = []
    for track in tracks:
        expanded: list[MidiEvent] = []
        intro = [
            event
            for event in track
            if event.tick < loop_start and event.meta_type != 0x2F
        ]
        loop = [
            event
            for event in track
            if loop_start <= event.tick < loop_end
            and event.meta_type not in (0x06, 0x2F)
        ]
        expanded.extend(intro)
        for repetition in range(LOOP_REPETITIONS):
            offset = repetition * loop_length
            expanded.extend(
                MidiEvent(
                    event.tick + offset,
                    event.order,
                    event.data,
                    event.meta_type,
                    event.meta_data,
                )
                for event in loop
            )
        output_tracks.append(encode_track(expanded, final_tick))

    header = b"MThd" + struct.pack(">IHHH", 6, 1, len(output_tracks), division)
    path.write_bytes(header + b"".join(output_tracks))
    return final_tick


def load_fluidsynth() -> ctypes.CDLL:
    library_path = os.environ.get("PYRITE_FLUIDSYNTH_LIB")
    if not library_path:
        library_path = ctypes.util.find_library("fluidsynth")
    if not library_path:
        raise RuntimeError(
            "libfluidsynth was not found; install FluidSynth or set "
            "PYRITE_FLUIDSYNTH_LIB"
        )
    library = ctypes.CDLL(library_path)
    pointer = ctypes.c_void_p

    library.new_fluid_settings.restype = pointer
    for name, arguments in (
        ("fluid_settings_setnum", [pointer, ctypes.c_char_p, ctypes.c_double]),
        ("fluid_settings_setint", [pointer, ctypes.c_char_p, ctypes.c_int]),
        ("fluid_settings_setstr", [pointer, ctypes.c_char_p, ctypes.c_char_p]),
    ):
        function = getattr(library, name)
        function.argtypes = arguments
        function.restype = ctypes.c_int
    library.new_fluid_synth.argtypes = [pointer]
    library.new_fluid_synth.restype = pointer
    library.fluid_synth_sfload.argtypes = [pointer, ctypes.c_char_p, ctypes.c_int]
    library.fluid_synth_sfload.restype = ctypes.c_int
    library.new_fluid_player.argtypes = [pointer]
    library.new_fluid_player.restype = pointer
    library.fluid_player_add.argtypes = [pointer, ctypes.c_char_p]
    library.fluid_player_add.restype = ctypes.c_int
    library.fluid_player_play.argtypes = [pointer]
    library.fluid_player_play.restype = ctypes.c_int
    library.fluid_synth_write_s16.argtypes = [
        pointer,
        ctypes.c_int,
        pointer,
        ctypes.c_int,
        ctypes.c_int,
        pointer,
        ctypes.c_int,
        ctypes.c_int,
    ]
    library.fluid_synth_write_s16.restype = ctypes.c_int
    return library


def render_midi(midi_path: Path, frame_count: int) -> list[int]:
    fluid = load_fluidsynth()
    settings = fluid.new_fluid_settings()
    if not settings:
        raise RuntimeError("FluidSynth could not create its settings object")
    fluid.fluid_settings_setnum(settings, b"synth.sample-rate", float(SAMPLE_RATE))
    fluid.fluid_settings_setnum(settings, b"synth.gain", SYNTH_GAIN)
    fluid.fluid_settings_setint(settings, b"synth.polyphony", 64)
    fluid.fluid_settings_setint(settings, b"synth.reverb.active", 1)
    fluid.fluid_settings_setint(settings, b"synth.chorus.active", 0)
    fluid.fluid_settings_setstr(settings, b"player.timing-source", b"sample")

    synth = fluid.new_fluid_synth(settings)
    if not synth:
        raise RuntimeError("FluidSynth could not create its synthesizer")
    soundfont_id = fluid.fluid_synth_sfload(synth, os.fsencode(SOUNDFONT), 1)
    if soundfont_id < 0:
        raise RuntimeError(f"FluidSynth could not load {SOUNDFONT}")
    player = fluid.new_fluid_player(synth)
    if not player:
        raise RuntimeError("FluidSynth could not create its MIDI player")
    if fluid.fluid_player_add(player, os.fsencode(midi_path)) != 0:
        raise RuntimeError(f"FluidSynth could not load {midi_path}")
    if fluid.fluid_player_play(player) != 0:
        raise RuntimeError("FluidSynth could not start MIDI playback")

    mono: list[int] = []
    remaining = frame_count
    while remaining:
        frames = min(4096, remaining)
        stereo = (ctypes.c_short * (frames * 2))()
        result = fluid.fluid_synth_write_s16(
            synth, frames, stereo, 0, 2, stereo, 1, 2
        )
        if result != 0:
            raise RuntimeError("FluidSynth failed while rendering audio")
        mono.extend(
            max(-32768, min(32767, (stereo[index] + stereo[index + 1]) // 2))
            for index in range(0, frames * 2, 2)
        )
        remaining -= frames
    return mono


def riff_chunk(chunk_id: bytes, payload: bytes) -> bytes:
    return (
        chunk_id
        + struct.pack("<I", len(payload))
        + payload
        + (b"\0" if len(payload) & 1 else b"")
    )


def write_looped_wave(samples: list[int], loop_start: int, loop_end: int) -> None:
    fmt = struct.pack(
        "<HHIIHH", 1, 1, SAMPLE_RATE, SAMPLE_RATE * 2, 2, 16
    )
    smpl_header = struct.pack(
        "<9I",
        0,
        0,
        round(1_000_000_000 / SAMPLE_RATE),
        60,
        0,
        0,
        0,
        1,
        0,
    )
    smpl_loop = struct.pack("<6I", 0, 0, loop_start, loop_end - 1, 0, 0)
    pcm = struct.pack(f"<{len(samples)}h", *samples)
    body = b"WAVE" + b"".join(
        (
            riff_chunk(b"fmt ", fmt),
            riff_chunk(b"smpl", smpl_header + smpl_loop),
            riff_chunk(b"agbp", struct.pack("<I", SAMPLE_RATE * 1024)),
            riff_chunk(b"data", pcm),
        )
    )
    OUTPUT_WAV.write_bytes(b"RIFF" + struct.pack("<I", len(body)) + body)


def smooth_loop_boundary(samples: list[int], loop_start: int, loop_end: int) -> None:
    """Match value and slope over the final 38 ms to prevent a loop click."""
    length = min(512, loop_end - loop_start)
    first = loop_start
    last = loop_end - 1
    value_delta = samples[first] - samples[last]
    desired_slope = samples[first + 1] - samples[first]
    current_slope = samples[last] - samples[last - 1]
    slope_delta = desired_slope - current_slope
    span = length - 1
    for index in range(length):
        t = index / span
        value_basis = -2 * t**3 + 3 * t**2
        slope_basis = t**3 - t**2
        correction = value_basis * value_delta + slope_basis * slope_delta * span
        position = loop_end - length + index
        samples[position] = max(
            -32768, min(32767, round(samples[position] + correction))
        )


def main() -> None:
    division, tracks = load_midi()
    loop_start_tick, loop_end_tick, tempo = find_loop_and_tempo(tracks)
    expanded_path = Path("/tmp/pyrite-town-expanded.mid")
    final_tick = write_expanded_midi(
        expanded_path, division, tracks, loop_start_tick, loop_end_tick
    )

    seconds_per_tick = tempo / 1_000_000 / division
    output_loop_start = round(loop_end_tick * seconds_per_tick * SAMPLE_RATE)
    output_loop_end = round(final_tick * seconds_per_tick * SAMPLE_RATE)
    final_frames = output_loop_end
    samples = render_midi(expanded_path, final_frames)

    # The second iteration is used as the runtime loop.  By then FluidSynth's
    # reverb and sample tails have reached the same state they have at loop end.
    smooth_loop_boundary(samples, output_loop_start, output_loop_end)
    peak = max(map(abs, samples))
    write_looped_wave(samples, output_loop_start, output_loop_end)
    print(
        f"rendered {OUTPUT_WAV.relative_to(ROOT)}: "
        f"{len(samples) / SAMPLE_RATE:.3f}s, peak={peak}, "
        f"loop={output_loop_start / SAMPLE_RATE:.3f}s.."
        f"{output_loop_end / SAMPLE_RATE:.3f}s"
    )


if __name__ == "__main__":
    main()
