.align 2

.global track_622

track_622_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 70
	.byte PAN, c_v
	.byte N11, Cn3, v100
	.byte W11
	.byte FINE

.align 2

track_622:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_622_0

.align 2
