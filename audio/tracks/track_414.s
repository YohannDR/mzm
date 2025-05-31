.align 2

.global track_414

track_414_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 30
	.byte VOL, 63
	.byte PAN, c_v
	.byte BENDR, 9
	.byte LFOS, 40
	.byte BEND, c_v+8
	.byte N56, Cn3, v100
	.byte W02
	.byte BEND, c_v+5
	.byte W02
	.byte c_v+2 @ BEND
	.byte W02
	.byte c_v-1 @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v-7 @ BEND
	.byte W02
	.byte c_v-10 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W02
	.byte c_v-15 @ BEND
	.byte W02
	.byte c_v-18 @ BEND
	.byte W02
	.byte c_v-21 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W02
	.byte c_v-27 @ BEND
	.byte W02
	.byte c_v-29 @ BEND
	.byte W02
	.byte c_v-32 @ BEND
	.byte W02
	.byte c_v-35 @ BEND
	.byte W02
	.byte c_v-38 @ BEND
	.byte W02
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-44 @ BEND
	.byte W02
	.byte c_v-46 @ BEND
	.byte W02
	.byte c_v-49 @ BEND
	.byte W02
	.byte c_v-52 @ BEND
	.byte W02
	.byte c_v-55 @ BEND
	.byte W02
	.byte c_v-58 @ BEND
	.byte W02
	.byte c_v-61 @ BEND
	.byte W02
	.byte c_v-63 @ BEND
	.byte W06
	.byte FINE

track_414_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte MOD, 30
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 6
	.byte LFOS, 120
	.byte BEND, c_v+8
	.byte N24, Fn2, v100
	.byte W02
	.byte BEND, c_v+5
	.byte W02
	.byte c_v+2 @ BEND
	.byte W02
	.byte c_v-1 @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v-7 @ BEND
	.byte W02
	.byte c_v-10 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W02
	.byte c_v-15 @ BEND
	.byte W02
	.byte c_v-18 @ BEND
	.byte W02
	.byte c_v-21 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W02
	.byte c_v-27 @ BEND
	.byte N24 @ Fn2, v100
	.byte W02
	.byte BEND, c_v-29
	.byte W02
	.byte c_v-32 @ BEND
	.byte W02
	.byte c_v-35 @ BEND
	.byte W02
	.byte c_v-38 @ BEND
	.byte W02
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-44 @ BEND
	.byte W02
	.byte c_v-46 @ BEND
	.byte W02
	.byte c_v-49 @ BEND
	.byte W02
	.byte c_v-52 @ BEND
	.byte W02
	.byte c_v-55 @ BEND
	.byte W02
	.byte c_v-58 @ BEND
	.byte W02
	.byte c_v-61 @ BEND
	.byte N08 @ Fn2, v100
	.byte W02
	.byte BEND, c_v-63
	.byte W06
	.byte FINE

.align 2

track_414:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group6
	.word track_414_0
	.word track_414_1

.align 2
