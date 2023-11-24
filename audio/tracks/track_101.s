.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_101

track_101_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 39
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Cn7
	.byte W02

	.byte FINE

.align 2

track_101:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_101_0

.align 2
