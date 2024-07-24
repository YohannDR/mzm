.align 2

.global track_359

track_359_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 24
	.byte VOL, 39
	.byte PAN, c_v
	.byte N02
	.byte Fn4, En6
	.byte W02
	.byte N04
	.byte Dn4, Gs4
	.byte W04

	.byte FINE

.align 2

track_359:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_359_0

.align 2
