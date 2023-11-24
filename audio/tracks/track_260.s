.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_260

track_260_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 37
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W10
	.byte Cn3, Gs0
	.byte W10
	.byte Cn3, CnM1
	.byte W10

	.byte FINE

.align 2

track_260:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group2
	.word track_260_0

.align 2
