.align 2

.global track_619

track_619_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte MOD, 60
	.byte VOL, 85
	.byte PAN, c_v
	.byte LFOS, 120
	.byte N24
	.byte En3, En6, DsM2
	.byte W12
	.byte MOD, 30
	.byte LFOS, 100
	.byte W02
	.byte VOL, 85
	.byte W01
	.byte Gs3
	.byte W01
	.byte Gn2
	.byte W01
	.byte As1
	.byte W01
	.byte Cs1
	.byte W01
	.byte Fn0
	.byte W01
	.byte BnM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_619:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_619_0

.align 2
