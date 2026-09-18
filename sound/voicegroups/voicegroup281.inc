	.align 2
voicegroup281::
	voice_keysplit_all voicegroup002
	.rept 21
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 60, 0, DirectSoundWaveData_dp_harmonica_c3_16, 67, 247, 191, 171
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_acgt_e3_16, 255, 253, 127, 208
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_oboe, 255, 165, 154, 127
	.rept 9
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fingered_bass, 255, 165, 51, 242
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fingered_bass, 255, 165, 51, 242
	.rept 11
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	.endr
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_string_ensemble_72, 255, 165, 51, 242
