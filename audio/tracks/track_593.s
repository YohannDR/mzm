.align 2

.global track_593

track_593_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 62
	.byte PAN, c_v
	.byte N16, Cn3, v080
	.byte W16
	.byte VOICE, 20
	.byte BEND, c_v
	.byte N02, Bn3, v060
	.byte W02
	.byte Cn4 @ N02, v060
	.byte W02
	.byte FINE

.align 2

track_593:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_593_0

.align 2
