.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_513

track_513_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 18
	.byte PAN, c_v
	.byte N01
	.byte Cn3, Gs4
	.byte W01

	.byte FINE

.align 2

track_513:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_513_0

.align 2
