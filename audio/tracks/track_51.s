.align 2

.global track_51

track_51_0:
	.byte KEYSH, 0
track_51_lbl_21fbd6:
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 6
	.byte N24, Cn3, v012
	.byte W96
	.byte GOTO
		.word track_51_lbl_21fbd6
	.byte FINE

.align 2

track_51:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_51_0

.align 2
