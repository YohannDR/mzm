.align 2

.global track_99

track_99_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 0
	.byte PAN, c_v
	.byte N12
	.byte Cn4, EnM2
	.byte W12

	.byte FINE

.align 2

track_99:
	.byte 1
	.byte 0
	.byte 255
	.byte 0
	.word voice_group1
	.word track_99_0

.align 2
