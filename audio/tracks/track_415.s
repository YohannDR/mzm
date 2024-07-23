.align 2

.global track_415

track_415_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 78
	.byte PAN, c_v
	.byte N12
	.byte An2, En6
	.byte W12
	.byte Cn3, Cn3
	.byte W06
	.byte VOL, 78
	.byte W01
	.byte Gs3
	.byte W01
	.byte Bn2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Gn1
	.byte W01
	.byte Cs1
	.byte W01
	.byte Gn0
	.byte N12
	.byte En3, GsM1
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte AsM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_415_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N24
	.byte Fn2, Gs4
	.byte W02
	.byte BEND, c_v+2
	.byte W02
	.byte An3
	.byte W02
	.byte Cs4
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 55
	.byte W01
	.byte Cn2
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 41
	.byte W01
	.byte Bn0
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte Cs0
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte FsM1
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte BnM2
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 8
	.byte W01
	.byte FsM2
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte DnM2
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_415:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word voice_group8
	.word track_415_0
	.word track_415_1

.align 2
