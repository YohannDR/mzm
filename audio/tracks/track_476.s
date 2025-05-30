.align 2

.global track_476

track_476_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 120
	.byte PAN, c_v
	.byte N60, Cn3, v120
	.byte W09
	.byte VOL, 100
	.byte W02
	.byte 99 @ VOL
	.byte W04
	.byte 97 @ VOL
	.byte W04
	.byte 95 @ VOL
	.byte W02
	.byte 93 @ VOL
	.byte W02
	.byte 91 @ VOL
	.byte W02
	.byte 89 @ VOL
	.byte W02
	.byte 87 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W02
	.byte 79 @ VOL
	.byte W02
	.byte 75 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_476:
	.byte 1
	.byte 0
	.byte 227
	.byte 0
	.word voice_group12
	.word track_476_0

.align 2
