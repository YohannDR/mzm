.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_682

track_682_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 94
	.byte PAN, c_v
	.byte N15
	.byte Cn3, Gs4
	.byte W15
	.byte Cn3, Gs0
	.byte W15
	.byte Cn3, CnM1
	.byte W15

	.byte FINE

.align 2

track_682:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group14
	.word track_682_0

.align 2
