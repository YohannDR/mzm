.align 2

.global track_482

track_482_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v
	.byte W02
	.byte N12, En3, v100
	.byte W12
	.byte FINE

.align 2

track_482:
	.byte 1
	.byte 0
	.byte 171
	.byte 0
	.word voice_group13
	.word track_482_0

.align 2
