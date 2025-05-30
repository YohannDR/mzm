.align 2

.global track_470

track_470_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 0
	.byte VOL, 0
	.byte N64, Cn2, v127
	.byte N80, Fn2, v127, 2
	.byte W01
	.byte VOL, 0
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_470:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_470_0

.align 2
