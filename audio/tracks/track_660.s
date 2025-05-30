.align 2

.global track_660

track_660_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 49
	.byte VOL, 47
	.byte PAN, c_v
	.byte W10
	.byte N11, Cn3, v100
	.byte W11
	.byte FINE

.align 2

track_660:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_660_0

.align 2
