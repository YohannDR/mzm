.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_320

track_320_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 56
	.byte PAN, c_v
	.byte N36
	.byte Cn3, Gn8
	.byte W36
	.byte W02

	.byte FINE

.align 2

track_320:
	.byte 1
	.byte 0
	.byte 196
	.byte 0
	.word voice_group3
	.word track_320_0

.align 2
