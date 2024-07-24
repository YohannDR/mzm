.align 2

.global track_159

track_159_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 34
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Gs4
	.byte W03
	.byte VOICE, 35
	.byte N13
	.byte W13

	.byte FINE

.align 2

track_159:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_159_0

.align 2
