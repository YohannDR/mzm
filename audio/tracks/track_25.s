.align 2

.global track_25

track_25_0:
	.byte KEYSH, 0
track_25_lbl_230096:
	.byte TEMPO, 79
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v+15
	.byte PRIO, 120
	.byte N84, Gn3, v060
	.byte W96
track_25_lbl_2300a4:
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
track_25_lbl_2300b5:
	.byte VOICE, 0
	.byte N84, Gn3, v060
	.byte W96
	.byte PEND
	.byte PATT
		.word track_25_lbl_2300a4
	.byte PATT
		.word track_25_lbl_2300b5
	.byte PATT
		.word track_25_lbl_2300a4
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
		.word track_25_lbl_2300a4
	.byte VOICE, 0
	.byte N66, Cn4, v060
	.byte W72
	.byte N24, Gn3, v068
	.byte W24
	.byte PATT
		.word track_25_lbl_2300a4
	.byte VOICE, 0
	.byte N72, Cn4, v060
	.byte W72
	.byte N24, Gn3, v068
	.byte W24
	.byte PATT
		.word track_25_lbl_2300a4
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
	.byte VOICE, 51
	.byte N96, Bn2 @ v052
	.byte W96
	.byte Cn3, v056 @ N96
	.byte W96
	.byte Bn2 @ N96, v056
	.byte W96
	.byte Cn3, v060 @ N96
	.byte W96
	.byte Bn2, v064 @ N96
	.byte W96
	.byte Cn3, v068 @ N96
	.byte W96
	.byte VOICE, 51
	.byte TIE, Bn2, v072
	.byte W96
	.byte W48
	.byte EOT @ Bn2, v072
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
	.byte N48, Bn2, v052
	.byte W48
	.byte Dn3, v060 @ N48
	.byte W48
track_25_lbl_2301b2:
	.byte N48, Cn3, v072
	.byte W48
	.byte Fn3, v080 @ N48
	.byte W48
	.byte PEND
track_25_lbl_2301ba:
	.byte N48, Bn2, v052
	.byte W48
	.byte Dn3, v060 @ N48
	.byte W48
	.byte PEND
	.byte PATT
		.word track_25_lbl_2301b2
	.byte PATT
		.word track_25_lbl_2301ba
	.byte PATT
		.word track_25_lbl_2301b2
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
track_25_lbl_2301e9:
	.byte VOICE, 2
	.byte N72, Fn3, v116
	.byte W72
	.byte VOICE, 1
	.byte N24, Dn3 @ v116
	.byte W24
	.byte PEND
track_25_lbl_2301f5:
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
		.word track_25_lbl_2301e9
	.byte PATT
		.word track_25_lbl_2301f5
	.byte PATT
		.word track_25_lbl_2301e9
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
track_25_lbl_23029d:
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
track_25_lbl_2302b0:
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
	.byte N24, Gn0, v127
	.byte W24
	.byte N08 @ Gn0, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte N24 @ Gn0, v127
	.byte W24
	.byte N08 @ Gn0, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
track_25_lbl_2302fe:
	.byte N24, As0, v127
	.byte W24
	.byte N08 @ As0, v127
	.byte W08
	.byte Fn1 @ N08, v127
	.byte W08
	.byte As0 @ N08, v127
	.byte W08
	.byte N24 @ As0, v127
	.byte W24
	.byte N08 @ As0, v127
	.byte W08
	.byte Fn1 @ N08, v127
	.byte W08
	.byte As0 @ N08, v127
	.byte W08
	.byte PEND
track_25_lbl_230311:
	.byte N24, Gn0, v127
	.byte W24
	.byte N08 @ Gn0, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte N24 @ Gn0, v127
	.byte W24
	.byte N08 @ Gn0, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte PEND
	.byte PATT
		.word track_25_lbl_2302fe
	.byte PATT
		.word track_25_lbl_230311
	.byte PATT
		.word track_25_lbl_2302fe
track_25_lbl_230333:
	.byte N24, Gn0, v127
	.byte W24
	.byte N08, Dn1 @ v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte N08 @ Gn0, v127
	.byte W08
	.byte N24 @ Gn0, v127
	.byte W24
	.byte N08, Dn1 @ v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte N08 @ Gn0, v127
	.byte W08
	.byte PEND
	.byte PATT
		.word track_25_lbl_230333
track_25_lbl_23034d:
	.byte N08, Cn0, v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte Cn0 @ N08, v127
	.byte W08
	.byte N24 @ Cn0, v127
	.byte W24
	.byte N08 @ Cn0, v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte Cn0 @ N08, v127
	.byte W08
	.byte N24 @ Cn0, v127
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
	.byte N24, Ds0, v127
	.byte W24
	.byte N24 @ Ds0, v127
	.byte W24
	.byte N24 @ Ds0, v127
	.byte W24
	.byte N24 @ Ds0, v127
	.byte W24
track_25_lbl_23038d:
	.byte N24, Dn0, v127
	.byte W24
	.byte N24 @ Dn0, v127
	.byte W24
	.byte N24 @ Dn0, v127
	.byte W24
	.byte N24 @ Dn0, v127
	.byte W24
	.byte PEND
	.byte Ds0 @ N24, v127
	.byte W24
	.byte Cs0 @ N24, v127
	.byte W24
	.byte Ds0 @ N24, v127
	.byte W24
	.byte N24 @ Ds0, v127
	.byte W24
	.byte PATT
		.word track_25_lbl_23038d
	.byte N24, Gn0, v127
	.byte W24
	.byte GnM1 @ N24, v127
	.byte W24
	.byte AnM1 @ N24, v127
	.byte W24
	.byte BnM1 @ N24, v127
	.byte W24
	.byte Dn0 @ N24, v127
	.byte W24
	.byte En0 @ N24, v127
	.byte W24
	.byte Fn0 @ N24, v127
	.byte W24
	.byte Gn0 @ N24, v127
	.byte W24
	.byte Gs0 @ N24, v127
	.byte W24
	.byte N08 @ Gs0, v127
	.byte W08
	.byte Ds0 @ N08, v127
	.byte W08
	.byte Cn0 @ N08, v127
	.byte W08
	.byte N24, GsM1 @ v127
	.byte W24
	.byte N08, Cn1 @ v127
	.byte W08
	.byte As0 @ N08, v127
	.byte W08
	.byte Gs0 @ N08, v127
	.byte W08
	.byte N24, Fn0 @ v127
	.byte W24
	.byte Ds0 @ N24, v127
	.byte W24
	.byte Dn0 @ N24, v127
	.byte W24
	.byte Cn0 @ N24, v127
	.byte W24
	.byte An0 @ N24, v127
	.byte W24
	.byte N24 @ An0, v127
	.byte W24
	.byte N24 @ An0, v127
	.byte W24
	.byte N24 @ An0, v127
	.byte W24
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
track_25_lbl_2303f2:
	.byte N24, Gn0, v127
	.byte W24
	.byte N08 @ Gn0, v127
	.byte W08
	.byte Dn0 @ N08, v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte N24 @ Gn0, v127
	.byte W24
	.byte N08 @ Gn0, v127
	.byte W08
	.byte Dn0 @ N08, v127
	.byte W08
	.byte Gn0 @ N08, v127
	.byte W08
	.byte PEND
track_25_lbl_230405:
	.byte N24, As0, v127
	.byte W24
	.byte N08 @ As0, v127
	.byte W08
	.byte Fn0 @ N08, v127
	.byte W08
	.byte As0 @ N08, v127
	.byte W08
	.byte N24 @ As0, v127
	.byte W24
	.byte N08 @ As0, v127
	.byte W08
	.byte Fn0 @ N08, v127
	.byte W08
	.byte As0 @ N08, v127
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
	.byte N72, Dn3, v096
	.byte W96
	.byte Cn3 @ N72, v096
	.byte W96
	.byte Dn3 @ N72, v096
	.byte W96
	.byte Cn3 @ N72, v096
	.byte W96
	.byte Dn3 @ N72, v096
	.byte W96
	.byte Cn3 @ N72, v096
	.byte W96
	.byte N96, Dn3 @ v096
	.byte W96
	.byte N48 @ Dn3, v096
	.byte W48
	.byte N42 @ Dn3, v096
	.byte W48
	.byte N84, Gn3, v060
	.byte W96
	.byte N88, Fn3, v056
	.byte W96
	.byte N80, Gn3, v060
	.byte W96
	.byte N90, Fn3, v056
	.byte W96
	.byte N80, Gn3, v060
	.byte W96
	.byte N76, Fn3, v056
	.byte W96
	.byte N80, Gn3, v060
	.byte W96
	.byte Gn3, v056 @ N80
	.byte W96
	.byte N78, Fn3, v052
	.byte W96
	.byte N80, Fn3, v060
	.byte W96
	.byte N78, Fn3, v068
	.byte W96
	.byte N80, Fn3, v076
	.byte W96
	.byte N84, Dn3, v060
	.byte W96
	.byte N48, Dn3, v076
	.byte W48
	.byte Dn3, v080 @ N48
	.byte W48
	.byte N96, Cn3, v096
	.byte W96
	.byte As2 @ N96, v096
	.byte W96
	.byte VOICE, 14
	.byte TIE, An3 @ v096
	.byte W96
	.byte W84
	.byte EOT @ An3, v096
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
	.byte N72, Bn2, v096
	.byte W96
	.byte Fn2 @ N72, v096
	.byte W96
	.byte Bn2 @ N72, v096
	.byte W96
	.byte Fn2 @ N72, v096
	.byte W96
	.byte Bn2 @ N72, v096
	.byte W96
	.byte Fn2 @ N72, v096
	.byte W96
	.byte N96, Bn2 @ v096
	.byte W96
	.byte N48, Cn3 @ v096
	.byte W48
	.byte N42, Bn2 @ v096
	.byte W48
	.byte N88, En3, v060
	.byte W96
	.byte Dn3, v056 @ N88
	.byte W96
	.byte N84, En3, v060
	.byte W96
	.byte N88, Dn3, v056
	.byte W96
	.byte N84, En3, v060
	.byte W96
	.byte N78, Dn3, v056
	.byte W96
	.byte N84, En3, v060
	.byte W96
	.byte En3, v056 @ N84
	.byte W96
	.byte N80, Cn3, v052
	.byte W96
	.byte As2, v060 @ N80
	.byte W96
	.byte N78, Cn3, v068
	.byte W96
	.byte N80, As2, v076
	.byte W96
	.byte N84, Gn2, v060
	.byte W96
	.byte N48, Cn3, v076
	.byte W48
	.byte Gn2, v080 @ N48
	.byte W48
	.byte N96, Fn2, v096
	.byte W96
	.byte Gn2 @ N96, v096
	.byte W96
	.byte VOICE, 14
	.byte TIE, Dn3 @ v096
	.byte W96
	.byte W84
	.byte EOT @ Dn3, v096
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
track_25_lbl_230542:
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
track_25_lbl_230559:
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
		.word track_25_lbl_230542
	.byte PATT
		.word track_25_lbl_230559
track_25_lbl_230576:
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
		.word track_25_lbl_230576
track_25_lbl_2305a1:
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
track_25_lbl_2305b4:
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
	.byte N36, Cn3, v127
	.byte W48
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte W96
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W48
	.byte W96
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W48
	.byte W96
	.byte W72
	.byte N24 @ Cn3, v127
	.byte W24
	.byte W72
	.byte N24 @ Cn3, v127
	.byte W24
	.byte W72
	.byte N24 @ Cn3, v127
	.byte W24
	.byte W72
	.byte N24 @ Cn3, v127
	.byte W24
	.byte W72
	.byte N24 @ Cn3, v127
	.byte W24
	.byte W72
	.byte N24 @ Cn3, v127
	.byte W24
	.byte W24
	.byte N24 @ Cn3, v127
	.byte W72
	.byte W24
	.byte N24 @ Cn3, v127
	.byte W72
	.byte W24
	.byte N24 @ Cn3, v127
	.byte W72
	.byte W24
	.byte N24 @ Cn3, v127
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W24
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
	.byte W48
	.byte N36 @ Cn3, v127
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
	.byte N36, Cn3, v096
	.byte W96
	.byte N36 @ Cn3, v096
	.byte W96
	.byte N36 @ Cn3, v096
	.byte W96
	.byte N36 @ Cn3, v096
	.byte W96
	.byte N36 @ Cn3, v096
	.byte W96
	.byte Cn3, v127 @ N36
	.byte W96
	.byte Cn3, v096 @ N36
	.byte W96
	.byte N36 @ Cn3, v096
	.byte W48
	.byte N36 @ Cn3, v096
	.byte W48
	.byte Cn3, v104 @ N36
	.byte W96
	.byte N36 @ Cn3, v104
	.byte W96
	.byte N36 @ Cn3, v104
	.byte W96
	.byte N36 @ Cn3, v104
	.byte W48
	.byte Cn3, v096 @ N36
	.byte W48
	.byte Cn3, v104 @ N36
	.byte W96
	.byte N36 @ Cn3, v104
	.byte W96
	.byte N36 @ Cn3, v104
	.byte W96
	.byte N36 @ Cn3, v104
	.byte W48
	.byte Cn3, v100 @ N36
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W96
	.byte N36 @ Cn3, v100
	.byte W96
	.byte N36 @ Cn3, v100
	.byte W96
	.byte N36 @ Cn3, v100
	.byte W96
	.byte W02
	.byte Cn3, v112 @ N36
	.byte W92
	.byte W02
	.byte W01
	.byte Cn3, v120 @ N36
	.byte W92
	.byte W03
	.byte W02
	.byte Cn3, v112 @ N36
	.byte W48
	.byte N36 @ Cn3, v112
	.byte W44
	.byte W02
	.byte W01
	.byte Cn3, v120 @ N36
	.byte W44
	.byte W03
	.byte N24, Cn3, v127
	.byte W48
	.byte W02
	.byte N36, Cn3, v112
	.byte W44
	.byte W03
	.byte Cn3, v100 @ N36
	.byte W44
	.byte W03
	.byte W01
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W44
	.byte W03
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte Cn3, v096 @ N36
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
