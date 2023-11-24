.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_372

track_372_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 37
	.byte PAN, c_v
	.byte N10
	.byte Cn3, En2
	.byte W10

	.byte FINE

.align 2

track_372:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_372_0

.align 2
