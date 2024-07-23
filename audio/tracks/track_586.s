.align 2

.global track_586

track_586_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 100
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N90
	.byte En3, Gs4
	.byte W60
	.byte VOL, 100
	.byte W03
	.byte Cn4
	.byte W03
	.byte Fn2
	.byte W03
	.byte En1
	.byte W03
	.byte Fn0
	.byte W03
	.byte AsM1
	.byte W03
	.byte DsM1
	.byte W03
	.byte AsM2
	.byte W03
	.byte FsM2
	.byte W03
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

track_586_1:
	.byte KEYSH, 0
	.byte VOICE, 38
	.byte VOL, 100
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte BEND, c_v
	.byte W09
	.byte N80
	.byte Gn3, Gs4, CsM2
	.byte W48
	.byte W03
	.byte VOL, 100
	.byte W03
	.byte Cn4
	.byte W03
	.byte Fn2
	.byte W03
	.byte En1
	.byte W03
	.byte Fn0
	.byte W03
	.byte AsM1
	.byte W03
	.byte DsM1
	.byte W03
	.byte AsM2
	.byte W03
	.byte FsM2
	.byte W03
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

track_586_2:
	.byte KEYSH, 0
	.byte VOICE, 39
	.byte VOL, 0
	.byte PAN, c_v-20
	.byte BENDR, 48
	.byte BEND, c_v+63
	.byte N90
	.byte Cn3, En6
	.byte W04
	.byte VOL, 78
	.byte BEND, c_v
	.byte W56
	.byte VOL, 78
	.byte W03
	.byte Cn4
	.byte W03
	.byte Fn2
	.byte W03
	.byte En1
	.byte W03
	.byte Fn0
	.byte W03
	.byte AsM1
	.byte W03
	.byte DsM1
	.byte W03
	.byte AsM2
	.byte W03
	.byte FsM2
	.byte W03
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_586:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_586_0
	.word track_586_1
	.word track_586_2

.align 2
