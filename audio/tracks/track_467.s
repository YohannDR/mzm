.align 2

.global track_467

track_467_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 0
	.byte VOL, 15
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-63
	.byte N60, An3, v084
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-59
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-55
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v-50
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v-46
	.byte W02
	.byte VOL, 38
	.byte BEND, c_v-42
	.byte W02
	.byte VOL, 42
	.byte BEND, c_v-38
	.byte W02
	.byte VOL, 46
	.byte BEND, c_v-34
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 53
	.byte BEND, c_v-25
	.byte W02
	.byte VOL, 56
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 60
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v-8
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v @ BEND
	.byte W02
	.byte VOL, 60
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_467_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte MOD, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte N60, Fn2, v092
	.byte W02
	.byte VOL, 2
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W18
	.byte 52 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_467:
	.byte 2
	.byte 0
	.byte 227
	.byte 0
	.word voice_group12
	.word track_467_0
	.word track_467_1

.align 2
