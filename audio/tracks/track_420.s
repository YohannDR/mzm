.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_420

track_420_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 94
	.byte PAN, c_v
	.byte W06
	.byte N18
	.byte Cn3, Gs4
	.byte W60

	.byte FINE

track_420_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 94
	.byte PAN, c_v
	.byte N12
	.byte Cn3, Cn8
	.byte W12
	.byte N18
	.byte Cn3, GsM1
	.byte W54

	.byte FINE

track_420_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte W03
	.byte N05
	.byte Gn2, En6
	.byte W05
	.byte N04
	.byte Fn2
	.byte W56
	.byte W02

	.byte FINE

.align 2

track_420:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group5
	.word track_420_0
	.word track_420_1
	.word track_420_2

.align 2
