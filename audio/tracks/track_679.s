.align 2

.global track_679

track_679_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 94
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N07
	.byte Cn4, En6
	.byte W07
	.byte VOICE, 10
	.byte BENDR, 4
	.byte VOL, 112
	.byte BEND, c_v-1
	.byte N18
	.byte An3, Gs4
	.byte W01
	.byte VOL, 99
	.byte BEND, c_v
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 50
	.byte W01
	.byte Fs1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fs0
	.byte W01
	.byte Cs0
	.byte W01
	.byte GnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W44
	.byte W02

	.byte FINE

track_679_1:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 120
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N05
	.byte Gn2, Gn8
	.byte W68
	.byte W01

	.byte FINE

.align 2

track_679:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group14
	.word track_679_0
	.word track_679_1

.align 2
