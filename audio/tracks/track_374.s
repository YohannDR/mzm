.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_374

track_374_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 50
	.byte PAN, c_v
	.byte N13
	.byte Cn3, En2
	.byte W13

	.byte FINE

.align 2

track_374:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word voice_group3
	.word track_374_0

.align 2
