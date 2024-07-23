.align 2

.global track_117

track_117_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 52
	.byte PAN, c_v
	.byte N40
	.byte Cn3, Gs4, CsM2
	.byte W24
	.byte VOL, 41
	.byte W01
	.byte An0
	.byte W01
	.byte Dn0
	.byte W01
	.byte GsM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FsM2
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
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_117:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_117_0

.align 2
