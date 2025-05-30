.align 2

.global track_543

track_543_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 4
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFOS, 120
	.byte N44, An2, v056, 3
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W28
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_543_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte N44, Gn3, v056, 3
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W16
	.byte 31 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_543:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_543_0
	.word track_543_1

.align 2
