.align 2

.global track_528

track_528_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 28
	.byte PAN, c_v
	.byte N02, Gs2, v080
	.byte W02
	.byte Cs3 @ N02, v080
	.byte W02
	.byte En3 @ N02, v080
	.byte W02
	.byte Gs3 @ N02, v080
	.byte W04
	.byte Gs3, v032 @ N02
	.byte W04
	.byte Gs3, v012 @ N02
	.byte W02
	.byte FINE

.align 2

track_528:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_528_0

.align 2
