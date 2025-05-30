.align 2

.global track_424

track_424_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 15
	.byte BEND, c_v-63
	.byte N40, Dn3, v100
	.byte W01
	.byte BEND, c_v-62
	.byte W01
	.byte c_v-60 @ BEND
	.byte W01
	.byte c_v-58 @ BEND
	.byte W01
	.byte c_v-56 @ BEND
	.byte W01
	.byte c_v-54 @ BEND
	.byte W01
	.byte c_v-52 @ BEND
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
	.byte c_v-41 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
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
	.byte c_v-20 @ BEND
	.byte W01
	.byte c_v-18 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
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
	.byte W07
	.byte MOD, 40
	.byte LFOS, 50
	.byte N48, Cn3, v080
	.byte W48
	.byte FINE

.align 2

track_424:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_424_0

.align 2
