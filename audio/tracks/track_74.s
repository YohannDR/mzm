.align 2

.global track_74

track_74_0:
	.byte KEYSH, 0
	.byte TEMPO, 45
	.byte VOICE, 86
	.byte VOL, 78
	.byte PAN, c_v+20
	.byte N24
	.byte Cn5, Gs4
	.byte W24
	.byte An4, Gs7
	.byte W04
	.byte VOL, 75
	.byte W03
	.byte Cn4
	.byte W02
	.byte As3
	.byte W03
	.byte Fs3
	.byte W03
	.byte Dn3
	.byte W03
	.byte Bn2
	.byte W03
	.byte Gs2
	.byte W03
	.byte TEMPO, 40
	.byte Fs4
	.byte N12
	.byte Gn4, En7
	.byte W12
	.byte En4
	.byte W12
	.byte Cn4, Cn8
	.byte W12
	.byte En4, En7
	.byte W12
	.byte TEMPO, 33
	.byte Dn5, Cn6
	.byte W12
	.byte As4
	.byte W12
	.byte Gn4, Cn5
	.byte W13
	.byte N17
	.byte Ds4
	.byte W11
	.byte W05
	.byte N48
	.byte Fs4, Gs4, CsM2
	.byte W22
	.byte VOL, 75
	.byte W04
	.byte Cn4
	.byte W04
	.byte An3
	.byte W04
	.byte Fs3
	.byte W05
	.byte Dn3
	.byte W04
	.byte Bn2
	.byte W04
	.byte Gs2
	.byte W04
	.byte Fn2
	.byte W04
	.byte Dn2
	.byte W04
	.byte Bn1
	.byte W32
	.byte 0xB6

track_74_1:
	.byte KEYSH, 0
	.byte VOICE, 84
	.byte VOL, 62
	.byte PAN, c_v
	.byte W01
	.byte N12
	.byte Fn3, En4
	.byte W12
	.byte As3, Gs4
	.byte W12
	.byte Cn4, En4
	.byte W12
	.byte Dn4
	.byte W11
	.byte W01
	.byte En4
	.byte W12
	.byte Cn4
	.byte W12
	.byte Gn3, En5
	.byte W12
	.byte Cn4, En4
	.byte W11
	.byte W01
	.byte N11
	.byte Fn4
	.byte W12
	.byte N12
	.byte Dn4, Gs3
	.byte W11
	.byte W01
	.byte N13
	.byte As3, En4
	.byte W13
	.byte N16
	.byte Gn3, Gs4
	.byte W10
	.byte W06
	.byte N44
	.byte An3, En3, DsM2
	.byte W90
	.byte 0xB6

track_74_2:
	.byte KEYSH, 0
	.byte VOICE, 67
	.byte VOL, 55
	.byte PAN, c_v-20
	.byte N48
	.byte Fn5, Cn1, CsM2
	.byte W48
	.byte W01
	.byte N44
	.byte En5, Gs0, DsM2
	.byte W44
	.byte W03
	.byte N52
	.byte Gn5, Cn1, CsM2
	.byte W24
	.byte W24
	.byte W05
	.byte N48
	.byte An5, Gs1
	.byte W32
	.byte W03
	.byte VOL, 51
	.byte W02
	.byte Cn2
	.byte W02
	.byte Gs1
	.byte W02
	.byte Fn1
	.byte W02
	.byte Dn1
	.byte W02
	.byte Bn0
	.byte W01
	.byte An0
	.byte W01
	.byte Gn0
	.byte W02
	.byte En0
	.byte W01
	.byte Dn0
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
	.byte N48
	.byte Fs2, En3
	.byte W44
	.byte W03
	.byte W01
	.byte Fn2
	.byte W44
	.byte W03
	.byte W01
	.byte BEND, c_v-13
	.byte N52
	.byte Gs2, Cn3, CsM2
	.byte W23
	.byte W24
	.byte W06
	.byte BEND, c_v+14
	.byte N44
	.byte An2, En2, DsM2
	.byte W90
	.byte 0xB6

track_74_4:
	.byte KEYSH, 0
	.byte VOICE, 69
	.byte VOL, 86
	.byte PAN, c_v-10
	.byte N48
	.byte As2, Cn4, CsM2
	.byte W48
	.byte W01
	.byte N44
	.byte An2, Gs4, DsM2
	.byte W44
	.byte W03
	.byte N54
	.byte Ds2, Gs7, CsM2
	.byte W24
	.byte W24
	.byte W07
	.byte N48
	.byte Dn2, Cn7, CsM2
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
