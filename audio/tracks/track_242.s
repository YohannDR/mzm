.align 2

.global track_242

track_242_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 0
	.byte PAN, c_v
	.byte W06
	.byte N18, Cn3, v052
	.byte W03
	.byte VOL, 41
	.byte W15
	.byte FINE

track_242_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 75
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte VOICE, 24
	.byte VOL, 20
	.byte N07, Cn3, v072
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W04
	.byte N07, Bn2, v028
	.byte W07
	.byte N05, An2, v012
	.byte W05
	.byte FINE

.align 2

track_242:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_242_0
	.word track_242_1

.align 2
