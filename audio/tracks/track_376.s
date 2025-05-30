.align 2

.global track_376

track_376_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 37
	.byte PAN, c_v
	.byte W04
	.byte N05, Bn2, v080
	.byte W07
	.byte En3, v060 @ N05
	.byte W07
	.byte En3, v032 @ N05
	.byte W07
	.byte En3, v012 @ N05
	.byte W05
	.byte FINE

.align 2

track_376:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_376_0

.align 2
