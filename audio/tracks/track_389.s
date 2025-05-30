.align 2

.global track_389

track_389_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 29
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v
	.byte W04
	.byte N04, Cn2, v060
	.byte W04
	.byte N10, Cn3, v080
	.byte W01
	.byte BEND, c_v-2
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-38 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-54 @ BEND
	.byte W01
	.byte c_v-59 @ BEND
	.byte W01
	.byte c_v-63 @ BEND
	.byte W01
	.byte FINE

.align 2

track_389:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_389_0

.align 2
