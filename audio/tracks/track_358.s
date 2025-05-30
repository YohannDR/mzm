.align 2

.global track_358

track_358_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 25
	.byte VOL, 50
	.byte PAN, c_v
	.byte N24, Fn4, v100, 1
	.byte W04
	.byte VOL, 42
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 14 @ VOL
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
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_358:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_358_0

.align 2
