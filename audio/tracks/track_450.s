.align 2

.global track_450

track_450_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 70
	.byte PAN, c_v-20
	.byte BENDR, 14
	.byte W06
	.byte BEND, c_v-47
	.byte N19, Cn3, v112
	.byte W01
	.byte BEND, c_v-42
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-26 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+47
	.byte W01
	.byte FINE

.align 2

track_450:
	.byte 1
	.byte 0
	.byte 201
	.byte 0
	.word voice_group10
	.word track_450_0

.align 2
