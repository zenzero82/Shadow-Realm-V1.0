	.include "MPlayDef.s"

	.equ	mus_pyrite_grp, voicegroup300
	.equ	mus_pyrite_pri, 0
	.equ	mus_pyrite_rev, reverb_set+0
	.equ	mus_pyrite_mvl, 100
	.equ	mus_pyrite_key, 0
	.equ	mus_pyrite_tbs, 1
	.equ	mus_pyrite_exg, 1
	.equ	mus_pyrite_cmp, 1

	.section .rodata
	.global	mus_pyrite
	.align	2

mus_pyrite_1:
	.byte	KEYSH, mus_pyrite_key+0
	.byte	TEMPO, 120*mus_pyrite_tbs/2
	.byte	VOICE, 0
	.byte	VOL, 127*mus_pyrite_mvl/mxv
	.byte	TIE, Cn3, v127

mus_pyrite_1_loop:
	.byte	W96
	.byte	GOTO
	.word	mus_pyrite_1_loop
	.byte	FINE

	.align	2
mus_pyrite:
	.byte	1 @ NumTrks
	.byte	0 @ NumBlks
	.byte	mus_pyrite_pri @ Priority
	.byte	mus_pyrite_rev @ Reverb
	.word	mus_pyrite_grp
	.word	mus_pyrite_1

	.end
