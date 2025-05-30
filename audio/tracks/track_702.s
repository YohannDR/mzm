.align 2

.global track_702

track_702_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 94
	.byte PAN, c_v-14
	.byte N48, Cn3, v100
	.byte W48
	.byte FINE

.align 2

track_702:
	.byte 1
	.byte 0
	.byte 190
	.byte 0
	.word voice_group15
	.word track_702_0

.align 2
