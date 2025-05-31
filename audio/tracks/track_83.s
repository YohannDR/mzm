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
	.byte N92, Cn2, v120, 3
	.byte W03
	.byte VOL, 7
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W36
	.byte W03
	.byte 23 @ VOL
	.byte W04
	.byte 21 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W05
	.byte 16 @ VOL
	.byte W05
	.byte 13 @ VOL
	.byte W05
	.byte 11 @ VOL
	.byte W05
	.byte 8 @ VOL
	.byte W03
	.byte 6 @ VOL
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
