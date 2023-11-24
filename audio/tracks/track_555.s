.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_555

track_555_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N03
	.byte Cn3, En6
	.byte W04
	.byte N28
	.byte Cn3, Gs4
	.byte W28

	.byte FINE

track_555_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N03
	.byte En2, Gs4
	.byte W04
	.byte N28
	.byte W28

	.byte FINE

.align 2

track_555:
	.byte 2
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_555_0
	.word track_555_1

.align 2
