.align 2

.global track_298

track_298_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W12
	.byte VOICE, 29
	.byte VOL, 0
	.byte PAN, c_v-10
	.byte BEND, c_v
	.byte N48
	.byte Cn2, Gs4
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte FsM2
	.byte W02
	.byte BnM2
	.byte W02
	.byte FnM1
	.byte W02
	.byte Dn0
	.byte W01
	.byte An0
	.byte W02
	.byte Fn1
	.byte W02
	.byte Gn1
	.byte W04
	.byte Fs1
	.byte W02
	.byte Ds1
	.byte W02
	.byte Bn0
	.byte W03
	.byte Ds0
	.byte W02
	.byte AsM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_298_1:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 29
	.byte VOL, 0
	.byte PAN, c_v-10
	.byte PRIO, 10
	.byte N48
	.byte En2, Gs4
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte FsM2
	.byte W02
	.byte BnM2
	.byte W02
	.byte FnM1
	.byte W02
	.byte Dn0
	.byte W01
	.byte An0
	.byte W02
	.byte Fn1
	.byte W02
	.byte Gn1
	.byte W04
	.byte Fs1
	.byte W02
	.byte Ds1
	.byte W02
	.byte Bn0
	.byte W03
	.byte Ds0
	.byte W02
	.byte AsM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_298_2:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 29
	.byte VOL, 0
	.byte PAN, c_v-10
	.byte PRIO, 20
	.byte N48
	.byte Gn2, Gs4
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte FsM2
	.byte W02
	.byte BnM2
	.byte W02
	.byte FnM1
	.byte W02
	.byte Dn0
	.byte W01
	.byte An0
	.byte W02
	.byte Fn1
	.byte W02
	.byte Gn1
	.byte W04
	.byte Fs1
	.byte W02
	.byte Ds1
	.byte W02
	.byte Bn0
	.byte W03
	.byte Ds0
	.byte W02
	.byte AsM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_298:
	.byte 3
	.byte 0
	.byte 180
	.byte 0
	.word voice_group4
	.word track_298_0
	.word track_298_1
	.word track_298_2

.align 2
