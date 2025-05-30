.align 2

.global track_15

track_15_0:
	.byte KEYSH, 0
	.byte TEMPO, 28
	.byte PRIO, 120
	.byte W96
	.byte W96
track_15_lbl_22f230:
	.byte VOICE, 29
	.byte VOL, 48
	.byte PAN, c_v
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
		.word track_15_lbl_22f230
	.byte FINE

track_15_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 56
	.byte PAN, c_v+20
	.byte PRIO, 118
	.byte N24, Cn1, v072
	.byte W48
	.byte Cn1, v084 @ N24
	.byte W48
	.byte Cn1, v076 @ N24
	.byte W48
	.byte Cn1, v080 @ N24
	.byte W48
track_15_lbl_22f2b0:
	.byte N24, Cn1, v072
	.byte W48
	.byte N24 @ Cn1, v072
	.byte W48
	.byte Cn1, v060 @ N24
	.byte W48
	.byte Cn1, v052 @ N24
	.byte W48
	.byte Cn1, v084 @ N24
	.byte W48
	.byte Cn1, v092 @ N24
	.byte W48
	.byte Cn1, v088 @ N24
	.byte W48
	.byte Cn1, v080 @ N24
	.byte W48
	.byte Cn1, v072 @ N24
	.byte W48
	.byte Cn1, v088 @ N24
	.byte W48
	.byte N24 @ Cn1, v088
	.byte W48
	.byte Cn1, v084 @ N24
	.byte W48
	.byte Cn1, v080 @ N24
	.byte W48
	.byte N24 @ Cn1, v080
	.byte W48
	.byte Cn1, v076 @ N24
	.byte W48
	.byte Cn1, v072 @ N24
	.byte W48
	.byte N24 @ Cn1, v072
	.byte W48
	.byte N24 @ Cn1, v072
	.byte W48
	.byte N24 @ Cn1, v072
	.byte W48
	.byte Cn1, v076 @ N24
	.byte W48
	.byte N24 @ Cn1, v076
	.byte W48
	.byte Cn1, v080 @ N24
	.byte W48
	.byte N24 @ Cn1, v080
	.byte W48
	.byte Cn1, v084 @ N24
	.byte W48
	.byte N24 @ Cn1, v084
	.byte W48
	.byte Cn1, v088 @ N24
	.byte W48
	.byte N24 @ Cn1, v088
	.byte W48
	.byte Cn1, v092 @ N24
	.byte W48
	.byte GOTO
		.word track_15_lbl_22f2b0
	.byte FINE

track_15_2:
	.byte KEYSH, 0
	.byte PRIO, 119
	.byte W01
	.byte VOICE, 4
	.byte VOL, 59
	.byte PAN, c_v-22
	.byte N28, Cn1, v072
	.byte W48
	.byte Cn1, v076 @ N28
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, v080 @ N28
	.byte W48
	.byte Cn1, v076 @ N28
	.byte W44
	.byte W03
track_15_lbl_22f31c:
	.byte W01
	.byte N28, Cn1, v060
	.byte W48
	.byte Cn1, v092 @ N28
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, v076 @ N28
	.byte W48
	.byte Cn1, v060 @ N28
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, v088 @ N28
	.byte W48
	.byte Cn1, v084 @ N28
	.byte W44
	.byte W03
track_15_lbl_22f335:
	.byte W01
	.byte N28, Cn1, v076
	.byte W48
	.byte Cn1, v080 @ N28
	.byte W44
	.byte W03
	.byte PEND
	.byte W01
	.byte Cn1, v076 @ N28
	.byte W48
	.byte Cn1, v072 @ N28
	.byte W44
	.byte W03
	.byte W01
	.byte N28 @ Cn1, v072
	.byte W48
	.byte Cn1, v064 @ N28
	.byte W44
	.byte W03
track_15_lbl_22f34e:
	.byte W01
	.byte N28, Cn1, v072
	.byte W48
	.byte Cn1, v076 @ N28
	.byte W44
	.byte W03
	.byte PEND
	.byte W01
	.byte Cn1, v080 @ N28
	.byte W48
	.byte Cn1, v092 @ N28
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, v060 @ N28
	.byte W48
	.byte Cn1, v072 @ N28
	.byte W44
	.byte W03
	.byte PATT
		.word track_15_lbl_22f335
	.byte W01
	.byte N28, Cn1, v080
	.byte W48
	.byte N28 @ Cn1, v080
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, v076 @ N28
	.byte W48
	.byte Cn1, v092 @ N28
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, v076 @ N28
	.byte W48
	.byte N28 @ Cn1, v076
	.byte W44
	.byte W03
	.byte PATT
		.word track_15_lbl_22f34e
	.byte GOTO
		.word track_15_lbl_22f31c
	.byte FINE

.align 2

track_15:
	.byte 3
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_15_0
	.word track_15_1
	.word track_15_2

.align 2
