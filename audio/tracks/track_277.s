.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_277

track_277_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W10
	.byte VOICE, 4
	.byte VOL, 49
	.byte PAN, c_v
	.byte N12
	.byte En2, Cn3
	.byte W12
	.byte VOICE, 7
	.byte VOL, 49
	.byte N04
	.byte Cn4
	.byte W04
	.byte Cn4, GsM1
	.byte W04

	.byte FINE

.align 2

track_277:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_277_0

.align 2
