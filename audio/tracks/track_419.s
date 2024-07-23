.align 2

.global track_419

track_419_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 110
	.byte PAN, c_v
	.byte W32
	.byte N32
	.byte Cn2, Cn4
	.byte W32
	.byte N24
	.byte Dn2, En2
	.byte W24
	.byte N20
	.byte En2, Cn3
	.byte W08
	.byte W12
	.byte N16
	.byte Fn2, Cn4
	.byte W16
	.byte N12
	.byte Gn2, Gs4
	.byte W12
	.byte N08
	.byte An2, Gs5
	.byte W08
	.byte N23
	.byte Gn3, En6
	.byte W23

	.byte FINE

track_419_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 60
	.byte PAN, c_v
	.byte W32
	.byte N32
	.byte Cn1, Cn4
	.byte W24
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte Cn0
	.byte W01
	.byte EnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte Cn3
	.byte N24
	.byte Dn1, Cn3
	.byte W16
	.byte VOL, 37
	.byte W01
	.byte Dn0
	.byte W01
	.byte FsM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte Cn3
	.byte N20
	.byte En1, Gs3
	.byte W08
	.byte W03
	.byte VOL, 43
	.byte W01
	.byte Gn0
	.byte W01
	.byte AsM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte Cn3
	.byte N16
	.byte Fn1, Cn4
	.byte W09
	.byte VOL, 39
	.byte W01
	.byte Ds0
	.byte W01
	.byte FsM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte Cn3
	.byte N12
	.byte Gn1, En4
	.byte W06
	.byte VOL, 37
	.byte W01
	.byte Cn0
	.byte W01
	.byte DsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte Cn3
	.byte N08
	.byte An1, Gs4
	.byte W05
	.byte VOL, 20
	.byte W01
	.byte GnM2
	.byte W01
	.byte CnM2
	.byte W04
	.byte Gs4
	.byte N10
	.byte Cn2, Gs5
	.byte W03
	.byte VOL, 65
	.byte W01
	.byte Dn2
	.byte W01
	.byte Bn0
	.byte W01
	.byte GsM1
	.byte W03
	.byte GsM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte FsM2
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_419:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group8
	.word track_419_0
	.word track_419_1

.align 2
