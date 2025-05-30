.align 2

.global track_491

track_491_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 94
	.byte PAN, c_v
	.byte N24, En3, v100, 2
	.byte W24
	.byte W02
	.byte FINE

track_491_1:
	.byte KEYSH, 0
	.byte W05
	.byte VOICE, 8
	.byte VOL, 94
	.byte PAN, c_v
	.byte N24, En3, v032, 2
	.byte W24
	.byte W02
	.byte FINE

.align 2

track_491:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word voice_group13
	.word track_491_0
	.word track_491_1

.align 2
