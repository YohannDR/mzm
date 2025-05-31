.align 2

.global track_108

track_108_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 39
	.byte VOL, 59
	.byte PAN, c_v
	.byte N12, Cn3, v080
	.byte W12
	.byte FINE

.align 2

track_108:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_108_0

.align 2
