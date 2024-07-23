.align 2

.global track_56

track_56_0:
	.byte KEYSH, 0
track_56_lbl_2213d6:
	.byte TEMPO, 60
	.byte VOICE, 3
	.byte VOL, 7
	.byte N24
	.byte Cn3, CnM1
	.byte W96
	.byte GOTO
		.word track_56_lbl_2213d6

	.byte FINE

.align 2

track_56:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voice_group21
	.word track_56_0

.align 2
