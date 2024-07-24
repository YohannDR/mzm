.align 2

.global track_421

track_421_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 94
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gn8
	.byte W10
	.byte Cn3, En1
	.byte W10
	.byte N18
	.byte Cn3, EnM1
	.byte W18

	.byte FINE

track_421_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 78
	.byte PAN, c_v
	.byte W06
	.byte N12
	.byte An2, Gn8
	.byte W12
	.byte An2, En1
	.byte W12
	.byte N18
	.byte An2, EnM1
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
