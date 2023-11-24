.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_471

track_471_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte N84
	.byte Cn2, Gn8
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte GnM2
	.byte W02
	.byte CsM1
	.byte W02
	.byte AnM1
	.byte W02
	.byte Cn1
	.byte W02
	.byte Dn3
	.byte W24
	.byte Dn3
	.byte W02
	.byte An2
	.byte W02
	.byte Ds2
	.byte W02
	.byte Bn1
	.byte W02
	.byte Fs1
	.byte W02
	.byte Dn1
	.byte W02
	.byte As0
	.byte W02
	.byte Fs0
	.byte W02
	.byte Ds0
	.byte W02
	.byte Cn0
	.byte W02
	.byte AsM1
	.byte W02
	.byte GnM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte CsM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte AsM2
	.byte W02
	.byte GsM2
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
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_471_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte N84
	.byte Fn2, Gn8
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte FsM2
	.byte W02
	.byte AsM2
	.byte W02
	.byte DnM1
	.byte W02
	.byte GnM1
	.byte W02
	.byte Cn0
	.byte W02
	.byte Gs0
	.byte W02
	.byte En1
	.byte W02
	.byte Dn2
	.byte W02
	.byte Dn3
	.byte W16
	.byte Dn3
	.byte W02
	.byte An2
	.byte W02
	.byte Ds2
	.byte W02
	.byte Bn1
	.byte W02
	.byte Fs1
	.byte W02
	.byte Dn1
	.byte W02
	.byte As0
	.byte W02
	.byte Fs0
	.byte W02
	.byte Ds0
	.byte W02
	.byte Cn0
	.byte W02
	.byte AsM1
	.byte W02
	.byte GnM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte CsM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte AsM2
	.byte W02
	.byte GsM2
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
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_471:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group12
	.word track_471_0
	.word track_471_1

.align 2
