.align 2

.global track_325

track_325_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 15
	.byte VOL, 40
	.byte PAN, c_v
	.byte BENDR, 2
	.byte LFOS, 100
	.byte BEND, c_v+63
	.byte N16
	.byte An2, Cn3
	.byte W16

	.byte FINE

.align 2

track_325:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_325_0

.align 2
