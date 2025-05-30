.align 2

.global track_287

track_287_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 81
	.byte PAN, c_v+16
	.byte N03, An2, v040
	.byte W03
	.byte Cn3, v060 @ N03
	.byte W03
	.byte N04, Bn2, v080
	.byte W04
	.byte An2, v100 @ N04
	.byte W04
	.byte N05, Gn2, v127
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W05
	.byte N06, Dn2, v080
	.byte W06
	.byte Cn2, v072 @ N06
	.byte W06
	.byte N08, An1, v060
	.byte W36
	.byte FINE

track_287_1:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 10
	.byte VOL, 115
	.byte PAN, c_v+16
	.byte N13, Cn3, v127
	.byte W13
	.byte Cn3, v060 @ N13
	.byte W13
	.byte N19, Cn3, v032
	.byte W32
	.byte W02
	.byte FINE

track_287_2:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 72
	.byte PAN, c_v+16
	.byte N11, Cn3, v112
	.byte W02
	.byte VOL, 76
	.byte W02
	.byte 81 @ VOL
	.byte W02
	.byte 86 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 115 @ VOL
	.byte W01
	.byte N04, Cn3, v080
	.byte W06
	.byte VOICE, 12
	.byte VOL, 108
	.byte N03, En3, v120
	.byte W05
	.byte N10, Cn3 @ v120
	.byte W11
	.byte N19, Cn3, v040
	.byte W36
	.byte W03
	.byte FINE

track_287_3:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 115
	.byte PAN, c_v+16
	.byte W04
	.byte N02, An2, v120
	.byte W03
	.byte N04, Bn2 @ v120
	.byte W04
	.byte N15, Fn2, v127
	.byte W60
	.byte W01
	.byte FINE

.align 2

track_287:
	.byte 4
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_287_0
	.word track_287_1
	.word track_287_2
	.word track_287_3

.align 2
