.align 2

.global track_680

track_680_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte N12, Cn3, v080
	.byte W12
	.byte FINE

.align 2

track_680:
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.word voice_group1
	.word track_680_0

.align 2
