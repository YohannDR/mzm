.align 2

.global track_503

track_503_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 59
	.byte PAN, c_v
	.byte N04
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W04

	.byte FINE

.align 2

track_503:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_503_0

.align 2
