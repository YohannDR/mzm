.align 2

.global track_430

track_430_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 15
	.byte BEND, c_v-63
	.byte N22, Dn3, v100
	.byte W01
	.byte BEND, c_v-60
	.byte W01
	.byte c_v-56 @ BEND
	.byte W01
	.byte c_v-52 @ BEND
	.byte W01
	.byte c_v-48 @ BEND
	.byte W01
	.byte c_v-44 @ BEND
	.byte W01
	.byte c_v-40 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-20 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W06
	.byte FINE

.align 2

track_430:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_430_0

.align 2
