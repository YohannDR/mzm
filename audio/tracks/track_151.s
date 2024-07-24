.align 2

.global track_151

track_151_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 25
	.byte PAN, c_v
	.byte N02
	.byte An3, Cn7
	.byte W02

	.byte FINE

.align 2

track_151:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_151_0

.align 2
