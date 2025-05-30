.align 2

.global track_382

track_382_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 40
	.byte PAN, c_v
	.byte N13, Fn1, v072
	.byte W06
	.byte VOL, 40
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W12
	.byte FINE

track_382_1:
	.byte KEYSH, 0
	.byte VOICE, 40
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, Bn2, v080
	.byte W24
	.byte FINE

.align 2

track_382:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_382_0
	.word track_382_1

.align 2
