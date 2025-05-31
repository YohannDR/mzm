.align 2

.global track_272

track_272_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 47
	.byte PAN, c_v
	.byte N16, Gs2, v080
	.byte W16
	.byte FINE

.align 2

track_272:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group4
	.word track_272_0

.align 2
