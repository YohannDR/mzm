.align 2

.global track_311

track_311_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 47
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte N19, En3, v040
	.byte W19
	.byte FINE

.align 2

track_311:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group5
	.word track_311_0

.align 2
