.align 2

.global track_425

track_425_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 15
	.byte N40, Cn3, v080
	.byte W03
	.byte BEND, c_v
	.byte W01
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-18 @ BEND
	.byte W01
	.byte c_v-20 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-23 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-30 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W01
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-44 @ BEND
	.byte W01
	.byte c_v-46 @ BEND
	.byte W01
	.byte c_v-48 @ BEND
	.byte W01
	.byte c_v-50 @ BEND
	.byte W01
	.byte c_v-51 @ BEND
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte c_v-55 @ BEND
	.byte W01
	.byte c_v-57 @ BEND
	.byte W01
	.byte c_v-58 @ BEND
	.byte W01
	.byte c_v-60 @ BEND
	.byte W01
	.byte c_v-62 @ BEND
	.byte W01
	.byte c_v-63 @ BEND
	.byte W01
	.byte FINE

.align 2

track_425:
	.byte 1
	.byte 0
	.byte 211
	.byte 0
	.word voice_group9
	.word track_425_0

.align 2
