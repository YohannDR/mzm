.align 2

.global track_346

track_346_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 42
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-32
	.byte N24, Fn2, v080
	.byte W02
	.byte BEND, c_v-21
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v @ BEND
	.byte W02
	.byte VOL, 42
	.byte W02
	.byte 28 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_346:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_346_0

.align 2
