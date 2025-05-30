.align 2

.global track_182

track_182_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 62
	.byte PAN, c_v-21
	.byte N16, Cn3, v100
	.byte W16
	.byte FINE

.align 2

track_182:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group11
	.word track_182_0

.align 2
