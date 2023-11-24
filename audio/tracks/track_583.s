.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_583

track_583_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte MOD, 30
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 60
	.byte MODT, mod_tre
	.byte BEND, c_v+63
	.byte TIE
	.byte Cn3, Gs4
	.byte W02
	.byte VOL, 70
	.byte W08
	.byte An3
	.byte W02
	.byte Gs3
	.byte W04
	.byte Fs3
	.byte W06
	.byte Fs3
	.byte W02
	.byte Fn3
	.byte W02
	.byte En3
	.byte W02
	.byte Ds3
	.byte W02
	.byte Dn3
	.byte W02
	.byte Dn3
	.byte W04
	.byte Cn3
	.byte W04
	.byte Bn2
	.byte W04
	.byte An2
	.byte W04
	.byte Gn2
	.byte W02
	.byte Gn2
	.byte W02
	.byte Fs2
	.byte W02
	.byte En2
	.byte W02
	.byte Ds2
	.byte W02
	.byte Cs2
	.byte W02
	.byte Cn2
	.byte W02
	.byte As1
	.byte W02
	.byte Fn1
	.byte W02
	.byte Dn1
	.byte W02
	.byte An0
	.byte W02
	.byte Fs0
	.byte W02
	.byte Ds0
	.byte W02
	.byte Cn0
	.byte W02
	.byte AnM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte EnM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte CnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W02
	.byte CnM2
	.byte W02
	.byte EOT

	.byte FINE

track_583_1:
	.byte KEYSH, 0
	.byte VOICE, 34
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+63
	.byte TIE
	.byte Cn2, Gs4
	.byte W02
	.byte VOL, 70
	.byte W08
	.byte An3
	.byte W02
	.byte Gs3
	.byte W04
	.byte Fs3
	.byte W06
	.byte Fs3
	.byte W02
	.byte Fn3
	.byte W02
	.byte En3
	.byte W02
	.byte Ds3
	.byte W02
	.byte Dn3
	.byte W02
	.byte Dn3
	.byte W04
	.byte Cn3
	.byte W04
	.byte Bn2
	.byte W04
	.byte An2
	.byte W04
	.byte Gn2
	.byte W02
	.byte Gn2
	.byte W02
	.byte Fs2
	.byte W02
	.byte En2
	.byte W02
	.byte Ds2
	.byte W02
	.byte Cs2
	.byte W02
	.byte Cn2
	.byte W02
	.byte As1
	.byte W02
	.byte Fn1
	.byte W02
	.byte Dn1
	.byte W02
	.byte An0
	.byte W02
	.byte Fs0
	.byte W02
	.byte Ds0
	.byte W02
	.byte Cn0
	.byte W02
	.byte AnM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte EnM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte CnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W02
	.byte CnM2
	.byte W02
	.byte EOT

	.byte FINE

.align 2

track_583:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_583_0
	.word track_583_1

.align 2
