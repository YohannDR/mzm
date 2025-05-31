.align 2

.global track_381

track_381_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 35
	.byte PAN, c_v
	.byte N02, An2, v100
	.byte W02
	.byte VOICE, 8
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N12, Fn1 @ v100
	.byte W01
	.byte BEND, c_v-35
	.byte W01
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_381:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_381_0

.align 2
