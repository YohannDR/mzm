.align 2

.global track_358

track_358_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 25
	.byte VOL, 50
	.byte PAN, c_v
	.byte N24
	.byte Fn4, En6, CsM2
	.byte W04
	.byte VOL, 42
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Cs0
	.byte W01
	.byte AnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_358:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_358_0

.align 2
