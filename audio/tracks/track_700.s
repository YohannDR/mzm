.align 2

.global track_700

track_700_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v
	.byte N42, Cn3, v100
	.byte W42
	.byte FINE

.align 2

track_700:
	.byte 1
	.byte 0
	.byte 182
	.byte 0
	.word voice_group15
	.word track_700_0

.align 2
