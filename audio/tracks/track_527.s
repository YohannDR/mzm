.align 2

.global track_527

track_527_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W24
	.byte W02
	.byte VOICE, 14
	.byte VOL, 56
	.byte PAN, c_v
	.byte N07
	.byte Fs3, Gs4
	.byte W11
	.byte N07
	.byte W11
	.byte N07
	.byte W07

	.byte FINE

track_527_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 2
	.byte BEND, c_v
	.byte N04
	.byte Gn2, Gs4
	.byte W04
	.byte BEND, c_v+5
	.byte N04
	.byte Bn2
	.byte W05
	.byte N04
	.byte W05
	.byte Bn2, Cn3
	.byte W05
	.byte Bn2, En1
	.byte W05
	.byte Bn2, CnM1
	.byte W04

	.byte FINE

.align 2

track_527:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_527_0
	.word track_527_1

.align 2
