.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_362

track_362_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 55
	.byte PAN, c_v
	.byte N17
	.byte Cn3, Gs4
	.byte W17

	.byte FINE

.align 2

track_362:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_362_0

.align 2
