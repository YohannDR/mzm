.align 2

.global track_141

track_141_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 56
	.byte PAN, c_v
	.byte N16, Cn3, v080
	.byte W16
	.byte FINE

.align 2

track_141:
	.byte 1
	.byte 0
	.byte 227
	.byte 0
	.word voice_group1
	.word track_141_0

.align 2
