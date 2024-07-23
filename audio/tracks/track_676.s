.align 2

.global track_676

track_676_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N20
	.byte Cn3, En6
	.byte W20

	.byte FINE

.align 2

track_676:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_676_0

.align 2
