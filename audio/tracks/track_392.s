.align 2

.global track_392

track_392_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 44
	.byte PAN, c_v
	.byte W04
	.byte N06
	.byte An2, Gs4
	.byte W06
	.byte N10
	.byte Fs3
	.byte W10
	.byte N07
	.byte Dn3
	.byte W03
	.byte VOL, 33
	.byte W01
	.byte AsM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte CnM2
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
