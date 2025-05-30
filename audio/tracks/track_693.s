.align 2

.global track_693

track_693_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 43
	.byte VOL, 94
	.byte PAN, c_v-14
	.byte W04
	.byte N05, Cn3, v060
	.byte W05
	.byte En3 @ N05, v060
	.byte W05
	.byte En3, v020 @ N05
	.byte W05
	.byte FINE

track_693_1:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 113
	.byte PAN, c_v-14
	.byte W04
	.byte N05, Gn3, v120
	.byte W05
	.byte N05 @ Gn3, v120
	.byte W05
	.byte Gn3, v032 @ N05
	.byte W05
	.byte FINE

.align 2

track_693:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_693_0
	.word track_693_1

.align 2
