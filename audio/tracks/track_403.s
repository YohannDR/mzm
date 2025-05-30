.align 2

.global track_403

track_403_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 110
	.byte PAN, c_v
	.byte N12, An2, v127
	.byte W12
	.byte N19, Cn3, v068
	.byte W19
	.byte FINE

.align 2

track_403:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group5
	.word track_403_0

.align 2
