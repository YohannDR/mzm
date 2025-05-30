.align 2

.global track_286

track_286_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 69
	.byte PAN, c_v+16
	.byte N04, An2, v040
	.byte W04
	.byte N03, Cn3, v060
	.byte W03
	.byte Bn2, v080 @ N03
	.byte W03
	.byte N04, An2, v100
	.byte W04
	.byte Gn2, v120 @ N04
	.byte W04
	.byte Fn2, v080 @ N04
	.byte W04
	.byte N05, Dn2, v060
	.byte W05
	.byte N06, Cn2 @ v060
	.byte W06
	.byte N08, An1 @ v060
	.byte W36
	.byte W03
	.byte FINE

track_286_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 69
	.byte PAN, c_v+16
	.byte N11, Cn3, v112
	.byte W02
	.byte VOL, 77
	.byte W02
	.byte 86 @ VOL
	.byte W02
	.byte 95 @ VOL
	.byte W02
	.byte 103 @ VOL
	.byte W02
	.byte 110 @ VOL
	.byte W01
	.byte VOICE, 10
	.byte N13, Cn3, v127
	.byte W13
	.byte Cn3, v060 @ N13
	.byte W13
	.byte N19, Cn3, v032
	.byte W32
	.byte W03
	.byte FINE

track_286_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 103
	.byte PAN, c_v+16
	.byte W02
	.byte N02, An2, v100
	.byte W02
	.byte N04, Bn2 @ v100
	.byte W04
	.byte N15, Fn2, v127
	.byte W04
	.byte VOL, 110
	.byte W60
	.byte FINE

.align 2

track_286:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_286_0
	.word track_286_1
	.word track_286_2

.align 2
