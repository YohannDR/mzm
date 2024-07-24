.align 2

.global track_206

track_206_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 37
	.byte PAN, c_v
	.byte N18
	.byte Cn3, Gs4
	.byte W18

	.byte FINE

.align 2

track_206:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_206_0

.align 2
