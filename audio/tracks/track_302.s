.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_302

track_302_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 74
	.byte PAN, c_v
	.byte N03
	.byte Bn2, Gs5
	.byte W03
	.byte VOICE, 19
	.byte N06
	.byte W06
	.byte N21
	.byte Cn3, Cn4
	.byte W44
	.byte W03

	.byte FINE

track_302_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N02
	.byte Cn4, Gs4
	.byte W02
	.byte VOICE, 2
	.byte N04
	.byte Gn2, Cn8
	.byte W54

	.byte FINE

.align 2

track_302:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_302_0
	.word track_302_1

.align 2
