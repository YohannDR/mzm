.align 2

.global track_24

track_24_0:
	.byte KEYSH, 0
track_24_lbl_22ff56:
	.byte TEMPO, 49
	.byte VOICE, 99
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 28
	.byte TIE, Gn3, v127
	.byte W96
	.byte W96
	.byte EOT @ Gn3, v127
	.byte VOICE, 97
	.byte PAN, c_v+15
	.byte TIE, Fn1, v060
	.byte W96
	.byte W96
	.byte EOT @ Fn1, v060
	.byte W96
	.byte W96
	.byte PAN, c_v-17
	.byte TIE, An1 @ v060
	.byte W96
	.byte W96
	.byte EOT @ An1, v060
	.byte W96
	.byte W96
	.byte PAN, c_v
	.byte TIE, Fs1 @ v060
	.byte W96
	.byte W96
	.byte EOT @ Fs1, v060
	.byte W96
	.byte W96
	.byte GOTO
		.word track_24_lbl_22ff56
	.byte FINE

track_24_1:
	.byte KEYSH, 0
track_24_lbl_22ff8c:
	.byte VOICE, 96
	.byte VOL, 62
	.byte PAN, c_v-17
	.byte PRIO, 29
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
	.byte GOTO
		.word track_24_lbl_22ff8c
	.byte FINE

track_24_2:
	.byte KEYSH, 0
track_24_lbl_22ffb3:
	.byte VOICE, 96
	.byte VOL, 62
	.byte PAN, c_v+15
	.byte PRIO, 30
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
	.byte GOTO
		.word track_24_lbl_22ffb3
	.byte FINE

track_24_3:
	.byte KEYSH, 0
track_24_lbl_22ffda:
	.byte VOICE, 26
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 118
	.byte N12, Gs2, v116
	.byte W96
	.byte Gs2, v127 @ N12
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte N12 @ Gs2, v127
	.byte W96
	.byte GOTO
		.word track_24_lbl_22ffda
	.byte FINE

track_24_4:
	.byte KEYSH, 0
track_24_lbl_230009:
	.byte VOICE, 58
	.byte VOL, 44
	.byte PAN, c_v-17
	.byte PRIO, 119
	.byte N96, Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte N96 @ Bn1, v100
	.byte W96
	.byte GOTO
		.word track_24_lbl_230009
	.byte FINE

track_24_5:
	.byte KEYSH, 0
track_24_lbl_230037:
	.byte W48
	.byte VOICE, 58
	.byte VOL, 44
	.byte PAN, c_v+15
	.byte PRIO, 120
	.byte N96, Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte W48
	.byte N96 @ Bn1, v100
	.byte W48
	.byte GOTO
		.word track_24_lbl_230037
	.byte W48
	.byte FINE

.align 2

track_24:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_24_0
	.word track_24_1
	.word track_24_2
	.word track_24_3
	.word track_24_4
	.word track_24_5

.align 2
