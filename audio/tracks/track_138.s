.align 2

.global track_138

track_138_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 42
	.byte VOL, 27
	.byte PAN, c_v
	.byte N02, En4, v080
	.byte W04
	.byte N02 @ En4, v080
	.byte W04
	.byte N02 @ En4, v080
	.byte W04
	.byte En4, v060 @ N02
	.byte W04
	.byte En4, v040 @ N02
	.byte W02
	.byte FINE

.align 2

track_138:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group1
	.word track_138_0

.align 2
