.align 2

.global track_412

track_412_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 44
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N36, Cn3, v100, 1
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-53
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v-19
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+55 @ BEND
	.byte W03
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+33 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-27 @ BEND
	.byte W02
	.byte c_v-31 @ BEND
	.byte W02
	.byte c_v-25 @ BEND
	.byte W02
	.byte c_v-16 @ BEND
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte 21 @ VOL
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte 10 @ VOL
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte 2 @ VOL
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01
	.byte FINE

.align 2

track_412:
	.byte 1
	.byte 0
	.byte 228
	.byte 0
	.word voice_group6
	.word track_412_0

.align 2
