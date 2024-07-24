.align 2

.global track_365

track_365_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 30
	.byte VOL, 14
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N32
	.byte Bn3, Gs5
	.byte W02
	.byte VOL, 20
	.byte W02
	.byte Cn1
	.byte W01
	.byte Gn2
	.byte W02
	.byte An3
	.byte W02
	.byte As3
	.byte W02
	.byte Ds3
	.byte W01
	.byte Gn2
	.byte W02
	.byte Fn1
	.byte W02
	.byte Fs0
	.byte W02
	.byte AnM1
	.byte W02
	.byte EnM1
	.byte W02
	.byte CnM1
	.byte W02
	.byte GsM2
	.byte W02
	.byte EnM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_365_1:
	.byte KEYSH, 0
	.byte VOICE, 31
	.byte MOD, 40
	.byte VOL, 14
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 127
	.byte BEND, c_v-47
	.byte N30
	.byte En3, Cn4, CsM2
	.byte W02
	.byte VOL, 17
	.byte BEND, c_v-42
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-36
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v-31
	.byte W02
	.byte VOL, 42
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 53
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 56
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 55
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v+6
	.byte W02
	.byte VOL, 18
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 12
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 7
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v+27
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v+32
	.byte W01

	.byte FINE

.align 2

track_365:
	.byte 2
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_365_0
	.word track_365_1

.align 2
