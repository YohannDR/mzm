.align 2

.global track_437

track_437_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 28
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N12, Cn2, v060
	.byte W12
	.byte N18, En2 @ v060
	.byte W18
	.byte FINE

track_437_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 0
	.byte PAN, c_v
	.byte N18, An3, v120
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte N18, Cn4, v060
	.byte W01
	.byte VOL, 46
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_437:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group9
	.word track_437_0
	.word track_437_1

.align 2
