.align 2

.global track_322

track_322_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 74
	.byte PAN, c_v
	.byte N12
	.byte Cn3, Gs4
	.byte W04
	.byte N04
	.byte Gn2
	.byte W04
	.byte Cn2
	.byte W04
	.byte N06
	.byte Bn1
	.byte W06

	.byte FINE

.align 2

track_322:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_322_0

.align 2
