.align 2

.global track_684

track_684_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 56
	.byte PAN, c_v+6
	.byte N08, An2, v080
	.byte W08
	.byte FINE

.align 2

track_684:
	.byte 1
	.byte 0
	.byte 179
	.byte 0
	.word voice_group14
	.word track_684_0

.align 2
