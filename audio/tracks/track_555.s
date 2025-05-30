.align 2

.global track_555

track_555_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N03, Cn3, v100
	.byte W04
	.byte N28, Cn3, v080
	.byte W28
	.byte FINE

track_555_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N03, En2, v080
	.byte W04
	.byte N28 @ En2, v080
	.byte W28
	.byte FINE

.align 2

track_555:
	.byte 2
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_555_0
	.word track_555_1

.align 2
