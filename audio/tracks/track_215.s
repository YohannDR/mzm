.align 2

.global track_215

track_215_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 44
	.byte PAN, c_v
	.byte N28, Cn3, v080
	.byte W28
	.byte FINE

.align 2

track_215:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_215_0

.align 2
