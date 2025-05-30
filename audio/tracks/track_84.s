.align 2

.global track_84

track_84_0:
	.byte KEYSH, 0
track_84_lbl_22b946:
	.byte TEMPO, 28
	.byte VOICE, 102
	.byte PAN, c_v
	.byte PRIO, 120
	.byte VOL, 11
	.byte N92, Bn1, v120, 3
	.byte N92, Fn2, v120, 3
	.byte W03
	.byte VOL, 13
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W36
	.byte W03
	.byte 29 @ VOL
	.byte W04
	.byte 27 @ VOL
	.byte W05
	.byte 25 @ VOL
	.byte W05
	.byte 22 @ VOL
	.byte W05
	.byte 20 @ VOL
	.byte W05
	.byte 17 @ VOL
	.byte W05
	.byte 15 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W01
	.byte GOTO
		.word track_84_lbl_22b946
	.byte FINE

.align 2

track_84:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_84_0

.align 2
