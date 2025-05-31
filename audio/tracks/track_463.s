.align 2

.global track_463

track_463_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 80
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N44, An2, v100, 2
	.byte W06
	.byte BEND, c_v+31
	.byte W06
	.byte c_v+63 @ BEND
	.byte W24
	.byte W01
	.byte VOL, 80
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 23 @ VOL
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
	.byte FINE

.align 2

track_463:
	.byte 1
	.byte 0
	.byte 204
	.byte 0
	.word voice_group10
	.word track_463_0

.align 2
