.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_210

track_210_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 37
	.byte PAN, c_v
	.byte N18
	.byte Cn3, Gs4
	.byte W18

	.byte FINE

.align 2

track_210:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_210_0

.align 2
