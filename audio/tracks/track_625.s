.align 2

.global track_625

track_625_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 120
	.byte PAN, c_v
	.byte N13
	.byte An2, Gs4
	.byte W13
	.byte An2, Gs0
	.byte W13
	.byte An2, CnM1
	.byte W13

	.byte FINE

.align 2

track_625:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_625_0

.align 2
