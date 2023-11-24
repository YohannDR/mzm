.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_521

track_521_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 40
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gs4
	.byte W02
	.byte An2
	.byte W04
	.byte An2, Gs0
	.byte W04
	.byte An2, CnM1
	.byte W02

	.byte FINE

.align 2

track_521:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_521_0

.align 2
