.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_327

track_327_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 35
	.byte PAN, c_v
	.byte W04
	.byte N08
	.byte Fn1, Gs4
	.byte W08
	.byte Bn1
	.byte W08

	.byte FINE

.align 2

track_327:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_327_0

.align 2
