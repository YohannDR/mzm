.align 2

.global track_294

track_294_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 0
	.byte VOL, 0
	.byte N80
	.byte Gn1, Gn8, DnM2
	.byte N80
	.byte Cn2, Gn8, DnM2
	.byte W01
	.byte VOL, 0
	.byte W02
	.byte CsM2
	.byte W01
	.byte DnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte GnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte AsM2
	.byte W01
	.byte BnM2
	.byte W01
	.byte BnM2
	.byte W01
	.byte CsM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte AnM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Cs0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Fs0
	.byte W01
	.byte An0
	.byte W01
	.byte Cn1
	.byte W01
	.byte En1
	.byte W01
	.byte Gn1
	.byte W01
	.byte Bn1
	.byte W01
	.byte Ds2
	.byte W01
	.byte Gn2
	.byte W01
	.byte Cs3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Cs4
	.byte W01
	.byte Fs4
	.byte W24
	.byte W01
	.byte Fs4
	.byte W01
	.byte En3
	.byte W01
	.byte Gn2
	.byte W01
	.byte As1
	.byte W01
	.byte En1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Cs0
	.byte W01
	.byte AsM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte AsM2
	.byte W01
	.byte GsM2
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
	.byte CnM2
	.byte W15
	.byte W05

	.byte FINE

track_294_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 14
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-47
	.byte N52
	.byte Cn2, En1
	.byte W03
	.byte BEND, c_v-42
	.byte W03
	.byte VOL, 16
	.byte BEND, c_v-36
	.byte W03
	.byte An0
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-25
	.byte W03
	.byte VOL, 18
	.byte BEND, c_v-20
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v-14
	.byte W03
	.byte Gn2
	.byte W03
	.byte VOL, 21
	.byte BEND, c_v-4
	.byte W03
	.byte VOL, 22
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v+7
	.byte W03
	.byte VOL, 25
	.byte BEND, c_v+13
	.byte W03
	.byte VOL, 27
	.byte BEND, c_v+18
	.byte W03
	.byte VOL, 29
	.byte BEND, c_v+24
	.byte W03
	.byte VOL, 30
	.byte BEND, c_v+29
	.byte W03
	.byte VOL, 33
	.byte BEND, c_v+34
	.byte W03
	.byte VOL, 37
	.byte BEND, c_v+40
	.byte W03
	.byte VOL, 39
	.byte W01
	.byte VOICE, 25
	.byte VOL, 78
	.byte BENDR, 8
	.byte PRIO, 25
	.byte BEND, c_v-63
	.byte N10
	.byte Cn3, En6
	.byte W01
	.byte BEND, c_v-54
	.byte W01
	.byte GnM1
	.byte W01
	.byte En0
	.byte W01
	.byte Cs1
	.byte W01
	.byte As1
	.byte W01
	.byte Gn2
	.byte W01
	.byte En3
	.byte W01
	.byte Cs4
	.byte W01
	.byte As4
	.byte W01
	.byte Gn5
	.byte W01
	.byte En6
	.byte W01
	.byte Cs7
	.byte W01
	.byte Bn7
	.byte W01
	.byte Gn8
	.byte W30
	.byte W05

	.byte FINE

.align 2

track_294:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_294_0
	.word track_294_1

.align 2
