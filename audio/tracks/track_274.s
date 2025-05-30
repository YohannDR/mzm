.align 2

.global track_274

track_274_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 5
	.byte VOL, 27
	.byte PAN, c_v
	.byte N16, Fs2, v080
	.byte W10
	.byte VOL, 27
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_274:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group4
	.word track_274_0

.align 2
