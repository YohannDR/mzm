.align 2

.global track_235

track_235_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 32
	.byte VOL, 56
	.byte PAN, c_v
	.byte N28
	.byte Dn3, Gs4
	.byte W03
	.byte MOD, 40
	.byte LFOS, 110
	.byte W12
	.byte MOD, 0
	.byte W13

	.byte FINE

track_235_1:
	.byte KEYSH, 0
	.byte VOICE, 32
	.byte VOL, 42
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte N07
	.byte Fn2, Cn3
	.byte W01
	.byte BEND, c_v+47
	.byte W01
	.byte Cn6
	.byte W01
	.byte Gs4
	.byte W01
	.byte En3
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte GnM2
	.byte W01
	.byte VOICE, 24
	.byte VOL, 28
	.byte BENDR, 12
	.byte BEND, c_v-6
	.byte N28
	.byte Cn3, En6, CsM2
	.byte W01
	.byte VOL, 42
	.byte W01
	.byte Gs2
	.byte W07
	.byte DnM1
	.byte BEND, c_v-16
	.byte W09
	.byte VOL, 7
	.byte BEND, c_v-18
	.byte W11

	.byte FINE

.align 2

track_235:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_235_0
	.word track_235_1

.align 2
