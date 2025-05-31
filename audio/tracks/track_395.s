.align 2

.global track_395

track_395_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 0
	.byte PAN, c_v
	.byte W04
	.byte N06, Cn4, v060
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte N07, An3 @ v060
	.byte W02
	.byte VOL, 12
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W03
	.byte FINE

.align 2

track_395:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_395_0

.align 2
