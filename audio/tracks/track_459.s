.align 2

.global track_459

track_459_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 75
	.byte PAN, c_v
	.byte N03, An3, v120
	.byte W03
	.byte VOICE, 3
	.byte VOL, 69
	.byte N04, Gn2 @ v120
	.byte W04
	.byte Fn2, v040 @ N04
	.byte W04
	.byte En2, v012 @ N04
	.byte W04
	.byte FINE

.align 2

track_459:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group10
	.word track_459_0

.align 2
