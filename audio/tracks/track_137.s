.align 2

.global track_137

track_137_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 55
	.byte PAN, c_v
	.byte N02, En3, v080
	.byte W04
	.byte N02 @ En3, v080
	.byte W04
	.byte N02 @ En3, v080
	.byte W04
	.byte En3, v060 @ N02
	.byte W04
	.byte En3, v040 @ N02
	.byte W02
	.byte FINE

.align 2

track_137:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group1
	.word track_137_0

.align 2
