.align 2

.global track_613

track_613_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 54
	.byte VOL, 89
	.byte PAN, c_v
	.byte W04
	.byte N10, En3, v100
	.byte W10
	.byte En3, v052 @ N10
	.byte W10
	.byte En3, v020 @ N10
	.byte W10
	.byte FINE

.align 2

track_613:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group3
	.word track_613_0

.align 2
