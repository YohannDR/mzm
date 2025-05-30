.align 2

.global track_265

track_265_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 40
	.byte PAN, c_v
	.byte N21, Dn3, v060
	.byte W16
	.byte VOL, 33
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_265:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_265_0

.align 2
