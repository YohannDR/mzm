.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_311

track_311_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 47
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W10
	.byte N19
	.byte En3, En1
	.byte W19

	.byte FINE

.align 2

track_311:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group5
	.word track_311_0

.align 2
