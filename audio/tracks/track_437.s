.align 2

.global track_437

track_437_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 28
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N12
	.byte Cn2, Cn3
	.byte W12
	.byte N18
	.byte En2
	.byte W18

	.byte FINE

track_437_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 0
	.byte PAN, c_v
	.byte N18
	.byte An3, Cn8
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte FsM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte DsM1
	.byte W01
	.byte Cs0
	.byte W01
	.byte Bn1
	.byte W01
	.byte As1
	.byte W01
	.byte An1
	.byte W01
	.byte Gn1
	.byte W01
	.byte Fs1
	.byte W01
	.byte En1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fs0
	.byte W01
	.byte Cn0
	.byte W01
	.byte DnM1
	.byte W02
	.byte Bn1
	.byte N18
	.byte Cn4, Cn3
	.byte W01
	.byte VOL, 46
	.byte W01
	.byte An1
	.byte W01
	.byte Gs1
	.byte W01
	.byte Fs1
	.byte W01
	.byte Fs1
	.byte W01
	.byte En1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Cn1
	.byte W01
	.byte As0
	.byte W01
	.byte Gs0
	.byte W01
	.byte AsM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_437:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group9
	.word track_437_0
	.word track_437_1

.align 2
