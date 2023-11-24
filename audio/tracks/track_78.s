.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_78

track_78_0:
	.byte KEYSH, 0
track_78_lbl_22a576:
	.byte TEMPO, 65
	.byte VOICE, 66
	.byte VOL, 44
	.byte PAN, c_v+10
	.byte PRIO, 120
	.byte N48
	.byte Gs3, En1
	.byte W48
	.byte N24
	.byte Bn3
	.byte W24
track_78_lbl_22a587:
	.byte N48
	.byte Dn4, Cn1
	.byte W48
	.byte N24
	.byte Ds4
	.byte W24
	.byte PEND
	.byte N48
	.byte Gs3, En1
	.byte W48
	.byte N24
	.byte Bn3
	.byte W24
	.byte PATT
		.word track_78_lbl_22a587
	.byte N48
	.byte En4, Cn1
	.byte W48
	.byte N24
	.byte Ds4
	.byte W24
	.byte N48
	.byte En4
	.byte W48
	.byte N24
	.byte Fn4
	.byte W24
	.byte N48
	.byte Fs4
	.byte W48
	.byte N24
	.byte Fn4
	.byte W24
	.byte N48
	.byte Fs4
	.byte W48
	.byte N24
	.byte Gn4
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte N48
	.byte An3, En1
	.byte W48
	.byte N24
	.byte Gs3
	.byte W24
	.byte N48
	.byte An3, En2
	.byte W48
	.byte N24
	.byte As3
	.byte W24
	.byte VOICE, 67
	.byte VOL, 50
	.byte PAN, c_v+16
	.byte TIE
	.byte As4, Gs4
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte An4
	.byte W24
	.byte TIE
	.byte As4
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte An4
	.byte W24
	.byte TIE
	.byte As4
	.byte W72
	.byte W72
	.byte EOT
	.byte W72
	.byte VOICE, 66
	.byte VOL, 44
	.byte PAN, c_v+10
	.byte N08
	.byte As2, Cn3
	.byte W08
	.byte Cs3
	.byte W08
	.byte En3
	.byte W08
	.byte Cs3, En2
	.byte W08
	.byte En3
	.byte W08
	.byte Gn3
	.byte W08
	.byte N12
	.byte As3
	.byte W06
	.byte Cs4, En1
	.byte W06
	.byte En4
	.byte W06
	.byte N06
	.byte Gn4
	.byte W06
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W32
	.byte N08
	.byte Gs2, En3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Gs3, En1
	.byte W08
	.byte Cn4
	.byte W08
	.byte GOTO
		.word track_78_lbl_22a576

	.byte FINE

track_78_1:
	.byte KEYSH, 0
track_78_lbl_22a622:
	.byte VOICE, 66
	.byte VOL, 44
	.byte PAN, c_v
	.byte PRIO, 119
	.byte W06
	.byte N06
	.byte Bn2, Cn2
	.byte W06
	.byte Dn3
	.byte W06
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W06
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W06
	.byte Bn2
	.byte W12
	.byte Gs3
	.byte W06
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W06
track_78_lbl_22a641:
	.byte W06
	.byte N06
	.byte Dn3, Cn2
	.byte W06
	.byte Fn3
	.byte W06
	.byte Gs3
	.byte W06
	.byte Bn3
	.byte W06
	.byte Gs3
	.byte W06
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W12
	.byte Fs3
	.byte W06
	.byte An3, Cn1
	.byte W06
	.byte Cn4
	.byte W06
	.byte PEND
	.byte W06
	.byte Bn2, Cn2
	.byte W06
	.byte Dn3
	.byte W06
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W06
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W06
	.byte Bn2
	.byte W12
	.byte Gs3
	.byte W06
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W06
	.byte PATT
		.word track_78_lbl_22a641
	.byte W06
	.byte N06
	.byte Cs4, Cn1
	.byte W06
	.byte As3
	.byte W06
	.byte Gn3, Cn2
	.byte W06
	.byte En3
	.byte W06
	.byte Cs3
	.byte W06
	.byte En3
	.byte W06
	.byte Gn3
	.byte W12
	.byte Cn4, Cn1
	.byte W06
	.byte An3, Cn2
	.byte W06
	.byte Fs3
	.byte W06
	.byte W06
	.byte Cs4, Cn1
	.byte W06
	.byte As3, Cn2
	.byte W06
	.byte Gn3
	.byte W06
	.byte En3
	.byte W06
	.byte Cs3
	.byte W06
	.byte En3
	.byte W06
	.byte Gn3
	.byte W12
	.byte Dn4, Cn1
	.byte W06
	.byte Bn3
	.byte W06
	.byte Gs3, Cn2
	.byte W06
	.byte W06
	.byte Ds4, Cn1
	.byte W06
	.byte Cn4
	.byte W06
	.byte An3, Cn2
	.byte W06
	.byte Fs3
	.byte W06
	.byte Ds3
	.byte W06
	.byte Fs3
	.byte W06
	.byte Gn3
	.byte W12
	.byte Dn4, Cn1
	.byte W06
	.byte Bn3
	.byte W06
	.byte Gs3, Cn2
	.byte W06
	.byte W06
	.byte Ds4, Cn1
	.byte W06
	.byte Cn4
	.byte W06
	.byte An3, Cn2
	.byte W06
	.byte Fs3
	.byte W06
	.byte Ds3
	.byte W06
	.byte Fs3
	.byte W06
	.byte An3
	.byte W12
	.byte En4, Cn1
	.byte W06
	.byte Cs4
	.byte W06
	.byte As3, Cn2
	.byte W06
	.byte N08
	.byte Gs4, Gs0
	.byte W06
	.byte Fn4
	.byte W06
	.byte Dn4
	.byte W06
	.byte Bn3, Cn1
	.byte W06
	.byte Fn4
	.byte W06
	.byte Dn4
	.byte W06
	.byte Bn3
	.byte W06
	.byte Gs3
	.byte W06
	.byte Dn4
	.byte W06
	.byte Bn3
	.byte W06
	.byte Gs3
	.byte W06
	.byte Fn3
	.byte W06
	.byte N12
	.byte Gs3, Gs2
	.byte W08
	.byte Fn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Bn2
	.byte W08
	.byte Gs2
	.byte W08
	.byte Bn2
	.byte W08
	.byte N08
	.byte Dn3
	.byte W06
	.byte Bn2
	.byte W06
	.byte Gs2, Gs0
	.byte W06
	.byte Fn2
	.byte W06
	.byte An4, Cn0
	.byte W06
	.byte Fs4
	.byte W06
	.byte Ds4, En2
	.byte W06
	.byte Cn4, Gs2
	.byte W06
	.byte An3
	.byte W06
	.byte Fs3
	.byte W06
	.byte Ds3
	.byte W06
	.byte Cn3
	.byte W06
	.byte An2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Ds2
	.byte W06
	.byte Cn2
	.byte W06
	.byte Ds2
	.byte W06
	.byte Fs2
	.byte W06
	.byte An2
	.byte W06
	.byte Cn3, En2
	.byte W06
	.byte Ds3, En1
	.byte W06
	.byte Fs3
	.byte W06
	.byte An3
	.byte W06
	.byte Cn4, Gs0
	.byte W06
	.byte N12
	.byte Ds4
	.byte W08
	.byte Fs4
	.byte W08
	.byte An4
	.byte W08
	.byte N08
	.byte Gs4
	.byte W06
	.byte Fn4
	.byte W06
	.byte Dn4
	.byte W06
	.byte Bn3, Cn1
	.byte W06
	.byte Fn4, Gs0
	.byte W06
	.byte Dn4
	.byte W06
	.byte Bn3
	.byte W06
	.byte Gs3, Cn1
	.byte W06
	.byte Dn4
	.byte W06
	.byte Bn3
	.byte W06
	.byte Gs3
	.byte W06
	.byte Fn3
	.byte W06
	.byte Fn2, Gs2
	.byte W06
	.byte Dn2
	.byte W06
	.byte Fn2
	.byte W06
	.byte Gs2
	.byte W06
	.byte Bn2
	.byte W06
	.byte Gs2
	.byte W06
	.byte Fn2
	.byte W06
	.byte Dn2
	.byte W06
	.byte N12
	.byte Fn2
	.byte W08
	.byte Dn2
	.byte W08
	.byte N08
	.byte Bn1
	.byte W08
	.byte W06
	.byte N06
	.byte Fs4, GsM1
	.byte W06
	.byte Ds4
	.byte W06
	.byte Cn4, Cn2
	.byte W06
	.byte An3, Gs2
	.byte W06
	.byte Fs3
	.byte W06
	.byte Ds3
	.byte W06
	.byte Cn3
	.byte W12
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W06
	.byte Bn2
	.byte W06
	.byte W06
	.byte Fs3
	.byte W06
	.byte Ds3
	.byte W06
	.byte Cn3
	.byte W06
	.byte Ds2
	.byte W06
	.byte Cn2
	.byte W06
	.byte Ds2
	.byte W06
	.byte Fs2, En5
	.byte W12
	.byte As2
	.byte W06
	.byte Cs3
	.byte W06
	.byte En3
	.byte W06
	.byte TIE
	.byte As3, Cn2
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte An3, En2
	.byte W24
	.byte TIE
	.byte As3, Cn2
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte An3, En2
	.byte W24
	.byte TIE
	.byte As3, Cn2
	.byte W72
	.byte W48
	.byte EOT
	.byte W24
	.byte VOICE, 19
	.byte VOL, 44
	.byte N48
	.byte As2, Gs4
	.byte W24
	.byte N44
	.byte Cs3, Gs4, DnM2
	.byte W24
	.byte N24
	.byte En3, Cn4
	.byte W24
	.byte W72
	.byte VOICE, 66
	.byte VOL, 44
	.byte N08
	.byte Cn5, Gs0
	.byte W06
	.byte Gs4, En1
	.byte W06
	.byte Fs4
	.byte W06
	.byte Dn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Gs2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Dn2, Cn4
	.byte W06
	.byte Cn4
	.byte W06
	.byte Gs3
	.byte W06
	.byte Fs3
	.byte W06
	.byte Dn3
	.byte W06
track_78_lbl_22a7f4:
	.byte N12
	.byte Cn3, Cn4
	.byte W06
	.byte Gs2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Dn2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Gs2
	.byte W06
	.byte Dn3
	.byte W06
	.byte Cn4, En1
	.byte W06
	.byte Fs3
	.byte W06
	.byte Gs3
	.byte W06
	.byte Dn4
	.byte W06
	.byte Fs4
	.byte W06
	.byte PEND
	.byte N08
	.byte Cn5, Gs0
	.byte W06
	.byte Gs4, En1
	.byte W06
	.byte Fs4
	.byte W06
	.byte Dn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Gs2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Dn2, Cn4
	.byte W06
	.byte Cn4
	.byte W06
	.byte Gs3
	.byte W06
	.byte Fs3
	.byte W06
	.byte Dn3
	.byte W06
	.byte PATT
		.word track_78_lbl_22a7f4
	.byte N08
	.byte Cn5, Gs0
	.byte W06
	.byte Gs4, En1
	.byte W06
	.byte Fs4
	.byte W06
	.byte Dn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Gs2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Dn2, Cn4
	.byte W06
	.byte N12
	.byte Cn4, En2
	.byte W06
	.byte Gs3
	.byte W06
	.byte Fs3
	.byte W06
	.byte Dn3
	.byte W06
	.byte Cn4
	.byte W06
	.byte Gs3
	.byte W06
	.byte Fs3
	.byte W06
	.byte Dn3
	.byte W06
	.byte Cn3
	.byte W06
	.byte Gs2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Dn2
	.byte W06
	.byte Fs2, Cn4
	.byte W06
	.byte Gs2
	.byte W06
	.byte Dn3, En1
	.byte W06
	.byte Fs3
	.byte W06
	.byte Cn5, Gs0
	.byte W06
	.byte Gs4, En1
	.byte W06
	.byte Fs4
	.byte W06
	.byte Dn4
	.byte W06
	.byte Cn3, Cn4
	.byte W06
	.byte Gs2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Dn2
	.byte W06
	.byte Fs2
	.byte W06
	.byte Gs2
	.byte W06
	.byte Dn3, En2
	.byte W06
	.byte Fs3
	.byte W06
	.byte Cn5, Gs0
	.byte W06
	.byte Gs4, En1
	.byte W06
	.byte Fs4
	.byte W06
	.byte Dn4
	.byte W06
	.byte N08
	.byte Fs2, En3
	.byte W08
	.byte N12
	.byte Dn3
	.byte W08
	.byte Fs3
	.byte W08
	.byte Gs3
	.byte W08
	.byte Dn4, En1
	.byte W08
	.byte N08
	.byte Fs4
	.byte W08
	.byte GOTO
		.word track_78_lbl_22a622

	.byte FINE

track_78_2:
	.byte KEYSH, 0
track_78_lbl_22a8aa:
	.byte PRIO, 118
	.byte W01
	.byte VOICE, 96
	.byte VOL, 69
	.byte PAN, c_v-24
	.byte TIE
	.byte Bn1, Cn8
	.byte W68
	.byte W03
	.byte W48
	.byte EOT
	.byte W01
	.byte N23
	.byte Cn2
	.byte W23
	.byte W01
	.byte TIE
	.byte Bn1
	.byte W68
	.byte W03
	.byte W48
	.byte EOT
	.byte W01
	.byte N23
	.byte Cn2
	.byte W23
	.byte W01
	.byte N44
	.byte Cs2, Cn8, DsM2
	.byte W48
	.byte N23
	.byte Cn2
	.byte W23
	.byte W01
	.byte N44
	.byte Cs2, Cn8, DsM2
	.byte W48
	.byte N23
	.byte Dn2
	.byte W23
	.byte W01
	.byte N44
	.byte Ds2, Cn8, DsM2
	.byte W48
	.byte N23
	.byte Dn2
	.byte W23
	.byte W01
	.byte N44
	.byte Ds2, Cn8, DsM2
	.byte W48
	.byte N23
	.byte En2
	.byte W23
	.byte W01
	.byte TIE
	.byte Fn2
	.byte W68
	.byte W03
	.byte W72
	.byte EOT
	.byte W01
	.byte TIE
	.byte Fs2, En7
	.byte W68
	.byte W03
	.byte W72
	.byte EOT
	.byte W01
	.byte TIE
	.byte Fn2, Cn8
	.byte W68
	.byte W03
	.byte W72
	.byte EOT
	.byte W01
	.byte N44
	.byte Fs2, En7, DsM2
	.byte W48
	.byte N23
	.byte Fn2, Cn8
	.byte W23
	.byte W01
	.byte N44
	.byte Fs2, En7, DsM2
	.byte W48
	.byte N23
	.byte Gn2, Cn8
	.byte W23
	.byte VOICE, 101
	.byte VOL, 75
	.byte TIE
	.byte Cs4, En7
	.byte W72
	.byte W44
	.byte W01
	.byte EOT
	.byte W04
	.byte N21
	.byte Cn4, En6
	.byte W23
	.byte TIE
	.byte Cs4, En7
	.byte W72
	.byte W44
	.byte W01
	.byte EOT
	.byte W04
	.byte N21
	.byte Cn4, En6
	.byte W23
	.byte TIE
	.byte Cs4, En7
	.byte W72
	.byte W72
	.byte W72
	.byte W68
	.byte W01
	.byte EOT
	.byte W03
	.byte W72
	.byte VOICE, 102
	.byte VOL, 69
	.byte W01
	.byte N72
	.byte Dn2, Gs7
	.byte W68
	.byte W03
	.byte W72
	.byte W01
	.byte N68
	.byte Dn2, Gs7, DsM2
	.byte W68
	.byte W03
	.byte W01
	.byte Dn2, Gs7, DsM2
	.byte W68
	.byte W03
	.byte W01
	.byte Dn2, Gs7, DsM2
	.byte W68
	.byte W03
	.byte W01
	.byte Dn2, Gs7, DsM2
	.byte W68
	.byte W03
	.byte W01
	.byte N30
	.byte Dn2, Gs7, CsM2
	.byte W68
	.byte W03
	.byte GOTO
		.word track_78_lbl_22a8aa

	.byte FINE

track_78_3:
	.byte KEYSH, 0
track_78_lbl_22a972:
	.byte VOICE, 65
	.byte PRIO, 30
	.byte VOL, 50
	.byte PAN, c_v-14
	.byte TIE
	.byte Bn1, Cn4
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Cn2
	.byte W24
	.byte TIE
	.byte Bn1
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Cn2
	.byte W24
	.byte N48
	.byte Cs2, Gs4
	.byte W48
	.byte N24
	.byte Cn2
	.byte W24
	.byte N48
	.byte Cs2
	.byte W48
	.byte N24
	.byte Dn2
	.byte W24
	.byte N48
	.byte Ds2
	.byte W48
	.byte N24
	.byte Dn2
	.byte W24
	.byte N48
	.byte Ds2
	.byte W48
	.byte N24
	.byte En2
	.byte W24
	.byte VOICE, 103
	.byte TIE
	.byte Fn1, En4
	.byte W72
	.byte W72
	.byte EOT
	.byte TIE
	.byte Fs1
	.byte W72
	.byte W72
	.byte EOT
	.byte TIE
	.byte Fn1
	.byte W72
	.byte W72
	.byte EOT
	.byte N48
	.byte Fs1
	.byte W48
	.byte N24
	.byte Fn1
	.byte W24
	.byte N48
	.byte Fs1
	.byte W48
	.byte N24
	.byte Gn1
	.byte W24
	.byte VOICE, 23
	.byte PAN, c_v+22
	.byte TIE
	.byte Cs2, Cn8
	.byte W72
	.byte W44
	.byte W03
	.byte EOT
	.byte W01
	.byte N23
	.byte Cn2
	.byte W24
	.byte TIE
	.byte Cs2
	.byte W72
	.byte W44
	.byte W03
	.byte EOT
	.byte W01
	.byte N23
	.byte Cn2
	.byte W24
	.byte TIE
	.byte Cs2
	.byte W72
	.byte W72
	.byte W72
	.byte W68
	.byte W03
	.byte EOT
	.byte W01
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 100
	.byte PAN, c_v-14
	.byte VOL, 62
	.byte N68
	.byte Dn3, Cn7, DsM2
	.byte W72
	.byte Dn3, Cn7, DsM2
	.byte W72
	.byte N30
	.byte Dn3, Cn7, CsM2
	.byte W72
	.byte GOTO
		.word track_78_lbl_22a972

	.byte FINE

track_78_4:
	.byte KEYSH, 0
track_78_lbl_22aa05:
	.byte VOICE, 65
	.byte VOL, 37
	.byte PAN, c_v+16
	.byte PRIO, 30
	.byte TIE
	.byte Bn2, En1
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Cn3
	.byte W24
	.byte TIE
	.byte Bn2
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Cn3
	.byte W24
	.byte VOICE, 67
	.byte VOL, 50
	.byte N48
	.byte En5
	.byte W48
	.byte N24
	.byte Ds5
	.byte W24
	.byte N48
	.byte En5
	.byte W48
	.byte N24
	.byte Fn5
	.byte W24
	.byte N48
	.byte Fs5
	.byte W48
	.byte N24
	.byte Fn5
	.byte W24
	.byte N48
	.byte Fs5
	.byte W48
	.byte N24
	.byte Gn5
	.byte W24
	.byte VOICE, 103
	.byte VOL, 50
	.byte TIE
	.byte Dn2, En4
	.byte W72
	.byte W72
	.byte EOT
	.byte TIE
	.byte Ds2
	.byte W72
	.byte W72
	.byte EOT
	.byte TIE
	.byte Dn2
	.byte W72
	.byte W72
	.byte EOT
	.byte N48
	.byte Ds2
	.byte W48
	.byte N24
	.byte Dn2
	.byte W24
	.byte N48
	.byte Ds2
	.byte W48
	.byte N24
	.byte En2
	.byte W24
	.byte VOICE, 66
	.byte VOL, 44
	.byte TIE
	.byte En3, En2
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Ds3
	.byte W24
	.byte TIE
	.byte En3
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Ds3
	.byte W24
	.byte TIE
	.byte En3
	.byte W72
	.byte W48
	.byte EOT
	.byte W24
	.byte W72
	.byte VOICE, 19
	.byte VOL, 50
	.byte PAN, c_v+16
	.byte N48
	.byte Cs3, Cn6
	.byte W24
	.byte En3
	.byte W24
	.byte N24
	.byte Gn3
	.byte W24
	.byte W72
	.byte VOICE, 66
	.byte VOL, 62
	.byte PAN, c_v+10
	.byte N72
	.byte Dn1, En7
	.byte W72
	.byte W72
	.byte N72
	.byte W72
	.byte W72
	.byte TIE
	.byte W72
	.byte W36
	.byte EOT
	.byte W36
	.byte W72
	.byte GOTO
		.word track_78_lbl_22aa05

	.byte FINE

track_78_5:
	.byte KEYSH, 0
track_78_lbl_22aaa2:
	.byte VOICE, 100
	.byte VOL, 56
	.byte PAN, c_v+20
	.byte PRIO, 29
	.byte TIE
	.byte Bn3, Cn8
	.byte W72
	.byte W48
	.byte EOT
	.byte W02
	.byte N21
	.byte Cn4
	.byte W22
	.byte W02
	.byte TIE
	.byte Bn3
	.byte W68
	.byte W02
	.byte W44
	.byte W02
	.byte EOT
	.byte W04
	.byte N21
	.byte Cn4
	.byte W22
	.byte W02
	.byte N44
	.byte Cs4, Cn8, CsM2
	.byte W48
	.byte N21
	.byte Cn4
	.byte W22
	.byte W02
	.byte N44
	.byte Cs4, Cn8, CsM2
	.byte W48
	.byte N21
	.byte Dn4, En7
	.byte W22
	.byte W02
	.byte N44
	.byte Ds4, En7, CsM2
	.byte W48
	.byte N21
	.byte Dn4
	.byte W22
	.byte W02
	.byte N44
	.byte Ds4, En7, CsM2
	.byte W48
	.byte N21
	.byte En4
	.byte W22
	.byte W02
	.byte TIE
	.byte Fn4, Cn8
	.byte W68
	.byte W02
	.byte W72
	.byte EOT
	.byte W02
	.byte TIE
	.byte Fs4, En7
	.byte W68
	.byte W02
	.byte W72
	.byte EOT
	.byte W02
	.byte TIE
	.byte Fn4, Cn8
	.byte W68
	.byte W02
	.byte W72
	.byte EOT
	.byte W02
	.byte N44
	.byte Fs4, En7, DnM2
	.byte W48
	.byte N22
	.byte Fn4, Cn8
	.byte W22
	.byte W02
	.byte N44
	.byte Fs4, En6, CsM2
	.byte W48
	.byte N21
	.byte Gn4, Cn8
	.byte W22
	.byte W02
	.byte TIE
	.byte Gn4, En7
	.byte W68
	.byte W02
	.byte W44
	.byte W03
	.byte EOT
	.byte W03
	.byte N21
	.byte Fs4
	.byte W22
	.byte W02
	.byte TIE
	.byte Gn4
	.byte W68
	.byte W02
	.byte W44
	.byte W03
	.byte EOT
	.byte W03
	.byte N21
	.byte Fs4
	.byte W22
	.byte W02
	.byte TIE
	.byte Gn4
	.byte W68
	.byte W02
	.byte W72
	.byte W72
	.byte W68
	.byte W03
	.byte EOT
	.byte W01
	.byte W72
	.byte VOICE, 66
	.byte VOL, 50
	.byte N72
	.byte As1, Cn7
	.byte W72
	.byte W72
	.byte N72
	.byte W72
	.byte W72
	.byte TIE
	.byte W72
	.byte W36
	.byte EOT
	.byte W36
	.byte W72
	.byte GOTO
		.word track_78_lbl_22aaa2

	.byte FINE

track_78_6:
	.byte KEYSH, 0
track_78_lbl_22ab50:
	.byte VOICE, 65
	.byte VOL, 37
	.byte PAN, c_v
	.byte PRIO, 27
	.byte TIE
	.byte Dn3, Gs4
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Ds3
	.byte W24
	.byte TIE
	.byte Dn3
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Ds3
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 103
	.byte TIE
	.byte Gs2, Gs2
	.byte W72
	.byte W72
	.byte EOT
	.byte TIE
	.byte An2
	.byte W72
	.byte W72
	.byte EOT
	.byte TIE
	.byte Gs2
	.byte W72
	.byte W72
	.byte EOT
	.byte N48
	.byte An2
	.byte W48
	.byte N24
	.byte Gs2
	.byte W24
	.byte N48
	.byte An2
	.byte W48
	.byte N24
	.byte As2
	.byte W24
	.byte VOICE, 19
	.byte VOL, 50
	.byte TIE
	.byte Cs3, Gs4
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Cn3
	.byte W24
	.byte TIE
	.byte Cs3
	.byte W72
	.byte W48
	.byte EOT
	.byte N24
	.byte Cn3
	.byte W24
	.byte TIE
	.byte Cs3
	.byte W72
	.byte W72
	.byte EOT
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 66
	.byte VOL, 50
	.byte N72
	.byte Fs1, Cn7
	.byte W72
	.byte W72
	.byte N72
	.byte W72
	.byte W72
	.byte TIE
	.byte W72
	.byte W36
	.byte EOT
	.byte W36
	.byte W72
	.byte GOTO
		.word track_78_lbl_22ab50

	.byte FINE

.align 2

track_78:
	.byte 7
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_78_0
	.word track_78_1
	.word track_78_2
	.word track_78_3
	.word track_78_4
	.word track_78_5
	.word track_78_6

.align 2
