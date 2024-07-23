.align 2

.global track_528

track_528_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 28
	.byte PAN, c_v
	.byte N02
	.byte Gs2, Gs4
	.byte W02
	.byte Cs3
	.byte W02
	.byte En3
	.byte W02
	.byte Gs3
	.byte W04
	.byte Gs3, Gs0
	.byte W04
	.byte Gs3, CnM1
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
