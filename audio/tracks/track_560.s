.align 2

.global track_560

track_560_0:
	.byte KEYSH, 0
	.byte TEMPO, 56
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte N12, Gn3, v080
	.byte W12
	.byte FINE

.align 2

track_560:
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.word voice_group1
	.word track_560_0

.align 2
