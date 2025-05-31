.align 2

.global track_349

track_349_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 44
	.byte PAN, c_v
	.byte W04
	.byte N04, En2, v080
	.byte W04
	.byte N05, Bn2, v056
	.byte W05
	.byte N08, Cs2 @ v056
	.byte W08
	.byte N07, En2 @ v056
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_349:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_349_0

.align 2
