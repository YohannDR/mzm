.align 2

.global track_392

track_392_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 44
	.byte PAN, c_v
	.byte W04
	.byte N06, An2, v080
	.byte W06
	.byte N10, Fs3 @ v080
	.byte W10
	.byte N07, Dn3 @ v080
	.byte W03
	.byte VOL, 33
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_392:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_392_0

.align 2
