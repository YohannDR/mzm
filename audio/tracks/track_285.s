.align 2

.global track_285

track_285_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 22
	.byte PAN, c_v
	.byte BENDR, 10
	.byte BEND, c_v-63
	.byte W02
	.byte N04
	.byte Cn7, Gs4
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte Cs5
	.byte W01
	.byte Gn8
	.byte W02
	.byte CsM2
	.byte N04
	.byte Cn7, Gs0
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte Cs5
	.byte W01
	.byte Gn8
	.byte W02
	.byte CsM2
	.byte N04
	.byte Cn7, CnM1
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte Cn5
	.byte W01
	.byte Gn8
	.byte W01

	.byte FINE

track_285_1:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 55
	.byte PAN, c_v
	.byte N04
	.byte Cn4, Gs4
	.byte W04
	.byte Cn4, Gs0
	.byte W04
	.byte Cn4, CnM1
	.byte W04

	.byte FINE

.align 2

track_285:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_285_0
	.word track_285_1

.align 2
