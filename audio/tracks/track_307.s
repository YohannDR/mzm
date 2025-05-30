.align 2

.global track_307

track_307_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 74
	.byte PAN, c_v
	.byte W01
	.byte N10, Cn3, v080
	.byte W10
	.byte En3, v040 @ N10
	.byte W10
	.byte En3, v012 @ N10
	.byte W32
	.byte FINE

track_307_1:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 78
	.byte PAN, c_v
	.byte N05, Cn3, v080
	.byte W05
	.byte VOICE, 20
	.byte N10, Cn3, v100
	.byte W10
	.byte VOICE, 0
	.byte VOL, 78
	.byte N05, Fn2, v080
	.byte W36
	.byte W02
	.byte FINE

.align 2

track_307:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_307_0
	.word track_307_1

.align 2
