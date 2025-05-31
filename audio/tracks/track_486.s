.align 2

.global track_486

track_486_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 80
	.byte PAN, c_v
	.byte N13, Cn3, v080
	.byte W13
	.byte N10, Cn3, v032
	.byte W10
	.byte Cn3, v012 @ N10
	.byte W10
	.byte FINE

.align 2

track_486:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group13
	.word track_486_0

.align 2
