.align 2

.global track_421

track_421_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 94
	.byte PAN, c_v
	.byte N10, Cn3, v127
	.byte W10
	.byte Cn3, v040 @ N10
	.byte W10
	.byte N18, Cn3, v016
	.byte W18
	.byte FINE

track_421_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 78
	.byte PAN, c_v
	.byte W06
	.byte N12, An2, v127
	.byte W12
	.byte An2, v040 @ N12
	.byte W12
	.byte N18, An2, v016
	.byte W18
	.byte FINE

.align 2

track_421:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group5
	.word track_421_0
	.word track_421_1

.align 2
