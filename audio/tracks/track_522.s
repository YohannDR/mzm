.align 2

.global track_522

track_522_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 28
	.byte PAN, c_v
	.byte N02
	.byte An2, Gs4
	.byte W02
	.byte Dn3
	.byte W02
	.byte Fn3
	.byte W02
	.byte An3
	.byte W04
	.byte An3, Gs0
	.byte W04
	.byte An3, CnM1
	.byte W02

	.byte FINE

.align 2

track_522:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_522_0

.align 2
