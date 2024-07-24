.align 2

.global track_408

track_408_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 60
	.byte PAN, c_v
	.byte N14
	.byte Bn2, Gs5
	.byte W14

	.byte FINE

.align 2

track_408:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word voice_group6
	.word track_408_0

.align 2
