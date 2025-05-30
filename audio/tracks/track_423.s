.align 2

.global track_423

track_423_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 86
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte En3, v040 @ N10
	.byte W10
	.byte En3, v012 @ N10
	.byte W42
	.byte W01
	.byte FINE

track_423_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N05, Cn3, v080
	.byte W05
	.byte VOICE, 3
	.byte N23, An2, v100
	.byte W56
	.byte W02
	.byte FINE

track_423_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 22
	.byte N02, An4, v080
	.byte W02
	.byte VOICE, 1
	.byte N04, Fn2, v112
	.byte W60
	.byte W01
	.byte FINE

.align 2

track_423:
	.byte 3
	.byte 0
	.byte 218
	.byte 0
	.word voice_group9
	.word track_423_0
	.word track_423_1
	.word track_423_2

.align 2
