.align 2

.global track_61

track_61_0:
	.byte KEYSH, 0
track_61_lbl_222556:
	.byte TEMPO, 69
	.byte VOICE, 34
	.byte PAN, c_v
	.byte VOL, 85
	.byte N06
	.byte Fn1, Cn8
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
track_61_lbl_222580:
	.byte N06
	.byte Gn1, Cn8
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte PEND
	.byte Gs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Gs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Gs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Gs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Gs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Gs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Gs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Gs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte PATT
		.word track_61_lbl_222580
	.byte GOTO
		.word track_61_lbl_222556

	.byte FINE

track_61_1:
	.byte KEYSH, 0
track_61_lbl_2225d0:
	.byte VOICE, 5
	.byte VOL, 56
	.byte PAN, c_v-34
	.byte PRIO, 119
	.byte BEND, c_v-8
	.byte N96
	.byte Fn1, En7
	.byte W12
	.byte PAN, c_v-30
	.byte W11
	.byte Dn1
	.byte W11
	.byte Fs1
	.byte W11
	.byte As1
	.byte W10
	.byte Dn2
	.byte W11
	.byte Fs2
	.byte W11
	.byte As2
	.byte W11
	.byte Dn3
	.byte W08
	.byte N96
	.byte Fs1
	.byte W03
	.byte PAN, c_v+2
	.byte W05
	.byte Gs3
	.byte W11
	.byte Cn4
	.byte W11
	.byte En4
	.byte W11
	.byte Gs4
	.byte W11
	.byte Cn5
	.byte W11
	.byte En5
	.byte W10
	.byte Gs5
	.byte W11
	.byte Cn6
	.byte W11
	.byte En6
	.byte W01
	.byte N96
	.byte Gn1
	.byte W10
	.byte PAN, c_v+32
	.byte W10
	.byte Gs5
	.byte W05
	.byte Fs5
	.byte W11
	.byte Dn5
	.byte W10
	.byte As4
	.byte W10
	.byte Fs4
	.byte W10
	.byte Dn4
	.byte W11
	.byte As3
	.byte W10
	.byte Fs3
	.byte W09
	.byte N96
	.byte Fs1
	.byte W01
	.byte PAN, c_v-2
	.byte W10
	.byte As2
	.byte W11
	.byte Fs2
	.byte W10
	.byte Dn2
	.byte W10
	.byte As1
	.byte W10
	.byte Fs1
	.byte W11
	.byte Dn1
	.byte W10
	.byte As0
	.byte W10
	.byte Fs0
	.byte W10
	.byte Dn0
	.byte W03
	.byte GOTO
		.word track_61_lbl_2225d0

	.byte FINE

track_61_2:
	.byte KEYSH, 0
track_61_lbl_22263d:
	.byte VOICE, 14
	.byte VOL, 49
	.byte PAN, c_v+26
	.byte PRIO, 118
	.byte BEND, c_v
	.byte N96
	.byte Fn3, En6
	.byte W10
	.byte PAN, c_v+22
	.byte W10
	.byte As4
	.byte W11
	.byte Fs4
	.byte W11
	.byte Dn4
	.byte W11
	.byte As3
	.byte W10
	.byte Fs3
	.byte W11
	.byte Dn3
	.byte W11
	.byte As2
	.byte W11
	.byte Fs2
	.byte N96
	.byte Fs3
	.byte W10
	.byte PAN, c_v-14
	.byte W11
	.byte As1
	.byte W11
	.byte Fs1
	.byte W11
	.byte Dn1
	.byte W10
	.byte As0
	.byte W11
	.byte Fs0
	.byte W11
	.byte Dn0
	.byte W11
	.byte AsM1
	.byte W08
	.byte GnM1
	.byte W02
	.byte N96
	.byte Gn3
	.byte W15
	.byte PAN, c_v-40
	.byte W09
	.byte En0
	.byte W08
	.byte Gs0
	.byte W09
	.byte Cn1
	.byte W09
	.byte En1
	.byte W08
	.byte Gs1
	.byte W09
	.byte Cn2
	.byte W09
	.byte En2
	.byte W08
	.byte Gs2
	.byte W09
	.byte Cn3
	.byte W03
	.byte N96
	.byte Fs3
	.byte W06
	.byte PAN, c_v
	.byte W08
	.byte Gs3
	.byte W09
	.byte Cn4
	.byte W09
	.byte En4
	.byte W08
	.byte Gs4
	.byte W09
	.byte Cn5
	.byte W09
	.byte En5
	.byte W08
	.byte Gs5
	.byte W09
	.byte Cn6
	.byte W09
	.byte En6
	.byte W08
	.byte Gs6
	.byte W04
	.byte GOTO
		.word track_61_lbl_22263d
	.byte PAN, c_v+42

	.byte FINE

track_61_3:
	.byte KEYSH, 0
track_61_lbl_2226af:
	.byte VOICE, 14
	.byte PAN, c_v
	.byte VOL, 49
	.byte PRIO, 120
	.byte BEND, c_v
	.byte TIE
	.byte Fn3, En6
	.byte W96
	.byte W06
	.byte EOT
	.byte N96
	.byte Fs3
	.byte W90
	.byte W06
	.byte Gn3
	.byte W90
	.byte W06
	.byte N90
	.byte Fs3
	.byte W90
	.byte GOTO
		.word track_61_lbl_2226af

	.byte FINE

.align 2

track_61:
	.byte 4
	.byte 0
	.byte 130
	.byte 0
	.word voice_group22
	.word track_61_0
	.word track_61_1
	.word track_61_2
	.word track_61_3

.align 2
