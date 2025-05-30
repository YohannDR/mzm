.align 2

.global track_619

track_619_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte MOD, 60
	.byte VOL, 85
	.byte PAN, c_v
	.byte LFOS, 120
	.byte N24, En3, v100, 3
	.byte W12
	.byte MOD, 30
	.byte LFOS, 100
	.byte W02
	.byte VOL, 85
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_619:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_619_0

.align 2
