.align 2

.global track_347

track_347_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 45
	.byte PAN, c_v
	.byte N05
	.byte Cn3, En6
	.byte W05

	.byte FINE

.align 2

track_347:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_347_0

.align 2
