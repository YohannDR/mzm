.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_659

track_659_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 78
	.byte PAN, c_v
	.byte W10
	.byte N09
	.byte Cn3, En6
	.byte W09

	.byte FINE

.align 2

track_659:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_659_0

.align 2
