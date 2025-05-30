.align 2

.global track_490

track_490_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 86
	.byte PAN, c_v
	.byte N17, Cn3, v100
	.byte W17
	.byte FINE

track_490_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte N17, En4, v080
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_490:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group13
	.word track_490_0
	.word track_490_1

.align 2
