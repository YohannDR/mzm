.align 2

.global track_425

track_425_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 15
	.byte N40
	.byte Cn3, Gs4
	.byte W03
	.byte BEND, c_v
	.byte W01
	.byte Dn3
	.byte W01
	.byte Cn3
	.byte W01
	.byte As2
	.byte W01
	.byte Gs2
	.byte W01
	.byte Gn2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Cs2
	.byte W01
	.byte Cn2
	.byte W01
	.byte As1
	.byte W01
	.byte Gs1
	.byte W01
	.byte Fs1
	.byte W01
	.byte Fn1
	.byte W01
	.byte Ds1
	.byte W01
	.byte Cs1
	.byte W01
	.byte Bn0
	.byte W01
	.byte As0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Fs0
	.byte W01
	.byte En0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Cs0
	.byte W01
	.byte BnM1
	.byte W01
	.byte AnM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CsM2
	.byte W01

	.byte FINE

.align 2

track_425:
	.byte 1
	.byte 0
	.byte 211
	.byte 0
	.word voice_group9
	.word track_425_0

.align 2
