.align 2

.global track_444

track_444_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 14
	.byte BEND, c_v-63
	.byte N32
	.byte Cn2, Gs4, CsM2
	.byte W01
	.byte BEND, c_v-56
	.byte W01
	.byte DsM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Fn0
	.byte W01
	.byte Cn1
	.byte W01
	.byte MOD, 40
	.byte LFOS, 127
	.byte BEND, c_v-21
	.byte W01
	.byte Dn2
	.byte W01
	.byte An2
	.byte W01
	.byte En3
	.byte W01
	.byte Bn3
	.byte W01
	.byte Fs4
	.byte W01
	.byte MOD, 20
	.byte BEND, c_v+21
	.byte W01
	.byte Gs5
	.byte W01
	.byte Ds6
	.byte W01
	.byte As6
	.byte W01
	.byte Fn7
	.byte W01
	.byte Cn8
	.byte W01
	.byte MOD, 10
	.byte BEND, c_v+63
	.byte W06
	.byte VOL, 56
	.byte W01
	.byte Dn1
	.byte W01
	.byte Dn0
	.byte W01
	.byte GnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_444:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_444_0

.align 2
