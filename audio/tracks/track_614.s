.align 2

.global track_614

track_614_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 54
	.byte VOL, 80
	.byte PAN, c_v
	.byte N10, En3, v100
	.byte W10
	.byte Gn3, v052 @ N10
	.byte W10
	.byte Gn3, v020 @ N10
	.byte W10
	.byte FINE

.align 2

track_614:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group3
	.word track_614_0

.align 2
