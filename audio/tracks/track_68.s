.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_68

track_68_0:
	.byte KEYSH, 0
	.byte TEMPO, 27
	.byte VOICE, 83
	.byte PAN, c_v
	.byte PRIO, 120
	.byte VOL, 62
	.byte N03
	.byte Cn4, Gs1
	.byte W24
	.byte Cn4, Cn4
	.byte W24
	.byte N03
	.byte W72
	.byte N03
	.byte W24
	.byte W24
	.byte N03
	.byte W24
	.byte N03
	.byte W24
	.byte N02
	.byte W24
	.byte N03
	.byte W72
	.byte N03
	.byte W24
	.byte N03
	.byte W24
track_68_lbl_2255a8:
	.byte N03
	.byte Cn4, Cn4
	.byte W24
	.byte N03
	.byte W24
	.byte GOTO
		.word track_68_lbl_2255a8

	.byte FINE

track_68_1:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte PAN, c_v
	.byte W48
track_68_lbl_2255bb:
	.byte W12
	.byte VOL, 15
	.byte N56
	.byte Dn4, Gs1, DnM2
	.byte W28
	.byte W01
	.byte VOL, 12
	.byte W06
	.byte AsM2
	.byte W07
	.byte GnM2
	.byte W06
	.byte FnM2
	.byte W06
	.byte DnM2
	.byte W30
	.byte PEND
	.byte W96
	.byte PATT
		.word track_68_lbl_2255bb
	.byte W24
track_68_lbl_2255d7:
	.byte W48
	.byte GOTO
		.word track_68_lbl_2255d7

	.byte FINE

track_68_2:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte PAN, c_v-7
	.byte W36
	.byte VOL, 2
	.byte N80
	.byte An4, Gs4, DnM2
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte FsM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte AsM2
	.byte W01
	.byte CnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Cn0
	.byte W01
track_68_lbl_225603:
	.byte VOL, 27
	.byte W02
	.byte Cs0
	.byte W03
	.byte AsM1
	.byte W03
	.byte GsM1
	.byte W06
	.byte FnM1
	.byte W08
	.byte DsM1
	.byte W08
	.byte CnM1
	.byte W08
	.byte AsM2
	.byte W08
	.byte GnM2
	.byte W08
	.byte FnM2
	.byte W08
	.byte DnM2
	.byte W05
	.byte CsM2
	.byte W28
	.byte W01
	.byte PEND
	.byte W84
	.byte DnM2
	.byte N80
	.byte An4, Gs4, DnM2
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte FsM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte AsM2
	.byte W01
	.byte CnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Cn0
	.byte W01
	.byte PATT
		.word track_68_lbl_225603
	.byte W24
track_68_lbl_225642:
	.byte W48
	.byte GOTO
		.word track_68_lbl_225642

	.byte FINE

track_68_3:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte PAN, c_v
	.byte W48
track_68_lbl_225650:
	.byte VOL, 15
	.byte N68
	.byte Gs4, Cn2, DnM2
	.byte W02
	.byte VOL, 17
	.byte W02
	.byte GnM1
	.byte W02
	.byte AnM1
	.byte W02
	.byte BnM1
	.byte W02
	.byte Cn0
	.byte W04
	.byte AsM1
	.byte W05
	.byte GsM1
	.byte W05
	.byte FsM1
	.byte W06
	.byte EnM1
	.byte W07
	.byte CsM1
	.byte W06
	.byte BnM2
	.byte W06
	.byte GsM2
	.byte W07
	.byte FsM2
	.byte W06
	.byte DsM2
	.byte W06
	.byte CsM2
	.byte W28
	.byte PEND
	.byte W96
	.byte PATT
		.word track_68_lbl_225650
	.byte W24
track_68_lbl_22567e:
	.byte W48
	.byte GOTO
		.word track_68_lbl_22567e

	.byte FINE

track_68_4:
	.byte KEYSH, 0
	.byte VOICE, 64
	.byte PAN, c_v+10
	.byte PRIO, 119
	.byte W48
	.byte W72
	.byte VOL, 10
	.byte N24
	.byte An3, En5, DnM2
	.byte N24
	.byte An4, Gs3
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte FsM1
	.byte W01
	.byte BnM1
	.byte W01
	.byte Ds0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn1
	.byte W01
	.byte En1
	.byte W01
	.byte An1
	.byte W01
	.byte Cs2
	.byte W01
	.byte Fn2
	.byte W01
	.byte An2
	.byte W01
	.byte Dn3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Bn3
	.byte W01
	.byte Dn4
	.byte W03
	.byte Bn3
	.byte W02
	.byte As3
	.byte W03
	.byte Gs3
	.byte W01
	.byte Gn3
	.byte N72
	.byte Gs3
	.byte N72
	.byte Gs4, En3
	.byte W02
	.byte VOL, 65
	.byte W03
	.byte Dn3
	.byte W03
	.byte Cs3
	.byte W03
	.byte As2
	.byte W02
	.byte Gs2
	.byte W03
	.byte Fs2
	.byte W03
	.byte En2
	.byte W03
	.byte Cs2
	.byte W04
	.byte As1
	.byte W03
	.byte Gs1
	.byte W03
	.byte Fs1
	.byte W03
	.byte Ds1
	.byte W03
	.byte Cs1
	.byte W03
	.byte Bn0
	.byte W03
	.byte Gs0
	.byte W03
	.byte Fs0
	.byte W03
	.byte Ds0
	.byte W03
	.byte Cs0
	.byte W03
	.byte BnM1
	.byte W03
	.byte GsM1
	.byte W03
	.byte FsM1
	.byte W03
	.byte EnM1
	.byte W03
	.byte CsM1
	.byte W02
	.byte BnM2
	.byte W24
	.byte W02
	.byte W96
	.byte W24
track_68_lbl_2256f9:
	.byte W48
	.byte GOTO
		.word track_68_lbl_2256f9

	.byte FINE

track_68_5:
	.byte KEYSH, 0
	.byte VOICE, 83
	.byte PAN, c_v
	.byte PRIO, 30
	.byte VOL, 62
	.byte W48
	.byte W24
	.byte N03
	.byte Cn4, Gs4
	.byte W24
	.byte N03
	.byte W48
	.byte Cn4, Cn4
	.byte W96
	.byte W24
	.byte N03
	.byte W24
	.byte N03
	.byte W48
	.byte W24
track_68_lbl_22571b:
	.byte W48
	.byte GOTO
		.word track_68_lbl_22571b

	.byte FINE

.align 2

track_68:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_68_0
	.word track_68_1
	.word track_68_2
	.word track_68_3
	.word track_68_4
	.word track_68_5

.align 2
