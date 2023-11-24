.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_376

track_376_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 37
	.byte PAN, c_v
	.byte W04
	.byte N05
	.byte Bn2, Gs4
	.byte W07
	.byte En3, Cn3
	.byte W07
	.byte En3, Gs0
	.byte W07
	.byte En3, CnM1
	.byte W05

	.byte FINE

.align 2

track_376:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_376_0

.align 2
