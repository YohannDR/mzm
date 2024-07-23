.align 2

.global track_476

track_476_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 120
	.byte PAN, c_v
	.byte N60
	.byte Cn3, Cn8
	.byte W09
	.byte VOL, 100
	.byte W02
	.byte Ds6
	.byte W04
	.byte Cs6
	.byte W04
	.byte Bn5
	.byte W02
	.byte An5
	.byte W02
	.byte Gn5
	.byte W02
	.byte Fn5
	.byte W02
	.byte Ds5
	.byte W02
	.byte Cn5
	.byte W02
	.byte Gn4
	.byte W02
	.byte Ds4
	.byte W02
	.byte An3
	.byte W02
	.byte Cs3
	.byte W03
	.byte Bn1
	.byte W02
	.byte Ds1
	.byte W02
	.byte Gs0
	.byte W02
	.byte Dn0
	.byte W02
	.byte AnM1
	.byte W02
	.byte EnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte GsM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_476:
	.byte 1
	.byte 0
	.byte 227
	.byte 0
	.word voice_group12
	.word track_476_0

.align 2
