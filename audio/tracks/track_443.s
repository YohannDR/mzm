.align 2

.global track_443

track_443_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 56
	.byte PAN, c_v
	.byte N56, Cn3, v080, 3
	.byte W05
	.byte VOL, 43
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W48
	.byte FINE

.align 2

track_443:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_443_0

.align 2
