.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_92

track_92_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte N12
	.byte Cn3, Gs4
	.byte W12

	.byte FINE

.align 2

track_92:
	.byte 1
	.byte 0
	.byte 0
	.byte 0
	.word voice_group1
	.word track_92_0

.align 2
