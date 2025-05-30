.align 2

.global track_557

track_557_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte MOD, 30
	.byte VOL, 66
	.byte PAN, c_v
	.byte LFOS, 60
	.byte PRIO, 25
	.byte N24, En2, v060
	.byte W24
	.byte LFOS, 64
	.byte N24, En2, v068
	.byte W24
	.byte LFOS, 68
	.byte N24, En2, v076
	.byte W24
	.byte LFOS, 72
	.byte N24, En2, v084
	.byte W24
	.byte LFOS, 76
	.byte N24, En2, v088
	.byte W24
	.byte LFOS, 80
	.byte N24, En2, v096
	.byte W24
	.byte LFOS, 84
	.byte N24, En2, v100
	.byte W24
	.byte LFOS, 88
	.byte N24, En2, v104
	.byte W24
	.byte FINE

track_557_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 80
	.byte PAN, c_v
	.byte TIE, En2, v112
	.byte W96
	.byte W88
	.byte W01
	.byte VOL, 64
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ En2, v112
	.byte FINE

track_557_2:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 53
	.byte PAN, c_v
	.byte N08, Fn1, v036
	.byte W08
	.byte Fn1, v040 @ N08
	.byte W08
	.byte Fn1, v044 @ N08
	.byte W08
	.byte N08 @ Fn1, v044
	.byte W08
	.byte Fn1, v048 @ N08
	.byte W08
	.byte Fn1, v052 @ N08
	.byte W08
	.byte An1, v056 @ N08
	.byte W08
	.byte An1, v060 @ N08
	.byte W08
	.byte An1, v068 @ N08
	.byte W08
	.byte An1, v072 @ N08
	.byte W08
	.byte An1, v076 @ N08
	.byte W08
	.byte An1, v080 @ N08
	.byte W08
	.byte Cn2 @ N08, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte N08 @ Cn2, v080
	.byte W08
	.byte Cn2, v060 @ N08
	.byte W08
	.byte Cn2, v020 @ N08
	.byte W08
	.byte Cn2, v012 @ N08
	.byte W08
	.byte FINE

.align 2

track_557:
	.byte 3
	.byte 0
	.byte 228
	.byte 0
	.word voice_group10
	.word track_557_0
	.word track_557_1
	.word track_557_2

.align 2
