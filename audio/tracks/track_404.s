.align 2

.global track_404

track_404_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 30
	.byte VOL, 63
	.byte PAN, c_v
	.byte BENDR, 9
	.byte LFOS, 40
	.byte BEND, c_v+8
	.byte N42, Cn3, v100
	.byte W02
	.byte BEND, c_v+4
	.byte W02
	.byte c_v @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v-8 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W02
	.byte c_v-16 @ BEND
	.byte W02
	.byte c_v-20 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W02
	.byte c_v-28 @ BEND
	.byte W02
	.byte c_v-32 @ BEND
	.byte W02
	.byte c_v-36 @ BEND
	.byte W02
	.byte c_v-40 @ BEND
	.byte W02
	.byte c_v-44 @ BEND
	.byte W02
	.byte c_v-48 @ BEND
	.byte W02
	.byte c_v-52 @ BEND
	.byte W02
	.byte c_v-56 @ BEND
	.byte W02
	.byte c_v-60 @ BEND
	.byte W02
	.byte c_v-63 @ BEND
	.byte W06
	.byte FINE

track_404_1:
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
	.byte BEND, c_v+4
	.byte W02
	.byte c_v @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v-8 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W02
	.byte c_v-16 @ BEND
	.byte W02
	.byte c_v-20 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W02
	.byte c_v-28 @ BEND
	.byte W02
	.byte c_v-32 @ BEND
	.byte W02
	.byte c_v-36 @ BEND
	.byte W02
	.byte c_v-40 @ BEND
	.byte N18 @ Fn2, v100
	.byte W02
	.byte BEND, c_v-44
	.byte W02
	.byte c_v-48 @ BEND
	.byte W02
	.byte c_v-52 @ BEND
	.byte W02
	.byte c_v-56 @ BEND
	.byte W02
	.byte c_v-60 @ BEND
	.byte W02
	.byte c_v-63 @ BEND
	.byte W06
	.byte FINE

.align 2

track_404:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group6
	.word track_404_0
	.word track_404_1

.align 2
