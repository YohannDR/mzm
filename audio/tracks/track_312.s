.align 2

.global track_312

track_312_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 78
	.byte PAN, c_v
	.byte N03, Cn3, v096
	.byte W03
	.byte VOICE, 20
	.byte N08, Cn3, v100
	.byte W08
	.byte An2 @ N08, v100
	.byte W08
	.byte VOICE, 19
	.byte N15, Cn3, v092
	.byte W08
	.byte VOL, 62
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W32
	.byte W03
	.byte FINE

track_312_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N02, An4, v080
	.byte W03
	.byte N05, An2, v112
	.byte W07
	.byte Fn2, v100 @ N05
	.byte W56
	.byte W02
	.byte FINE

.align 2

track_312:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_312_0
	.word track_312_1

.align 2
