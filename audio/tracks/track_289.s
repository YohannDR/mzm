.align 2

.global track_289

track_289_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 55
	.byte PAN, c_v
	.byte W05
	.byte TIE
	.byte Cn3, En6
	.byte W01
track_289_lbl_20e617:
	.byte W90
	.byte W05
	.byte GOTO
		.word track_289_lbl_20e617
	.byte W01
	.byte EOT, Cn3

	.byte FINE

.align 2

track_289:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_289_0

.align 2
