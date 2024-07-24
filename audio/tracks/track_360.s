.align 2

.global track_360

track_360_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 47
	.byte PAN, c_v
	.byte N30
	.byte Cn3, En6
	.byte W30

	.byte FINE

.align 2

track_360:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_360_0

.align 2
