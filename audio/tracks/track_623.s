.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_623

track_623_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 69
	.byte PAN, c_v
	.byte N10
	.byte An2, Cn8
	.byte W10
	.byte VOICE, 53
	.byte N05
	.byte Cn2, Cn3
	.byte W32
	.byte W02
	.byte VOICE, 52
	.byte N08
	.byte Cn3, En1
	.byte W08

	.byte FINE

.align 2

track_623:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_623_0

.align 2
