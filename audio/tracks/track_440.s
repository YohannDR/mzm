.align 2

.global track_440

track_440_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 70
	.byte PAN, c_v
	.byte N07
	.byte Bn2, Gs4
	.byte W07
	.byte An2, Gs0
	.byte W07
	.byte Gn2, GsM2
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
