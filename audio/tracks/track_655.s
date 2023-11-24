.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_655

track_655_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 86
	.byte PAN, c_v-20
	.byte TIE
	.byte Dn3, En6
	.byte W96
	.byte W54
	.byte VOL, 86
	.byte W02
	.byte Cs5
	.byte W06
	.byte Cn5
	.byte W02
	.byte Cn5
	.byte W04
	.byte As4
	.byte W04
	.byte An4
	.byte W02
	.byte Gs4
	.byte W02
	.byte Fs4
	.byte W04
	.byte Fn4
	.byte W02
	.byte Ds4
	.byte W02
	.byte Cs4
	.byte W02
	.byte As3
	.byte W02
	.byte Gs3
	.byte W02
	.byte En3
	.byte W02
	.byte Dn3
	.byte W02
	.byte As2
	.byte W02
	.byte Fs2
	.byte W02
	.byte Cs2
	.byte W02
	.byte An1
	.byte W02
	.byte Fs1
	.byte W02
	.byte Dn1
	.byte W02
	.byte Bn0
	.byte W02
	.byte Gs0
	.byte W02
	.byte Fs0
	.byte W02
	.byte Dn0
	.byte W02
	.byte Cs0
	.byte W02
	.byte BnM1
	.byte W02
	.byte GnM1
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
	.byte FsM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CsM2
	.byte W02
	.byte CnM2
	.byte W02
	.byte EOT

	.byte FINE

track_655_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 110
	.byte PAN, c_v-20
	.byte TIE
	.byte En2, En0
	.byte W96
	.byte W54
	.byte VOL, 86
	.byte W02
	.byte Cs5
	.byte W06
	.byte Cn5
	.byte W02
	.byte Cn5
	.byte W04
	.byte As4
	.byte W04
	.byte An4
	.byte W02
	.byte Gs4
	.byte W02
	.byte Fs4
	.byte W04
	.byte Fn4
	.byte W02
	.byte Ds4
	.byte W02
	.byte Cs4
	.byte W02
	.byte As3
	.byte W02
	.byte Gs3
	.byte W02
	.byte En3
	.byte W02
	.byte Dn3
	.byte W02
	.byte As2
	.byte W02
	.byte Fs2
	.byte W02
	.byte Cs2
	.byte W02
	.byte An1
	.byte W02
	.byte Fs1
	.byte W02
	.byte Dn1
	.byte W02
	.byte Bn0
	.byte W02
	.byte Gs0
	.byte W02
	.byte Fs0
	.byte W02
	.byte Dn0
	.byte W02
	.byte Cs0
	.byte W02
	.byte BnM1
	.byte W02
	.byte GnM1
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
	.byte FsM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CsM2
	.byte W02
	.byte CnM2
	.byte W02
	.byte EOT

	.byte FINE

.align 2

track_655:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group17
	.word track_655_0
	.word track_655_1

.align 2
