.align 2

.global track_470

track_470_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 0
	.byte VOL, 0
	.byte N64
	.byte Cn2, Gn8
	.byte N80
	.byte Fn2, Gn8, DnM2
	.byte W01
	.byte VOL, 0
	.byte W02
	.byte CsM2
	.byte W01
	.byte DnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte EnM2
	.byte W02
	.byte FsM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte AsM2
	.byte W01
	.byte CnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Cn0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Fs1
	.byte W01
	.byte As1
	.byte W01
	.byte Dn2
	.byte W01
	.byte Fs2
	.byte W01
	.byte An2
	.byte W01
	.byte Cn3
	.byte W01
	.byte Ds3
	.byte W01
	.byte Fn3
	.byte W01
	.byte Gn3
	.byte W01
	.byte Gs3
	.byte W01
	.byte As3
	.byte W02
	.byte As3
	.byte W01
	.byte As3
	.byte W02
	.byte Gs3
	.byte W01
	.byte Gn3
	.byte W01
	.byte Fn3
	.byte W01
	.byte En3
	.byte W01
	.byte Cs3
	.byte W01
	.byte As2
	.byte W01
	.byte Gn2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Dn2
	.byte W01
	.byte As1
	.byte W01
	.byte Gn1
	.byte W01
	.byte En1
	.byte W01
	.byte Cs1
	.byte W01
	.byte As0
	.byte W01
	.byte Gn0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Cn0
	.byte W01
	.byte BnM1
	.byte W01
	.byte AnM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FsM2
	.byte W02
	.byte EnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_470:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_470_0

.align 2
