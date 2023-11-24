.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_406

track_406_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 56
	.byte PAN, c_v
	.byte N16
	.byte Cn3, Gs4
	.byte W16

	.byte FINE

track_406_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 70
	.byte PAN, c_v
	.byte N02
	.byte Bn3, Gs4
	.byte W03
	.byte Cn4, Cn3
	.byte W03
	.byte Bn3, Gs4
	.byte W03
	.byte Cn4, Cn3
	.byte W03
	.byte Bn3, Gs4
	.byte W03
	.byte N01
	.byte Cn4, Cn3
	.byte W01

	.byte FINE

.align 2

track_406:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group6
	.word track_406_0
	.word track_406_1

.align 2
