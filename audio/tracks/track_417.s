.align 2

.global track_417

track_417_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 76
	.byte PAN, c_v
	.byte N04, An4, v092
	.byte W36
	.byte W01
	.byte FINE

track_417_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 95
	.byte PAN, c_v
	.byte N44, Cn3, v112, 1
	.byte W02
	.byte VOL, 82
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W04
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_417:
	.byte 2
	.byte 0
	.byte 166
	.byte 0
	.word voice_group8
	.word track_417_0
	.word track_417_1

.align 2
