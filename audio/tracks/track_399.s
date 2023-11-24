.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_399

track_399_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 44
	.byte PAN, c_v
	.byte N06
	.byte An3, Gs4
	.byte W06

	.byte FINE

.align 2

track_399:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group5
	.word track_399_0

.align 2
