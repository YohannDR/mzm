.align 2

.global track_13

track_13_0:
	.byte KEYSH, 0
	.byte TEMPO, 28
	.byte VOICE, 99
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 120
	.byte TIE, Gn3, v127
	.byte W96
	.byte W96
	.byte EOT @ Gn3, v127
track_13_lbl_22ed8e:
	.byte VOICE, 97
	.byte PAN, c_v+15
	.byte TIE, Fn1, v072
	.byte W96
	.byte W96
	.byte EOT @ Fn1, v072
	.byte W96
	.byte W96
	.byte PAN, c_v-17
	.byte TIE, An1, v080
	.byte W96
	.byte W96
	.byte EOT @ An1, v080
	.byte W96
	.byte W96
	.byte PAN, c_v
	.byte TIE, Fs1, v092
	.byte W96
	.byte W96
	.byte EOT @ Fs1, v092
	.byte W96
	.byte W96
	.byte PAN, c_v+15
	.byte TIE, Dn1, v080
	.byte W96
	.byte W96
	.byte EOT @ Dn1, v080
	.byte W96
	.byte W96
	.byte PAN, c_v-17
	.byte TIE, En1 @ v080
	.byte W96
	.byte W96
	.byte EOT @ En1, v080
	.byte W96
	.byte W96
	.byte PAN, c_v
	.byte TIE, Gs1, v127
	.byte W96
	.byte W96
	.byte EOT @ Gs1, v127
	.byte W96
	.byte W96
	.byte GOTO
		.word track_13_lbl_22ed8e
	.byte FINE

track_13_1:
	.byte KEYSH, 0
	.byte VOICE, 99
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 119
	.byte TIE, Cn3, v127
	.byte W96
	.byte W96
	.byte EOT @ Cn3, v127
track_13_lbl_22ede1:
	.byte W96
	.byte W96
	.byte VOICE, 98
	.byte PAN, c_v-10
	.byte TIE, Gn2, v100
	.byte W96
	.byte W96
	.byte EOT @ Gn2, v100
	.byte W96
	.byte W96
	.byte PAN, c_v
	.byte TIE, Fn2, v112
	.byte W96
	.byte W96
	.byte EOT @ Fn2, v112
	.byte W96
	.byte W96
	.byte PAN, c_v+15
	.byte TIE, En2, v127
	.byte W96
	.byte W96
	.byte EOT @ En2, v127
	.byte W96
	.byte W96
	.byte VOICE, 98
	.byte PAN, c_v
	.byte TIE, Gn2, v100
	.byte W96
	.byte W96
	.byte EOT @ Gn2, v100
	.byte W96
	.byte W96
	.byte VOICE, 98
	.byte PAN, c_v+15
	.byte TIE, Dn2, v112
	.byte W96
	.byte W96
	.byte EOT @ Dn2, v112
	.byte W96
	.byte W96
	.byte VOICE, 98
	.byte PAN, c_v
	.byte TIE, Gn2 @ v112
	.byte W96
	.byte W96
	.byte EOT @ Gn2, v112
	.byte GOTO
		.word track_13_lbl_22ede1
	.byte FINE

track_13_2:
	.byte KEYSH, 0
	.byte VOICE, 99
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 118
	.byte TIE, Cn3, v127
	.byte W96
	.byte W96
	.byte EOT @ Cn3, v127
track_13_lbl_22ee3a:
	.byte VOICE, 27
	.byte VOL, 55
	.byte N24, Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W96
	.byte GOTO
		.word track_13_lbl_22ee3a
	.byte N24, Cn2, v100
	.byte W96
	.byte N24 @ Cn2, v100
	.byte W24
	.byte FINE

track_13_3:
	.byte KEYSH, 0
	.byte VOICE, 26
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 30
	.byte N06, Cn3, v100
	.byte W48
	.byte N06 @ Cn3, v100
	.byte W48
track_13_lbl_22ee8c:
	.byte N06, Cn3, v100
	.byte W48
	.byte N06 @ Cn3, v100
	.byte W48
	.byte PEND
track_13_lbl_22ee93:
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte GOTO
		.word track_13_lbl_22ee93
	.byte PATT
		.word track_13_lbl_22ee8c
	.byte N06, Cn3, v100
	.byte W48
	.byte N06 @ Cn3, v100
	.byte W06
	.byte FINE

track_13_4:
	.byte KEYSH, 0
	.byte VOICE, 26
	.byte VOL, 55
	.byte PAN, c_v
	.byte PRIO, 29
	.byte W02
	.byte N10, Gn2, v120
	.byte W48
	.byte N10 @ Gn2, v120
	.byte W44
	.byte W02
track_13_lbl_22ef2e:
	.byte W02
	.byte N10, Gn2, v120
	.byte W48
	.byte N10 @ Gn2, v120
	.byte W44
	.byte W02
	.byte PEND
track_13_lbl_22ef37:
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte GOTO
		.word track_13_lbl_22ef37
	.byte PATT
		.word track_13_lbl_22ef2e
	.byte W02
	.byte N10, Gn2, v120
	.byte W48
	.byte N10 @ Gn2, v120
	.byte W10
	.byte FINE

track_13_5:
	.byte KEYSH, 0
	.byte VOICE, 96
	.byte VOL, 78
	.byte PAN, c_v-17
	.byte PRIO, 28
	.byte N96, Cn2, v127
	.byte W96
	.byte W96
track_13_lbl_22efd0:
	.byte N96, Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte GOTO
		.word track_13_lbl_22efd0
	.byte N96, Cn2, v127
	.byte W96
	.byte FINE

track_13_6:
	.byte KEYSH, 0
	.byte VOICE, 96
	.byte VOL, 78
	.byte PAN, c_v+15
	.byte PRIO, 27
	.byte W96
	.byte N96, Cn2, v127
	.byte W96
track_13_lbl_22f00f:
	.byte W96
	.byte N96, Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte W96
	.byte N96 @ Cn2, v127
	.byte W96
	.byte GOTO
		.word track_13_lbl_22f00f
	.byte W96
	.byte N96, Cn2, v127
	.byte W96
	.byte FINE

.align 2

track_13:
	.byte 7
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_13_0
	.word track_13_1
	.word track_13_2
	.word track_13_3
	.word track_13_4
	.word track_13_5
	.word track_13_6

.align 2
