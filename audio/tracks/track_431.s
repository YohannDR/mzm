.align 2

.global track_431

track_431_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N16, Gn3, v100
	.byte W01
	.byte BEND, c_v-58
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-26 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W04
	.byte FINE

.align 2

track_431:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_431_0

.align 2
