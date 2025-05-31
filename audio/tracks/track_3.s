.align 2

.global track_3

track_3_0:
	.byte KEYSH, 0
track_3_lbl_22c9be:
	.byte TEMPO, 37
	.byte VOICE, 21
	.byte VOL, 18
	.byte PAN, c_v
	.byte N06, As5, v040
	.byte W24
	.byte Fn5 @ N06, v040
	.byte W24
	.byte An5 @ N06, v040
	.byte W24
	.byte Cs5 @ N06, v040
	.byte W24
	.byte W36
	.byte Cn5 @ N06, v040
	.byte W24
	.byte Fs5 @ N06, v040
	.byte W24
	.byte Bn5 @ N06, v040
	.byte W12
	.byte W36
	.byte Fn6 @ N06, v040
	.byte W24
	.byte Dn6 @ N06, v040
	.byte W36
	.byte W96
	.byte W72
	.byte GOTO
		.word track_3_lbl_22c9be
	.byte FINE

track_3_1:
	.byte KEYSH, 0
track_3_lbl_22c9e6:
	.byte VOICE, 22
	.byte VOL, 18
	.byte PAN, c_v
	.byte W06
	.byte N03, As5, v032
	.byte W24
	.byte Fn5 @ N03, v032
	.byte W24
	.byte An5 @ N03, v032
	.byte W24
	.byte Cs5 @ N03, v032
	.byte W18
	.byte W42
	.byte Cn5 @ N03, v032
	.byte W24
	.byte Fs5 @ N03, v032
	.byte W24
	.byte Bn5 @ N03, v032
	.byte W06
	.byte W42
	.byte Fn6 @ N03, v032
	.byte W24
	.byte Dn6 @ N03, v032
	.byte W30
	.byte W96
	.byte W72
	.byte GOTO
		.word track_3_lbl_22c9e6
	.byte FINE

track_3_2:
	.byte KEYSH, 0
track_3_lbl_22ca0d:
	.byte VOICE, 14
	.byte VOL, 75
	.byte PAN, c_v-14
	.byte N96, Dn3, v100
	.byte W96
	.byte W36
	.byte N96 @ Dn3, v100
	.byte W60
	.byte W96
	.byte W12
	.byte TIE @ Dn3, v100
	.byte W84
	.byte W36
	.byte EOT @ Dn3, v100
	.byte W36
	.byte GOTO
		.word track_3_lbl_22ca0d
	.byte FINE

track_3_3:
	.byte KEYSH, 0
track_3_lbl_22ca29:
	.byte VOICE, 19
	.byte VOL, 37
	.byte PAN, c_v+14
	.byte N96, AsM1, v092
	.byte W96
	.byte W36
	.byte N96 @ AsM1, v092
	.byte W60
	.byte W96
	.byte W12
	.byte TIE @ AsM1, v092
	.byte W84
	.byte W36
	.byte EOT @ AsM1, v092
	.byte W36
	.byte GOTO
		.word track_3_lbl_22ca29
	.byte FINE

track_3_4:
	.byte KEYSH, 0
track_3_lbl_22ca45:
	.byte VOICE, 14
	.byte VOL, 25
	.byte PAN, c_v
	.byte N06, As3, v080
	.byte W24
	.byte Fn3 @ N06, v080
	.byte W24
	.byte An3 @ N06, v080
	.byte W24
	.byte Cs3 @ N06, v080
	.byte W24
	.byte W36
	.byte Cn3 @ N06, v080
	.byte W24
	.byte Fs3 @ N06, v080
	.byte W24
	.byte Bn3 @ N06, v080
	.byte W12
	.byte W36
	.byte Fn3 @ N06, v080
	.byte W24
	.byte Dn3 @ N06, v080
	.byte W36
	.byte W96
	.byte W72
	.byte GOTO
		.word track_3_lbl_22ca45
	.byte FINE

.align 2

track_3:
	.byte 5
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_3_0
	.word track_3_1
	.word track_3_2
	.word track_3_3
	.word track_3_4

.align 2
