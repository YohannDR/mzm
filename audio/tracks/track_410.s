.align 2

.global track_410

track_410_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 47
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N36, Dn3, v100, 1
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-53
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 58
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 64
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v-19
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+55 @ BEND
	.byte W01
	.byte c_v+57 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01
	.byte FINE

.align 2

track_410:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group6
	.word track_410_0

.align 2
