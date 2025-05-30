.align 2

.global track_19

track_19_0:
	.byte KEYSH, 0
	.byte TEMPO, 69
	.byte W12
	.byte VOICE, 75
	.byte VOL, 94
	.byte PAN, c_v
	.byte TIE, Gn2, v092
	.byte W84
	.byte W96
	.byte W36
	.byte EOT @ Gn2, v092
	.byte W60
	.byte W24
	.byte FINE

track_19_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 94
	.byte PAN, c_v
	.byte TIE, Gn1, v112
	.byte W72
	.byte VOICE, 28
	.byte W24
	.byte W96
	.byte EOT @ Gn1, v112
	.byte W96
	.byte W24
	.byte FINE

track_19_2:
	.byte KEYSH, 0
	.byte VOICE, 71
	.byte VOL, 70
	.byte PAN, c_v+20
	.byte N48, Gn4, v080
	.byte W48
	.byte PAN, c_v-22
	.byte N48, Ds4, v092
	.byte W48
	.byte PAN, c_v+20
	.byte N48, Cn4, v104
	.byte W48
	.byte PAN, c_v-22
	.byte N48, As4, v116
	.byte W48
	.byte PAN, c_v+20
	.byte N48, Gs4, v127
	.byte W96
	.byte W24
	.byte FINE

track_19_3:
	.byte KEYSH, 0
	.byte VOICE, 71
	.byte VOL, 94
	.byte PAN, c_v+20
	.byte N06, Cn4, v112
	.byte W12
	.byte Ds4 @ N06, v112
	.byte W12
	.byte Dn4, v116 @ N06
	.byte W12
	.byte Fn4, v120 @ N06
	.byte W12
	.byte Ds4, v124 @ N06
	.byte W12
	.byte Gs4 @ N06, v124
	.byte W12
	.byte Gn4, v127 @ N06
	.byte W12
	.byte Dn4 @ N06, v127
	.byte W12
track_19_lbl_22f8c5:
	.byte N06, Cn4, v112
	.byte W12
	.byte Ds4 @ N06, v112
	.byte W12
	.byte Dn4, v116 @ N06
	.byte W12
	.byte Fn4, v120 @ N06
	.byte W12
	.byte Ds4, v124 @ N06
	.byte W12
	.byte Gs4 @ N06, v124
	.byte W12
	.byte Gn4, v127 @ N06
	.byte W12
	.byte Dn4 @ N06, v127
	.byte W12
	.byte PEND
	.byte PATT
		.word track_19_lbl_22f8c5
	.byte W24
	.byte FINE

track_19_4:
	.byte KEYSH, 0
	.byte VOICE, 52
	.byte VOL, 39
	.byte PAN, c_v-22
	.byte N12, Cn2, v064
	.byte W24
	.byte Cn2, v068 @ N12
	.byte W24
	.byte Cn2, v072 @ N12
	.byte W24
	.byte Cn2, v080 @ N12
	.byte W24
	.byte Cn2, v084 @ N12
	.byte W24
	.byte Cn2, v092 @ N12
	.byte W24
	.byte PAN, c_v+20
	.byte N12, Cn2, v096
	.byte W24
	.byte Cn2, v100 @ N12
	.byte W24
	.byte Cn2, v108 @ N12
	.byte W96
	.byte W24
	.byte FINE

.align 2

track_19:
	.byte 5
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_19_0
	.word track_19_1
	.word track_19_2
	.word track_19_3
	.word track_19_4

.align 2
