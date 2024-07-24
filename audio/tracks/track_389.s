.align 2

.global track_389

track_389_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 29
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v
	.byte W04
	.byte N04
	.byte Cn2, Cn3
	.byte W04
	.byte N10
	.byte Cn3, Gs4
	.byte W01
	.byte BEND, c_v-2
	.byte W01
	.byte Bn2
	.byte W01
	.byte Gn2
	.byte W01
	.byte Ds1
	.byte W01
	.byte Dn0
	.byte W01
	.byte FnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte CsM2
	.byte W01

	.byte FINE

.align 2

track_389:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_389_0

.align 2
