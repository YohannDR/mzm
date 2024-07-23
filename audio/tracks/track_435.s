.align 2

.global track_435

track_435_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 94
	.byte PAN, c_v
	.byte N14
	.byte Cn3, En6
	.byte W14
	.byte N16
	.byte Cn3, En2
	.byte W16
	.byte N18
	.byte Cn3, CnM1
	.byte W42

	.byte FINE

track_435_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 94
	.byte PAN, c_v
	.byte N04
	.byte Fn3, Gs4
	.byte W05
	.byte Dn3
	.byte W05
	.byte Bn2
	.byte W06
	.byte Bn2, Gs0
	.byte W06
	.byte Bn2, CnM1
	.byte W04
	.byte Gn3, Gs0
	.byte W04
	.byte Fn3, CnM1
	.byte W04
	.byte En3, GsM2
	.byte W36
	.byte W02

	.byte FINE

track_435_2:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 94
	.byte PAN, c_v
	.byte N04
	.byte Fn2, Cn8
	.byte W07
	.byte N04
	.byte W07
	.byte N04
	.byte W07
	.byte Fn2, En6
	.byte W48
	.byte W03

	.byte FINE

.align 2

track_435:
	.byte 3
	.byte 0
	.byte 212
	.byte 0
	.word voice_group9
	.word track_435_0
	.word track_435_1
	.word track_435_2

.align 2
