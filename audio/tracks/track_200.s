.align 2

.global track_200

track_200_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 49
	.byte PAN, c_v
	.byte N18, Cn3, v080
	.byte W18
	.byte FINE

.align 2

track_200:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_200_0

.align 2
