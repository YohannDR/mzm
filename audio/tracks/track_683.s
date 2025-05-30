.align 2

.global track_683

track_683_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 70
	.byte PAN, c_v+6
	.byte N12, Cn3, v100
	.byte W12
	.byte FINE

.align 2

track_683:
	.byte 1
	.byte 0
	.byte 179
	.byte 0
	.word voice_group14
	.word track_683_0

.align 2
