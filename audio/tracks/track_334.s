.align 2

.global track_334

track_334_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N24, Fn2, v080, 1
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v-3
	.byte W02
	.byte VOL, 8
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 17
	.byte BEND, c_v-8
	.byte W02
	.byte VOL, 24
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 27
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-18
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-20
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v-23
	.byte W02
	.byte VOL, 6
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v-28
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-32
	.byte FINE

.align 2

track_334:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_334_0

.align 2
