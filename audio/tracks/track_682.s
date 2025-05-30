.align 2

.global track_682

track_682_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 94
	.byte PAN, c_v
	.byte N15, Cn3, v080
	.byte W15
	.byte Cn3, v032 @ N15
	.byte W15
	.byte Cn3, v012 @ N15
	.byte W15
	.byte FINE

.align 2

track_682:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group14
	.word track_682_0

.align 2
