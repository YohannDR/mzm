.align 2

.global track_556

track_556_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v-63
	.byte W01
	.byte N12, An3, v060
	.byte W01
	.byte BEND, c_v-52
	.byte W01
	.byte c_v-40 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-6 @ BEND
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+63
	.byte W01
	.byte FINE

track_556_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 18
	.byte PAN, c_v
	.byte BENDR, 10
	.byte BEND, c_v-63
	.byte W01
	.byte N12, Cn4, v052
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-46
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-20
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-12
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte FINE

.align 2

track_556:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group10
	.word track_556_0
	.word track_556_1

.align 2
