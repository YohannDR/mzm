.align 2

.global track_254

track_254_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte N03, Cn3, v080
	.byte W03
	.byte FINE

.align 2

track_254:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group2
	.word track_254_0

.align 2
