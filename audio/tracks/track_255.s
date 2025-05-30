.align 2

.global track_255

track_255_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 78
	.byte PAN, c_v
	.byte N18, Cn3, v127
	.byte W44
	.byte W02
	.byte FINE

track_255_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte W08
	.byte N14, Gs2, v080
	.byte W36
	.byte W02
	.byte FINE

.align 2

track_255:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_255_0
	.word track_255_1

.align 2
