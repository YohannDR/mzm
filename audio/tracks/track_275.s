.align 2

.global track_275

track_275_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte PAN, c_v
	.byte W01
	.byte VOL, 9
	.byte W01
	.byte N16, Fs2, v080
	.byte W01
	.byte VOL, 11
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W10
	.byte 9 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_275:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group4
	.word track_275_0

.align 2
