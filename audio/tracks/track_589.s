.align 2

.global track_589

track_589_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W48
	.byte W02
	.byte VOICE, 20
	.byte VOL, 70
	.byte BEND, c_v
	.byte N03, Cn3, v080
	.byte W03
	.byte N04, An2, v060
	.byte W42
	.byte W01
	.byte W16
	.byte VOICE, 7
	.byte N05, Fn4, v068
	.byte W05
	.byte N09, Fn4, v020
	.byte W09
	.byte VOICE, 4
	.byte N12, Fn2, v092
	.byte W11
	.byte VOL, 23
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

track_589_1:
	.byte KEYSH, 0
	.byte W48
	.byte W02
	.byte VOICE, 21
	.byte VOL, 47
	.byte PAN, c_v
	.byte W10
	.byte N28, Cn3, v060
	.byte W22
	.byte VOL, 47
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_589:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_589_0
	.word track_589_1

.align 2
