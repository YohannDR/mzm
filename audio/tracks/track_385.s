.align 2

.global track_385

track_385_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 30
	.byte PAN, c_v
	.byte N04, En2, v100
	.byte W04
	.byte N03, An2, v080
	.byte W03
	.byte Fn2 @ N03, v080
	.byte W13
	.byte N04, Gn2, v100
	.byte W04
	.byte N03, Cn3, v080
	.byte W16
	.byte Cn2 @ N03, v080
	.byte W03
	.byte Bn2, v060 @ N03
	.byte W09
	.byte En3 @ N03, v060
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
