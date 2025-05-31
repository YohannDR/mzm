.align 2

.global track_74

track_74_0:
	.byte KEYSH, 0
	.byte TEMPO, 45
	.byte VOICE, 86
	.byte VOL, 78
	.byte PAN, c_v+20
	.byte N24, Cn5, v080
	.byte W24
	.byte An4, v116 @ N24
	.byte W04
	.byte VOL, 75
	.byte W03
	.byte 72 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte TEMPO, 40
	.byte 78 @ VOL
	.byte N12, Gn4, v112
	.byte W12
	.byte En4 @ N12, v112
	.byte W12
	.byte Cn4, v120 @ N12
	.byte W12
	.byte En4, v112 @ N12
	.byte W12
	.byte TEMPO, 33
	.byte Dn5, v096 @ N12
	.byte W12
	.byte As4 @ N12, v096
	.byte W12
	.byte Gn4, v084 @ N12
	.byte W13
	.byte N17, Ds4 @ v084
	.byte W11
	.byte W05
	.byte N48, Fs4, v080, 1
	.byte W22
	.byte VOL, 75
	.byte W04
	.byte 72 @ VOL
	.byte W04
	.byte 69 @ VOL
	.byte W04
	.byte 66 @ VOL
	.byte W05
	.byte 62 @ VOL
	.byte W04
	.byte 59 @ VOL
	.byte W04
	.byte 56 @ VOL
	.byte W04
	.byte 53 @ VOL
	.byte W04
	.byte 50 @ VOL
	.byte W04
	.byte 47 @ VOL
	.byte W32
	.byte 0xB6

track_74_1:
	.byte KEYSH, 0
	.byte VOICE, 84
	.byte VOL, 62
	.byte PAN, c_v
	.byte W01
	.byte N12, Fn3, v076
	.byte W12
	.byte As3, v080 @ N12
	.byte W12
	.byte Cn4, v076 @ N12
	.byte W12
	.byte Dn4 @ N12, v076
	.byte W11
	.byte W01
	.byte En4 @ N12, v076
	.byte W12
	.byte Cn4 @ N12, v076
	.byte W12
	.byte Gn3, v088 @ N12
	.byte W12
	.byte Cn4, v076 @ N12
	.byte W11
	.byte W01
	.byte N11, Fn4 @ v076
	.byte W12
	.byte N12, Dn4, v068
	.byte W11
	.byte W01
	.byte N13, As3, v076
	.byte W13
	.byte N16, Gn3, v080
	.byte W10
	.byte W06
	.byte N44, An3, v064, 3
	.byte W90
	.byte 0xB6

track_74_2:
	.byte KEYSH, 0
	.byte VOICE, 67
	.byte VOL, 55
	.byte PAN, c_v-20
	.byte N48, Fn5, v036, 1
	.byte W48
	.byte W01
	.byte N44, En5, v032, 3
	.byte W44
	.byte W03
	.byte N52, Gn5, v036, 1
	.byte W24
	.byte W24
	.byte W05
	.byte N48, An5, v044
	.byte W32
	.byte W03
	.byte VOL, 51
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W40
	.byte W01
	.byte 0xB6

track_74_3:
	.byte KEYSH, 0
	.byte W01
	.byte VOICE, 88
	.byte VOL, 78
	.byte PAN, c_v+26
	.byte BEND, c_v-10
	.byte N48, Fs2, v064
	.byte W44
	.byte W03
	.byte W01
	.byte Fn2 @ N48, v064
	.byte W44
	.byte W03
	.byte W01
	.byte BEND, c_v-13
	.byte N52, Gs2, v060, 1
	.byte W23
	.byte W24
	.byte W06
	.byte BEND, c_v+14
	.byte N44, An2, v052, 3
	.byte W90
	.byte 0xB6

track_74_4:
	.byte KEYSH, 0
	.byte VOICE, 69
	.byte VOL, 86
	.byte PAN, c_v-10
	.byte N48, As2, v072, 1
	.byte W48
	.byte W01
	.byte N44, An2, v080, 3
	.byte W44
	.byte W03
	.byte N54, Ds2, v116, 1
	.byte W24
	.byte W24
	.byte W07
	.byte N48, Dn2, v108, 1
	.byte W88
	.byte W01
	.byte 0xB6

.align 2

track_74:
	.byte 5
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_74_0
	.word track_74_1
	.word track_74_2
	.word track_74_3
	.word track_74_4

.align 2
