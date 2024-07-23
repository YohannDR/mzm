.align 2

.global track_593

track_593_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 62
	.byte PAN, c_v
	.byte N16
	.byte Cn3, Gs4
	.byte W16
	.byte VOICE, 20
	.byte BEND, c_v
	.byte N02
	.byte Bn3, Cn3
	.byte W02
	.byte Cn4
	.byte W02

	.byte FINE

.align 2

track_593:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_593_0

.align 2
