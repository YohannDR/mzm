.align 2

.global track_23

track_23_0:
	.byte KEYSH, 0
	.byte TEMPO, 28
	.byte W96
track_23_lbl_22fe79:
	.byte VOICE, 93
	.byte VOL, 37
	.byte PAN, c_v+20
	.byte PRIO, 118
	.byte W01
	.byte N36
	.byte Gn1, En7
	.byte W92
	.byte W03
	.byte W01
	.byte N36
	.byte W92
	.byte W03
	.byte W01
	.byte Gn1, Cn7
	.byte W92
	.byte W03
	.byte W01
	.byte Gn1, En7
	.byte W92
	.byte W03
	.byte W01
	.byte N36
	.byte W92
	.byte W03
	.byte W01
	.byte Gn1, Cn7
	.byte W92
	.byte W03
	.byte W01
	.byte N36
	.byte W92
	.byte W03
	.byte W01
	.byte Gn1, En7
	.byte W92
	.byte W03
	.byte W01
	.byte N36
	.byte W92
	.byte W03
	.byte W01
	.byte Gn1, Cn7
	.byte W92
	.byte W03
	.byte W01
	.byte Gn1, En7
	.byte W92
	.byte W03
	.byte W01
	.byte Gn1, Cn7
	.byte W92
	.byte W03
	.byte GOTO
		.word track_23_lbl_22fe79

	.byte FINE

track_23_1:
	.byte KEYSH, 0
	.byte W96
track_23_lbl_22fec3:
	.byte VOICE, 94
	.byte VOL, 37
	.byte PAN, c_v-22
	.byte PRIO, 119
	.byte N72
	.byte Dn3, En7
	.byte W96
	.byte N72
	.byte W96
	.byte Dn3, Cn7
	.byte W96
	.byte Dn3, En7
	.byte W96
	.byte N72
	.byte W96
	.byte Dn3, Cn7
	.byte W96
	.byte N72
	.byte W96
	.byte Dn3, En7
	.byte W96
	.byte N72
	.byte W96
	.byte Dn3, Cn7
	.byte W96
	.byte Dn3, En7
	.byte W96
	.byte Dn3, Cn7
	.byte W96
	.byte GOTO
		.word track_23_lbl_22fec3

	.byte FINE

track_23_2:
	.byte KEYSH, 0
	.byte PRIO, 120
	.byte W24
	.byte VOICE, 71
	.byte VOL, 31
	.byte PAN, c_v+15
	.byte N84
	.byte Gn4, En3
	.byte W72
track_23_lbl_22ff01:
	.byte W48
	.byte PAN, c_v-17
	.byte N84
	.byte Gn4, En3
	.byte W48
	.byte W72
	.byte PAN, c_v+15
	.byte N84
	.byte As4, En2
	.byte W24
	.byte W96
	.byte PAN, c_v-17
	.byte N84
	.byte An4, En3
	.byte W96
	.byte W24
	.byte PAN, c_v+15
	.byte N84
	.byte Fn4, Cn4
	.byte W72
	.byte W48
	.byte PAN, c_v-17
	.byte N84
	.byte Gn4, Gs3
	.byte W48
	.byte W72
	.byte PAN, c_v+15
	.byte N84
	.byte As4, En4
	.byte W24
	.byte W96
	.byte PAN, c_v-17
	.byte N84
	.byte An4
	.byte W96
	.byte W24
	.byte PAN, c_v+15
	.byte N84
	.byte Dn5, Cn2
	.byte W72
	.byte W96
	.byte W96
	.byte GOTO
		.word track_23_lbl_22ff01

	.byte FINE

.align 2

track_23:
	.byte 3
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_23_0
	.word track_23_1
	.word track_23_2

.align 2
