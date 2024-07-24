.align 2

.global track_22

track_22_0:
	.byte KEYSH, 0
	.byte TEMPO, 28
	.byte VOICE, 27
	.byte VOL, 75
	.byte PAN, c_v
	.byte N12
	.byte Gn1, En7
	.byte W72
	.byte VOICE, 28

	.byte FINE

track_22_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 75
	.byte PAN, c_v
	.byte N12
	.byte Gn3, En7
	.byte W12

	.byte FINE

.align 2

track_22:
	.byte 2
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_22_0
	.word track_22_1

.align 2
