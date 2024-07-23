.align 2

.global track_364

track_364_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 50
	.byte PAN, c_v
	.byte N04
	.byte Fn3, Cn3
	.byte W04
	.byte VOICE, 24
	.byte N04
	.byte An4, Gs4
	.byte W04

	.byte FINE

.align 2

track_364:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_364_0

.align 2
