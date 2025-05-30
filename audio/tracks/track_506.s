.align 2

.global track_506

track_506_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 27
	.byte PAN, c_v
	.byte N03, Cn3, v080
	.byte W03
	.byte Cn3, v032 @ N03
	.byte W03
	.byte Cn3, v012 @ N03
	.byte W03
	.byte FINE

.align 2

track_506:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_506_0

.align 2
