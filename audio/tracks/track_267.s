.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_267

track_267_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v
	.byte TIE
	.byte An1, En6
	.byte W01
track_267_lbl_20fc4a:
	.byte W05
	.byte BEND, c_v+10
	.byte W06
	.byte Bn4
	.byte W06
	.byte Gn5
	.byte W06
	.byte Bn5
	.byte W05
	.byte Cn6
	.byte W08
	.byte As5
	.byte W06
	.byte Fn5
	.byte W05
	.byte Bn4
	.byte W06
	.byte Ds4
	.byte W06
	.byte Fn3
	.byte W07
	.byte Fn2
	.byte W05
	.byte An1
	.byte W06
	.byte Dn1
	.byte W06
	.byte An0
	.byte W12
	.byte W01
	.byte Bn0
	.byte W05
	.byte Dn1
	.byte W06
	.byte An1
	.byte W06
	.byte Fs2
	.byte W06
	.byte En3
	.byte W06
	.byte Dn4
	.byte W06
	.byte Bn4
	.byte W06
	.byte Gn5
	.byte W06
	.byte Bn5
	.byte W05
	.byte Cn6
	.byte W09
	.byte An5
	.byte W05
	.byte Fn5
	.byte W05
	.byte Bn4
	.byte W06
	.byte Ds4
	.byte W06
	.byte Fn3
	.byte W06
	.byte Gn2
	.byte W06
	.byte An1
	.byte W06
	.byte Dn1
	.byte W06
	.byte An0
	.byte W13
	.byte As0
	.byte W05
	.byte Dn1
	.byte W06
	.byte An1
	.byte W06
	.byte Fs2
	.byte W06
	.byte GOTO
		.word track_267_lbl_20fc4a
	.byte W01
	.byte EOT, An1

	.byte FINE

track_267_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte MOD, 50
	.byte VOL, 94
	.byte PAN, c_v
	.byte LFOS, 20
	.byte MODT, mod_tre
	.byte TIE
	.byte Cn3, Cn8
	.byte W01
track_267_lbl_20fcb2:
	.byte W23
	.byte MOD, 30
	.byte W24
	.byte GsM1
	.byte W24
	.byte Cn3
	.byte W24
	.byte Dn2
	.byte W24
	.byte GsM1
	.byte W24
	.byte En1
	.byte W24
	.byte Fs0
	.byte W24
	.byte Cn3
	.byte W24
	.byte Dn2
	.byte W24
	.byte GOTO
		.word track_267_lbl_20fcb2
	.byte W01
	.byte EOT, Cn3

	.byte FINE

track_267_2:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte MOD, 12
	.byte VOL, 70
	.byte PAN, c_v
	.byte LFOS, 120
	.byte PRIO, 25
	.byte W01
track_267_lbl_20fcde:
	.byte N05
	.byte Gn2, Gs4
	.byte W05
	.byte Dn2, En6
	.byte W09
	.byte Gn2, Gs4
	.byte W05
	.byte Dn2, En6
	.byte W05
	.byte Gn2, Gs4
	.byte W06
	.byte N05
	.byte W05
	.byte Dn2, En6
	.byte W05
	.byte Gn2, Gs4
	.byte W09
	.byte Dn2, En6
	.byte W05
	.byte Gn2, Gs4
	.byte W05
	.byte N05
	.byte W06
	.byte En2, En6
	.byte W08
	.byte Fn2, Gs5
	.byte W05
	.byte Dn2, En6
	.byte W07
	.byte Gn2, Gs4
	.byte W05
	.byte Dn2, En6
	.byte W05
	.byte W01
	.byte Fn2, Gs5
	.byte W05
	.byte Gn2, En6
	.byte W07
	.byte Dn2
	.byte W05
	.byte Fn2, Gs5
	.byte W07
	.byte Gn2, Gs4
	.byte W05
	.byte Fn2, Gs5
	.byte W09
	.byte En2, En6
	.byte W05
	.byte Dn2
	.byte W05
	.byte Fn2
	.byte W06
	.byte Gn2
	.byte W05
	.byte Fn2, Gs5
	.byte W05
	.byte Gn2, Gs4
	.byte W09
	.byte Dn2, En6
	.byte W05
	.byte Gn2, Gs4
	.byte W05
	.byte Fn2, En6
	.byte W06
	.byte En2
	.byte W06
	.byte W02
	.byte Fn2
	.byte W05
	.byte Dn2, Gs5
	.byte W07
	.byte Gn2, Gs4
	.byte W05
	.byte Fn2, En6
	.byte W06
	.byte Gn2, Gs4
	.byte W05
	.byte Dn2, En6
	.byte W07
	.byte N05
	.byte W05
	.byte Gn2, Gs5
	.byte W06
	.byte GOTO
		.word track_267_lbl_20fcde

	.byte FINE

.align 2

track_267:
	.byte 3
	.byte 0
	.byte 228
	.byte 0
	.word voice_group4
	.word track_267_0
	.word track_267_1
	.word track_267_2

.align 2
