.align 2

.global track_385

track_385_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 30
	.byte PAN, c_v
	.byte N04
	.byte En2, En6
	.byte W04
	.byte N03
	.byte An2, Gs4
	.byte W03
	.byte Fn2
	.byte W13
	.byte N04
	.byte Gn2, En6
	.byte W04
	.byte N03
	.byte Cn3, Gs4
	.byte W16
	.byte Cn2
	.byte W03
	.byte Bn2, Cn3
	.byte W09
	.byte En3
	.byte W03

	.byte FINE

.align 2

track_385:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_385_0

.align 2
