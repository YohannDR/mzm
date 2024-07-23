.align 2

.global track_693

track_693_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 43
	.byte VOL, 94
	.byte PAN, c_v-14
	.byte W04
	.byte N05
	.byte Cn3, Cn3
	.byte W05
	.byte En3
	.byte W05
	.byte En3, GsM1
	.byte W05

	.byte FINE

track_693_1:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 113
	.byte PAN, c_v-14
	.byte W04
	.byte N05
	.byte Gn3, Cn8
	.byte W05
	.byte N05
	.byte W05
	.byte Gn3, Gs0
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
