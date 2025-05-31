.align 2

.global track_62

track_62_0:
	.byte KEYSH, 0
track_62_lbl_2226ea:
	.byte TEMPO, 100
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
track_62_lbl_222700:
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
track_62_lbl_22270d:
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
		.word track_62_lbl_222700
	.byte PATT
		.word track_62_lbl_22270d
	.byte PATT
		.word track_62_lbl_222700
	.byte PATT
		.word track_62_lbl_22270d
	.byte PATT
		.word track_62_lbl_222700
	.byte PATT
		.word track_62_lbl_22270d
	.byte PATT
		.word track_62_lbl_222700
	.byte PATT
		.word track_62_lbl_22270d
	.byte PATT
		.word track_62_lbl_222700
	.byte PATT
		.word track_62_lbl_22270d
	.byte PATT
		.word track_62_lbl_222700
	.byte PATT
		.word track_62_lbl_22270d
	.byte PATT
		.word track_62_lbl_222700
	.byte GOTO
		.word track_62_lbl_2226ea
	.byte FINE

track_62_1:
	.byte KEYSH, 0
track_62_lbl_222763:
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
track_62_lbl_222780:
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
		.word track_62_lbl_222780
	.byte EOT, Gn2 @ v088
	.byte W02
	.byte GOTO
		.word track_62_lbl_222763
	.byte FINE

track_62_2:
	.byte KEYSH, 0
track_62_lbl_2227bf:
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
track_62_lbl_2227d9:
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
		.word track_62_lbl_2227d9
	.byte EOT, Cs4 @ v076
	.byte W02
	.byte W96
	.byte W24
	.byte GOTO
		.word track_62_lbl_2227bf
	.byte FINE

track_62_3:
	.byte KEYSH, 0
track_62_lbl_22281a:
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
		.word track_62_lbl_22281a
	.byte FINE

track_62_4:
	.byte KEYSH, 0
track_62_lbl_222865:
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
track_62_lbl_22288c:
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
		.word track_62_lbl_22288c
	.byte EOT, Cs2 @ v080
	.byte W02
	.byte GOTO
		.word track_62_lbl_222865
	.byte FINE

track_62_5:
	.byte KEYSH, 0
track_62_lbl_2228c3:
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
track_62_lbl_2228e1:
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
		.word track_62_lbl_2228e1
	.byte EOT, Cs4 @ v032
	.byte W02
	.byte W96
	.byte W24
	.byte GOTO
		.word track_62_lbl_2228c3
	.byte FINE

track_62_6:
	.byte KEYSH, 0
track_62_lbl_22291a:
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
		.word track_62_lbl_22291a
	.byte FINE

track_62_7:
	.byte KEYSH, 0
track_62_lbl_222958:
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
track_62_lbl_22296d:
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
track_62_lbl_22297b:
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
		.word track_62_lbl_22296d
	.byte PATT
		.word track_62_lbl_22297b
	.byte PATT
		.word track_62_lbl_22296d
	.byte PATT
		.word track_62_lbl_22297b
	.byte PATT
		.word track_62_lbl_22296d
	.byte PATT
		.word track_62_lbl_22297b
	.byte PATT
		.word track_62_lbl_22296d
	.byte PATT
		.word track_62_lbl_22297b
	.byte PATT
		.word track_62_lbl_22296d
	.byte PATT
		.word track_62_lbl_22297b
	.byte PATT
		.word track_62_lbl_22296d
	.byte PATT
		.word track_62_lbl_22297b
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
		.word track_62_lbl_222958
	.byte FINE

track_62_8:
	.byte KEYSH, 0
track_62_lbl_2229db:
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
		.word track_62_lbl_2229db
	.byte FINE

.align 2

track_62:
	.byte 9
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_62_0
	.word track_62_1
	.word track_62_2
	.word track_62_3
	.word track_62_4
	.word track_62_5
	.word track_62_6
	.word track_62_7
	.word track_62_8

.align 2
