.align 2

.global track_427

track_427_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N36, Cn3, v100
	.byte W01
	.byte BEND, c_v-61
	.byte W01
	.byte c_v-59 @ BEND
	.byte W01
	.byte c_v-57 @ BEND
	.byte W01
	.byte c_v-55 @ BEND
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte c_v-50 @ BEND
	.byte W01
	.byte c_v-48 @ BEND
	.byte W01
	.byte c_v-46 @ BEND
	.byte W01
	.byte c_v-44 @ BEND
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte c_v-40 @ BEND
	.byte W01
	.byte c_v-38 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-23 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W06
	.byte FINE

.align 2

track_427:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_427_0

.align 2
