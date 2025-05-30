.align 2

.global track_526

track_526_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 21
	.byte PAN, c_v
	.byte N02, Cn4, v080
	.byte W04
	.byte En4, v052 @ N02
	.byte W02
	.byte FINE

track_526_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 17
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W04
	.byte Cn3, v040 @ N02
	.byte W04
	.byte Cn3, v020 @ N02
	.byte W02
	.byte FINE

.align 2

track_526:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_526_0
	.word track_526_1

.align 2
