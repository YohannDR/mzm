.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_460

track_460_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 74
	.byte PAN, c_v-20
	.byte N15
	.byte Cn3, En7
	.byte W15
	.byte VOICE, 1
	.byte N19
	.byte Cn3, Gs5
	.byte W42

	.byte FINE

track_460_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 86
	.byte PAN, c_v-28
	.byte N05
	.byte Fn2, En6
	.byte W56
	.byte W01

	.byte FINE

.align 2

track_460:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group10
	.word track_460_0
	.word track_460_1

.align 2
