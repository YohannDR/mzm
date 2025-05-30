.align 2

.global track_361

track_361_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 55
	.byte PAN, c_v
	.byte N17, Cn3, v080
	.byte W17
	.byte FINE

.align 2

track_361:
	.byte 1
	.byte 0
	.byte 171
	.byte 0
	.word voice_group3
	.word track_361_0

.align 2
