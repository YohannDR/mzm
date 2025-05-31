.align 2

.global track_448

track_448_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 78
	.byte PAN, c_v-20
	.byte BENDR, 14
	.byte W07
	.byte BEND, c_v-47
	.byte N20, Cn3, v112
	.byte W01
	.byte BEND, c_v-42
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+22 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+47
	.byte W01
	.byte FINE

.align 2

track_448:
	.byte 1
	.byte 0
	.byte 202
	.byte 0
	.word voice_group10
	.word track_448_0

.align 2
