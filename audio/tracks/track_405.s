.align 2

.global track_405

track_405_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 30
	.byte VOL, 63
	.byte PAN, c_v
	.byte BENDR, 8
	.byte LFOS, 40
	.byte BEND, c_v-63
	.byte N44
	.byte Cn3, En6
	.byte W02
	.byte BEND, c_v-61
	.byte W02
	.byte FsM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte CnM1
	.byte W02
	.byte DsM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte AnM1
	.byte W02
	.byte Cn0
	.byte W02
	.byte Ds0
	.byte W02
	.byte Fs0
	.byte W02
	.byte An0
	.byte W02
	.byte Cn1
	.byte W02
	.byte Ds1
	.byte W02
	.byte Fn1
	.byte W02
	.byte Gs1
	.byte W02
	.byte Bn1
	.byte W02
	.byte Dn2
	.byte W02
	.byte Fn2
	.byte W02
	.byte Gs2
	.byte W02
	.byte Bn2
	.byte W02
	.byte Dn3
	.byte W01
	.byte En3
	.byte W01

	.byte FINE

track_405_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte MOD, 30
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 6
	.byte LFOS, 120
	.byte BEND, c_v-63
	.byte N24
	.byte Fn2, En6
	.byte W02
	.byte BEND, c_v-61
	.byte W02
	.byte FsM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte CnM1
	.byte W02
	.byte DsM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte AnM1
	.byte W02
	.byte Cn0
	.byte W02
	.byte Ds0
	.byte W02
	.byte Fs0
	.byte W02
	.byte An0
	.byte W02
	.byte Cn1
	.byte N20
	.byte W02
	.byte BEND, c_v-25
	.byte W02
	.byte Fn1
	.byte W02
	.byte Gs1
	.byte W02
	.byte Bn1
	.byte W02
	.byte Dn2
	.byte W02
	.byte Fn2
	.byte W02
	.byte Gs2
	.byte W02
	.byte Bn2
	.byte W02
	.byte Dn3
	.byte W01
	.byte En3
	.byte W01

	.byte FINE

.align 2

track_405:
	.byte 2
	.byte 0
	.byte 201
	.byte 0
	.word voice_group6
	.word track_405_0
	.word track_405_1

.align 2
