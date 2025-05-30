.align 2

.global track_79

track_79_0:
	.byte KEYSH, 0
	.byte TEMPO, 100
	.byte W96
track_79_lbl_22abe9:
	.byte VOICE, 98
	.byte VOL, 35
	.byte PAN, c_v-10
	.byte PRIO, 120
	.byte N23, An2, v112
	.byte W24
	.byte Dn3 @ N23, v112
	.byte W24
	.byte Gn3 @ N23, v112
	.byte W24
	.byte Fs3 @ N23, v112
	.byte W24
	.byte Fn3 @ N23, v112
	.byte W24
track_79_lbl_22abfd:
	.byte N23, En3, v112
	.byte W24
	.byte Gn2 @ N23, v112
	.byte W24
	.byte Ds3 @ N23, v112
	.byte W24
	.byte Dn3 @ N23, v112
	.byte W24
	.byte Cs3 @ N23, v112
	.byte W24
	.byte PEND
track_79_lbl_22ac0a:
	.byte N23, An2, v112
	.byte W24
	.byte Dn3 @ N23, v112
	.byte W24
	.byte Gn3 @ N23, v112
	.byte W24
	.byte Fs3 @ N23, v112
	.byte W24
	.byte Fn3 @ N23, v112
	.byte W24
	.byte PEND
	.byte PATT
		.word track_79_lbl_22abfd
	.byte PATT
		.word track_79_lbl_22ac0a
	.byte PATT
		.word track_79_lbl_22abfd
	.byte PATT
		.word track_79_lbl_22ac0a
	.byte PATT
		.word track_79_lbl_22abfd
	.byte PATT
		.word track_79_lbl_22ac0a
	.byte PATT
		.word track_79_lbl_22abfd
	.byte PATT
		.word track_79_lbl_22ac0a
	.byte PATT
		.word track_79_lbl_22abfd
	.byte PATT
		.word track_79_lbl_22ac0a
	.byte PATT
		.word track_79_lbl_22abfd
	.byte PATT
		.word track_79_lbl_22ac0a
	.byte PATT
		.word track_79_lbl_22abfd
	.byte GOTO
		.word track_79_lbl_22abe9
	.byte FINE

track_79_1:
	.byte KEYSH, 0
	.byte W96
track_79_lbl_22ac61:
	.byte W02
	.byte VOICE, 96
	.byte VOL, 56
	.byte PAN, c_v-26
	.byte PRIO, 119
	.byte W96
	.byte W22
	.byte W02
	.byte TIE, Fs2, v100
	.byte W96
	.byte W20
	.byte EOT @ Fs2, v100
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE @ Fs2, v100
	.byte W96
	.byte W20
	.byte EOT @ Fs2, v100
	.byte W02
	.byte W96
	.byte W24
track_79_lbl_22ac7e:
	.byte W02
	.byte TIE, Gn2, v100
	.byte W96
	.byte W20
	.byte PEND
	.byte EOT @ Gn2, v100
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE @ Gn2, v100
	.byte W96
	.byte W20
	.byte EOT @ Gn2, v100
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Fs2 @ v100
	.byte W96
	.byte W20
	.byte EOT @ Fs2, v100
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Fs2, v088
	.byte W96
	.byte W20
	.byte EOT @ Fs2, v088
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Gn2 @ v088
	.byte W96
	.byte W20
	.byte EOT @ Gn2, v088
	.byte W02
	.byte W96
	.byte W24
	.byte PATT
		.word track_79_lbl_22ac7e
	.byte EOT, Gn2 @ v088
	.byte W02
	.byte GOTO
		.word track_79_lbl_22ac61
	.byte FINE

track_79_2:
	.byte KEYSH, 0
	.byte W96
track_79_lbl_22acbe:
	.byte W02
	.byte VOICE, 97
	.byte VOL, 56
	.byte PAN, c_v-10
	.byte PRIO, 119
	.byte TIE, Cn4, v092
	.byte W96
	.byte W20
	.byte EOT @ Cn4, v092
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE @ Cn4, v092
	.byte W96
	.byte W20
	.byte EOT @ Cn4, v092
	.byte W02
	.byte W96
	.byte W24
track_79_lbl_22acd8:
	.byte W02
	.byte TIE, Cs4, v092
	.byte W96
	.byte W20
	.byte PEND
	.byte EOT @ Cs4, v092
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE @ Cs4, v092
	.byte W96
	.byte W20
	.byte EOT @ Cs4, v092
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cn4 @ v092
	.byte W96
	.byte W20
	.byte EOT @ Cn4, v092
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cn4, v076
	.byte W96
	.byte W20
	.byte EOT @ Cn4, v076
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cs4 @ v076
	.byte W96
	.byte W20
	.byte EOT @ Cs4, v076
	.byte W02
	.byte W96
	.byte W24
	.byte PATT
		.word track_79_lbl_22acd8
	.byte EOT, Cs4 @ v076
	.byte W02
	.byte W96
	.byte W24
	.byte GOTO
		.word track_79_lbl_22acbe
	.byte FINE

track_79_3:
	.byte KEYSH, 0
	.byte W96
track_79_lbl_22ad1a:
	.byte W01
	.byte VOICE, 27
	.byte PAN, c_v
	.byte PRIO, 118
	.byte VOL, 35
	.byte TIE, En3, v080
	.byte W96
	.byte W23
	.byte EOT @ En3, v080
	.byte W01
	.byte N68, Ds3, v080, 3
	.byte W72
	.byte N44, Fs3, v080, 3
	.byte W44
	.byte W03
	.byte W01
	.byte TIE, Fn3 @ v080
	.byte W96
	.byte W23
	.byte EOT @ Fn3, v080
	.byte W01
	.byte TIE, En3 @ v080
	.byte W96
	.byte W23
	.byte EOT @ En3, v080
	.byte W01
	.byte TIE, Ds3 @ v080
	.byte W96
	.byte W23
	.byte W96
	.byte W24
	.byte EOT @ Ds3, v080
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte GOTO
		.word track_79_lbl_22ad1a
	.byte FINE

track_79_4:
	.byte KEYSH, 0
	.byte W96
track_79_lbl_22ad66:
	.byte W02
	.byte VOICE, 96
	.byte VOL, 56
	.byte PAN, c_v+32
	.byte PRIO, 30
	.byte W96
	.byte W22
	.byte W02
	.byte TIE, Cn2, v096
	.byte W96
	.byte W20
	.byte EOT @ Cn2, v096
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE @ Cn2, v096
	.byte W96
	.byte W20
	.byte EOT @ Cn2, v096
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cs2, v076
	.byte W96
	.byte W20
	.byte EOT @ Cs2, v076
	.byte W02
	.byte W96
	.byte W24
track_79_lbl_22ad8d:
	.byte W02
	.byte TIE, Cs2, v096
	.byte W96
	.byte W20
	.byte PEND
	.byte EOT @ Cs2, v096
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cn2 @ v096
	.byte W96
	.byte W20
	.byte EOT @ Cn2, v096
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cn2, v080
	.byte W96
	.byte W20
	.byte EOT @ Cn2, v080
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cs2 @ v080
	.byte W96
	.byte W20
	.byte EOT @ Cs2, v080
	.byte W02
	.byte W96
	.byte W24
	.byte PATT
		.word track_79_lbl_22ad8d
	.byte EOT, Cs2 @ v080
	.byte W02
	.byte GOTO
		.word track_79_lbl_22ad66
	.byte FINE

track_79_5:
	.byte KEYSH, 0
	.byte W96
track_79_lbl_22adc5:
	.byte W02
	.byte VOICE, 97
	.byte VOL, 56
	.byte PAN, c_v+16
	.byte PRIO, 30
	.byte TIE, Cn4, v044
	.byte W96
	.byte W20
	.byte EOT @ Cn4, v044
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE @ Cn4, v044
	.byte W96
	.byte W20
	.byte EOT @ Cn4, v044
	.byte W02
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
track_79_lbl_22ade3:
	.byte W02
	.byte TIE, Cs4, v044
	.byte W96
	.byte W20
	.byte PEND
	.byte EOT @ Cs4, v044
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cn4 @ v044
	.byte W96
	.byte W20
	.byte EOT @ Cn4, v044
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cn4, v032
	.byte W96
	.byte W20
	.byte EOT @ Cn4, v032
	.byte W02
	.byte W96
	.byte W24
	.byte W02
	.byte TIE, Cs4 @ v032
	.byte W96
	.byte W20
	.byte EOT @ Cs4, v032
	.byte W02
	.byte W96
	.byte W24
	.byte PATT
		.word track_79_lbl_22ade3
	.byte EOT, Cs4 @ v032
	.byte W02
	.byte W96
	.byte W24
	.byte GOTO
		.word track_79_lbl_22adc5
	.byte FINE

track_79_6:
	.byte KEYSH, 0
	.byte W96
track_79_lbl_22ae1d:
	.byte VOICE, 99
	.byte PAN, c_v-20
	.byte PRIO, 29
	.byte VOL, 35
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W03
	.byte TIE, Cn3, v080
	.byte W96
	.byte W21
	.byte W03
	.byte EOT @ Cn3, v080
	.byte TIE @ Cn3, v080
	.byte W96
	.byte W21
	.byte W01
	.byte EOT @ Cn3, v080
	.byte W02
	.byte TIE, An2 @ v080
	.byte W96
	.byte W21
	.byte W96
	.byte W15
	.byte EOT @ An2, v080
	.byte W09
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte GOTO
		.word track_79_lbl_22ae1d
	.byte FINE

track_79_7:
	.byte KEYSH, 0
	.byte W96
track_79_lbl_22ae5c:
	.byte PAN, c_v+10
	.byte PRIO, 28
	.byte W16
	.byte VOICE, 98
	.byte VOL, 42
	.byte N23, An2, v056
	.byte W24
	.byte Dn3 @ N23, v056
	.byte W24
	.byte Gn3 @ N23, v056
	.byte W24
	.byte Fs3 @ N23, v056
	.byte W24
	.byte Fn3 @ N23, v056
	.byte W08
track_79_lbl_22ae71:
	.byte W16
	.byte N23, En3, v056
	.byte W24
	.byte Gn2 @ N23, v056
	.byte W24
	.byte Ds3 @ N23, v056
	.byte W24
	.byte Dn3 @ N23, v056
	.byte W24
	.byte Cs3 @ N23, v056
	.byte W08
	.byte PEND
track_79_lbl_22ae7f:
	.byte W16
	.byte N23, An2, v056
	.byte W24
	.byte Dn3 @ N23, v056
	.byte W24
	.byte Gn3 @ N23, v056
	.byte W24
	.byte Fs3 @ N23, v056
	.byte W24
	.byte Fn3 @ N23, v056
	.byte W08
	.byte PEND
	.byte PATT
		.word track_79_lbl_22ae71
	.byte PATT
		.word track_79_lbl_22ae7f
	.byte PATT
		.word track_79_lbl_22ae71
	.byte PATT
		.word track_79_lbl_22ae7f
	.byte PATT
		.word track_79_lbl_22ae71
	.byte PATT
		.word track_79_lbl_22ae7f
	.byte PATT
		.word track_79_lbl_22ae71
	.byte PATT
		.word track_79_lbl_22ae7f
	.byte PATT
		.word track_79_lbl_22ae71
	.byte PATT
		.word track_79_lbl_22ae7f
	.byte PATT
		.word track_79_lbl_22ae71
	.byte PATT
		.word track_79_lbl_22ae7f
	.byte W16
	.byte N23, En3, v056
	.byte W24
	.byte Gn2 @ N23, v056
	.byte W24
	.byte Ds3 @ N23, v056
	.byte W24
	.byte Dn3 @ N23, v056
	.byte W24
	.byte N08, Cs3 @ v056
	.byte W08
	.byte GOTO
		.word track_79_lbl_22ae5c
	.byte FINE

track_79_8:
	.byte KEYSH, 0
	.byte W96
track_79_lbl_22aee0:
	.byte VOICE, 99
	.byte PAN, c_v+10
	.byte PRIO, 27
	.byte VOL, 35
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W03
	.byte TIE, Cs3, v072
	.byte W96
	.byte W21
	.byte W96
	.byte W15
	.byte EOT @ Cs3, v072
	.byte W09
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte GOTO
		.word track_79_lbl_22aee0
	.byte FINE

.align 2

track_79:
	.byte 9
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_79_0
	.word track_79_1
	.word track_79_2
	.word track_79_3
	.word track_79_4
	.word track_79_5
	.word track_79_6
	.word track_79_7
	.word track_79_8

.align 2
