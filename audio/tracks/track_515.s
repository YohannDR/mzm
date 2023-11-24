.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_515

track_515_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 48
	.byte PAN, c_v
	.byte N03
	.byte En2, En3
	.byte W03
	.byte Cn2, Gs4
	.byte W03
	.byte Cn2, Gs0
	.byte W03
	.byte Cn2, CnM1
	.byte W03

	.byte FINE

.align 2

track_515:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_515_0

.align 2
