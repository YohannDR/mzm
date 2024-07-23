.align 2

.global track_244

track_244_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 0
	.byte PAN, c_v
	.byte W07
	.byte N18
	.byte Cs3, Cn3
	.byte W03
	.byte VOL, 13
	.byte W01
	.byte Ds0
	.byte W01
	.byte Fn1
	.byte W01
	.byte Bn1
	.byte W01
	.byte Fs2
	.byte W11

	.byte FINE

track_244_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 68
	.byte PAN, c_v
	.byte N11
	.byte Cn3, Gs4
	.byte W11
	.byte VOICE, 24
	.byte MOD, 20
	.byte LFOS, 40
	.byte VOL, 37
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

track_244:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_244_0
	.word track_244_1

.align 2
