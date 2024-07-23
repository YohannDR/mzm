.align 2

.global track_423

track_423_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 86
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W10
	.byte En3, En1
	.byte W10
	.byte En3, CnM1
	.byte W42
	.byte W01

	.byte FINE

track_423_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N05
	.byte Cn3, Gs4
	.byte W05
	.byte VOICE, 3
	.byte N23
	.byte An2, En6
	.byte W56
	.byte W02

	.byte FINE

track_423_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 22
	.byte N02
	.byte An4, Gs4
	.byte W02
	.byte VOICE, 1
	.byte N04
	.byte Fn2, En7
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
