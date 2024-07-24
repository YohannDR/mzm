.align 2

.global track_409

track_409_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 63
	.byte PAN, c_v
	.byte N13
	.byte Cn3, Gs5
	.byte W13

	.byte FINE

.align 2

track_409:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group6
	.word track_409_0

.align 2
