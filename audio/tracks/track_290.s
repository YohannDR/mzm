.align 2

.global track_290

track_290_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 0
	.byte PAN, c_v
	.byte TIE
	.byte En2, Gs4
	.byte W03
	.byte VOL, 0
	.byte W03
	.byte CsM2
	.byte W03
	.byte CsM2
	.byte W03
	.byte DnM2
	.byte W03
	.byte EnM2
	.byte W03
	.byte FsM2
	.byte W03
	.byte GsM2
	.byte W03
	.byte CsM1
	.byte W03
	.byte BnM1
	.byte W03
	.byte Cs2
	.byte W01
track_290_lbl_20e653:
	.byte W64
	.byte W01
	.byte GOTO
		.word track_290_lbl_20e653
	.byte W01
	.byte EOT, En2

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
