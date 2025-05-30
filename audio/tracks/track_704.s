.align 2

.global track_704

track_704_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte N15, Cn3, v127
	.byte W15
	.byte N24, An2, v127, 2
	.byte W76
	.byte W01
	.byte FINE

track_704_1:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 14
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte N15, Cn3, v127
	.byte W15
	.byte N24, An2, v127, 1
	.byte W20
	.byte VOL, 120
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W36
	.byte FINE

track_704_2:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte N02, Cn3, v127
	.byte W02
	.byte VOICE, 20
	.byte N05, Cn3, v100
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v052
	.byte W13
	.byte VOICE, 19
	.byte VOL, 75
	.byte W02
	.byte VOICE, 20
	.byte VOL, 120
	.byte N05, Cn3, v100
	.byte W01
	.byte VOL, 95
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte N14, En3, v127
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W40
	.byte W01
	.byte FINE

track_704_3:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte PRIO, 25
	.byte N02, An4, v080
	.byte W02
	.byte VOICE, 17
	.byte N02, An2, v112
	.byte W13
	.byte VOICE, 18
	.byte N02, Gn2, v080
	.byte W02
	.byte VOICE, 17
	.byte N09, Gn2, v120
	.byte W09
	.byte VOL, 120
	.byte PAN, c_v+6
	.byte PRIO, 25
	.byte W02
	.byte VOICE, 17
	.byte N02, Gn2, v112
	.byte W64
	.byte FINE

.align 2

track_704:
	.byte 4
	.byte 0
	.byte 229
	.byte 0
	.word voice_group13
	.word track_704_0
	.word track_704_1
	.word track_704_2
	.word track_704_3

.align 2
