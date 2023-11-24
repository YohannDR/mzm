.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_213

track_213_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 45
	.byte PAN, c_v
	.byte N28
	.byte Cn3, Gs4
	.byte W28

	.byte FINE

.align 2

track_213:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_213_0

.align 2
