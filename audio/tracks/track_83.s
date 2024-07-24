.align 2

.global track_83

track_83_0:
	.byte KEYSH, 0
track_83_lbl_22b8fe:
	.byte TEMPO, 28
	.byte VOICE, 102
	.byte PAN, c_v
	.byte PRIO, 120
	.byte VOL, 5
	.byte N92
	.byte Cn2, Cn8, DsM2
	.byte W03
	.byte VOL, 7
	.byte W03
	.byte AsM2
	.byte W03
	.byte CnM1
	.byte W03
	.byte DsM1
	.byte W03
	.byte FnM1
	.byte W03
	.byte GsM1
	.byte W03
	.byte BnM1
	.byte W03
	.byte Cs0
	.byte W36
	.byte W03
	.byte BnM1
	.byte W04
	.byte AnM1
	.byte W05
	.byte FsM1
	.byte W05
	.byte EnM1
	.byte W05
	.byte CsM1
	.byte W05
	.byte BnM2
	.byte W05
	.byte GsM2
	.byte W03
	.byte FsM2
	.byte W01
	.byte GOTO
		.word track_83_lbl_22b8fe

	.byte FINE

.align 2

track_83:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_83_0

.align 2
