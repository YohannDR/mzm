.align 2

.global track_407

track_407_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N10, Cn4, v080
	.byte W01
	.byte BEND, c_v-59
	.byte W01
	.byte c_v-51 @ BEND
	.byte W01
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W01
	.byte FINE

.align 2

track_407:
	.byte 1
	.byte 0
	.byte 179
	.byte 0
	.word voice_group6
	.word track_407_0

.align 2
