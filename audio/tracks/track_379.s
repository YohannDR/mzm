.align 2

.global track_379

track_379_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte MOD, 20
	.byte VOL, 29
	.byte PAN, c_v
	.byte BENDR, 8
	.byte LFOS, 120
	.byte W04
	.byte BEND, c_v-32
	.byte N10, Fn2, v080
	.byte W02
	.byte BEND, c_v-19
	.byte W02
	.byte c_v-6 @ BEND
	.byte W02
	.byte c_v-19 @ BEND
	.byte W02
	.byte c_v-26 @ BEND
	.byte W02
	.byte c_v-32 @ BEND
	.byte N06, An2, v060
	.byte W02
	.byte BEND, c_v-16
	.byte W02
	.byte c_v @ BEND
	.byte W02
	.byte FINE

.align 2

track_379:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_379_0

.align 2
