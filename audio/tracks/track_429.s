.align 2

.global track_429

track_429_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 15
	.byte BEND, c_v-63
	.byte N32, An2, v100, 1
	.byte W01
	.byte BEND, c_v-61
	.byte W01
	.byte c_v-58 @ BEND
	.byte W01
	.byte c_v-56 @ BEND
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte c_v-50 @ BEND
	.byte W01
	.byte c_v-48 @ BEND
	.byte W01
	.byte c_v-45 @ BEND
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte c_v-40 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W09
	.byte FINE

.align 2

track_429:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_429_0

.align 2
