.align 2

.global track_405

track_405_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 30
	.byte VOL, 63
	.byte PAN, c_v
	.byte BENDR, 8
	.byte LFOS, 40
	.byte BEND, c_v-63
	.byte N44, Cn3, v100
	.byte W02
	.byte BEND, c_v-61
	.byte W02
	.byte c_v-58 @ BEND
	.byte W02
	.byte c_v-55 @ BEND
	.byte W02
	.byte c_v-52 @ BEND
	.byte W02
	.byte c_v-49 @ BEND
	.byte W02
	.byte c_v-46 @ BEND
	.byte W02
	.byte c_v-43 @ BEND
	.byte W02
	.byte c_v-40 @ BEND
	.byte W02
	.byte c_v-37 @ BEND
	.byte W02
	.byte c_v-34 @ BEND
	.byte W02
	.byte c_v-31 @ BEND
	.byte W02
	.byte c_v-28 @ BEND
	.byte W02
	.byte c_v-25 @ BEND
	.byte W02
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v-20 @ BEND
	.byte W02
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-14 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-8 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte FINE

track_405_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte MOD, 30
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 6
	.byte LFOS, 120
	.byte BEND, c_v-63
	.byte N24, Fn2, v100
	.byte W02
	.byte BEND, c_v-61
	.byte W02
	.byte c_v-58 @ BEND
	.byte W02
	.byte c_v-55 @ BEND
	.byte W02
	.byte c_v-52 @ BEND
	.byte W02
	.byte c_v-49 @ BEND
	.byte W02
	.byte c_v-46 @ BEND
	.byte W02
	.byte c_v-43 @ BEND
	.byte W02
	.byte c_v-40 @ BEND
	.byte W02
	.byte c_v-37 @ BEND
	.byte W02
	.byte c_v-34 @ BEND
	.byte W02
	.byte c_v-31 @ BEND
	.byte W02
	.byte c_v-28 @ BEND
	.byte N20 @ Fn2, v100
	.byte W02
	.byte BEND, c_v-25
	.byte W02
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v-20 @ BEND
	.byte W02
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-14 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-8 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte FINE

.align 2

track_405:
	.byte 2
	.byte 0
	.byte 201
	.byte 0
	.word voice_group6
	.word track_405_0
	.word track_405_1

.align 2
