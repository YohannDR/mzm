.align 2

.global track_322

track_322_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 74
	.byte PAN, c_v
	.byte N12, Cn3, v080
	.byte W04
	.byte N04, Gn2 @ v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte N06, Bn1 @ v080
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
