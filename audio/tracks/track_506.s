.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_506

track_506_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 27
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Gs4
	.byte W03
	.byte Cn3, Gs0
	.byte W03
	.byte Cn3, CnM1
	.byte W03

	.byte FINE

.align 2

track_506:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_506_0

.align 2
