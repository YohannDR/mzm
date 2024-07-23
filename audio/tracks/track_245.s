.align 2

.global track_245

track_245_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 56
	.byte PAN, c_v
	.byte MODT, mod_tre
	.byte N28
	.byte Cn3, Gs4
	.byte W03
	.byte MOD, 30
	.byte LFOS, 100
	.byte W17
	.byte MOD, 0
	.byte W02
	.byte VOL, 55
	.byte W01
	.byte Fn2
	.byte W01
	.byte En2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Cs2
	.byte W02

	.byte FINE

track_245_1:
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
	.byte N09
	.byte Bn2, Gs4
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte En0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Gn1
	.byte W01
	.byte Ds2
	.byte W01
	.byte As2
	.byte W06
	.byte N09
	.byte An2, Gs0
	.byte W09
	.byte Gn2, CnM1
	.byte W09

	.byte FINE

.align 2

track_245:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_245_0
	.word track_245_1

.align 2
