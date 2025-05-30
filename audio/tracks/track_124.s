.align 2

.global track_124

track_124_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 59
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W04
	.byte Cn3, v040 @ N04
	.byte W04
	.byte Cn3, v012 @ N04
	.byte W04
	.byte FINE

.align 2

track_124:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word voice_group1
	.word track_124_0

.align 2
