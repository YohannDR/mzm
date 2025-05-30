.align 2

.global track_315

track_315_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 47
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte N19, En3, v040
	.byte W19
	.byte FINE

track_315_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 47
	.byte PAN, c_v
	.byte BENDR, 26
	.byte BEND, c_v-32
	.byte N13, Cn3, v080
	.byte W01
	.byte BEND, c_v-30
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W02
	.byte N05, Cn3, v060
	.byte W06
	.byte Cn3, v032 @ N05
	.byte W06
	.byte Cn3, v012 @ N05
	.byte W05
	.byte FINE

.align 2

track_315:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_315_0
	.word track_315_1

.align 2
