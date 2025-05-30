.align 2

.global track_28

track_28_0:
	.byte KEYSH, 0
track_28_lbl_23201e:
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 75
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N96, An1, v127
	.byte W96
	.byte Cn2 @ N96, v127
	.byte W96
	.byte Bn1 @ N96, v127
	.byte W96
	.byte En1 @ N96, v127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_28_lbl_23201e
	.byte FINE

track_28_1:
	.byte KEYSH, 0
track_28_lbl_232044:
	.byte VOICE, 26
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 119
	.byte N12, Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_28_lbl_232044
	.byte FINE

track_28_2:
	.byte KEYSH, 0
track_28_lbl_232068:
	.byte VOICE, 58
	.byte VOL, 44
	.byte PAN, c_v-17
	.byte PRIO, 30
	.byte N96, Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_28_lbl_232068
	.byte FINE

track_28_3:
	.byte KEYSH, 0
track_28_lbl_23208c:
	.byte VOICE, 58
	.byte VOL, 44
	.byte PAN, c_v+15
	.byte PRIO, 118
	.byte N96, Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_28_lbl_23208c
	.byte FINE

.align 2

track_28:
	.byte 4
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_28_0
	.word track_28_1
	.word track_28_2
	.word track_28_3

.align 2
