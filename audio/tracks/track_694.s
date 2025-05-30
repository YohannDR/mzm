.align 2

.global track_694

track_694_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 43
	.byte VOL, 94
	.byte PAN, c_v-14
	.byte W04
	.byte N05, Cn3, v072
	.byte W05
	.byte En3 @ N05, v072
	.byte W05
	.byte Gn3, v060 @ N05
	.byte W05
	.byte Gn3, v020 @ N05
	.byte W05
	.byte FINE

track_694_1:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte W04
	.byte N05, Gn3, v120
	.byte W05
	.byte Gs3 @ N05, v120
	.byte W05
	.byte An3, v080 @ N05
	.byte W05
	.byte An3, v036 @ N05
	.byte W05
	.byte FINE

.align 2

track_694:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_694_0
	.word track_694_1

.align 2
