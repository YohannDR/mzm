.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_468

track_468_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte MOD, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 127
	.byte PRIO, 2
	.byte BEND, c_v-63
	.byte TIE
	.byte Fn3, Gs4
	.byte W01
	.byte BEND, c_v-42
	.byte W01
	.byte Gn1
	.byte W01
	.byte Ds3
	.byte W01
	.byte Cn5
	.byte W01
	.byte An6
	.byte W01
	.byte Fs8
	.byte W90
	.byte W24
	.byte W01
	.byte VOL, 39
	.byte W01
	.byte Fs0
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
	.byte EOT

	.byte FINE

track_468_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte TIE
	.byte Cn7, En1
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte DsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte DsM1
	.byte W01
	.byte Cs0
	.byte W90
	.byte W20
	.byte GsM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W06
	.byte EOT

	.byte FINE

track_468_2:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 5
	.byte VOL, 49
	.byte PAN, c_v
	.byte BENDR, 6
	.byte PRIO, 1
	.byte N44
	.byte Cn3, Gs4, CsM2
	.byte W02
	.byte VOL, 51
	.byte W02
	.byte Fs2
	.byte W02
	.byte As2
	.byte W02
	.byte Cs3
	.byte W02
	.byte Bn2
	.byte W02
	.byte Ds2
	.byte W02
	.byte Ds1
	.byte W02
	.byte Fn0
	.byte W02
	.byte AnM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte An0
	.byte W02
	.byte En1
	.byte W02
	.byte Bn1
	.byte W02
	.byte En2
	.byte W02
	.byte Gs2
	.byte W02
	.byte Fs2
	.byte W02
	.byte Ds2
	.byte W02
	.byte Cs2
	.byte W02
	.byte En2
	.byte W02
	.byte Gn2
	.byte W02
	.byte Gs2
	.byte W03

	.byte FINE

.align 2

track_468:
	.byte 3
	.byte 0
	.byte 227
	.byte 0
	.word voice_group12
	.word track_468_0
	.word track_468_1
	.word track_468_2

.align 2
