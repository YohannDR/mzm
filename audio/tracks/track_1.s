.align 2

.global track_1

track_1_0:
	.byte KEYSH, 0
	.byte TEMPO, 72
	.byte VOICE, 13
	.byte VOL, 70
	.byte PAN, c_v
	.byte N96
	.byte Bn3, En2
	.byte W96
	.byte Cn4, Cn3
	.byte W96
	.byte Bn3, En2
	.byte W96
	.byte Cn4, Cn3
	.byte W96
track_1_lbl_22b9a7:
	.byte VOICE, 13
	.byte N96
	.byte Bn3, En2
	.byte W96
	.byte Cn4, Cn3
	.byte W96
	.byte VOICE, 14
	.byte TIE
	.byte Bn3, En2
	.byte W96
	.byte W48
	.byte EOT
	.byte W48
track_1_lbl_22b9b9:
	.byte VOICE, 0
	.byte N84
	.byte Gn3, Cn3
	.byte W96
	.byte PEND
track_1_lbl_22b9c0:
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
	.byte PATT
		.word track_1_lbl_22b9b9
	.byte PATT
		.word track_1_lbl_22b9c0
	.byte PATT
		.word track_1_lbl_22b9b9
	.byte PATT
		.word track_1_lbl_22b9c0
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
		.word track_1_lbl_22b9c0
	.byte VOICE, 0
	.byte N66
	.byte Cn4, Cn3
	.byte W72
	.byte N24
	.byte Gn3, Gs3
	.byte W24
	.byte PATT
		.word track_1_lbl_22b9c0
	.byte VOICE, 0
	.byte N72
	.byte Cn4, Cn3
	.byte W72
	.byte N24
	.byte Gn3, Gs3
	.byte W24
	.byte PATT
		.word track_1_lbl_22b9c0
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
	.byte VOICE, 13
	.byte N96
	.byte Bn3
	.byte W96
	.byte Cn4, Gs2
	.byte W96
	.byte Bn3
	.byte W96
	.byte Cn4, Cn3
	.byte W96
	.byte Bn3, En3
	.byte W96
	.byte Cn4, Gs3
	.byte W96
	.byte VOICE, 14
	.byte TIE
	.byte Bn3, Cn4
	.byte W96
	.byte W48
	.byte EOT
	.byte W48
	.byte N96
	.byte Bn3, Gs5
	.byte W96
	.byte Cn4, Cn6
	.byte W96
	.byte Bn3
	.byte W96
	.byte Cn4
	.byte W96
	.byte GOTO
		.word track_1_lbl_22b9a7

	.byte FINE

track_1_1:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 70
	.byte PAN, c_v+15
	.byte N24
	.byte Gn1, Gn8
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
track_1_lbl_22bae0:
	.byte N24
	.byte As1, Gn8
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
track_1_lbl_22baf3:
	.byte N24
	.byte Gn1, Gn8
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
		.word track_1_lbl_22bae0
track_1_lbl_22bb0b:
	.byte PATT
		.word track_1_lbl_22baf3
	.byte PATT
		.word track_1_lbl_22bae0
	.byte PATT
		.word track_1_lbl_22baf3
	.byte PATT
		.word track_1_lbl_22bae0
	.byte VOICE, 2
	.byte VOL, 70
	.byte PAN, c_v+15
	.byte N48
	.byte Bn2, En2
	.byte W48
	.byte Dn3, Cn3
	.byte W48
track_1_lbl_22bb2c:
	.byte N48
	.byte Cn3, Cn4
	.byte W48
	.byte Fn3, Gs4
	.byte W48
	.byte PEND
track_1_lbl_22bb34:
	.byte N48
	.byte Bn2, En2
	.byte W48
	.byte Dn3, Cn3
	.byte W48
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bb2c
	.byte PATT
		.word track_1_lbl_22bb34
	.byte PATT
		.word track_1_lbl_22bb2c
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
track_1_lbl_22bb63:
	.byte VOICE, 2
	.byte N72
	.byte Fn3, Gs7
	.byte W72
	.byte VOICE, 1
	.byte N24
	.byte Dn3
	.byte W24
	.byte PEND
track_1_lbl_22bb6f:
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
		.word track_1_lbl_22bb63
	.byte PATT
		.word track_1_lbl_22bb6f
	.byte PATT
		.word track_1_lbl_22bb63
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
track_1_lbl_22bc17:
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
track_1_lbl_22bc2a:
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
		.word track_1_lbl_22bc17
	.byte PATT
		.word track_1_lbl_22bc2a
	.byte PATT
		.word track_1_lbl_22bc17
	.byte PATT
		.word track_1_lbl_22bc2a
	.byte PATT
		.word track_1_lbl_22bc17
	.byte PATT
		.word track_1_lbl_22bc2a
	.byte PATT
		.word track_1_lbl_22bc17
	.byte PATT
		.word track_1_lbl_22bc2a
	.byte PATT
		.word track_1_lbl_22bc17
	.byte GOTO
		.word track_1_lbl_22bb0b

	.byte FINE

track_1_2:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 78
	.byte PAN, c_v
	.byte N24
	.byte Gn0, En6
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
track_1_lbl_22bc8a:
	.byte N24
	.byte As0, En6
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
track_1_lbl_22bc9d:
	.byte N24
	.byte Gn0, En6
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
	.byte PATT
		.word track_1_lbl_22bc8a
track_1_lbl_22bcb5:
	.byte PATT
		.word track_1_lbl_22bc9d
	.byte PATT
		.word track_1_lbl_22bc8a
	.byte PATT
		.word track_1_lbl_22bc9d
	.byte PATT
		.word track_1_lbl_22bc8a
track_1_lbl_22bcc9:
	.byte N24
	.byte Gn0, En6
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
track_1_lbl_22bcdc:
	.byte N24
	.byte As0, En6
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
	.byte PATT
		.word track_1_lbl_22bcc9
	.byte PATT
		.word track_1_lbl_22bcdc
	.byte PATT
		.word track_1_lbl_22bcc9
	.byte PATT
		.word track_1_lbl_22bcdc
track_1_lbl_22bd03:
	.byte N24
	.byte Gn0, En6
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
		.word track_1_lbl_22bd03
track_1_lbl_22bd1d:
	.byte N08
	.byte Cn0, En6
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
		.word track_1_lbl_22bd1d
	.byte PATT
		.word track_1_lbl_22bd1d
	.byte PATT
		.word track_1_lbl_22bd1d
	.byte PATT
		.word track_1_lbl_22bd1d
	.byte PATT
		.word track_1_lbl_22bd1d
	.byte PATT
		.word track_1_lbl_22bd1d
	.byte PATT
		.word track_1_lbl_22bd1d
	.byte N24
	.byte Ds0, En6
	.byte W24
	.byte N24
	.byte W24
	.byte N24
	.byte W24
	.byte N24
	.byte W24
track_1_lbl_22bd5d:
	.byte N24
	.byte Dn0, En6
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
		.word track_1_lbl_22bd5d
	.byte N24
	.byte Gn0, En6
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
	.byte PATT
		.word track_1_lbl_22bc9d
	.byte PATT
		.word track_1_lbl_22bc8a
	.byte PATT
		.word track_1_lbl_22bc9d
	.byte PATT
		.word track_1_lbl_22bc8a
	.byte PATT
		.word track_1_lbl_22bc9d
	.byte PATT
		.word track_1_lbl_22bc8a
	.byte PATT
		.word track_1_lbl_22bc9d
	.byte PATT
		.word track_1_lbl_22bc8a
	.byte PATT
		.word track_1_lbl_22bc9d
	.byte PATT
		.word track_1_lbl_22bc8a
	.byte PATT
		.word track_1_lbl_22bc9d
	.byte PATT
		.word track_1_lbl_22bc8a
	.byte GOTO
		.word track_1_lbl_22bcb5

	.byte FINE

track_1_3:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 47
	.byte PAN, c_v-22
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_1_lbl_22be10:
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 13
	.byte N72
	.byte Dn4, Cn6
	.byte W96
	.byte Cn4
	.byte W96
	.byte Dn4
	.byte W96
	.byte Cn4
	.byte W96
	.byte Dn4
	.byte W96
	.byte Cn4
	.byte W96
	.byte N96
	.byte Dn4
	.byte W96
	.byte N48
	.byte W48
	.byte N42
	.byte W48
	.byte N84
	.byte Gn4, Cn3
	.byte W96
	.byte N88
	.byte Fn4, Gs2
	.byte W96
	.byte N80
	.byte Gn4, Cn3
	.byte W96
	.byte N90
	.byte Fn4, Gs2
	.byte W96
	.byte N80
	.byte Gn4, Cn3
	.byte W96
	.byte N76
	.byte Fn4, Gs2
	.byte W96
	.byte N80
	.byte Gn4, Cn3
	.byte W96
	.byte Gn4, Gs2
	.byte W96
	.byte N78
	.byte Fn4, En2
	.byte W96
	.byte N80
	.byte Fn4, Cn3
	.byte W96
	.byte N78
	.byte Fn4, Gs3
	.byte W96
	.byte N80
	.byte Fn4, En4
	.byte W96
	.byte N84
	.byte Dn4, Cn3
	.byte W96
	.byte N48
	.byte Dn4, En4
	.byte W48
	.byte Dn4, Gs4
	.byte W48
	.byte N96
	.byte Cn4, Cn6
	.byte W96
	.byte As3
	.byte W96
	.byte VOICE, 14
	.byte TIE
	.byte An4
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
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_1_lbl_22be10

	.byte FINE

track_1_4:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 47
	.byte PAN, c_v+20
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_1_lbl_22be91:
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 13
	.byte N72
	.byte Bn3, Cn6
	.byte W96
	.byte Fn3
	.byte W96
	.byte Bn3
	.byte W96
	.byte Fn3
	.byte W96
	.byte Bn3
	.byte W96
	.byte Fn3
	.byte W96
	.byte N96
	.byte Bn3
	.byte W96
	.byte N48
	.byte Cn4
	.byte W48
	.byte N42
	.byte Bn3
	.byte W48
	.byte N88
	.byte En4, Cn3
	.byte W96
	.byte Dn4, Gs2
	.byte W96
	.byte N84
	.byte En4, Cn3
	.byte W96
	.byte N88
	.byte Dn4, Gs2
	.byte W96
	.byte N84
	.byte En4, Cn3
	.byte W96
	.byte N78
	.byte Dn4, Gs2
	.byte W96
	.byte N84
	.byte En4, Cn3
	.byte W96
	.byte En4, Gs2
	.byte W96
	.byte N80
	.byte Cn4, En2
	.byte W96
	.byte As3, Cn3
	.byte W96
	.byte N78
	.byte Cn4, Gs3
	.byte W96
	.byte N80
	.byte As3, En4
	.byte W96
	.byte N84
	.byte Gn3, Cn3
	.byte W96
	.byte N48
	.byte Cn4, En4
	.byte W48
	.byte Gn3, Gs4
	.byte W48
	.byte N96
	.byte Fn3, Cn6
	.byte W96
	.byte Gn3
	.byte W96
	.byte VOICE, 14
	.byte TIE
	.byte Dn4
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
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_1_lbl_22be91

	.byte FINE

track_1_5:
	.byte KEYSH, 0
	.byte VOICE, 16
	.byte VOL, 70
	.byte PAN, c_v
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_1_lbl_22bf12:
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_1_lbl_22bf16:
	.byte N24
	.byte Gn1, Cn4
	.byte W48
	.byte Gn1, Gs5
	.byte W48
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
track_1_lbl_22bf41:
	.byte W24
	.byte N24
	.byte Gn1, Cn4
	.byte W48
	.byte Gn1, Gs5
	.byte W24
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf41
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
track_1_lbl_22bf8b:
	.byte N24
	.byte Gn1, Cn4
	.byte W24
	.byte N24
	.byte W24
	.byte Gn1, Gs5
	.byte W24
	.byte N24
	.byte W24
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bf8b
track_1_lbl_22bf9c:
	.byte N24
	.byte Gn1, Cn4
	.byte W24
	.byte N24
	.byte W24
	.byte Gn1, Gs5
	.byte W24
	.byte Gn1, Cn4
	.byte W24
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bf9c
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte PATT
		.word track_1_lbl_22bf16
	.byte GOTO
		.word track_1_lbl_22bf12

	.byte FINE

track_1_6:
	.byte KEYSH, 0
	.byte VOICE, 16
	.byte VOL, 55
	.byte PAN, c_v
	.byte N08
	.byte En3, GsM1
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte En3, Cn0
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
	.byte En3, Gs0
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
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
track_1_lbl_22c046:
	.byte N08
	.byte En3, Cn1
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
	.byte En3, En1
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
	.byte N08
	.byte W16
	.byte En3, Gs1
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
	.byte N08
	.byte W16
	.byte En3, Cn2
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
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte En3, En2
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte VOL, 55
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
	.byte N08
	.byte W16
	.byte N08
	.byte W08
	.byte N08
	.byte W24
track_1_lbl_22c0a6:
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
track_1_lbl_22c0bd:
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
		.word track_1_lbl_22c0a6
	.byte PATT
		.word track_1_lbl_22c0bd
track_1_lbl_22c0da:
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
		.word track_1_lbl_22c0da
track_1_lbl_22c105:
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
track_1_lbl_22c118:
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
		.word track_1_lbl_22c105
	.byte PATT
		.word track_1_lbl_22c118
	.byte PATT
		.word track_1_lbl_22c105
	.byte PATT
		.word track_1_lbl_22c118
	.byte PATT
		.word track_1_lbl_22c105
	.byte PATT
		.word track_1_lbl_22c118
track_1_lbl_22c145:
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
		.word track_1_lbl_22c118
	.byte PATT
		.word track_1_lbl_22c145
	.byte PATT
		.word track_1_lbl_22c118
	.byte PATT
		.word track_1_lbl_22c145
	.byte PATT
		.word track_1_lbl_22c145
	.byte PATT
		.word track_1_lbl_22c145
	.byte PATT
		.word track_1_lbl_22c145
	.byte PATT
		.word track_1_lbl_22c145
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
	.byte PATT
		.word track_1_lbl_22c0bd
	.byte PATT
		.word track_1_lbl_22c0a6
	.byte PATT
		.word track_1_lbl_22c0bd
	.byte PATT
		.word track_1_lbl_22c0a6
	.byte GOTO
		.word track_1_lbl_22c046

	.byte FINE

.align 2

track_1:
	.byte 7
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_1_0
	.word track_1_1
	.word track_1_2
	.word track_1_3
	.word track_1_4
	.word track_1_5
	.word track_1_6

.align 2
