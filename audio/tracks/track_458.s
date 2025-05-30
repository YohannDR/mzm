.align 2

.global track_458

track_458_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 110
	.byte PAN, c_v
	.byte N02, Cn3, v120
	.byte W02
	.byte VOICE, 7
	.byte N05, Cn3, v100
	.byte W05
	.byte En3, v127 @ N05
	.byte W05
	.byte Dn3, v080 @ N05
	.byte W05
	.byte VOICE, 8
	.byte N18, Cn3, v032
	.byte W18
	.byte VOICE, 6
	.byte N02, Cn3, v040
	.byte W02
	.byte VOICE, 7
	.byte N13, Dn3 @ v040
	.byte W13
	.byte VOICE, 8
	.byte N18, Cn3, v020
	.byte W36
	.byte W01
	.byte FINE

track_458_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 6
	.byte VOL, 110
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte VOICE, 7
	.byte N05, Cn3, v100
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v080
	.byte W13
	.byte VOICE, 8
	.byte N18, Cn3, v040
	.byte W44
	.byte W01
	.byte FINE

track_458_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 33
	.byte N05, An2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W12
	.byte N05, Gn2, v100
	.byte W08
	.byte N04, Fn2 @ v100
	.byte W60
	.byte W02
	.byte FINE

.align 2

track_458:
	.byte 3
	.byte 0
	.byte 220
	.byte 0
	.word voice_group10
	.word track_458_0
	.word track_458_1
	.word track_458_2

.align 2
