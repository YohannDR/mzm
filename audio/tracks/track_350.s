.align 2

.global track_350

track_350_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte MOD, 45
	.byte VOL, 37
	.byte PAN, c_v
	.byte LFOS, 127
	.byte N32, An3, v080
	.byte W02
	.byte VOL, 25
	.byte W02
	.byte 20 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte FINE

.align 2

track_350:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_350_0

.align 2
