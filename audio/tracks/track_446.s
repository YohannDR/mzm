.align 2

.global track_446

track_446_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 78
	.byte PAN, c_v
	.byte TIE
	.byte Bn2, En6
	.byte W96
	.byte W96
	.byte W96
	.byte W40
	.byte VOL, 54
	.byte W01
	.byte Cs1
	.byte W01
	.byte Cs0
	.byte W01
	.byte FnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte EOT
	.byte W24

	.byte FINE

track_446_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte TIE
	.byte Bn2, Gs4
	.byte W06
	.byte BEND, c_v-1
	.byte W10
	.byte Dn3
	.byte W10
	.byte Cs3
	.byte W12
	.byte Cn3
	.byte W10
	.byte Bn2
	.byte W10
	.byte As2
	.byte W10
	.byte An2
	.byte W10
	.byte Gs2
	.byte W12
	.byte Gn2
	.byte W06
	.byte W04
	.byte Fs2
	.byte W10
	.byte Fn2
	.byte W10
	.byte En2
	.byte W10
	.byte Ds2
	.byte W12
	.byte Dn2
	.byte W10
	.byte Cs2
	.byte W10
	.byte Cn2
	.byte W10
	.byte Bn1
	.byte W10
	.byte As1
	.byte W10
	.byte An1
	.byte W12
	.byte Gs1
	.byte W10
	.byte Gn1
	.byte W10
	.byte Fs1
	.byte W10
	.byte Fn1
	.byte W10
	.byte En1
	.byte W12
	.byte Ds1
	.byte W10
	.byte Dn1
	.byte W10
	.byte Cs1
	.byte W10
	.byte Cn1
	.byte W02
	.byte W08
	.byte Bn0
	.byte W10
	.byte As0
	.byte W12
	.byte An0
	.byte W10
	.byte VOL, 54
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte Cs0
	.byte W01
	.byte FnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte EOT
	.byte W24

	.byte FINE

track_446_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte MOD, 30
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 100
	.byte PRIO, 2
	.byte N24
	.byte Fn2, Gs4
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24
	.byte LFOS, 60
	.byte N24
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24
track_446_lbl_21469f:
	.byte LFOS, 100
	.byte N24
	.byte Fn2, Gs4
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24
	.byte LFOS, 60
	.byte N24
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24
	.byte PEND
	.byte PATT
		.word track_446_lbl_21469f
	.byte LFOS, 100
	.byte N24
	.byte Fn2, Gs4
	.byte W24
	.byte LFOS, 80
	.byte N12
	.byte W48

	.byte FINE

.align 2

track_446:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group9
	.word track_446_0
	.word track_446_1
	.word track_446_2

.align 2
