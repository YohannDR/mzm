.align 2

.global track_514

track_514_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 56
	.byte PAN, c_v
	.byte N03, Cn2, v080
	.byte W03
	.byte En2 @ N03, v080
	.byte W03
	.byte En2, v032 @ N03
	.byte W03
	.byte En2, v012 @ N03
	.byte W03
	.byte FINE

.align 2

track_514:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_514_0

.align 2
