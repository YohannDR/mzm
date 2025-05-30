.align 2

.global track_290

track_290_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 0
	.byte PAN, c_v
	.byte TIE, En2, v080
	.byte W03
	.byte VOL, 0
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W01
track_290_lbl_20e653:
	.byte W64
	.byte W01
	.byte GOTO
		.word track_290_lbl_20e653
	.byte W01
	.byte EOT, En2 @ v080
	.byte FINE

.align 2

track_290:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_290_0

.align 2
