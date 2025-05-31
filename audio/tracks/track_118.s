.align 2

.global track_118

track_118_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v
	.byte N09, Cn3, v100
	.byte W09
	.byte FINE

.align 2

track_118:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group1
	.word track_118_0

.align 2
