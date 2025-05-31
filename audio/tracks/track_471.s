.align 2

.global track_471

track_471_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte N84, Cn2, v127
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W24
	.byte 62 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
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

track_471_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte N84, Fn2, v127
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W16
	.byte 62 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
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

track_471:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group12
	.word track_471_0
	.word track_471_1

.align 2
