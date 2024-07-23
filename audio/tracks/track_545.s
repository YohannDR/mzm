.align 2

.global track_545

track_545_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 33
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N10
	.byte Cn4, Gs4
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+35
	.byte W01
	.byte Fn7
	.byte W01
	.byte Gn8
	.byte W01
	.byte VOICE, 17
	.byte VOL, 22
	.byte BENDR, 10
	.byte BEND, c_v-63
	.byte W02
	.byte N04
	.byte Cn7
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

track_545_1:
	.byte KEYSH, 0
	.byte W10
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

track_545:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_545_0
	.word track_545_1

.align 2
