.align 2

.global track_398

track_398_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 70
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte N12, Cn3, v032
	.byte W08
	.byte VOL, 70
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_398:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_398_0

.align 2
