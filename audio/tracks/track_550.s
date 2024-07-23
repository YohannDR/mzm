.align 2

.global track_550

track_550_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 31
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gs4
	.byte W02

	.byte FINE

.align 2

track_550:
	.byte 1
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_550_0

.align 2
