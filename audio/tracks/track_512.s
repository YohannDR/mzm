.align 2

.global track_512

track_512_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 37
	.byte PAN, c_v
	.byte N01, Cn3, v080
	.byte W01
	.byte FINE

.align 2

track_512:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_512_0

.align 2
