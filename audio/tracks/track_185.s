.align 2

.global track_185

track_185_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 85
	.byte PAN, c_v+3
	.byte N16
	.byte Cn3, En6
	.byte W16

	.byte FINE

.align 2

track_185:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group11
	.word track_185_0

.align 2
