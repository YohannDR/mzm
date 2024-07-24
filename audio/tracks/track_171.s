.align 2

.global track_171

track_171_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte N05
	.byte Cn2, En6
	.byte W06
	.byte N06
	.byte Dn2, Gs4
	.byte W06
	.byte N05
	.byte Cn2, En1
	.byte W06
	.byte N06
	.byte Bn1, GsM1
	.byte W06

	.byte FINE

.align 2

track_171:
	.byte 1
	.byte 0
	.byte 190
	.byte 0
	.word voice_group7
	.word track_171_0

.align 2
