.align 2

.global track_4

track_4_0:
	.byte KEYSH, 0
	.byte TEMPO, 77
	.byte VOICE, 24
	.byte VOL, 75
	.byte PAN, c_v+20
	.byte PRIO, 30
	.byte N96, An3, v092
	.byte W96
	.byte Gs3, v100 @ N96
	.byte W96
	.byte Gn3, v112 @ N96
	.byte W96
	.byte Fs3, v120 @ N96
	.byte W96
	.byte TIE, An5, v080
	.byte W96
	.byte W92
	.byte W01
	.byte EOT @ An5, v080
	.byte W03
	.byte TIE, An4, v100
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT @ An4, v100
	.byte FINE

track_4_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 75
	.byte PAN, c_v+20
	.byte PRIO, 29
	.byte N96, Fs3, v092
	.byte W96
	.byte Fs3, v100 @ N96
	.byte W96
	.byte W96
	.byte Fs3, v120 @ N96
	.byte W96
	.byte TIE, Ds5, v080
	.byte W96
	.byte W92
	.byte W02
	.byte EOT @ Ds5, v080
	.byte W02
	.byte TIE, Ds4, v100
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT @ Ds4, v100
	.byte FINE

track_4_2:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 75
	.byte PAN, c_v-22
	.byte PRIO, 28
	.byte N96, Ds3, v092
	.byte W96
	.byte Ds3, v100 @ N96
	.byte W96
	.byte Ds3, v112 @ N96
	.byte W96
	.byte Ds3, v120 @ N96
	.byte W96
	.byte TIE, Fs4, v080
	.byte W96
	.byte W92
	.byte W02
	.byte EOT @ Fs4, v080
	.byte W02
	.byte TIE, Fs3, v100
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT @ Fs3, v100
	.byte FINE

track_4_3:
	.byte KEYSH, 0
	.byte VOICE, 85
	.byte VOL, 75
	.byte PAN, c_v-17
	.byte PRIO, 117
	.byte N84, Cn2, v092
	.byte W96
	.byte Cn2, v100 @ N84
	.byte W96
	.byte Cn2, v112 @ N84
	.byte W96
	.byte N84 @ Cn2, v112
	.byte W96
	.byte Cn2, v080 @ N84
	.byte W96
	.byte N84 @ Cn2, v080
	.byte W96
	.byte N18, Cn2, v100
	.byte W24
	.byte Cn2, v108 @ N18
	.byte W24
	.byte Cn2, v100 @ N18
	.byte W24
	.byte N07, Cn2, v112
	.byte W08
	.byte Cn2, v100 @ N07
	.byte W08
	.byte Cn2, v116 @ N07
	.byte W08
	.byte N18, Cn2, v124
	.byte W24
	.byte Cn2, v108 @ N18
	.byte W24
	.byte Cn2, v116 @ N18
	.byte W24
	.byte N07 @ Cn2, v116
	.byte W08
	.byte Cn2, v092 @ N07
	.byte W08
	.byte Cn2, v104 @ N07
	.byte W08
	.byte N18, Cn2, v120
	.byte W24
	.byte Cn2, v112 @ N18
	.byte W24
	.byte Cn2, v120 @ N18
	.byte W24
	.byte N07, Cn2, v116
	.byte W08
	.byte Cn2, v108 @ N07
	.byte W08
	.byte Cn2, v112 @ N07
	.byte W08
	.byte N18, Cn2, v124
	.byte W24
	.byte Cn2, v116 @ N18
	.byte W24
	.byte N18 @ Cn2, v116
	.byte W24
	.byte N07, Cn2, v112
	.byte W08
	.byte Cn2, v108 @ N07
	.byte W08
	.byte Cn2, v120 @ N07
	.byte W07
	.byte FINE

track_4_4:
	.byte KEYSH, 0
	.byte VOICE, 26
	.byte VOL, 75
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N08, Dn3, v127
	.byte W24
	.byte N07 @ Dn3, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W24
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
track_4_lbl_22cb85:
	.byte N07, Cn3, v127
	.byte W24
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte PEND
track_4_lbl_22cb9c:
	.byte N07, Cn3, v127
	.byte W24
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W24
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte PEND
	.byte PATT
		.word track_4_lbl_22cb85
	.byte PATT
		.word track_4_lbl_22cb9c
	.byte PATT
		.word track_4_lbl_22cb85
	.byte PATT
		.word track_4_lbl_22cb9c
	.byte PATT
		.word track_4_lbl_22cb85
	.byte PATT
		.word track_4_lbl_22cb9c
	.byte N07, Cn3, v127
	.byte W24
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W08
	.byte Cn3 @ N07, v127
	.byte W08
	.byte Dn3 @ N07, v127
	.byte W07
	.byte FINE

track_4_5:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 75
	.byte PAN, c_v+15
	.byte PRIO, 119
	.byte N54, Cn3, v127
	.byte W96
	.byte W96
	.byte N54 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N54 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N54 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N48 @ Cn3, v127
	.byte W48
	.byte N48 @ Cn3, v127
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W48
	.byte N24 @ Cn3, v127
	.byte W24
	.byte N24 @ Cn3, v127
	.byte W24
	.byte FINE

track_4_6:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 53
	.byte PAN, c_v
	.byte PRIO, 118
	.byte N08, Gn5, v032
	.byte W16
	.byte Gn5, v036 @ N08
	.byte W08
	.byte Fs5 @ N08, v036
	.byte W08
	.byte Cn5, v040 @ N08
	.byte W08
	.byte Fs5 @ N08, v040
	.byte W08
	.byte Gn5, v044 @ N08
	.byte W08
	.byte Cn5 @ N08, v044
	.byte W08
	.byte Gn5, v048 @ N08
	.byte W08
	.byte Fs5 @ N08, v048
	.byte W08
	.byte Cn5 @ N08, v048
	.byte W08
	.byte Fs5, v052 @ N08
	.byte W08
	.byte Gn5 @ N08, v052
	.byte W16
	.byte Gn5, v056 @ N08
	.byte W08
	.byte Fs5, v060 @ N08
	.byte W08
	.byte Cn5 @ N08, v060
	.byte W08
	.byte Fs5, v064 @ N08
	.byte W08
	.byte Gn5 @ N08, v064
	.byte W08
	.byte Cn5, v068 @ N08
	.byte W08
	.byte Gn5 @ N08, v068
	.byte W08
	.byte Fs5, v072 @ N08
	.byte W08
	.byte Cn5 @ N08, v072
	.byte W08
	.byte Fs5, v076 @ N08
	.byte W08
	.byte Gn5 @ N08, v076
	.byte W16
	.byte Gn5, v080 @ N08
	.byte W08
	.byte Fs5 @ N08, v080
	.byte W08
	.byte Cn5, v084 @ N08
	.byte W08
	.byte Fs5 @ N08, v084
	.byte W08
	.byte Gn5, v088 @ N08
	.byte W08
	.byte Cn5 @ N08, v088
	.byte W08
	.byte Gn5, v092 @ N08
	.byte W08
	.byte Fs5 @ N08, v092
	.byte W08
	.byte Cn5, v096 @ N08
	.byte W08
	.byte Fs5 @ N08, v096
	.byte W08
	.byte Gn5, v100 @ N08
	.byte W08
	.byte Cn5, v108 @ N08
	.byte W08
	.byte Gn5, v104 @ N08
	.byte W08
	.byte Fs5 @ N08, v104
	.byte W08
	.byte Cn5, v108 @ N08
	.byte W08
	.byte Fs5 @ N08, v108
	.byte W08
	.byte Gn5 @ N08, v108
	.byte W08
	.byte Cn5, v112 @ N08
	.byte W08
	.byte Gn5 @ N08, v112
	.byte W08
	.byte Fs5, v116 @ N08
	.byte W08
	.byte Cn5 @ N08, v116
	.byte W08
	.byte Fs5, v120 @ N08
	.byte W08
track_4_lbl_22cc84:
	.byte N08, Gn5, v100
	.byte W16
	.byte Gn5, v104 @ N08
	.byte W08
	.byte Fs5 @ N08, v104
	.byte W08
	.byte Cn5, v108 @ N08
	.byte W08
	.byte Fs5 @ N08, v108
	.byte W08
	.byte Gn5 @ N08, v108
	.byte W08
	.byte Cn5, v112 @ N08
	.byte W08
	.byte Gn5 @ N08, v112
	.byte W08
	.byte Fs5, v116 @ N08
	.byte W08
	.byte Cn5 @ N08, v116
	.byte W08
	.byte Fs5, v120 @ N08
	.byte W08
	.byte PEND
	.byte PATT
		.word track_4_lbl_22cc84
	.byte PATT
		.word track_4_lbl_22cc84
	.byte PATT
		.word track_4_lbl_22cc84
	.byte PATT
		.word track_4_lbl_22cc84
	.byte N08, Gn5, v100
	.byte W16
	.byte Gn5, v104 @ N08
	.byte W08
	.byte Fs5 @ N08, v104
	.byte W08
	.byte Cn5, v108 @ N08
	.byte W08
	.byte Fs5 @ N08, v108
	.byte W08
	.byte Gn5 @ N08, v108
	.byte W08
	.byte Cn5, v112 @ N08
	.byte W08
	.byte Gn5 @ N08, v112
	.byte W08
	.byte Fs5, v116 @ N08
	.byte W08
	.byte Cn5 @ N08, v116
	.byte W08
	.byte FINE

.align 2

track_4:
	.byte 7
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_4_0
	.word track_4_1
	.word track_4_2
	.word track_4_3
	.word track_4_4
	.word track_4_5
	.word track_4_6

.align 2
