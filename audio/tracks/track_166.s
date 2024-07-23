.align 2

.global track_166

track_166_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 40
	.byte VOL, 78
	.byte PAN, c_v
	.byte TIE
	.byte Cn3, En6
	.byte W96
	.byte W96
	.byte W48
	.byte VOL, 78
	.byte W03
	.byte Dn4
	.byte W03
	.byte An3
	.byte W03
	.byte Ds3
	.byte W03
	.byte Bn2
	.byte W03
	.byte Fs2
	.byte W03
	.byte Cs2
	.byte W03
	.byte Gs1
	.byte W03
	.byte Ds1
	.byte W03
	.byte As0
	.byte W03
	.byte Fn0
	.byte W03
	.byte Cn0
	.byte W03
	.byte GnM1
	.byte W03
	.byte DnM1
	.byte W03
	.byte AsM2
	.byte W03
	.byte EnM2
	.byte W03
	.byte CnM2
	.byte W01
	.byte EOT

	.byte FINE

.align 2

track_166:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_166_0

.align 2
