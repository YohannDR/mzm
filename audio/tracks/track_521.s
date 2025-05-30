.align 2

.global track_521

track_521_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 40
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte An2 @ N02, v080
	.byte W04
	.byte An2, v032 @ N02
	.byte W04
	.byte An2, v012 @ N02
	.byte W02
	.byte FINE

.align 2

track_521:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_521_0

.align 2
