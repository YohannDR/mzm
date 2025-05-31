.align 2

.global track_103

track_103_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 35
	.byte PAN, c_v
	.byte N04, Cn3, v108
	.byte W08
	.byte FINE

.align 2

track_103:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group1
	.word track_103_0

.align 2
