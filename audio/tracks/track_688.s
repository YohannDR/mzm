.align 2

.global track_688

track_688_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte N15, Cn3, v127
	.byte W15
	.byte N24, An2, v127, 2
	.byte W24
	.byte W02
	.byte N15, Cn3, v080
	.byte W15
	.byte N24, An2, v080, 2
	.byte W40
	.byte W12
	.byte FINE

track_688_1:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte N15, Cn3, v127
	.byte W15
	.byte N24, An2, v127, 1
	.byte W24
	.byte W01
	.byte N15, An2, v080
	.byte W15
	.byte N24, Fn2, v080, 1
	.byte W32
	.byte W03
	.byte W12
	.byte FINE

track_688_2:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 127
	.byte PAN, c_v+6
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
	.byte VOL, 80
	.byte W02
	.byte VOICE, 20
	.byte N05, Cn3, v100
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v052
	.byte W13
	.byte VOICE, 21
	.byte N18, Cn3, v020
	.byte W28
	.byte W12
	.byte FINE

track_688_3:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 127
	.byte PAN, c_v+6
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
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte PRIO, 25
	.byte W02
	.byte VOICE, 17
	.byte N02, An2, v112
	.byte W13
	.byte VOICE, 18
	.byte N02, Gn2, v080
	.byte W02
	.byte VOICE, 17
	.byte N09, Gn2, v120
	.byte W52
	.byte W01
	.byte W12
	.byte FINE

.align 2

track_688:
	.byte 4
	.byte 0
	.byte 251
	.byte 0
	.word voice_group13
	.word track_688_0
	.word track_688_1
	.word track_688_2
	.word track_688_3

.align 2
