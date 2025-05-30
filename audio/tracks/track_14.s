.align 2

.global track_14

track_14_0:
	.byte KEYSH, 0
	.byte TEMPO, 28
	.byte PRIO, 120
	.byte W96
	.byte W96
track_14_lbl_22f06c:
	.byte VOICE, 29
	.byte VOL, 48
	.byte PAN, c_v+15
	.byte N44, Bn3, v080
	.byte W48
	.byte N24, Cn4, v076
	.byte W24
	.byte Gn3, v064 @ N24
	.byte W24
	.byte Gs3 @ N24, v064
	.byte W24
	.byte Fn3, v060 @ N24
	.byte W24
	.byte Gn3, v056 @ N24
	.byte W24
	.byte Ds3, v044 @ N24
	.byte W24
	.byte Fn3, v112 @ N24
	.byte W24
	.byte Dn3 @ N24, v112
	.byte W24
	.byte Ds3, v104 @ N24
	.byte W24
	.byte N96, Gn2, v127
	.byte W24
	.byte W96
	.byte N24, As3, v088
	.byte W24
	.byte Gs3 @ N24, v088
	.byte W24
	.byte N96, Gn3 @ v088
	.byte W48
	.byte W96
	.byte N24, Fn3, v104
	.byte W24
	.byte Dn3 @ N24, v104
	.byte W24
	.byte Ds3 @ N24, v104
	.byte W24
	.byte TIE, Gn2 @ v104
	.byte W24
	.byte W96
	.byte W24
	.byte EOT @ Gn2, v104
	.byte W72
	.byte N48, Dn4, v088
	.byte W48
	.byte N24, Ds4 @ v088
	.byte W24
	.byte Bn3 @ N24, v088
	.byte W24
	.byte Cn4 @ N24, v088
	.byte W24
	.byte Gn3 @ N24, v088
	.byte W24
	.byte As3 @ N24, v088
	.byte W24
	.byte Gs3 @ N24, v088
	.byte W24
	.byte N96, Gn3 @ v088
	.byte W96
	.byte W24
	.byte N24, Fn3, v120
	.byte W24
	.byte Dn3 @ N24, v120
	.byte W24
	.byte Ds3 @ N24, v120
	.byte W24
	.byte N96, Gn2, v127
	.byte W96
	.byte GOTO
		.word track_14_lbl_22f06c
	.byte FINE

track_14_1:
	.byte KEYSH, 0
	.byte W96
	.byte W96
track_14_lbl_22f0d9:
	.byte VOICE, 27
	.byte VOL, 37
	.byte PAN, c_v-17
	.byte PRIO, 119
	.byte N44, Bn1, v080
	.byte W48
	.byte N24, Cn2, v092
	.byte W24
	.byte Gn1 @ N24, v092
	.byte W24
	.byte VOICE, 60
	.byte N24, Gs1 @ v092
	.byte W24
	.byte Fn1, v088 @ N24
	.byte W24
	.byte Gn1, v084 @ N24
	.byte W24
	.byte Ds1, v072 @ N24
	.byte W24
	.byte Fn1, v127 @ N24
	.byte W24
	.byte Dn1 @ N24, v127
	.byte W24
	.byte Ds1 @ N24, v127
	.byte W24
	.byte N96, Gn0 @ v127
	.byte W24
	.byte W96
	.byte N24, As1, v088
	.byte W24
	.byte Gs1, v104 @ N24
	.byte W24
	.byte TIE, Gn1 @ v104
	.byte W48
	.byte W72
	.byte EOT @ Gn1, v104
	.byte W24
	.byte N24, Fn1 @ v104
	.byte W24
	.byte Dn1 @ N24, v104
	.byte W24
	.byte Ds1 @ N24, v104
	.byte W24
	.byte TIE, Gn0 @ v104
	.byte W24
	.byte W96
	.byte W72
	.byte EOT @ Gn0, v104
	.byte W24
	.byte N48, Dn2, v088
	.byte W48
	.byte N24, Ds2 @ v088
	.byte W24
	.byte Bn1 @ N24, v088
	.byte W24
	.byte Cn2 @ N24, v088
	.byte W24
	.byte Gn1 @ N24, v088
	.byte W24
	.byte As1 @ N24, v088
	.byte W24
	.byte Gs1 @ N24, v088
	.byte W24
	.byte N96, Gn1 @ v088
	.byte W96
	.byte N24, Fn1, v127
	.byte W24
	.byte Dn1 @ N24, v127
	.byte W24
	.byte Ds1 @ N24, v127
	.byte W24
	.byte TIE, Gn0 @ v127
	.byte W24
	.byte W96
	.byte EOT @ Gn0, v127
	.byte GOTO
		.word track_14_lbl_22f0d9
	.byte FINE

track_14_2:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 80
	.byte PAN, c_v+20
	.byte PRIO, 118
	.byte N24, Cn1, v127
	.byte W48
	.byte N24 @ Cn1, v127
	.byte W48
track_14_lbl_22f156:
	.byte N24, Cn1, v127
	.byte W48
	.byte N24 @ Cn1, v127
	.byte W48
	.byte PEND
track_14_lbl_22f15d:
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte PATT
		.word track_14_lbl_22f156
	.byte GOTO
		.word track_14_lbl_22f15d
	.byte FINE

track_14_3:
	.byte KEYSH, 0
	.byte PRIO, 30
	.byte W01
	.byte VOICE, 4
	.byte VOL, 59
	.byte PAN, c_v-22
	.byte N28, Cn1, v100
	.byte W48
	.byte N28 @ Cn1, v100
	.byte W44
	.byte W03
track_14_lbl_22f1bb:
	.byte W01
	.byte N28, Cn1, v100
	.byte W48
	.byte N28 @ Cn1, v100
	.byte W44
	.byte W03
	.byte PEND
track_14_lbl_22f1c4:
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte PATT
		.word track_14_lbl_22f1bb
	.byte GOTO
		.word track_14_lbl_22f1c4
	.byte FINE

.align 2

track_14:
	.byte 4
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_14_0
	.word track_14_1
	.word track_14_2
	.word track_14_3

.align 2
