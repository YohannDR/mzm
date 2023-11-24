.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_674

track_674_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 56
	.byte PAN, c_v+6
	.byte N12
	.byte Cn3, Gs4
	.byte W12

	.byte FINE

.align 2

track_674:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_674_0

.align 2
