.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_313

track_313_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 24
	.byte VOL, 70
	.byte PAN, c_v
	.byte N16
	.byte Cn3, Gs5
	.byte W16

	.byte FINE

.align 2

track_313:
	.byte 1
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_313_0

.align 2
