	.align 2
voicegroup284:: @ Pokemon Black/White - Team Plasma
	voice_keysplit voicegroup294, KeySplitTable66 @ 0: Acoustic grand piano
	.rept 10 @ 1-10
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_keysplit voicegroup288, KeySplitTable61 @ 11: Vibraphone
	voice_keysplit voicegroup289, KeySplitTable62 @ 12: Marimba
	.rept 3 @ 13-15
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_keysplit voicegroup244, KeySplitTable40 @ 16: Drawbar organ
	.rept 8 @ 17-24
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_keysplit voicegroup291, KeySplitTable64 @ 25: Steel-string guitar
	.rept 3 @ 26-28
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 255, 165, 51, 242 @ 29: Overdriven guitar
	voice_keysplit voicegroup249, KeySplitTable32 @ 30: Distortion guitar
	voice_keysplit voicegroup291, KeySplitTable64 @ 31: Guitar harmonics
	voice_keysplit voicegroup290, KeySplitTable63 @ 32: Acoustic bass
	.rept 2 @ 33-34
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_keysplit voicegroup292, KeySplitTable65 @ 35: Fretless bass
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 216 @ 36: Slap bass 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ 37
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass1_c2_16, 255, 42, 255, 196 @ 38: Synth bass 1
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass2_c1_16, 255, 0, 255, 222 @ 39: Synth bass 2
	.rept 7 @ 40-46
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 44, 0, DirectSoundWaveData_bw_timpani_44_16, 255, 248, 0, 205 @ 47
	voice_keysplit voicegroup285, KeySplitTable59 @ 48: Strings
	voice_keysplit voicegroup286, KeySplitTable59 @ 49: Slow strings
	voice_keysplit voicegroup286, KeySplitTable59 @ 50: Synth strings
	.rept 5 @ 51-55
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_keysplit voicegroup287, KeySplitTable60 @ 56: Trumpet
	voice_directsound 72, 0, DirectSoundWaveData_bw_trombone_72_16, 255, 243, 159, 208 @ 57
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ 58
	voice_keysplit voicegroup287, KeySplitTable60 @ 59: Muted-trumpet part
	voice_keysplit voicegroup287, KeySplitTable60 @ 60: French-horn part
	voice_keysplit voicegroup287, KeySplitTable60 @ 61: Brass-section part
	.rept 10 @ 62-71
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 84, 0, DirectSoundWaveData_bw_piccolo_84_16, 255, 247, 78, 196 @ 72
	voice_directsound 84, 0, DirectSoundWaveData_bw_piccolo_84_16, 255, 247, 78, 196 @ 73
	.rept 10 @ 74-83
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 72, 0, DirectSoundWaveData_dp_sawtoothlead60, 255, 197, 255, 171 @ 84: Charang
	.rept 3 @ 85-87
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_keysplit voicegroup286, KeySplitTable59 @ 88: Pad 1 (new age)
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ 89
	voice_directsound 72, 0, DirectSoundWaveData_dp_sawtoothlead60, 80, 200, 220, 180 @ 90: Polysynth
	.rept 12 @ 91-102
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 72, 0, DirectSoundWaveData_dp_sawtoothlead60, 255, 197, 255, 32 @ 103: Laser FX
	.rept 15 @ 104-118
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 43, 0, DirectSoundWaveData_bw_reverse_cymbal_43_16, 2, 0, 255, 16 @ 119
	voice_directsound 60, 0, DirectSoundWaveData_dp_fretnoise60, 255, 0, 255, 16 @ 120: Guitar fret noise
	.rept 5 @ 121-125
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_keysplit_all voicegroup192 @ 126: Analog drum kit
	voice_directsound 43, 0, DirectSoundWaveData_bw_reverse_cymbal_43_16, 2, 0, 255, 16 @ 127

	.align 2
voicegroup285:: @ Strings
	voice_directsound 69, 0, DirectSoundWaveData_bw_strings_69_16, 255, 243, 227, 208
	voice_directsound 77, 0, DirectSoundWaveData_bw_strings_77_16, 255, 243, 227, 208
	voice_directsound 84, 0, DirectSoundWaveData_bw_strings_84_16, 255, 243, 227, 208

	.align 2
voicegroup286:: @ Slow strings
	voice_directsound 69, 0, DirectSoundWaveData_bw_strings_69_16, 80, 243, 227, 208
	voice_directsound 77, 0, DirectSoundWaveData_bw_strings_77_16, 80, 243, 227, 208
	voice_directsound 84, 0, DirectSoundWaveData_bw_strings_84_16, 80, 243, 227, 208

	.align 2
voicegroup287:: @ Trumpet
	voice_directsound 69, 0, DirectSoundWaveData_bw_trumpet_69_16, 255, 243, 101, 208
	voice_directsound 79, 0, DirectSoundWaveData_bw_trumpet_79_16, 255, 243, 101, 208

	.align 2
voicegroup288:: @ Vibraphone
	voice_directsound 60, 0, DirectSoundWaveData_bw_vibraphone_60_16, 255, 247, 0, 196
	voice_directsound 72, 0, DirectSoundWaveData_bw_vibraphone_72_16, 255, 247, 0, 196
	voice_directsound 84, 0, DirectSoundWaveData_bw_vibraphone_84_16, 255, 247, 0, 196

	.align 2
voicegroup289:: @ Marimba
	voice_directsound 60, 0, DirectSoundWaveData_bw_marimba_60_16, 255, 247, 0, 216
	voice_directsound 72, 0, DirectSoundWaveData_bw_marimba_72_16, 255, 247, 0, 216

	.align 2
voicegroup290:: @ Acoustic bass
	voice_directsound 36, 0, DirectSoundWaveData_bw_acoustic_bass_36_16, 255, 251, 0, 196
	voice_directsound 48, 0, DirectSoundWaveData_bw_acoustic_bass_48_16, 255, 251, 0, 196

	.align 2
voicegroup291:: @ Steel-string guitar
	voice_directsound 40, 0, DirectSoundWaveData_bw_steel_guitar_40_16, 255, 247, 255, 176
	voice_directsound 45, 0, DirectSoundWaveData_bw_steel_guitar_45_16, 255, 247, 255, 176
	voice_directsound 50, 0, DirectSoundWaveData_bw_steel_guitar_50_16, 255, 247, 255, 176
	voice_directsound 55, 0, DirectSoundWaveData_bw_steel_guitar_55_16, 255, 247, 255, 176
	voice_directsound 59, 0, DirectSoundWaveData_bw_steel_guitar_59_16, 255, 247, 255, 176
	voice_directsound 64, 0, DirectSoundWaveData_bw_steel_guitar_64_16, 255, 247, 255, 176

	.align 2
voicegroup292:: @ Fretless bass
	voice_directsound 31, 0, DirectSoundWaveData_bw_fretless_bass_31_16, 255, 251, 0, 196
	voice_directsound 36, 0, DirectSoundWaveData_bw_fretless_bass_36_16, 255, 251, 0, 196
	voice_directsound 43, 0, DirectSoundWaveData_bw_fretless_bass_43_16, 255, 251, 0, 196
	voice_directsound 48, 0, DirectSoundWaveData_bw_fretless_bass_48_16, 255, 251, 0, 196

	.align 2
voicegroup293:: @ Brush drum kit (one entry per MIDI key)
	.rept 36 @ 0-35
	voice_directsound 31, 64, DirectSoundWaveData_bw_brush_drum_31_16, 255, 0, 255, 0
	.endr
	voice_directsound 36, 64, DirectSoundWaveData_bw_brush_drum_36_16, 255, 0, 255, 0 @ 36
	voice_directsound 39, 30, DirectSoundWaveData_bw_brush_drum_39_16, 255, 0, 255, 0 @ 37
	voice_directsound 36, 64, DirectSoundWaveData_bw_brush_drum_36_16, 255, 0, 255, 0 @ 38
	.rept 2 @ 39-40
	voice_directsound 39, 30, DirectSoundWaveData_bw_brush_drum_39_16, 255, 0, 255, 0
	.endr
	voice_directsound 41, 64, DirectSoundWaveData_bw_brush_drum_41_16, 255, 0, 255, 0 @ 41
	.rept 4 @ 42-45
	voice_directsound 42, 80, DirectSoundWaveData_bw_brush_drum_42_16, 255, 0, 255, 0
	.endr
	.rept 3 @ 46-48
	voice_directsound 46, 80, DirectSoundWaveData_bw_brush_drum_46_16, 255, 241, 0, 0
	.endr
	.rept 27 @ 49-75
	voice_directsound 49, 64, DirectSoundWaveData_bw_brush_cymbal_49_16, 255, 241, 0, 0
	.endr

	.align 2
voicegroup294:: @ Grand piano
	voice_directsound 48, 0, DirectSoundWaveData_bw_grand_piano_48_16, 255, 250, 0, 221
	voice_directsound 55, 0, DirectSoundWaveData_bw_grand_piano_55_16, 255, 250, 0, 221
	voice_directsound 60, 0, DirectSoundWaveData_bw_grand_piano_60_16, 255, 250, 0, 221
	voice_directsound 67, 0, DirectSoundWaveData_bw_grand_piano_67_16, 255, 250, 0, 221
	voice_directsound 72, 0, DirectSoundWaveData_bw_grand_piano_72_16, 255, 250, 0, 221
	voice_directsound 79, 0, DirectSoundWaveData_bw_grand_piano_79_16, 255, 250, 0, 221
	.rept 2 @ 76-77
	voice_directsound 42, 80, DirectSoundWaveData_bw_brush_drum_42_16, 255, 0, 255, 0
	.endr
	.rept 50 @ 78-127
	voice_directsound 49, 64, DirectSoundWaveData_bw_brush_cymbal_49_16, 255, 241, 0, 0
	.endr
