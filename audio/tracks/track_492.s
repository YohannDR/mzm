.align 2

.global track_492

track_492_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W22
	.byte VOICE, 4
	.byte VOL, 78
	.byte BEND, c_v
	.byte N08, Cn3, v080
	.byte W08
	.byte Cn3, v032 @ N08
	.byte W08
	.byte N10, Cn3, v012
	.byte W10
	.byte FINE

track_492_1:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 78
	.byte PAN, c_v
	.byte N24, Cn3, v100, 2
	.byte W05
	.byte An2, v032, 2 @ N24
	.byte W24
	.byte W02
	.byte FINE

.align 2

track_492:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word voice_group13
	.word track_492_0
	.word track_492_1

.align 2
