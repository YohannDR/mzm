.align 2

.global track_446

track_446_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 78
	.byte PAN, c_v
	.byte TIE, Bn2, v100
	.byte W96
	.byte W96
	.byte W96
	.byte W40
	.byte VOL, 54
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ Bn2, v100
	.byte W24
	.byte FINE

track_446_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte TIE, Bn2, v080
	.byte W06
	.byte BEND, c_v-1
	.byte W10
	.byte c_v-2 @ BEND
	.byte W10
	.byte c_v-3 @ BEND
	.byte W12
	.byte c_v-4 @ BEND
	.byte W10
	.byte c_v-5 @ BEND
	.byte W10
	.byte c_v-6 @ BEND
	.byte W10
	.byte c_v-7 @ BEND
	.byte W10
	.byte c_v-8 @ BEND
	.byte W12
	.byte c_v-9 @ BEND
	.byte W06
	.byte W04
	.byte c_v-10 @ BEND
	.byte W10
	.byte c_v-11 @ BEND
	.byte W10
	.byte c_v-12 @ BEND
	.byte W10
	.byte c_v-13 @ BEND
	.byte W12
	.byte c_v-14 @ BEND
	.byte W10
	.byte c_v-15 @ BEND
	.byte W10
	.byte c_v-16 @ BEND
	.byte W10
	.byte c_v-17 @ BEND
	.byte W10
	.byte c_v-18 @ BEND
	.byte W10
	.byte c_v-19 @ BEND
	.byte W12
	.byte c_v-20 @ BEND
	.byte W10
	.byte c_v-21 @ BEND
	.byte W10
	.byte c_v-22 @ BEND
	.byte W10
	.byte c_v-23 @ BEND
	.byte W10
	.byte c_v-24 @ BEND
	.byte W12
	.byte c_v-25 @ BEND
	.byte W10
	.byte c_v-26 @ BEND
	.byte W10
	.byte c_v-27 @ BEND
	.byte W10
	.byte c_v-28 @ BEND
	.byte W02
	.byte W08
	.byte c_v-29 @ BEND
	.byte W10
	.byte c_v-30 @ BEND
	.byte W12
	.byte c_v-31 @ BEND
	.byte W10
	.byte VOL, 54
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ Bn2, v080
	.byte W24
	.byte FINE

track_446_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte MOD, 30
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 100
	.byte PRIO, 2
	.byte N24, Fn2, v080
	.byte W24
	.byte LFOS, 80
	.byte N24 @ Fn2, v080
	.byte W24
	.byte LFOS, 60
	.byte N24 @ Fn2, v080
	.byte W24
	.byte LFOS, 80
	.byte N24 @ Fn2, v080
	.byte W24
track_446_lbl_21469f:
	.byte LFOS, 100
	.byte N24, Fn2, v080
	.byte W24
	.byte LFOS, 80
	.byte N24 @ Fn2, v080
	.byte W24
	.byte LFOS, 60
	.byte N24 @ Fn2, v080
	.byte W24
	.byte LFOS, 80
	.byte N24 @ Fn2, v080
	.byte W24
	.byte PEND
	.byte PATT
		.word track_446_lbl_21469f
	.byte LFOS, 100
	.byte N24, Fn2, v080
	.byte W24
	.byte LFOS, 80
	.byte N12 @ Fn2, v080
	.byte W48
	.byte FINE

.align 2

track_446:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group9
	.word track_446_0
	.word track_446_1
	.word track_446_2

.align 2
