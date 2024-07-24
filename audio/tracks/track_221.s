.align 2

.global track_221

track_221_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 30
	.byte VOL, 44
	.byte PAN, c_v
	.byte BENDR, 7
	.byte BEND, c_v+38
	.byte N16
	.byte Cn3, Gs4
	.byte W16

	.byte FINE

.align 2

track_221:
	.byte 1
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_221_0

.align 2
