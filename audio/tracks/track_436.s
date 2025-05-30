.align 2

.global track_436

track_436_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte MOD, 60
	.byte VOL, 56
	.byte PAN, c_v
	.byte LFOS, 40
	.byte N32, Cn3, v080
	.byte W32
	.byte FINE

.align 2

track_436:
	.byte 1
	.byte 0
	.byte 190
	.byte 0
	.word voice_group9
	.word track_436_0

.align 2
