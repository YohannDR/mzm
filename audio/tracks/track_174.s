.align 2

.global track_174

track_174_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte PRIO, 1
	.byte N06
	.byte Cn2, Cn8
	.byte W05
track_174_lbl_2124c4:
	.byte W01
	.byte N04
	.byte Dn2, En6
	.byte W04
	.byte N06
	.byte Cn2, Cn8
	.byte W06
	.byte N04
	.byte Bn1, En6
	.byte W04
	.byte N06
	.byte Cn2, Cn8
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
	.byte N04
	.byte Dn2, En6
	.byte W04
	.byte Cs2, Cn8
	.byte W06
	.byte Bn1, En6
	.byte W04
	.byte Cs2, Cn8
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
	.byte N05
	.byte Gn3, Cn3
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte Bn6
	.byte W01
	.byte Cn8
	.byte W01
	.byte Gn8
	.byte W01
track_174_lbl_212513:
	.byte BEND, c_v-32
	.byte N05
	.byte Gn3, Gs4
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn6
	.byte W01
	.byte Gn8
	.byte W01
	.byte Gs0
	.byte N05
	.byte An3, Cn3
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn6
	.byte W01
	.byte Gn8
	.byte W01
	.byte Gs0
	.byte N05
	.byte Gn3, Gs4
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn6
	.byte W01
	.byte Gn8
	.byte W01
	.byte Gs0
	.byte N05
	.byte An3, Cn3
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn6
	.byte W01
	.byte Gn8
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
