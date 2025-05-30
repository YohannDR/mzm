.align 2

.global track_248

track_248_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 69
	.byte PAN, c_v
	.byte N13, Cn3, v100
	.byte W13
	.byte FINE

.align 2

track_248:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_248_0

.align 2
