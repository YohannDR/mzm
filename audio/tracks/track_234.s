.align 2

.global track_234

track_234_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 0
	.byte PAN, c_v
	.byte W07
	.byte N18, Cn3, v052
	.byte W03
	.byte VOL, 40
	.byte W15
	.byte FINE

track_234_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 66
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte VOICE, 24
	.byte VOL, 46
	.byte N07, Cn3, v072
	.byte W07
	.byte Bn2, v028 @ N07
	.byte W07
	.byte N05, An2, v012
	.byte W05
	.byte FINE

.align 2

track_234:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_234_0
	.word track_234_1

.align 2
