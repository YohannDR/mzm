.align 2

.global track_309

track_309_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 62
	.byte PAN, c_v
	.byte N06
	.byte Cn3, Gn8
	.byte W06
	.byte N14
	.byte En3, En6
	.byte W14
	.byte N03
	.byte Dn3, En1
	.byte W03

	.byte FINE

track_309_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gn8
	.byte W02

	.byte FINE

.align 2

track_309:
	.byte 2
	.byte 0
	.byte 191
	.byte 0
	.word voice_group5
	.word track_309_0
	.word track_309_1

.align 2
