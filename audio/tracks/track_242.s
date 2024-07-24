.align 2

.global track_242

track_242_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 0
	.byte PAN, c_v
	.byte W06
	.byte N18
	.byte Cn3, En2
	.byte W03
	.byte VOL, 41
	.byte W15

	.byte FINE

track_242_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 75
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W10
	.byte VOICE, 24
	.byte VOL, 20
	.byte N07
	.byte Cn3, Cn4
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte As0
	.byte W01
	.byte Bn1
	.byte W04
	.byte N07
	.byte Bn2, En0
	.byte W07
	.byte N05
	.byte An2, CnM1
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
