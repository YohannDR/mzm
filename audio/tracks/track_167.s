.align 2

.global track_167

track_167_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 39
	.byte VOL, 59
	.byte PAN, c_v
	.byte N10, Cn3, v112
	.byte W10
	.byte VOICE, 10
	.byte N15, Cn3, v092
	.byte W15
	.byte N19, Cn3, v040
	.byte W32
	.byte W01
	.byte FINE

track_167_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 75
	.byte PAN, c_v
	.byte N02, An2, v100
	.byte W05
	.byte N05, Fn2, v127
	.byte W52
	.byte W01
	.byte FINE

.align 2

track_167:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_167_0
	.word track_167_1

.align 2
