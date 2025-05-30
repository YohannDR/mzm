.align 2

.global track_504

track_504_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 51
	.byte PAN, c_v
	.byte N04, Fs3, v060
	.byte W04
	.byte Bn2, v080 @ N04
	.byte W04
	.byte Gn2, v040 @ N04
	.byte W04
	.byte FINE

.align 2

track_504:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_504_0

.align 2
