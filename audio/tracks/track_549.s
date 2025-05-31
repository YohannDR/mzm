.align 2

.global track_549

track_549_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 28
	.byte PAN, c_v
	.byte N21, Cn3, v060
	.byte W16
	.byte VOL, 23
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_549:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_549_0

.align 2
