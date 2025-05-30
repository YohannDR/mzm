.align 2

.global track_355

track_355_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 20
	.byte VOL, 29
	.byte PAN, c_v
	.byte BENDR, 2
	.byte LFOS, 110
	.byte BEND, c_v+63
	.byte N16, En3, v060
	.byte W16
	.byte FINE

.align 2

track_355:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_355_0

.align 2
