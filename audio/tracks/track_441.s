.align 2

.global track_441

track_441_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 0
	.byte PAN, c_v
	.byte TIE, Cn3, v100
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W92
	.byte W01
	.byte W96
	.byte W48
	.byte EOT @ Cn3, v100
	.byte FINE

track_441_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte TIE, Bn2, v080
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W30
	.byte W01
	.byte BEND, c_v-62
	.byte W04
	.byte c_v-61 @ BEND
	.byte W02
	.byte c_v-60 @ BEND
	.byte W04
	.byte c_v-59 @ BEND
	.byte W02
	.byte c_v-58 @ BEND
	.byte W04
	.byte c_v-57 @ BEND
	.byte W04
	.byte c_v-56 @ BEND
	.byte W02
	.byte c_v-55 @ BEND
	.byte W04
	.byte c_v-54 @ BEND
	.byte W02
	.byte c_v-53 @ BEND
	.byte W04
	.byte c_v-52 @ BEND
	.byte W04
	.byte c_v-51 @ BEND
	.byte W02
	.byte c_v-50 @ BEND
	.byte W04
	.byte c_v-49 @ BEND
	.byte W02
	.byte c_v-48 @ BEND
	.byte W04
	.byte c_v-47 @ BEND
	.byte W02
	.byte c_v-46 @ BEND
	.byte W04
	.byte c_v-45 @ BEND
	.byte W04
	.byte c_v-44 @ BEND
	.byte W02
	.byte c_v-43 @ BEND
	.byte W02
	.byte W02
	.byte c_v-42 @ BEND
	.byte W02
	.byte c_v-41 @ BEND
	.byte W04
	.byte c_v-40 @ BEND
	.byte W04
	.byte c_v-39 @ BEND
	.byte W02
	.byte c_v-38 @ BEND
	.byte W04
	.byte c_v-37 @ BEND
	.byte W02
	.byte c_v-36 @ BEND
	.byte W04
	.byte c_v-35 @ BEND
	.byte W02
	.byte c_v-34 @ BEND
	.byte W04
	.byte c_v-33 @ BEND
	.byte W04
	.byte c_v-32 @ BEND
	.byte W02
	.byte c_v-31 @ BEND
	.byte W04
	.byte c_v-30 @ BEND
	.byte W02
	.byte c_v-29 @ BEND
	.byte W04
	.byte c_v-28 @ BEND
	.byte W04
	.byte c_v-27 @ BEND
	.byte W02
	.byte c_v-26 @ BEND
	.byte W04
	.byte c_v-25 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W04
	.byte c_v-23 @ BEND
	.byte W04
	.byte c_v-22 @ BEND
	.byte W02
	.byte c_v-21 @ BEND
	.byte W04
	.byte c_v-20 @ BEND
	.byte W02
	.byte c_v-19 @ BEND
	.byte W04
	.byte c_v-18 @ BEND
	.byte W02
	.byte c_v-17 @ BEND
	.byte W03
	.byte c_v-16 @ BEND
	.byte W13
	.byte W48
	.byte EOT @ Bn2, v080
	.byte FINE

track_441_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte MOD, 30
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 100
	.byte PRIO, 25
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
	.byte LFOS, 100
	.byte N24 @ Fn2, v080
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
	.byte LFOS, 100
	.byte N24 @ Fn2, v080
	.byte W24
	.byte LFOS, 80
	.byte N24 @ Fn2, v080
	.byte W24
	.byte FINE

.align 2

track_441:
	.byte 3
	.byte 0
	.byte 228
	.byte 0
	.word voice_group9
	.word track_441_0
	.word track_441_1
	.word track_441_2

.align 2
