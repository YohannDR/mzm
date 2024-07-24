.align 2

.global track_492

track_492_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W22
	.byte VOICE, 4
	.byte VOL, 78
	.byte BEND, c_v
	.byte N08
	.byte Cn3, Gs4
	.byte W08
	.byte Cn3, Gs0
	.byte W08
	.byte N10
	.byte Cn3, CnM1
	.byte W10

	.byte FINE

track_492_1:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 78
	.byte PAN, c_v
	.byte N24
	.byte Cn3, En6, DnM2
	.byte W05
	.byte An2, Gs0, DnM2
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
