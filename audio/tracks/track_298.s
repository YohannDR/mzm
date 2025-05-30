.align 2

.global track_298

track_298_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W12
	.byte VOICE, 29
	.byte VOL, 0
	.byte PAN, c_v-10
	.byte BEND, c_v
	.byte N48, Cn2, v080
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W04
	.byte 42 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_298_1:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 29
	.byte VOL, 0
	.byte PAN, c_v-10
	.byte PRIO, 10
	.byte N48, En2, v080
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W04
	.byte 42 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_298_2:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 29
	.byte VOL, 0
	.byte PAN, c_v-10
	.byte PRIO, 20
	.byte N48, Gn2, v080
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W04
	.byte 42 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_298:
	.byte 3
	.byte 0
	.byte 180
	.byte 0
	.word voice_group4
	.word track_298_0
	.word track_298_1
	.word track_298_2

.align 2
