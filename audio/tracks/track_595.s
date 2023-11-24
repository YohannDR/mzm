.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_595

track_595_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte PAN, c_v
	.byte W72
	.byte VOICE, 12
	.byte VOL, 110
	.byte BENDR, 6
	.byte BEND, c_v-63
	.byte TIE
	.byte Cn2, Gn8
	.byte W03
	.byte BEND, c_v-62
	.byte W01
	.byte DsM2
	.byte W03
	.byte EnM2
	.byte W01
	.byte FnM2
	.byte W02
	.byte FsM2
	.byte W01
	.byte GnM2
	.byte W03
	.byte GsM2
	.byte W01
	.byte AnM2
	.byte W02
	.byte AsM2
	.byte W01
	.byte BnM2
	.byte W02
	.byte CnM1
	.byte W01
	.byte CsM1
	.byte W02
	.byte DnM1
	.byte W01
	.byte DsM1
	.byte W02
	.byte EnM1
	.byte W01
	.byte FnM1
	.byte W02
	.byte FsM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte AnM1
	.byte W02
	.byte BnM1
	.byte W02
	.byte Cs0
	.byte W02
	.byte Ds0
	.byte W01
	.byte En0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Fs0
	.byte W01
	.byte Gn0
	.byte W01
	.byte An0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Cs1
	.byte W01
	.byte Fs1
	.byte W01
	.byte Gn1
	.byte W01
	.byte An1
	.byte W01
	.byte As1
	.byte W01
	.byte Bn1
	.byte W02
	.byte Cn2
	.byte W01
	.byte Cs2
	.byte W18
	.byte Cs2
	.byte W03
	.byte Cn2
	.byte W01
	.byte Bn1
	.byte W14
	.byte As1
	.byte W02
	.byte An1
	.byte W13
	.byte As1
	.byte W02
	.byte Bn1
	.byte W04
	.byte Cn2
	.byte W01
	.byte Cs2
	.byte W09
	.byte W03
	.byte Cn2
	.byte W01
	.byte Bn1
	.byte W09
	.byte Cn2
	.byte W01
	.byte Cs2
	.byte W11
	.byte Cn2
	.byte W01
	.byte Bn1
	.byte W09
	.byte Cn2
	.byte W01
	.byte Cs2
	.byte W02
	.byte Dn2
	.byte W07
	.byte Cs2
	.byte W09
	.byte EOT

	.byte FINE

track_595_1:
	.byte KEYSH, 0
	.byte W44
	.byte W02
	.byte VOICE, 33
	.byte VOL, 86
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v
	.byte N60
	.byte Bn2, Gn8
	.byte W36
	.byte W02
	.byte VOL, 85
	.byte W01
	.byte Fn4
	.byte W01
	.byte Gs3
	.byte W01
	.byte Cs3
	.byte W01
	.byte Fs2
	.byte W01
	.byte Cs2
	.byte W01
	.byte Gs1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Gn0
	.byte W01
	.byte Dn0
	.byte W01
	.byte Cn0
	.byte W01
	.byte AnM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_595_2:
	.byte KEYSH, 0
	.byte W22
	.byte VOICE, 35
	.byte VOL, 77
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N05
	.byte Cn3, Gn8
	.byte W05
	.byte VOICE, 36
	.byte N07
	.byte W07
	.byte Cn3, En2
	.byte W07
	.byte Cn3, CnM1
	.byte W03
	.byte VOICE, 34
	.byte VOL, 60
	.byte N05
	.byte Cn4, Gs4
	.byte W05
	.byte As4
	.byte W05
	.byte Gs4
	.byte W07
	.byte Gs4, En1
	.byte W07
	.byte N05
	.byte W07
	.byte Gs4, GsM1
	.byte W07
	.byte N05
	.byte W05

	.byte FINE

.align 2

track_595:
	.byte 3
	.byte 0
	.byte 252
	.byte 0
	.word voice_group17
	.word track_595_0
	.word track_595_1
	.word track_595_2

.align 2
