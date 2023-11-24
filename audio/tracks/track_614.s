.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_614

track_614_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 54
	.byte VOL, 80
	.byte PAN, c_v
	.byte N10
	.byte En3, En6
	.byte W10
	.byte Gn3, En2
	.byte W10
	.byte Gn3, GsM1
	.byte W10

	.byte FINE

.align 2

track_614:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group3
	.word track_614_0

.align 2
