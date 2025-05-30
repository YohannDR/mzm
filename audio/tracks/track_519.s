.align 2

.global track_519

track_519_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 44
	.byte PAN, c_v
	.byte N03, An2, v080
	.byte W03
	.byte An2, v032 @ N03
	.byte W03
	.byte An2, v012 @ N03
	.byte W03
	.byte FINE

.align 2

track_519:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_519_0

.align 2
