.align 2

.global track_288

track_288_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 44
	.byte PAN, c_v
	.byte W01
track_288_lbl_20e5ef:
	.byte N07, Cn3, v080
	.byte W14
	.byte GOTO
		.word track_288_lbl_20e5ef
	.byte FINE

.align 2

track_288:
	.byte 1
	.byte 0
	.byte 254
	.byte 0
	.word voice_group4
	.word track_288_0

.align 2
