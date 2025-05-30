.align 2

.global track_174

track_174_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte PRIO, 1
	.byte N06, Cn2, v120
	.byte W05
track_174_lbl_2124c4:
	.byte W01
	.byte N04, Dn2, v100
	.byte W04
	.byte N06, Cn2, v120
	.byte W06
	.byte N04, Bn1, v100
	.byte W04
	.byte N06, Cn2, v120
	.byte W05
	.byte GOTO
		.word track_174_lbl_2124c4
	.byte W01
	.byte FINE

track_174_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte W05
track_174_lbl_2124e5:
	.byte N04, Dn2, v100
	.byte W04
	.byte Cs2, v120 @ N04
	.byte W06
	.byte Bn1, v100 @ N04
	.byte W04
	.byte Cs2, v120 @ N04
	.byte W06
	.byte GOTO
		.word track_174_lbl_2124e5
	.byte FINE

track_174_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte BENDR, 12
	.byte PRIO, 52
	.byte BEND, c_v-32
	.byte N05, Gn3, v060
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
track_174_lbl_212513:
	.byte BEND, c_v-32
	.byte N05, Gn3, v080
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte N05, An3, v060
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte N05, Gn3, v080
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte N05, An3, v060
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte GOTO
		.word track_174_lbl_212513
	.byte FINE

.align 2

track_174:
	.byte 3
	.byte 0
	.byte 200
	.byte 0
	.word voice_group7
	.word track_174_0
	.word track_174_1
	.word track_174_2

.align 2
