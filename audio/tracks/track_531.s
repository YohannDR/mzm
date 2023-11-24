.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_531

track_531_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W14
	.byte VOICE, 15
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 0
	.byte N60
	.byte Gn1, En6, CsM2
	.byte N60
	.byte Cn2, En6, CsM2
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte DsM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte BnM2
	.byte W01
	.byte DnM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte BnM1
	.byte W01
	.byte Fn0
	.byte W01
	.byte Dn1
	.byte W01
	.byte Gs1
	.byte W01
	.byte Cn2
	.byte W01
	.byte En2
	.byte W01
	.byte Gn2
	.byte W01
	.byte As2
	.byte W01
	.byte Cs3
	.byte W01
	.byte Ds3
	.byte W01
	.byte Fn3
	.byte W01
	.byte Gn3
	.byte W01
	.byte Gs3
	.byte W01
	.byte As3
	.byte W02
	.byte As3
	.byte W01
	.byte Bn3
	.byte W01
	.byte As3
	.byte W02
	.byte As3
	.byte W02
	.byte Gs3
	.byte W01
	.byte Gn3
	.byte W02
	.byte Fn3
	.byte W01
	.byte Ds3
	.byte W01
	.byte Cs3
	.byte W01
	.byte Cn3
	.byte W01
	.byte As2
	.byte W01
	.byte Gs2
	.byte W01
	.byte Fs2
	.byte W01
	.byte En2
	.byte W01
	.byte Dn2
	.byte W01
	.byte Bn1
	.byte W01
	.byte Gs1
	.byte W01
	.byte Fn1
	.byte W01
	.byte Cn1
	.byte W01
	.byte Gn0
	.byte W01
	.byte Dn0
	.byte W01
	.byte BnM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte AnM2
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
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_531_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 42
	.byte PAN, c_v
	.byte N05
	.byte Cn3, Gs4
	.byte W05
	.byte En3
	.byte W05
	.byte Bn3
	.byte W05
	.byte Bn3, Gs0
	.byte W05
	.byte Bn3, CnM1
	.byte W05

	.byte FINE

.align 2

track_531:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group16
	.word track_531_0
	.word track_531_1

.align 2
