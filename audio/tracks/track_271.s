.align 2

.global track_271

track_271_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 18
	.byte W01
track_271_lbl_20dc1d:
	.byte BEND, c_v-13
	.byte N15, Cn3, v080
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+34 @ BEND
	.byte W01
	.byte c_v+40 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W02
	.byte GOTO
		.word track_271_lbl_20dc1d
	.byte FINE

track_271_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 18
	.byte W01
track_271_lbl_20dc51:
	.byte W01
	.byte BEND, c_v-13
	.byte N15, Gn2, v060
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+34 @ BEND
	.byte W01
	.byte c_v+40 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte GOTO
		.word track_271_lbl_20dc51
	.byte FINE

.align 2

track_271:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_271_0
	.word track_271_1

.align 2
