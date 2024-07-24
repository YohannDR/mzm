.align 2

.global track_195

track_195_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 51
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N36
	.byte En3, Gs4, DnM2
	.byte W01
	.byte BEND, c_v-45
	.byte W02
	.byte AnM1
	.byte W02
	.byte BnM1
	.byte W01
	.byte Cs0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Gn0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Cs1
	.byte W01
	.byte Fn1
	.byte W01
	.byte An1
	.byte W01
	.byte Ds2
	.byte W01
	.byte As2
	.byte W01
	.byte Gn3
	.byte W01
	.byte Ds4
	.byte W01
	.byte Gs4
	.byte W01
	.byte Bn4
	.byte W01
	.byte Cn5
	.byte W02
	.byte Bn4
	.byte W02
	.byte An4
	.byte W01
	.byte Gn4
	.byte W01
	.byte Fn4
	.byte W01
	.byte Dn4
	.byte W01
	.byte Bn3
	.byte W01
	.byte As3
	.byte W01
	.byte An3
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01

	.byte FINE

.align 2

track_195:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group11
	.word track_195_0

.align 2
