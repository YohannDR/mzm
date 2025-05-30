.align 2

.global track_523

track_523_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 30
	.byte PAN, c_v
	.byte N03, Gn2, v080
	.byte W03
	.byte Cn3 @ N03, v080
	.byte W03
	.byte Cn3, v032 @ N03
	.byte W04
	.byte N03 @ Cn3, v032
	.byte W04
	.byte N03 @ Cn3, v032
	.byte W04
	.byte Cn3, v012 @ N03
	.byte W03
	.byte FINE

.align 2

track_523:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_523_0

.align 2
