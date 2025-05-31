.align 2

.global track_1

track_1_0:
	.byte KEYSH, 0
	.byte TEMPO, 72
	.byte VOICE, 13
	.byte VOL, 70
	.byte PAN, c_v
	.byte N96, Bn3, v052
	.byte W96
	.byte Cn4, v060 @ N96
	.byte W96
	.byte Bn3, v052 @ N96
	.byte W96
	.byte Cn4, v060 @ N96
	.byte W96
track_1_lbl_22b9a7:
	.byte VOICE, 13
	.byte N96, Bn3, v052
	.byte W96
	.byte Cn4, v060 @ N96
	.byte W96
	.byte VOICE, 14
	.byte TIE, Bn3, v052
	.byte W96
	.byte W48
	.byte EOT @ Bn3, v052
	.byte W48
track_1_lbl_22b9b9:
	.byte VOICE, 0
	.byte N84, Gn3, v060
	.byte W96
	.byte PEND
track_1_lbl_22b9c0:
	.byte N66, As3, v072
	.byte W72
	.byte VOICE, 1
	.byte N06, An3, v080
	.byte W06
	.byte As3 @ N06, v080
	.byte W06
	.byte An3 @ N06, v080
	.byte W06
	.byte Fn3 @ N06, v080
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
	.byte TIE, Gn3, v080
	.byte W96
	.byte W72
	.byte EOT @ Gn3, v080
	.byte W24
	.byte N66, Cn4, v060
	.byte W72
	.byte N24, Gn3, v068
	.byte W24
	.byte PATT
		.word track_1_lbl_22b9c0
	.byte VOICE, 0
	.byte N66, Cn4, v060
	.byte W72
	.byte N24, Gn3, v068
	.byte W24
	.byte PATT
		.word track_1_lbl_22b9c0
	.byte VOICE, 0
	.byte N72, Cn4, v060
	.byte W72
	.byte N24, Gn3, v068
	.byte W24
	.byte PATT
		.word track_1_lbl_22b9c0
	.byte VOICE, 0
	.byte N90, Gn3, v060
	.byte W96
	.byte En3, v080 @ N90
	.byte W96
	.byte N66, An3, v060
	.byte W72
	.byte VOICE, 1
	.byte N08, An3, v072
	.byte W08
	.byte Gn3 @ N08, v072
	.byte W08
	.byte An3 @ N08, v072
	.byte W08
	.byte VOICE, 0
	.byte N42, As3, v076
	.byte W48
	.byte VOICE, 1
	.byte N18, Fn3, v080
	.byte W24
	.byte N08, Cn3, v060
	.byte W08
	.byte Fn3 @ N08, v060
	.byte W08
	.byte Gn3, v064 @ N08
	.byte W08
	.byte VOICE, 0
	.byte N66, An3 @ v064
	.byte W72
	.byte VOICE, 1
	.byte N08, An3, v072
	.byte W08
	.byte Gn3 @ N08, v072
	.byte W08
	.byte An3, v076 @ N08
	.byte W08
	.byte VOICE, 0
	.byte N48, As3 @ v076
	.byte W48
	.byte VOICE, 1
	.byte N18, Fn3, v080
	.byte W24
	.byte N08, Fn3, v060
	.byte W08
	.byte As3 @ N08, v060
	.byte W08
	.byte Cn4 @ N08, v060
	.byte W08
	.byte VOICE, 0
	.byte N96, Dn4, v080
	.byte W96
	.byte N48, Cn4, v072
	.byte W48
	.byte Bn3, v060 @ N48
	.byte W48
	.byte N66, Cn4, v080
	.byte W72
	.byte VOICE, 1
	.byte N08, Ds4 @ v080
	.byte W08
	.byte Dn4 @ N08, v080
	.byte W08
	.byte Cn4 @ N08, v080
	.byte W08
	.byte N48, Dn4, v084
	.byte W48
	.byte VOICE, 1
	.byte N18, As3 @ v084
	.byte W24
	.byte N08 @ As3, v084
	.byte W08
	.byte Dn4 @ N08, v084
	.byte W08
	.byte Fn4 @ N08, v084
	.byte W08
	.byte VOICE, 3
	.byte TIE, Fs4, v052
	.byte W96
	.byte W96
	.byte EOT @ Fs4, v052
	.byte VOICE, 13
	.byte N96, Bn3 @ v052
	.byte W96
	.byte Cn4, v056 @ N96
	.byte W96
	.byte Bn3 @ N96, v056
	.byte W96
	.byte Cn4, v060 @ N96
	.byte W96
	.byte Bn3, v064 @ N96
	.byte W96
	.byte Cn4, v068 @ N96
	.byte W96
	.byte VOICE, 14
	.byte TIE, Bn3, v072
	.byte W96
	.byte W48
	.byte EOT @ Bn3, v072
	.byte W48
	.byte N96, Bn3, v092
	.byte W96
	.byte Cn4, v096 @ N96
	.byte W96
	.byte Bn3 @ N96, v096
	.byte W96
	.byte Cn4 @ N96, v096
	.byte W96
	.byte GOTO
		.word track_1_lbl_22b9a7
	.byte FINE

track_1_1:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 70
	.byte PAN, c_v+15
	.byte N24, Gn1, v127
	.byte W24
	.byte N08 @ Gn1, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte Gn1 @ N08, v127
	.byte W08
	.byte N24 @ Gn1, v127
	.byte W24
	.byte N08 @ Gn1, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte Gn1 @ N08, v127
	.byte W08
track_1_lbl_22bae0:
	.byte N24, As1, v127
	.byte W24
	.byte N08 @ As1, v127
	.byte W08
	.byte Fn1 @ N08, v127
	.byte W08
	.byte As1 @ N08, v127
	.byte W08
	.byte N24 @ As1, v127
	.byte W24
	.byte N08 @ As1, v127
	.byte W08
	.byte Fn1 @ N08, v127
	.byte W08
	.byte As1 @ N08, v127
	.byte W08
	.byte PEND
track_1_lbl_22baf3:
	.byte N24, Gn1, v127
	.byte W24
	.byte N08 @ Gn1, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte Gn1 @ N08, v127
	.byte W08
	.byte N24 @ Gn1, v127
	.byte W24
	.byte N08 @ Gn1, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte Gn1 @ N08, v127
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
	.byte N48, Bn2, v052
	.byte W48
	.byte Dn3, v060 @ N48
	.byte W48
track_1_lbl_22bb2c:
	.byte N48, Cn3, v072
	.byte W48
	.byte Fn3, v080 @ N48
	.byte W48
	.byte PEND
track_1_lbl_22bb34:
	.byte N48, Bn2, v052
	.byte W48
	.byte Dn3, v060 @ N48
	.byte W48
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bb2c
	.byte PATT
		.word track_1_lbl_22bb34
	.byte PATT
		.word track_1_lbl_22bb2c
	.byte N96, Bn2, v052
	.byte W96
	.byte N48, Cn3, v072
	.byte W48
	.byte Dn3, v080 @ N48
	.byte W48
	.byte N72, En3 @ v080
	.byte W72
	.byte VOICE, 1
	.byte N08, Cn3, v116
	.byte W08
	.byte Gn2 @ N08, v116
	.byte W08
	.byte Cn3 @ N08, v116
	.byte W08
track_1_lbl_22bb63:
	.byte VOICE, 2
	.byte N72, Fn3, v116
	.byte W72
	.byte VOICE, 1
	.byte N24, Dn3 @ v116
	.byte W24
	.byte PEND
track_1_lbl_22bb6f:
	.byte VOICE, 2
	.byte N72, En3, v116
	.byte W72
	.byte VOICE, 1
	.byte N08, Cn3 @ v116
	.byte W08
	.byte Gn2 @ N08, v116
	.byte W08
	.byte Cn3 @ N08, v116
	.byte W08
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bb63
	.byte PATT
		.word track_1_lbl_22bb6f
	.byte PATT
		.word track_1_lbl_22bb63
	.byte VOICE, 2
	.byte N96, En3, v116
	.byte W96
	.byte Gn2 @ N96, v116
	.byte W96
	.byte VOICE, 1
	.byte N24, Fn3 @ v116
	.byte W24
	.byte Cn3 @ N24, v116
	.byte W24
	.byte An2 @ N24, v116
	.byte W24
	.byte N08, Cn3 @ v116
	.byte W08
	.byte As2 @ N08, v116
	.byte W08
	.byte Cn3 @ N08, v116
	.byte W08
	.byte N24, Dn3 @ v116
	.byte W24
	.byte Fn3 @ N24, v116
	.byte W24
	.byte Cn3 @ N24, v116
	.byte W24
	.byte N16 @ Cn3, v116
	.byte W16
	.byte N08 @ Cn3, v116
	.byte W08
	.byte N24, Ds3 @ v116
	.byte W24
	.byte An2 @ N24, v116
	.byte W24
	.byte Fn2 @ N24, v116
	.byte W24
	.byte N08, Cn2 @ v116
	.byte W08
	.byte As1 @ N08, v116
	.byte W08
	.byte Cn2 @ N08, v116
	.byte W08
	.byte N24, Dn2 @ v116
	.byte W24
	.byte Fn2 @ N24, v116
	.byte W24
	.byte As2 @ N24, v116
	.byte W24
	.byte N08, Cn3 @ v116
	.byte W08
	.byte Fn3 @ N08, v116
	.byte W08
	.byte Gn3 @ N08, v116
	.byte W08
	.byte VOICE, 2
	.byte N48, Bn2 @ v116
	.byte W48
	.byte An2 @ N48, v116
	.byte W48
	.byte Gn2 @ N48, v116
	.byte W48
	.byte Dn3 @ N48, v116
	.byte W48
	.byte VOICE, 1
	.byte N24, Ds3 @ v116
	.byte W24
	.byte Fn3 @ N24, v116
	.byte W24
	.byte Gs2, v120 @ N24
	.byte W24
	.byte N08, Gn2 @ v120
	.byte W08
	.byte Fn2 @ N08, v120
	.byte W08
	.byte Ds2 @ N08, v120
	.byte W08
	.byte N24, Fn2 @ v120
	.byte W24
	.byte As2, v124 @ N24
	.byte W24
	.byte Gn2 @ N24, v124
	.byte W24
	.byte N08, Fn2, v127
	.byte W08
	.byte As2 @ N08, v127
	.byte W08
	.byte N08 @ As2, v127
	.byte W08
	.byte VOICE, 2
	.byte N96, Dn3 @ v127
	.byte W96
	.byte N48, Bn2, v116
	.byte W48
	.byte Gn2 @ N48, v116
	.byte W48
	.byte VOICE, 4
	.byte N24, Gn1 @ v116
	.byte W24
	.byte N08 @ Gn1, v116
	.byte W08
	.byte Dn1 @ N08, v116
	.byte W08
	.byte Gn1 @ N08, v116
	.byte W08
	.byte N24 @ Gn1, v116
	.byte W24
	.byte N08 @ Gn1, v116
	.byte W08
	.byte Dn1 @ N08, v116
	.byte W08
	.byte Gn1 @ N08, v116
	.byte W08
track_1_lbl_22bc17:
	.byte N24, As1, v116
	.byte W24
	.byte N08 @ As1, v116
	.byte W08
	.byte Fn1 @ N08, v116
	.byte W08
	.byte As1 @ N08, v116
	.byte W08
	.byte N24 @ As1, v116
	.byte W24
	.byte N08 @ As1, v116
	.byte W08
	.byte Fn1 @ N08, v116
	.byte W08
	.byte As1 @ N08, v116
	.byte W08
	.byte PEND
track_1_lbl_22bc2a:
	.byte N24, Gn1, v116
	.byte W24
	.byte N08 @ Gn1, v116
	.byte W08
	.byte Dn1 @ N08, v116
	.byte W08
	.byte Gn1 @ N08, v116
	.byte W08
	.byte N24 @ Gn1, v116
	.byte W24
	.byte N08 @ Gn1, v116
	.byte W08
	.byte Dn1 @ N08, v116
	.byte W08
	.byte Gn1 @ N08, v116
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
	.byte N24, Gn0, v100
	.byte W24
	.byte N08 @ Gn0, v100
	.byte W08
	.byte Dn0 @ N08, v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
	.byte N24 @ Gn0, v100
	.byte W24
	.byte N08 @ Gn0, v100
	.byte W08
	.byte Dn0 @ N08, v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
track_1_lbl_22bc8a:
	.byte N24, As0, v100
	.byte W24
	.byte N08 @ As0, v100
	.byte W08
	.byte Fn0 @ N08, v100
	.byte W08
	.byte As0 @ N08, v100
	.byte W08
	.byte N24 @ As0, v100
	.byte W24
	.byte N08 @ As0, v100
	.byte W08
	.byte Fn0 @ N08, v100
	.byte W08
	.byte As0 @ N08, v100
	.byte W08
	.byte PEND
track_1_lbl_22bc9d:
	.byte N24, Gn0, v100
	.byte W24
	.byte N08 @ Gn0, v100
	.byte W08
	.byte Dn0 @ N08, v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
	.byte N24 @ Gn0, v100
	.byte W24
	.byte N08 @ Gn0, v100
	.byte W08
	.byte Dn0 @ N08, v100
	.byte W08
	.byte Gn0 @ N08, v100
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
	.byte N24, Gn0, v100
	.byte W24
	.byte N08 @ Gn0, v100
	.byte W08
	.byte Dn1 @ N08, v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
	.byte N24 @ Gn0, v100
	.byte W24
	.byte N08 @ Gn0, v100
	.byte W08
	.byte Dn1 @ N08, v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
	.byte PEND
track_1_lbl_22bcdc:
	.byte N24, As0, v100
	.byte W24
	.byte N08 @ As0, v100
	.byte W08
	.byte Fn1 @ N08, v100
	.byte W08
	.byte As0 @ N08, v100
	.byte W08
	.byte N24 @ As0, v100
	.byte W24
	.byte N08 @ As0, v100
	.byte W08
	.byte Fn1 @ N08, v100
	.byte W08
	.byte As0 @ N08, v100
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
	.byte N24, Gn0, v100
	.byte W24
	.byte N08, Dn1 @ v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
	.byte N08 @ Gn0, v100
	.byte W08
	.byte N24 @ Gn0, v100
	.byte W24
	.byte N08, Dn1 @ v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
	.byte N08 @ Gn0, v100
	.byte W08
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bd03
track_1_lbl_22bd1d:
	.byte N08, Cn0, v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
	.byte Cn0 @ N08, v100
	.byte W08
	.byte N24 @ Cn0, v100
	.byte W24
	.byte N08 @ Cn0, v100
	.byte W08
	.byte Gn0 @ N08, v100
	.byte W08
	.byte Cn0 @ N08, v100
	.byte W08
	.byte N24 @ Cn0, v100
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
	.byte N24, Ds0, v100
	.byte W24
	.byte N24 @ Ds0, v100
	.byte W24
	.byte N24 @ Ds0, v100
	.byte W24
	.byte N24 @ Ds0, v100
	.byte W24
track_1_lbl_22bd5d:
	.byte N24, Dn0, v100
	.byte W24
	.byte N24 @ Dn0, v100
	.byte W24
	.byte N24 @ Dn0, v100
	.byte W24
	.byte N24 @ Dn0, v100
	.byte W24
	.byte PEND
	.byte Ds0 @ N24, v100
	.byte W24
	.byte Cs0 @ N24, v100
	.byte W24
	.byte Ds0 @ N24, v100
	.byte W24
	.byte N24 @ Ds0, v100
	.byte W24
	.byte PATT
		.word track_1_lbl_22bd5d
	.byte N24, Gn0, v100
	.byte W24
	.byte GnM1 @ N24, v100
	.byte W24
	.byte AnM1 @ N24, v100
	.byte W24
	.byte BnM1 @ N24, v100
	.byte W24
	.byte Dn0 @ N24, v100
	.byte W24
	.byte En0 @ N24, v100
	.byte W24
	.byte Fn0 @ N24, v100
	.byte W24
	.byte Gn0 @ N24, v100
	.byte W24
	.byte Gs0 @ N24, v100
	.byte W24
	.byte N08 @ Gs0, v100
	.byte W08
	.byte Ds0 @ N08, v100
	.byte W08
	.byte Cn0 @ N08, v100
	.byte W08
	.byte N24, GsM1 @ v100
	.byte W24
	.byte N08, Cn1 @ v100
	.byte W08
	.byte As0 @ N08, v100
	.byte W08
	.byte Gs0 @ N08, v100
	.byte W08
	.byte N24, Fn0 @ v100
	.byte W24
	.byte Ds0 @ N24, v100
	.byte W24
	.byte Dn0 @ N24, v100
	.byte W24
	.byte Cn0 @ N24, v100
	.byte W24
	.byte An0 @ N24, v100
	.byte W24
	.byte N24 @ An0, v100
	.byte W24
	.byte N24 @ An0, v100
	.byte W24
	.byte N24 @ An0, v100
	.byte W24
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
	.byte W08
	.byte N08 @ An0, v100
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
	.byte N72, Dn4, v096
	.byte W96
	.byte Cn4 @ N72, v096
	.byte W96
	.byte Dn4 @ N72, v096
	.byte W96
	.byte Cn4 @ N72, v096
	.byte W96
	.byte Dn4 @ N72, v096
	.byte W96
	.byte Cn4 @ N72, v096
	.byte W96
	.byte N96, Dn4 @ v096
	.byte W96
	.byte N48 @ Dn4, v096
	.byte W48
	.byte N42 @ Dn4, v096
	.byte W48
	.byte N84, Gn4, v060
	.byte W96
	.byte N88, Fn4, v056
	.byte W96
	.byte N80, Gn4, v060
	.byte W96
	.byte N90, Fn4, v056
	.byte W96
	.byte N80, Gn4, v060
	.byte W96
	.byte N76, Fn4, v056
	.byte W96
	.byte N80, Gn4, v060
	.byte W96
	.byte Gn4, v056 @ N80
	.byte W96
	.byte N78, Fn4, v052
	.byte W96
	.byte N80, Fn4, v060
	.byte W96
	.byte N78, Fn4, v068
	.byte W96
	.byte N80, Fn4, v076
	.byte W96
	.byte N84, Dn4, v060
	.byte W96
	.byte N48, Dn4, v076
	.byte W48
	.byte Dn4, v080 @ N48
	.byte W48
	.byte N96, Cn4, v096
	.byte W96
	.byte As3 @ N96, v096
	.byte W96
	.byte VOICE, 14
	.byte TIE, An4 @ v096
	.byte W96
	.byte W84
	.byte EOT @ An4, v096
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
	.byte N72, Bn3, v096
	.byte W96
	.byte Fn3 @ N72, v096
	.byte W96
	.byte Bn3 @ N72, v096
	.byte W96
	.byte Fn3 @ N72, v096
	.byte W96
	.byte Bn3 @ N72, v096
	.byte W96
	.byte Fn3 @ N72, v096
	.byte W96
	.byte N96, Bn3 @ v096
	.byte W96
	.byte N48, Cn4 @ v096
	.byte W48
	.byte N42, Bn3 @ v096
	.byte W48
	.byte N88, En4, v060
	.byte W96
	.byte Dn4, v056 @ N88
	.byte W96
	.byte N84, En4, v060
	.byte W96
	.byte N88, Dn4, v056
	.byte W96
	.byte N84, En4, v060
	.byte W96
	.byte N78, Dn4, v056
	.byte W96
	.byte N84, En4, v060
	.byte W96
	.byte En4, v056 @ N84
	.byte W96
	.byte N80, Cn4, v052
	.byte W96
	.byte As3, v060 @ N80
	.byte W96
	.byte N78, Cn4, v068
	.byte W96
	.byte N80, As3, v076
	.byte W96
	.byte N84, Gn3, v060
	.byte W96
	.byte N48, Cn4, v076
	.byte W48
	.byte Gn3, v080 @ N48
	.byte W48
	.byte N96, Fn3, v096
	.byte W96
	.byte Gn3 @ N96, v096
	.byte W96
	.byte VOICE, 14
	.byte TIE, Dn4 @ v096
	.byte W96
	.byte W84
	.byte EOT @ Dn4, v096
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
	.byte N24, Gn1, v072
	.byte W48
	.byte Gn1, v092 @ N24
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
	.byte N24, Gn1, v072
	.byte W48
	.byte Gn1, v092 @ N24
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
	.byte N24, Gn1, v072
	.byte W24
	.byte N24 @ Gn1, v072
	.byte W24
	.byte Gn1, v092 @ N24
	.byte W24
	.byte N24 @ Gn1, v092
	.byte W24
	.byte PEND
	.byte PATT
		.word track_1_lbl_22bf8b
track_1_lbl_22bf9c:
	.byte N24, Gn1, v072
	.byte W24
	.byte N24 @ Gn1, v072
	.byte W24
	.byte Gn1, v092 @ N24
	.byte W24
	.byte Gn1, v072 @ N24
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
	.byte N08, En3, v020
	.byte W16
	.byte N08 @ En3, v020
	.byte W08
	.byte N08 @ En3, v020
	.byte W08
	.byte En3, v024 @ N08
	.byte W08
	.byte N08 @ En3, v024
	.byte W08
	.byte N08 @ En3, v024
	.byte W16
	.byte N08 @ En3, v024
	.byte W08
	.byte N08 @ En3, v024
	.byte W24
	.byte N08 @ En3, v024
	.byte W16
	.byte N08 @ En3, v024
	.byte W08
	.byte N08 @ En3, v024
	.byte W08
	.byte En3, v028 @ N08
	.byte W08
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W16
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W16
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W08
	.byte En3, v032 @ N08
	.byte W08
	.byte N08 @ En3, v032
	.byte W16
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W24
	.byte N08 @ En3, v032
	.byte W16
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W08
	.byte En3, v036 @ N08
	.byte W16
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W08
track_1_lbl_22c046:
	.byte N08, En3, v036
	.byte W16
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W16
	.byte En3, v040 @ N08
	.byte W08
	.byte N08 @ En3, v040
	.byte W24
	.byte N08 @ En3, v040
	.byte W16
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W16
	.byte En3, v044 @ N08
	.byte W08
	.byte N08 @ En3, v044
	.byte W08
	.byte N08 @ En3, v044
	.byte W08
	.byte N08 @ En3, v044
	.byte W08
	.byte N08 @ En3, v044
	.byte W16
	.byte N08 @ En3, v044
	.byte W08
	.byte N08 @ En3, v044
	.byte W08
	.byte N08 @ En3, v044
	.byte W08
	.byte N08 @ En3, v044
	.byte W08
	.byte N08 @ En3, v044
	.byte W16
	.byte En3, v048 @ N08
	.byte W08
	.byte N08 @ En3, v048
	.byte W24
	.byte N08 @ En3, v048
	.byte W16
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W16
	.byte N08 @ En3, v048
	.byte W08
	.byte En3, v052 @ N08
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte VOL, 55
	.byte N08 @ En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W24
track_1_lbl_22c0a6:
	.byte N08, En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte PEND
track_1_lbl_22c0bd:
	.byte N08, En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W24
	.byte PEND
	.byte PATT
		.word track_1_lbl_22c0a6
	.byte PATT
		.word track_1_lbl_22c0bd
track_1_lbl_22c0da:
	.byte N08, En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W24
	.byte N08 @ En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte PEND
	.byte N08 @ En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N48, Dn2 @ v052
	.byte N08, En3 @ v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W24
	.byte PATT
		.word track_1_lbl_22c0da
track_1_lbl_22c105:
	.byte N08, En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W32
	.byte N08 @ En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte PEND
track_1_lbl_22c118:
	.byte N08, En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W32
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
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
	.byte N08, En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W16
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
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
	.byte N08, En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte N08 @ En3, v052
	.byte W08
	.byte En3, v020 @ N08
	.byte W16
	.byte N08 @ En3, v020
	.byte W08
	.byte N08 @ En3, v020
	.byte W24
	.byte En3, v024 @ N08
	.byte W16
	.byte N08 @ En3, v024
	.byte W08
	.byte N08 @ En3, v024
	.byte W24
	.byte N08 @ En3, v024
	.byte W08
	.byte N08 @ En3, v024
	.byte W08
	.byte N08 @ En3, v024
	.byte W08
	.byte N08 @ En3, v024
	.byte W08
	.byte En3, v028 @ N08
	.byte W08
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W16
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W24
	.byte N08 @ En3, v028
	.byte W16
	.byte N08 @ En3, v028
	.byte W08
	.byte N08 @ En3, v028
	.byte W24
	.byte En3, v032 @ N08
	.byte W16
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W24
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W08
	.byte N08 @ En3, v032
	.byte W08
	.byte En3, v036 @ N08
	.byte W16
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W24
	.byte N08 @ En3, v036
	.byte W16
	.byte N08 @ En3, v036
	.byte W08
	.byte N08 @ En3, v036
	.byte W24
	.byte N08 @ En3, v036
	.byte W16
	.byte En3, v040 @ N08
	.byte W08
	.byte N08 @ En3, v040
	.byte W24
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W08
	.byte N08 @ En3, v040
	.byte W16
	.byte En3, v044 @ N08
	.byte W08
	.byte N08 @ En3, v044
	.byte W24
	.byte N08 @ En3, v044
	.byte W16
	.byte N08 @ En3, v044
	.byte W08
	.byte N08 @ En3, v044
	.byte W24
	.byte N08 @ En3, v044
	.byte W16
	.byte En3, v048 @ N08
	.byte W08
	.byte N08 @ En3, v048
	.byte W24
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W08
	.byte N08 @ En3, v048
	.byte W16
	.byte N08 @ En3, v048
	.byte W08
	.byte En3, v052 @ N08
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
