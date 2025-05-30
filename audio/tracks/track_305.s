.align 2

.global track_305

track_305_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 94
	.byte PAN, c_v
	.byte N06, Cn3, v100
	.byte W06
	.byte VOICE, 0
	.byte VOL, 70
	.byte N10, Gn2, v060
	.byte W36
	.byte FINE

track_305_1:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 78
	.byte PAN, c_v
	.byte W02
	.byte N10, Cn3, v100
	.byte W10
	.byte Dn3, v020 @ N10
	.byte W30
	.byte FINE

.align 2

track_305:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_305_0
	.word track_305_1

.align 2
