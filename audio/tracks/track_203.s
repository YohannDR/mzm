.align 2

.global track_203

track_203_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 40
	.byte PAN, c_v
	.byte N28, Cn3, v080
	.byte W28
	.byte FINE

.align 2

track_203:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_203_0

.align 2
