.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_25

track_25_0:
	.byte KEYSH, 0
track_25_lbl_230096:
	.byte TEMPO, 79
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v+15
	.byte PRIO, 120
	.byte N84
	.byte Gn3, Cn3
	.byte W96
track_25_lbl_2300a4:
	.byte N66
	.byte As3, Cn4
	.byte W72
	.byte VOICE, 1
	.byte N06
	.byte An3, Gs4
	.byte W06
	.byte As3
	.byte W06
	.byte An3
	.byte W06
	.byte Fn3
	.byte W06
	.byte PEND
track_25_lbl_2300b5:
	.byte VOICE, 0
	.byte N84
	.byte Gn3, Cn3
	.byte W96
	.byte PEND
	.byte PATT
		.word track_25_lbl_2300a4
	.byte PATT
		.word track_25_lbl_2300b5
	.byte PATT
		.word track_25_lbl_2300a4
	.byte VOICE, 0
	.byte TIE
	.byte Gn3, Gs4
	.byte W96
	.byte W72
	.byte EOT
	.byte W24
	.byte N66
	.byte Cn4, Cn3
	.byte W72
	.byte N24
	.byte Gn3, Gs3
	.byte W24
	.byte PATT
		.word track_25_lbl_2300a4
	.byte VOICE, 0
	.byte N66
	.byte Cn4, Cn3
	.byte W72
	.byte N24
	.byte Gn3, Gs3
	.byte W24
	.byte PATT
		.word track_25_lbl_2300a4
	.byte VOICE, 0
	.byte N72
	.byte Cn4, Cn3
	.byte W72
	.byte N24
	.byte Gn3, Gs3
	.byte W24
	.byte PATT
		.word track_25_lbl_2300a4
	.byte VOICE, 0
	.byte N90
	.byte Gn3, Cn3
	.byte W96
	.byte En3, Gs4
	.byte W96
	.byte N66
	.byte An3, Cn3
	.byte W72
	.byte VOICE, 1
	.byte N08
	.byte An3, Cn4
	.byte W08
	.byte Gn3
	.byte W08
	.byte An3
	.byte W08
	.byte VOICE, 0
	.byte N42
	.byte As3, En4
	.byte W48
	.byte VOICE, 1
	.byte N18
	.byte Fn3, Gs4
	.byte W24
	.byte N08
	.byte Cn3, Cn3
	.byte W08
	.byte Fn3
	.byte W08
	.byte Gn3, En3
	.byte W08
	.byte VOICE, 0
	.byte N66
	.byte An3
	.byte W72
	.byte VOICE, 1
	.byte N08
	.byte An3, Cn4
	.byte W08
	.byte Gn3
	.byte W08
	.byte An3, En4
	.byte W08
	.byte VOICE, 0
	.byte N48
	.byte As3
	.byte W48
	.byte VOICE, 1
	.byte N18
	.byte Fn3, Gs4
	.byte W24
	.byte N08
	.byte Fn3, Cn3
	.byte W08
	.byte As3
	.byte W08
	.byte Cn4
	.byte W08
	.byte VOICE, 0
	.byte N96
	.byte Dn4, Gs4
	.byte W96
	.byte N48
	.byte Cn4, Cn4
	.byte W48
	.byte Bn3, Cn3
	.byte W48
	.byte N66
	.byte Cn4, Gs4
	.byte W72
	.byte VOICE, 1
	.byte N08
	.byte Ds4
	.byte W08
	.byte Dn4
	.byte W08
	.byte Cn4
	.byte W08
	.byte N48
	.byte Dn4, Cn5
	.byte W48
	.byte VOICE, 1
	.byte N18
	.byte As3
	.byte W24
	.byte N08
	.byte W08
	.byte Dn4
	.byte W08
	.byte Fn4
	.byte W08
	.byte VOICE, 3
	.byte TIE
	.byte Fs4, En2
	.byte W96
	.byte W96
	.byte EOT
	.byte VOICE, 51
	.byte N96
	.byte Bn2
	.byte W96
	.byte Cn3, Gs2
	.byte W96
	.byte Bn2
	.byte W96
	.byte Cn3, Cn3
	.byte W96
	.byte Bn2, En3
	.byte W96
	.byte Cn3, Gs3
	.byte W96
	.byte VOICE, 51
	.byte TIE
	.byte Bn2, Cn4
	.byte W96
	.byte W48
	.byte EOT
	.byte W48
	.byte GOTO
		.word track_25_lbl_230096

	.byte FINE

track_25_1:
	.byte KEYSH, 0
track_25_lbl_2301a3:
	.byte VOICE, 2
	.byte VOL, 78
	.byte PAN, c_v-17
	.byte PRIO, 119
	.byte N48
	.byte Bn2, En2
	.byte W48
	.byte Dn3, Cn3
	.byte W48
track_25_lbl_2301b2:
	.byte N48
	.byte Cn3, Cn4
	.byte W48
	.byte Fn3, Gs4
	.byte W48
	.byte PEND
track_25_lbl_2301ba:
	.byte N48
	.byte Bn2, En2
	.byte W48
	.byte Dn3, Cn3
	.byte W48
	.byte PEND
	.byte PATT
		.word track_25_lbl_2301b2
	.byte PATT
		.word track_25_lbl_2301ba
	.byte PATT
		.word track_25_lbl_2301b2
	.byte N96
	.byte Bn2, En2
	.byte W96
	.byte N48
	.byte Cn3, Cn4
	.byte W48
	.byte Dn3, Gs4
	.byte W48
	.byte N72
	.byte En3
	.byte W72
	.byte VOICE, 1
	.byte N08
	.byte Cn3, Gs7
	.byte W08
	.byte Gn2
	.byte W08
	.byte Cn3
	.byte W08
track_25_lbl_2301e9:
	.byte VOICE, 2
	.byte N72
	.byte Fn3, Gs7
	.byte W72
	.byte VOICE, 1
	.byte N24
	.byte Dn3
	.byte W24
	.byte PEND
track_25_lbl_2301f5:
	.byte VOICE, 2
	.byte N72
	.byte En3, Gs7
	.byte W72
	.byte VOICE, 1
	.byte N08
	.byte Cn3
	.byte W08
	.byte Gn2
	.byte W08
	.byte Cn3
	.byte W08
	.byte PEND
	.byte PATT
		.word track_25_lbl_2301e9
	.byte PATT
		.word track_25_lbl_2301f5
	.byte PATT
		.word track_25_lbl_2301e9
	.byte VOICE, 2
	.byte N96
	.byte En3, Gs7
	.byte W96
	.byte Gn2
	.byte W96
	.byte VOICE, 1
	.byte N24
	.byte Fn3
	.byte W24
	.byte Cn3
	.byte W24
	.byte An2
	.byte W24
	.byte N08
	.byte Cn3
	.byte W08
	.byte As2
	.byte W08
	.byte Cn3
	.byte W08
	.byte N24
	.byte Dn3
	.byte W24
	.byte Fn3
	.byte W24
	.byte Cn3
	.byte W24
	.byte N16
	.byte W16
	.byte N08
	.byte W08
	.byte N24
	.byte Ds3
	.byte W24
	.byte An2
	.byte W24
	.byte Fn2
	.byte W24
	.byte N08
	.byte Cn2
	.byte W08
	.byte As1
	.byte W08
	.byte Cn2
	.byte W08
	.byte N24
	.byte Dn2
	.byte W24
	.byte Fn2
	.byte W24
	.byte As2
	.byte W24
	.byte N08
	.byte Cn3
	.byte W08
	.byte Fn3
	.byte W08
	.byte Gn3
	.byte W08
	.byte VOICE, 2
	.byte N48
	.byte Bn2
	.byte W48
	.byte An2
	.byte W48
	.byte Gn2
	.byte W48
	.byte Dn3
	.byte W48
	.byte VOICE, 1
	.byte N24
	.byte Ds3
	.byte W24
	.byte Fn3
	.byte W24
	.byte Gs2, Cn8
	.byte W24
	.byte N08
	.byte Gn2
	.byte W08
	.byte Fn2
	.byte W08
	.byte Ds2
	.byte W08
	.byte N24
	.byte Fn2
	.byte W24
	.byte As2, En8
	.byte W24
	.byte Gn2
	.byte W24
	.byte N08
	.byte Fn2, Gn8
	.byte W08
	.byte As2
	.byte W08
	.byte N08
	.byte W08
	.byte VOICE, 2
	.byte N96
	.byte Dn3
	.byte W96
	.byte N48
	.byte Bn2, Gs7
	.byte W48
	.byte Gn2
	.byte W48
	.byte VOICE, 4
	.byte N24
	.byte Gn1
	.byte W24
	.byte N08
	.byte W08
	.byte Dn1
	.byte W08
	.byte Gn1
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Dn1
	.byte W08
	.byte Gn1
	.byte W08
track_25_lbl_23029d:
	.byte N24
	.byte As1, Gs7
	.byte W24
	.byte N08
	.byte W08
	.byte Fn1
	.byte W08
	.byte As1
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Fn1
	.byte W08
	.byte As1
	.byte W08
	.byte PEND
track_25_lbl_2302b0:
	.byte N24
	.byte Gn1, Gs7
	.byte W24
	.byte N08
	.byte W08
	.byte Dn1
	.byte W08
	.byte Gn1
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Dn1
	.byte W08
	.byte Gn1
	.byte W08
	.byte PEND
	.byte PATT
		.word track_25_lbl_23029d
	.byte PATT
		.word track_25_lbl_2302b0
	.byte PATT
		.word track_25_lbl_23029d
	.byte PATT
		.word track_25_lbl_2302b0
	.byte PATT
		.word track_25_lbl_23029d
	.byte GOTO
		.word track_25_lbl_2301a3

	.byte FINE

track_25_2:
	.byte KEYSH, 0
track_25_lbl_2302e4:
	.byte VOICE, 10
	.byte VOL, 84
	.byte PAN, c_v
	.byte PRIO, 118
	.byte N24
	.byte Gn0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte Dn1
	.byte W08
	.byte Gn0
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Dn1
	.byte W08
	.byte Gn0
	.byte W08
track_25_lbl_2302fe:
	.byte N24
	.byte As0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte Fn1
	.byte W08
	.byte As0
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Fn1
	.byte W08
	.byte As0
	.byte W08
	.byte PEND
track_25_lbl_230311:
	.byte N24
	.byte Gn0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte Dn1
	.byte W08
	.byte Gn0
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Dn1
	.byte W08
	.byte Gn0
	.byte W08
	.byte PEND
	.byte PATT
		.word track_25_lbl_2302fe
	.byte PATT
		.word track_25_lbl_230311
	.byte PATT
		.word track_25_lbl_2302fe
track_25_lbl_230333:
	.byte N24
	.byte Gn0, Gn8
	.byte W24
	.byte N08
	.byte Dn1
	.byte W08
	.byte Gn0
	.byte W08
	.byte N08
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte Dn1
	.byte W08
	.byte Gn0
	.byte W08
	.byte N08
	.byte W08
	.byte PEND
	.byte PATT
		.word track_25_lbl_230333
track_25_lbl_23034d:
	.byte N08
	.byte Cn0, Gn8
	.byte W08
	.byte Gn0
	.byte W08
	.byte Cn0
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Gn0
	.byte W08
	.byte Cn0
	.byte W08
	.byte N24
	.byte W24
	.byte PEND
	.byte PATT
		.word track_25_lbl_23034d
	.byte PATT
		.word track_25_lbl_23034d
	.byte PATT
		.word track_25_lbl_23034d
	.byte PATT
		.word track_25_lbl_23034d
	.byte PATT
		.word track_25_lbl_23034d
	.byte PATT
		.word track_25_lbl_23034d
	.byte PATT
		.word track_25_lbl_23034d
	.byte N24
	.byte Ds0, Gn8
	.byte W24
	.byte N24
	.byte W24
	.byte N24
	.byte W24
	.byte N24
	.byte W24
track_25_lbl_23038d:
	.byte N24
	.byte Dn0, Gn8
	.byte W24
	.byte N24
	.byte W24
	.byte N24
	.byte W24
	.byte N24
	.byte W24
	.byte PEND
	.byte Ds0
	.byte W24
	.byte Cs0
	.byte W24
	.byte Ds0
	.byte W24
	.byte N24
	.byte W24
	.byte PATT
		.word track_25_lbl_23038d
	.byte N24
	.byte Gn0, Gn8
	.byte W24
	.byte GnM1
	.byte W24
	.byte AnM1
	.byte W24
	.byte BnM1
	.byte W24
	.byte Dn0
	.byte W24
	.byte En0
	.byte W24
	.byte Fn0
	.byte W24
	.byte Gn0
	.byte W24
	.byte Gs0
	.byte W24
	.byte N08
	.byte W08
	.byte Ds0
	.byte W08
	.byte Cn0
	.byte W08
	.byte N24
	.byte GsM1
	.byte W24
	.byte N08
	.byte Cn1
	.byte W08
	.byte As0
	.byte W08
	.byte Gs0
	.byte W08
	.byte N24
	.byte Fn0
	.byte W24
	.byte Ds0
	.byte W24
	.byte Dn0
	.byte W24
	.byte Cn0
	.byte W24
	.byte An0
	.byte W24
	.byte N24
	.byte W24
	.byte N24
	.byte W24
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
track_25_lbl_2303f2:
	.byte N24
	.byte Gn0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte Dn0
	.byte W08
	.byte Gn0
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Dn0
	.byte W08
	.byte Gn0
	.byte W08
	.byte PEND
track_25_lbl_230405:
	.byte N24
	.byte As0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte Fn0
	.byte W08
	.byte As0
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte Fn0
	.byte W08
	.byte As0
	.byte W08
	.byte PEND
	.byte PATT
		.word track_25_lbl_2303f2
	.byte PATT
		.word track_25_lbl_230405
	.byte PATT
		.word track_25_lbl_2303f2
	.byte PATT
		.word track_25_lbl_230405
	.byte PATT
		.word track_25_lbl_2303f2
	.byte PATT
		.word track_25_lbl_230405
	.byte GOTO
		.word track_25_lbl_2302e4

	.byte FINE

track_25_3:
	.byte KEYSH, 0
track_25_lbl_23043e:
	.byte VOICE, 51
	.byte VOL, 39
	.byte PAN, c_v
	.byte PRIO, 30
	.byte N72
	.byte Dn3, Cn6
	.byte W96
	.byte Cn3
	.byte W96
	.byte Dn3
	.byte W96
	.byte Cn3
	.byte W96
	.byte Dn3
	.byte W96
	.byte Cn3
	.byte W96
	.byte N96
	.byte Dn3
	.byte W96
	.byte N48
	.byte W48
	.byte N42
	.byte W48
	.byte N84
	.byte Gn3, Cn3
	.byte W96
	.byte N88
	.byte Fn3, Gs2
	.byte W96
	.byte N80
	.byte Gn3, Cn3
	.byte W96
	.byte N90
	.byte Fn3, Gs2
	.byte W96
	.byte N80
	.byte Gn3, Cn3
	.byte W96
	.byte N76
	.byte Fn3, Gs2
	.byte W96
	.byte N80
	.byte Gn3, Cn3
	.byte W96
	.byte Gn3, Gs2
	.byte W96
	.byte N78
	.byte Fn3, En2
	.byte W96
	.byte N80
	.byte Fn3, Cn3
	.byte W96
	.byte N78
	.byte Fn3, Gs3
	.byte W96
	.byte N80
	.byte Fn3, En4
	.byte W96
	.byte N84
	.byte Dn3, Cn3
	.byte W96
	.byte N48
	.byte Dn3, En4
	.byte W48
	.byte Dn3, Gs4
	.byte W48
	.byte N96
	.byte Cn3, Cn6
	.byte W96
	.byte As2
	.byte W96
	.byte VOICE, 14
	.byte TIE
	.byte An3
	.byte W96
	.byte W84
	.byte EOT
	.byte W12
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_25_lbl_23043e

	.byte FINE

track_25_4:
	.byte KEYSH, 0
track_25_lbl_2304b3:
	.byte VOICE, 51
	.byte VOL, 39
	.byte PAN, c_v
	.byte PRIO, 27
	.byte N72
	.byte Bn2, Cn6
	.byte W96
	.byte Fn2
	.byte W96
	.byte Bn2
	.byte W96
	.byte Fn2
	.byte W96
	.byte Bn2
	.byte W96
	.byte Fn2
	.byte W96
	.byte N96
	.byte Bn2
	.byte W96
	.byte N48
	.byte Cn3
	.byte W48
	.byte N42
	.byte Bn2
	.byte W48
	.byte N88
	.byte En3, Cn3
	.byte W96
	.byte Dn3, Gs2
	.byte W96
	.byte N84
	.byte En3, Cn3
	.byte W96
	.byte N88
	.byte Dn3, Gs2
	.byte W96
	.byte N84
	.byte En3, Cn3
	.byte W96
	.byte N78
	.byte Dn3, Gs2
	.byte W96
	.byte N84
	.byte En3, Cn3
	.byte W96
	.byte En3, Gs2
	.byte W96
	.byte N80
	.byte Cn3, En2
	.byte W96
	.byte As2, Cn3
	.byte W96
	.byte N78
	.byte Cn3, Gs3
	.byte W96
	.byte N80
	.byte As2, En4
	.byte W96
	.byte N84
	.byte Gn2, Cn3
	.byte W96
	.byte N48
	.byte Cn3, En4
	.byte W48
	.byte Gn2, Gs4
	.byte W48
	.byte N96
	.byte Fn2, Cn6
	.byte W96
	.byte Gn2
	.byte W96
	.byte VOICE, 14
	.byte TIE
	.byte Dn3
	.byte W96
	.byte W84
	.byte EOT
	.byte W12
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_25_lbl_2304b3

	.byte FINE

track_25_5:
	.byte KEYSH, 0
track_25_lbl_230528:
	.byte VOICE, 16
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 29
	.byte N08
	.byte En3, En2
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
track_25_lbl_230542:
	.byte N08
	.byte En3, En2
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte PEND
track_25_lbl_230559:
	.byte N08
	.byte En3, En2
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte PEND
	.byte PATT
		.word track_25_lbl_230542
	.byte PATT
		.word track_25_lbl_230559
track_25_lbl_230576:
	.byte N08
	.byte En3, En2
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte PEND
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N48
	.byte Dn2
	.byte N08
	.byte En3
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte PATT
		.word track_25_lbl_230576
track_25_lbl_2305a1:
	.byte N08
	.byte En3, En2
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W32
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte PEND
track_25_lbl_2305b4:
	.byte N08
	.byte En3, En2
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W32
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W32
	.byte PEND
	.byte PATT
		.word track_25_lbl_2305a1
	.byte PATT
		.word track_25_lbl_2305b4
	.byte PATT
		.word track_25_lbl_2305a1
	.byte PATT
		.word track_25_lbl_2305b4
	.byte PATT
		.word track_25_lbl_2305a1
	.byte PATT
		.word track_25_lbl_2305b4
track_25_lbl_2305e1:
	.byte N08
	.byte En3, En2
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte PEND
	.byte PATT
		.word track_25_lbl_2305b4
	.byte PATT
		.word track_25_lbl_2305e1
	.byte PATT
		.word track_25_lbl_2305b4
	.byte PATT
		.word track_25_lbl_2305e1
	.byte PATT
		.word track_25_lbl_2305e1
	.byte PATT
		.word track_25_lbl_2305e1
	.byte PATT
		.word track_25_lbl_2305e1
	.byte PATT
		.word track_25_lbl_2305e1
	.byte N08
	.byte En3, En2
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte En3, GsM1
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte En3, Cn0
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte En3, En0
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte En3, Gs0
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte En3, Cn1
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W16
	.byte En3, En1
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W16
	.byte En3, Gs1
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W16
	.byte En3, Cn2
	.byte W08
	.byte N08
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte En3, En2
	.byte W24
	.byte GOTO
		.word track_25_lbl_230528

	.byte FINE

track_25_6:
	.byte KEYSH, 0
track_25_lbl_2306c1:
	.byte VOICE, 92
	.byte VOL, 84
	.byte PAN, c_v
	.byte PRIO, 26
	.byte W48
	.byte N36
	.byte Cn3, Gn8
	.byte W48
	.byte W48
	.byte N36
	.byte W48
	.byte W48
	.byte N36
	.byte W48
	.byte W48
	.byte N36
	.byte W48
	.byte W48
	.byte N36
	.byte W48
	.byte W48
	.byte N36
	.byte W48
	.byte W48
	.byte N36
	.byte W48
	.byte W96
	.byte W48
	.byte N24
	.byte W48
	.byte W48
	.byte N24
	.byte W48
	.byte W48
	.byte N24
	.byte W48
	.byte W96
	.byte W48
	.byte N24
	.byte W48
	.byte W48
	.byte N24
	.byte W48
	.byte W48
	.byte N24
	.byte W48
	.byte W96
	.byte W72
	.byte N24
	.byte W24
	.byte W72
	.byte N24
	.byte W24
	.byte W72
	.byte N24
	.byte W24
	.byte W72
	.byte N24
	.byte W24
	.byte W72
	.byte N24
	.byte W24
	.byte W72
	.byte N24
	.byte W24
	.byte W24
	.byte N24
	.byte W72
	.byte W24
	.byte N24
	.byte W72
	.byte W24
	.byte N24
	.byte W72
	.byte W24
	.byte N24
	.byte W48
	.byte N24
	.byte W24
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte GOTO
		.word track_25_lbl_2306c1

	.byte FINE

track_25_7:
	.byte KEYSH, 0
track_25_lbl_23073c:
	.byte VOICE, 25
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 28
	.byte N36
	.byte Cn3, Cn6
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W96
	.byte Cn3, Gn8
	.byte W96
	.byte Cn3, Cn6
	.byte W96
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte Cn3, Gs6
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W48
	.byte Cn3, Cn6
	.byte W48
	.byte Cn3, Gs6
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W48
	.byte Cn3, En6
	.byte W48
	.byte N36
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W96
	.byte N36
	.byte W96
	.byte W02
	.byte Cn3, En7
	.byte W92
	.byte W02
	.byte W01
	.byte Cn3, Cn8
	.byte W92
	.byte W03
	.byte W02
	.byte Cn3, En7
	.byte W48
	.byte N36
	.byte W44
	.byte W02
	.byte W01
	.byte Cn3, Cn8
	.byte W44
	.byte W03
	.byte N24
	.byte Cn3, Gn8
	.byte W48
	.byte W02
	.byte N36
	.byte Cn3, En7
	.byte W44
	.byte W03
	.byte Cn3, En6
	.byte W44
	.byte W03
	.byte W01
	.byte N36
	.byte W48
	.byte N36
	.byte W44
	.byte W03
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte Cn3, Cn6
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_25_lbl_23073c

	.byte FINE

.align 2

track_25:
	.byte 8
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_25_0
	.word track_25_1
	.word track_25_2
	.word track_25_3
	.word track_25_4
	.word track_25_5
	.word track_25_6
	.word track_25_7

.align 2
