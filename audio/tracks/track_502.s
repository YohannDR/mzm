.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_502

track_502_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 18
	.byte PAN, c_v
	.byte N04
	.byte Fn4, Gs4
	.byte W04
	.byte Fn4, En1
	.byte W04
	.byte Fn4, GsM1
	.byte W04

	.byte FINE

.align 2

track_502:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_502_0

.align 2
