.align 2

.global track_588

track_588_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 90
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N64, Cn3, v127, 1
	.byte W66
	.byte Cn3, v016, 1 @ N64
	.byte W30
	.byte W24
	.byte VOL, 90
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

track_588_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 90
	.byte PAN, c_v
	.byte W36
	.byte N64, Cn3, v036, 1
	.byte W60
	.byte W05
	.byte FINE

.align 2

track_588:
	.byte 2
	.byte 0
	.byte 225
	.byte 0
	.word voice_group13
	.word track_588_0
	.word track_588_1

.align 2
