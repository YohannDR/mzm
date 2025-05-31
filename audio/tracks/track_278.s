.align 2

.global track_278

track_278_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 62
	.byte BEND, c_v
	.byte N03, Cn3, v080
	.byte W05
	.byte N04, An2, v060
	.byte W04
	.byte FINE

track_278_1:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte VOL, 39
	.byte PAN, c_v
	.byte W10
	.byte N28, Cn3, v060
	.byte W22
	.byte VOL, 47
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_278:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_278_0
	.word track_278_1

.align 2
