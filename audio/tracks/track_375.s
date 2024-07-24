.align 2

.global track_375

track_375_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 25
	.byte PAN, c_v
	.byte BEND, c_v
	.byte W04
	.byte VOL, 12
	.byte N06
	.byte Gn3, Gs4
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte Cs0
	.byte W02
	.byte Cs0
	.byte W01
	.byte AnM1
	.byte W01
	.byte GnM1
	.byte BENDR, 28
	.byte N10
	.byte Cn4, Cn3
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-36
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-50
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-15
	.byte W01

	.byte FINE

.align 2

track_375:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_375_0

.align 2
