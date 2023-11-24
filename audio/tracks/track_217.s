.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_217

track_217_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 44
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v+40
	.byte N16
	.byte Cn3, Gs4
	.byte W16

	.byte FINE

.align 2

track_217:
	.byte 1
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_217_0

.align 2
