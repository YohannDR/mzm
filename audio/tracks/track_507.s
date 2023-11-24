.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_507

track_507_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 31
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Cn3
	.byte W04
	.byte N02
	.byte Dn3
	.byte W02
	.byte N03
	.byte Bn2, En2
	.byte W04
	.byte VOICE, 2
	.byte VOL, 19
	.byte N02
	.byte Cn4, Gs0
	.byte W04
	.byte Cn4, CnM1
	.byte W02

	.byte FINE

track_507_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 19
	.byte PAN, c_v
	.byte N02
	.byte Fn3, Gs4
	.byte W02
	.byte Dn3
	.byte W02
	.byte An3
	.byte W02
	.byte Cn4
	.byte W06
	.byte MOD, 5
	.byte VOL, 31
	.byte LFOS, 127
	.byte N12
	.byte An2, Cn3
	.byte W12
	.byte MOD, 0

	.byte FINE

.align 2

track_507:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_507_0
	.word track_507_1

.align 2
