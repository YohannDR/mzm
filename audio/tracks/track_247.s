.align 2

.global track_247

track_247_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 60
	.byte PAN, c_v
	.byte N28
	.byte Cn3, Gs4
	.byte W05
	.byte MOD, 28
	.byte LFOS, 127
	.byte MODT, mod_tre
	.byte W15
	.byte MOD, 0
	.byte W08

	.byte FINE

track_247_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 35
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte N07
	.byte Fn2, En2
	.byte W01
	.byte BEND, c_v+52
	.byte W01
	.byte As6
	.byte W01
	.byte Bn5
	.byte W01
	.byte Cs5
	.byte W01
	.byte Dn4
	.byte W01
	.byte En3
	.byte W01
	.byte VOICE, 24
	.byte VOL, 14
	.byte BENDR, 12
	.byte N30
	.byte Dn3, Gs5
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte En0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fs1
	.byte W01
	.byte Cs2
	.byte W01
	.byte Gs2
	.byte W05
	.byte As1
	.byte W01
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 36
	.byte W02
	.byte Fn0
	.byte W02
	.byte AnM1
	.byte W02
	.byte FnM1
	.byte W02
	.byte DnM1
	.byte BEND, c_v-16
	.byte W02
	.byte VOL, 12
	.byte W02
	.byte AnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte GnM2
	.byte W01

	.byte FINE

.align 2

track_247:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_247_0
	.word track_247_1

.align 2
