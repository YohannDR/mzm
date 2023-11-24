.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_363

track_363_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 50
	.byte PAN, c_v
	.byte N05
	.byte En3, Gs4
	.byte W05
	.byte N06
	.byte Cn3, GsM1
	.byte W06

	.byte FINE

.align 2

track_363:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_363_0

.align 2
