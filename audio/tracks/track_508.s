.align 2

.global track_508

track_508_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 25
	.byte PAN, c_v
	.byte N02
	.byte Fn3, Gs4
	.byte W02
	.byte Dn3
	.byte W02
	.byte An3
	.byte W02
	.byte Cn4
	.byte W04
	.byte Cn4, Gs0
	.byte W04
	.byte Cn4, CnM1
	.byte W02

	.byte FINE

.align 2

track_508:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_508_0

.align 2
