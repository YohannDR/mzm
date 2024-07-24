.align 2

.global track_517

track_517_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte N13
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte Fn0
	.byte W01
	.byte Gs1
	.byte W01
	.byte Gs1
	.byte W01
	.byte An0
	.byte N06
	.byte Gn3, Gs0
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte AsM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_517_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v-47
	.byte N08
	.byte En2, Cn3
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+31
	.byte W01
	.byte Ds7
	.byte W02

	.byte FINE

.align 2

track_517:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_517_0
	.word track_517_1

.align 2
