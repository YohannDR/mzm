.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_504

track_504_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 51
	.byte PAN, c_v
	.byte N04
	.byte Fs3, Cn3
	.byte W04
	.byte Bn2, Gs4
	.byte W04
	.byte Gn2, En1
	.byte W04

	.byte FINE

.align 2

track_504:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_504_0

.align 2
