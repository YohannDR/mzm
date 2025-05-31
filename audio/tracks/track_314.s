.align 2

.global track_314

track_314_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 78
	.byte PAN, c_v
	.byte N10, Cn3, v100
	.byte W10
	.byte VOICE, 18
	.byte N19, Cn3, v080
	.byte W56
	.byte FINE

track_314_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 55
	.byte W02
	.byte N04, Fn2, v112
	.byte W08
	.byte N04 @ Fn2, v112
	.byte W56
	.byte FINE

.align 2

track_314:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_314_0
	.word track_314_1

.align 2
