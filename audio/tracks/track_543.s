.align 2

.global track_543

track_543_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 4
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFOS, 120
	.byte N44
	.byte An2, Gs2, DsM2
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte CsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte CnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte BnM1
	.byte W01
	.byte Fn0
	.byte W01
	.byte Cs1
	.byte W01
	.byte Bn1
	.byte W28
	.byte W01
	.byte Cn0
	.byte W01
	.byte CsM1
	.byte W01
	.byte FnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_543_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte N44
	.byte Gn3, Gs2, DsM2
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte DnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte BnM2
	.byte W01
	.byte CsM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Dn0
	.byte W01
	.byte Fs0
	.byte W01
	.byte As0
	.byte W02
	.byte Bn0
	.byte W01
	.byte As0
	.byte W02
	.byte An0
	.byte W02
	.byte Gs0
	.byte W16
	.byte Gn0
	.byte W01
	.byte Cn0
	.byte W01
	.byte FsM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_543:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_543_0
	.word track_543_1

.align 2
