.align 2

.global track_658

track_658_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 6
	.byte PRIO, 1
	.byte BEND, c_v
	.byte N64
	.byte Cn3, Gs4, CsM2
	.byte W66
	.byte BEND, c_v-16
	.byte N56
	.byte Cn3, EnM1, DnM2
	.byte W30
	.byte W16
	.byte VOL, 33
	.byte W01
	.byte Cs0
	.byte W01
	.byte AnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_658_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v
	.byte W36
	.byte Gs2
	.byte N64
	.byte Cn3, En0, CsM2
	.byte W60
	.byte W05

	.byte FINE

.align 2

track_658:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group13
	.word track_658_0
	.word track_658_1

.align 2
