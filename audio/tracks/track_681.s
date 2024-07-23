.align 2

.global track_681

track_681_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-40
	.byte N19
	.byte Cn2, En6
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+45
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+61
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+63
	.byte W01
	.byte Fs8
	.byte W01
	.byte Ds8
	.byte W01
	.byte Bn7
	.byte W01
	.byte Fn7
	.byte W01
	.byte Bn6
	.byte W01
	.byte Fn6
	.byte W01
	.byte An5
	.byte W01
	.byte Cs5
	.byte W01
	.byte Fn4
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-16
	.byte W40

	.byte FINE

track_681_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N19
	.byte Fn1, Cn8
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte CnM1
	.byte W01
	.byte AnM1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Bn2
	.byte W01
	.byte Dn7
	.byte W06
	.byte Dn7
	.byte W01
	.byte Ds4
	.byte W01
	.byte Ds2
	.byte W01
	.byte Gs0
	.byte W01
	.byte GnM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte CnM2
	.byte W40

	.byte FINE

track_681_2:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 110
	.byte PAN, c_v
	.byte N03
	.byte Gn2, En6
	.byte W56
	.byte W02

	.byte FINE

.align 2

track_681:
	.byte 3
	.byte 0
	.byte 190
	.byte 0
	.word voice_group13
	.word track_681_0
	.word track_681_1
	.word track_681_2

.align 2
