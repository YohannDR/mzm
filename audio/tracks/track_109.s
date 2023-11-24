.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_109

track_109_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 40
	.byte VOL, 59
	.byte PAN, c_v
	.byte N08
	.byte Cn3, Gs4
	.byte W08

	.byte FINE

.align 2

track_109:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_109_0

.align 2
