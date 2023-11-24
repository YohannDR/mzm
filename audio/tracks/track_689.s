.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_689

track_689_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 85
	.byte PAN, c_v
	.byte N10
	.byte An4, En2
	.byte W15
	.byte N10
	.byte W15
	.byte N10
	.byte W15
track_689_lbl_216c0e:
	.byte N10
	.byte An4, Gs4
	.byte W15
	.byte N10
	.byte W15
	.byte N10
	.byte W15
	.byte N10
	.byte W06
	.byte W09
	.byte N10
	.byte W15
	.byte GOTO
		.word track_689_lbl_216c0e

	.byte FINE

.align 2

track_689:
	.byte 1
	.byte 0
	.byte 255
	.byte 0
	.word voice_group14
	.word track_689_0

.align 2
