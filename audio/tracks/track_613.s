.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_613

track_613_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 54
	.byte VOL, 89
	.byte PAN, c_v
	.byte W04
	.byte N10
	.byte En3, En6
	.byte W10
	.byte En3, En2
	.byte W10
	.byte En3, GsM1
	.byte W10

	.byte FINE

.align 2

track_613:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group3
	.word track_613_0

.align 2
