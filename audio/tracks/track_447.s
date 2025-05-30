.align 2

.global track_447

track_447_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 94
	.byte PAN, c_v-20
	.byte W03
	.byte TIE, Cn3, v120
	.byte W02
	.byte VOL, 79
	.byte W06
	.byte 81 @ VOL
	.byte W06
	.byte 82 @ VOL
	.byte W04
	.byte 84 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W02
	.byte 87 @ VOL
	.byte W02
	.byte 88 @ VOL
	.byte W02
	.byte 89 @ VOL
	.byte W02
	.byte 90 @ VOL
	.byte W02
	.byte 92 @ VOL
	.byte W02
	.byte 94 @ VOL
	.byte W56
	.byte W03
	.byte W56
	.byte W01
	.byte EOT @ Cn3, v120
	.byte W30
	.byte FINE

track_447_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 86
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte BEND, c_v
	.byte W12
	.byte N44, Cn3, v112, 1
	.byte W06
	.byte BEND, c_v+31
	.byte W06
	.byte c_v+63 @ BEND
	.byte W32
	.byte W01
	.byte N36, Cn3, v032, 1
	.byte W36
	.byte W01
	.byte Cn3, v008, 1 @ N36
	.byte W02
	.byte W84
	.byte W03
	.byte FINE

track_447_2:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte MOD, 30
	.byte VOL, 94
	.byte PAN, c_v
	.byte LFOS, 80
	.byte PRIO, 24
	.byte TIE, Fn2, v120
	.byte W96
	.byte VOL, 62
	.byte W48
	.byte EOT @ Fn2, v120
	.byte W36
	.byte W03
	.byte FINE

.align 2

track_447:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group10
	.word track_447_0
	.word track_447_1
	.word track_447_2

.align 2
