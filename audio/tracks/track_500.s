.align 2

.global track_500

track_500_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte BEND, c_v
	.byte W12
	.byte BENDR, 14
	.byte BEND, c_v-63
	.byte N24
	.byte Cn4, En1
	.byte W01
	.byte BEND, c_v-58
	.byte W01
	.byte CnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte BnM1
	.byte W01
	.byte En0
	.byte W01
	.byte As0
	.byte W01
	.byte Ds1
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W01
	.byte VOICE, 0
	.byte VOL, 25
	.byte BEND, c_v
	.byte N04
	.byte Fn3, Cn3
	.byte W04
	.byte Cs4, En1
	.byte W04
	.byte An3, Cn3
	.byte W04
	.byte Bn3, En1
	.byte W04
	.byte Gn3, Cn3
	.byte W04
	.byte Fn3, En1
	.byte W04

	.byte FINE

track_500_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte N13
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte An0
	.byte W01
	.byte Dn2
	.byte W01
	.byte Dn2
	.byte W01
	.byte Cs1
	.byte N06
	.byte Gn3, Gs0
	.byte W01
	.byte VOL, 25
	.byte W01
	.byte Cs0
	.byte W01
	.byte GsM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_500:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_500_0
	.word track_500_1

.align 2
