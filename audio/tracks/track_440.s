.align 2

.global track_440

track_440_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 70
	.byte PAN, c_v
	.byte N07, Bn2, v080
	.byte W07
	.byte An2, v032 @ N07
	.byte W07
	.byte Gn2, v008 @ N07
	.byte W07
	.byte FINE

.align 2

track_440:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group9
	.word track_440_0

.align 2
