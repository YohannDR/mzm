.align 2

.global track_455

track_455_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-63
	.byte N24, Cn4, v080
	.byte W01
	.byte BEND, c_v-58
	.byte W01
	.byte c_v-52 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-30 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+57 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte FINE

.align 2

track_455:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group10
	.word track_455_0

.align 2
