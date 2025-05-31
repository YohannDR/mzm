.align 2

.global track_453

track_453_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 62
	.byte PAN, c_v-20
	.byte W02
	.byte N11, An2, v080
	.byte W11
	.byte An2, v016 @ N11
	.byte W11
	.byte An2, v008 @ N11
	.byte W11
	.byte FINE

track_453_1:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 78
	.byte PAN, c_v-20
	.byte N08, Cn3, v080
	.byte W08
	.byte FINE

.align 2

track_453:
	.byte 2
	.byte 0
	.byte 203
	.byte 0
	.word voice_group10
	.word track_453_0
	.word track_453_1

.align 2
