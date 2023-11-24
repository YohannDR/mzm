.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_278

track_278_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 62
	.byte BEND, c_v
	.byte N03
	.byte Cn3, Gs4
	.byte W05
	.byte N04
	.byte An2, Cn3
	.byte W04

	.byte FINE

track_278_1:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte VOL, 39
	.byte PAN, c_v
	.byte W10
	.byte N28
	.byte Cn3, Cn3
	.byte W22
	.byte VOL, 47
	.byte W01
	.byte Cs1
	.byte W01
	.byte En0
	.byte W01
	.byte FsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_278:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_278_0
	.word track_278_1

.align 2
