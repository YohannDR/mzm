.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_520

track_520_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 34
	.byte PAN, c_v
	.byte N02
	.byte Fs3, Gs4
	.byte W02
	.byte Dn3
	.byte W02
	.byte An3
	.byte W04
	.byte An3, Gs0
	.byte W04
	.byte An3, CnM1
	.byte W02

	.byte FINE

.align 2

track_520:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_520_0

.align 2
