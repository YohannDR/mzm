.align 2

.global track_339

track_339_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte N23
	.byte Gn2, Gs5
	.byte W04
	.byte BEND, c_v+15
	.byte W04
	.byte Cn3
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte Dn1
	.byte W01
	.byte As0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Cn0
	.byte W01
	.byte GsM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_339:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_339_0

.align 2
