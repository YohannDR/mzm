.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_434

track_434_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 78
	.byte PAN, c_v
	.byte N14
	.byte Cn3, En6
	.byte W14
	.byte N18
	.byte Cn3, Gs0
	.byte W18

	.byte FINE

track_434_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v
	.byte N04
	.byte Fn3, Gs4
	.byte W05
	.byte Dn3
	.byte W05
	.byte Bn2
	.byte W06
	.byte Bn2, Gs0
	.byte W06
	.byte Bn2, CnM1
	.byte W04
	.byte VOL, 62
	.byte N04
	.byte Gn3, Gs0
	.byte W04
	.byte Fn3, CnM1
	.byte W04
	.byte En3, GsM2
	.byte W04

	.byte FINE

.align 2

track_434:
	.byte 2
	.byte 0
	.byte 212
	.byte 0
	.word voice_group9
	.word track_434_0
	.word track_434_1

.align 2
