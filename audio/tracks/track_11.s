.align 2

.global track_11

track_11_0:
	.byte KEYSH, 0
track_11_lbl_22eae2:
	.byte TEMPO, 49
	.byte VOICE, 14
	.byte VOL, 60
	.byte PAN, c_v-22
	.byte PRIO, 118
	.byte N96, Fn3, v120
	.byte W96
	.byte W72
	.byte Fn3, v092 @ N96
	.byte W24
	.byte W96
	.byte W48
	.byte Fn3, v112 @ N96
	.byte W48
	.byte W96
	.byte W24
	.byte Fn3, v092 @ N96
	.byte W72
	.byte W96
	.byte GOTO
		.word track_11_lbl_22eae2
	.byte FINE

track_11_1:
	.byte KEYSH, 0
track_11_lbl_22eb07:
	.byte VOICE, 14
	.byte VOL, 60
	.byte PAN, c_v+20
	.byte PRIO, 119
	.byte N96, Cn3, v120
	.byte W96
	.byte W72
	.byte Cn3, v112 @ N96
	.byte W24
	.byte W96
	.byte W48
	.byte Cn3, v092 @ N96
	.byte W48
	.byte W96
	.byte W24
	.byte Cn3, v112 @ N96
	.byte W72
	.byte W96
	.byte GOTO
		.word track_11_lbl_22eb07
	.byte FINE

track_11_2:
	.byte KEYSH, 0
track_11_lbl_22eb2a:
	.byte VOICE, 58
	.byte VOL, 110
	.byte PAN, c_v-17
	.byte PRIO, 120
	.byte N96, Fn1, v092
	.byte W96
	.byte Fn1, v080 @ N96
	.byte W96
	.byte N96 @ Fn1, v080
	.byte W96
	.byte Fn1, v072 @ N96
	.byte W96
	.byte Fn1, v060 @ N96
	.byte W96
	.byte Fn1, v092 @ N96
	.byte W96
	.byte Fn1, v072 @ N96
	.byte W96
	.byte GOTO
		.word track_11_lbl_22eb2a
	.byte FINE

.align 2

track_11:
	.byte 3
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_11_0
	.word track_11_1
	.word track_11_2

.align 2
