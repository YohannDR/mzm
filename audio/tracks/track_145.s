.align 2

.global track_145

track_145_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 44
	.byte PAN, c_v
	.byte N08
	.byte En2, Gs4
	.byte W08
	.byte Fn2, En6
	.byte W08
	.byte N09
	.byte Gn2, Gs4
	.byte W09
	.byte N36
	.byte An2, En3, DnM2
	.byte W03
	.byte VOL, 52
	.byte W03
	.byte Dn1
	.byte W03
	.byte Cs0
	.byte W03
	.byte FsM1
	.byte W03
	.byte CnM1
	.byte W03
	.byte GsM2
	.byte W03
	.byte FsM2
	.byte W03
	.byte EnM2
	.byte W03
	.byte DsM2
	.byte W03
	.byte DnM2
	.byte W03
	.byte CsM2
	.byte W03
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_145:
	.byte 1
	.byte 0
	.byte 150
	.byte 0
	.word voice_group1
	.word track_145_0

.align 2
