.align 2

.global track_369

track_369_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 120
	.byte PAN, c_v
	.byte N36, Cn3, v080
	.byte W36
	.byte FINE

.align 2

track_369:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group3
	.word track_369_0

.align 2
