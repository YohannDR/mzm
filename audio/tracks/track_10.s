.align 2

.global track_10

track_10_0:
	.byte KEYSH, 0
track_10_lbl_22e99e:
	.byte TEMPO, 49
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 28
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 97
	.byte PAN, c_v+15
	.byte TIE, En2, v040
	.byte W96
	.byte W48
	.byte EOT @ En2, v040
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte PAN, c_v
	.byte TIE, Cn2 @ v040
	.byte W96
	.byte W48
	.byte EOT @ Cn2, v040
	.byte W48
	.byte GOTO
		.word track_10_lbl_22e99e
	.byte FINE

track_10_1:
	.byte KEYSH, 0
track_10_lbl_22e9cb:
	.byte VOICE, 96
	.byte VOL, 62
	.byte PAN, c_v-17
	.byte PRIO, 27
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
		.word track_10_lbl_22e9cb
	.byte FINE

track_10_2:
	.byte KEYSH, 0
track_10_lbl_22e9f2:
	.byte VOICE, 96
	.byte VOL, 62
	.byte PAN, c_v+15
	.byte PRIO, 29
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
		.word track_10_lbl_22e9f2
	.byte FINE

track_10_3:
	.byte KEYSH, 0
track_10_lbl_22ea19:
	.byte VOICE, 27
	.byte VOL, 75
	.byte PAN, c_v
	.byte PRIO, 120
	.byte W96
	.byte N96, An1, v112
	.byte W96
	.byte Cn2 @ N96, v112
	.byte W96
	.byte Bn1 @ N96, v112
	.byte W96
	.byte TIE, En1, v100
	.byte W96
	.byte W48
	.byte EOT @ En1, v100
	.byte W48
	.byte W96
	.byte N96, An1, v112
	.byte W96
	.byte Cn2 @ N96, v112
	.byte W96
	.byte Bn1 @ N96, v112
	.byte W96
	.byte N90, En2, v072
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_10_lbl_22ea19
	.byte FINE

track_10_4:
	.byte KEYSH, 0
track_10_lbl_22ea49:
	.byte VOICE, 26
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 30
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
		.word track_10_lbl_22ea49
	.byte FINE

track_10_5:
	.byte KEYSH, 0
track_10_lbl_22ea78:
	.byte W48
	.byte VOICE, 58
	.byte VOL, 44
	.byte PAN, c_v+15
	.byte PRIO, 118
	.byte N96, Bn1, v080
	.byte W48
	.byte W48
	.byte Bn1, v072 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v092 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v080 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v072 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v092 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v072 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v080 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v072 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v060 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v080 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v092 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v080 @ N96
	.byte W48
	.byte W48
	.byte Bn1, v092 @ N96
	.byte W48
	.byte GOTO
		.word track_10_lbl_22ea78
	.byte W48
	.byte FINE

.align 2

track_10:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_10_0
	.word track_10_1
	.word track_10_2
	.word track_10_3
	.word track_10_4
	.word track_10_5

.align 2
