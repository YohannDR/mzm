.align 2

.global track_238

track_238_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 0
	.byte PAN, c_v
	.byte W07
	.byte N18
	.byte Cn3, En2
	.byte W03
	.byte VOL, 26
	.byte W15

	.byte FINE

track_238_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 66
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W10
	.byte VOICE, 24
	.byte VOL, 40
	.byte N07
	.byte Cn3, Cn4
	.byte W07
	.byte Bn2, En0
	.byte W07
	.byte N05
	.byte An2, CnM1
	.byte W05

	.byte FINE

.align 2

track_238:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_238_0
	.word track_238_1

.align 2
