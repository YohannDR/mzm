.align 2

.global track_432

track_432_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 74
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v
	.byte N36, Bn2, v092, 1
	.byte W01
	.byte BEND, c_v-2
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-20 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-26 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-38 @ BEND
	.byte W01
	.byte c_v-40 @ BEND
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte c_v-44 @ BEND
	.byte W01
	.byte c_v-46 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-51 @ BEND
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte c_v-55 @ BEND
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v-58
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-60
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-62
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_432:
	.byte 1
	.byte 0
	.byte 212
	.byte 0
	.word voice_group9
	.word track_432_0

.align 2
