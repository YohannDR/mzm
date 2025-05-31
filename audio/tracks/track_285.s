.align 2

.global track_285

track_285_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 22
	.byte PAN, c_v
	.byte BENDR, 10
	.byte BEND, c_v-63
	.byte W02
	.byte N04, Cn7, v080
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W02
	.byte c_v-63 @ BEND
	.byte N04, Cn7, v032
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W02
	.byte c_v-63 @ BEND
	.byte N04, Cn7, v012
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte FINE

track_285_1:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 55
	.byte PAN, c_v
	.byte N04, Cn4, v080
	.byte W04
	.byte Cn4, v032 @ N04
	.byte W04
	.byte Cn4, v012 @ N04
	.byte W04
	.byte FINE

.align 2

track_285:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_285_0
	.word track_285_1

.align 2
