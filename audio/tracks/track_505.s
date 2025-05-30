.align 2

.global track_505

track_505_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 32
	.byte PAN, c_v
	.byte N03, Cn3, v080
	.byte W06
	.byte Cn3, v032 @ N03
	.byte W06
	.byte Cn3, v012 @ N03
	.byte W03
	.byte FINE

.align 2

track_505:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_505_0

.align 2
