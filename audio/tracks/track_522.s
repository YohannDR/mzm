.align 2

.global track_522

track_522_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 28
	.byte PAN, c_v
	.byte N02, An2, v080
	.byte W02
	.byte Dn3 @ N02, v080
	.byte W02
	.byte Fn3 @ N02, v080
	.byte W02
	.byte An3 @ N02, v080
	.byte W04
	.byte An3, v032 @ N02
	.byte W04
	.byte An3, v012 @ N02
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
