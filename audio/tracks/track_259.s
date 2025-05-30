.align 2

.global track_259

track_259_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 27
	.byte PAN, c_v
	.byte N06, Cn3, v072
	.byte W06
	.byte FINE

.align 2

track_259:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group2
	.word track_259_0

.align 2
