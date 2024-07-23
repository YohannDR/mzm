.align 2

.global track_529

track_529_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 37
	.byte PAN, c_v
	.byte N02
	.byte En4, Cn3
	.byte W03
	.byte Fn4, Gs4
	.byte W02

	.byte FINE

.align 2

track_529:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_529_0

.align 2
