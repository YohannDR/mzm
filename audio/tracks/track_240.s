.align 2

.global track_240

track_240_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 0
	.byte PAN, c_v
	.byte W08
	.byte N18
	.byte Dn3, En2
	.byte W04
	.byte VOL, 51
	.byte W14

	.byte FINE

track_240_1:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 68
	.byte PAN, c_v
	.byte N12
	.byte Cn3, Gs4
	.byte W12
	.byte VOICE, 24
	.byte VOL, 41
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

track_240:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_240_0
	.word track_240_1

.align 2
