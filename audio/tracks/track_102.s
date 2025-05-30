.align 2

.global track_102

track_102_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 46
	.byte PAN, c_v
	.byte N04, Cn3, v112
	.byte W08
	.byte FINE

.align 2

track_102:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group1
	.word track_102_0

.align 2
