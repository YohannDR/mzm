.align 2

.global track_72

track_72_0:
	.byte KEYSH, 0
	.byte TEMPO, 69
	.byte VOICE, 34
	.byte PAN, c_v
	.byte VOL, 75
	.byte N06
	.byte Fn1, En1
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
	.byte Fn1, En2
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
	.byte Gn1
	.byte W06
	.byte Fs1, Gs2
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1, Cn3
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1, En3
	.byte W06
	.byte Fs1, Gs3
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1, Cn4
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Gs1, Gs4
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
	.byte Gs1, Cn6
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
	.byte Gn1, En6
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
	.byte Fn1, Cn7
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
	.byte Fn1, En7
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1, Gs7
	.byte W06
	.byte Fs1
	.byte W06
	.byte Fn1
	.byte W06
	.byte Fs1
	.byte W06
track_72_lbl_22763c:
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
		.word track_72_lbl_22763c
	.byte VOICE, 34
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
	.byte GOTO
		.word track_72_lbl_22763c

	.byte FINE

track_72_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 10
	.byte PAN, c_v-34
	.byte PRIO, 119
	.byte BEND, c_v-8
	.byte N96
	.byte Fn1, En7
	.byte W12
	.byte PAN, c_v-30
	.byte W06
	.byte VOL, 12
	.byte W05
	.byte PAN, c_v-26
	.byte W11
	.byte Fs1
	.byte W01
	.byte VOL, 15
	.byte W10
	.byte PAN, c_v-18
	.byte W08
	.byte VOL, 17
	.byte W02
	.byte PAN, c_v-14
	.byte W11
	.byte Fs2
	.byte W04
	.byte VOL, 20
	.byte W07
	.byte PAN, c_v-6
	.byte W11
	.byte VOL, 22
	.byte PAN, c_v-2
	.byte W08
	.byte N96
	.byte Fs1
	.byte W03
	.byte PAN, c_v+2
	.byte W05
	.byte Gs3
	.byte W10
	.byte VOL, 26
	.byte W01
	.byte PAN, c_v+8
	.byte W11
	.byte En4
	.byte W05
	.byte VOL, 28
	.byte W06
	.byte PAN, c_v+16
	.byte W11
	.byte Cn5
	.byte W01
	.byte VOL, 31
	.byte W10
	.byte PAN, c_v+24
	.byte W07
	.byte VOL, 34
	.byte W03
	.byte PAN, c_v+28
	.byte W15
	.byte VOL, 36
	.byte W07
	.byte PAN, c_v+36
	.byte W01
	.byte N96
	.byte Gn1
	.byte W09
	.byte VOL, 39
	.byte W01
	.byte PAN, c_v+32
	.byte W10
	.byte Gs5
	.byte W05
	.byte Fs5
	.byte W02
	.byte VOL, 41
	.byte W09
	.byte PAN, c_v+22
	.byte W08
	.byte VOL, 44
	.byte W02
	.byte PAN, c_v+18
	.byte W10
	.byte Fs4
	.byte W06
	.byte VOL, 46
	.byte W04
	.byte PAN, c_v+10
	.byte W11
	.byte As3
	.byte W02
	.byte VOL, 49
	.byte W08
	.byte PAN, c_v+2
	.byte W09
	.byte VOL, 51
	.byte N96
	.byte Fs1
	.byte W01
	.byte PAN, c_v-2
	.byte W10
	.byte As2
	.byte W07
	.byte VOL, 54
	.byte W04
	.byte PAN, c_v-10
	.byte W10
	.byte Dn2
	.byte W03
	.byte VOL, 56
	.byte W07
	.byte PAN, c_v-18
	.byte W10
	.byte Fs1
	.byte W01
	.byte VOL, 59
	.byte W10
	.byte PAN, c_v-26
	.byte W07
	.byte VOL, 61
	.byte W03
	.byte PAN, c_v-30
	.byte W10
	.byte Fs0
	.byte W05
	.byte VOL, 64
	.byte W05
	.byte PAN, c_v-38
	.byte W03
	.byte VOICE, 5
	.byte PAN, c_v-34
	.byte BEND, c_v-8
	.byte N96
	.byte Fn1
	.byte W09
	.byte VOL, 66
	.byte W03
	.byte PAN, c_v-30
	.byte W11
	.byte Dn1
	.byte W04
	.byte VOL, 69
	.byte W07
	.byte PAN, c_v-22
	.byte W10
	.byte VOL, 71
	.byte W01
	.byte PAN, c_v-18
	.byte W10
	.byte Dn2
	.byte W07
	.byte VOL, 74
	.byte W04
	.byte PAN, c_v-10
	.byte W11
	.byte As2
	.byte W02
	.byte VOL, 76
	.byte W09
	.byte PAN, c_v-2
	.byte W08
track_72_lbl_227790:
	.byte VOL, 79
	.byte N96
	.byte Fs1, En7
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
	.byte VOICE, 5
	.byte PAN, c_v-34
	.byte BEND, c_v-8
	.byte N96
	.byte Fn1
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
	.byte GOTO
		.word track_72_lbl_227790

	.byte FINE

track_72_2:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 10
	.byte PAN, c_v+26
	.byte PRIO, 118
	.byte BEND, c_v
	.byte N96
	.byte Fn3, En6
	.byte W10
	.byte PAN, c_v+22
	.byte W08
	.byte VOL, 12
	.byte W02
	.byte PAN, c_v+18
	.byte W11
	.byte Fs4
	.byte W04
	.byte VOL, 15
	.byte W07
	.byte PAN, c_v+10
	.byte W11
	.byte As3
	.byte VOL, 17
	.byte W10
	.byte PAN, c_v+2
	.byte W07
	.byte VOL, 20
	.byte W04
	.byte PAN, c_v-2
	.byte W11
	.byte As2
	.byte W03
	.byte VOL, 22
	.byte W08
	.byte PAN, c_v-10
	.byte N96
	.byte Fs3
	.byte W10
	.byte PAN, c_v-14
	.byte W08
	.byte VOL, 26
	.byte W03
	.byte PAN, c_v-18
	.byte W11
	.byte Fs1
	.byte W03
	.byte VOL, 28
	.byte W08
	.byte PAN, c_v-26
	.byte W10
	.byte As0
	.byte VOL, 31
	.byte W11
	.byte PAN, c_v-34
	.byte W06
	.byte VOL, 34
	.byte W05
	.byte PAN, c_v-38
	.byte W11
	.byte AsM1
	.byte W02
	.byte VOL, 36
	.byte W06
	.byte PAN, c_v-45
	.byte W02
	.byte N96
	.byte Gn3
	.byte W09
	.byte VOL, 39
	.byte W06
	.byte PAN, c_v-40
	.byte W09
	.byte En0
	.byte W03
	.byte VOL, 41
	.byte W05
	.byte PAN, c_v-32
	.byte W09
	.byte Cn1
	.byte W03
	.byte VOL, 44
	.byte W06
	.byte PAN, c_v-24
	.byte W08
	.byte Gs1
	.byte W04
	.byte VOL, 46
	.byte W05
	.byte PAN, c_v-16
	.byte W09
	.byte En2
	.byte W03
	.byte VOL, 49
	.byte W05
	.byte PAN, c_v-8
	.byte W09
	.byte Cn3
	.byte W03
	.byte VOL, 51
	.byte N96
	.byte Fs3
	.byte W06
	.byte PAN, c_v
	.byte W08
	.byte Gs3
	.byte W04
	.byte VOL, 54
	.byte W05
	.byte PAN, c_v+8
	.byte W09
	.byte En4
	.byte W03
	.byte VOL, 56
	.byte W05
	.byte PAN, c_v+16
	.byte W09
	.byte Cn5
	.byte W04
	.byte VOL, 59
	.byte W05
	.byte PAN, c_v+24
	.byte W08
	.byte Gs5
	.byte W04
	.byte VOL, 61
	.byte W05
	.byte PAN, c_v+32
	.byte W09
	.byte En6
	.byte W04
	.byte VOL, 64
	.byte W04
	.byte PAN, c_v+40
	.byte W04
	.byte VOICE, 14
	.byte PAN, c_v+26
	.byte BEND, c_v
	.byte N96
	.byte Fn3
	.byte W09
	.byte VOL, 66
	.byte W01
	.byte PAN, c_v+22
	.byte W10
	.byte As4
	.byte W07
	.byte VOL, 69
	.byte W04
	.byte PAN, c_v+14
	.byte W11
	.byte Dn4
	.byte W02
	.byte VOL, 71
	.byte W09
	.byte PAN, c_v+6
	.byte W09
	.byte VOL, 74
	.byte W01
	.byte PAN, c_v+2
	.byte W11
	.byte Dn3
	.byte W05
	.byte VOL, 76
	.byte W06
	.byte PAN, c_v-6
	.byte W11
track_72_lbl_2278df:
	.byte VOL, 79
	.byte PAN, c_v-10
	.byte N96
	.byte Fs3, En6
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
	.byte VOICE, 14
	.byte PAN, c_v+26
	.byte BEND, c_v
	.byte N96
	.byte Fn3
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
	.byte GOTO
		.word track_72_lbl_2278df

	.byte FINE

track_72_3:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte PAN, c_v
	.byte VOL, 10
	.byte PRIO, 120
	.byte BEND, c_v
	.byte TIE
	.byte Fn3, En6
	.byte W18
	.byte VOL, 12
	.byte W17
	.byte DsM1
	.byte W18
	.byte FnM1
	.byte W17
	.byte GsM1
	.byte W18
	.byte AsM1
	.byte W08
	.byte W06
	.byte EOT
	.byte N96
	.byte Fs3
	.byte W12
	.byte VOL, 26
	.byte W17
	.byte En0
	.byte W18
	.byte Gn0
	.byte W17
	.byte As0
	.byte W18
	.byte Cn1
	.byte W08
	.byte W06
	.byte N96
	.byte Gn3
	.byte W03
	.byte VOL, 39
	.byte W18
	.byte Fn1
	.byte W17
	.byte Gs1
	.byte W18
	.byte As1
	.byte W17
	.byte Cs2
	.byte W17
	.byte Ds2
	.byte W06
	.byte N90
	.byte Fs3
	.byte W12
	.byte VOL, 54
	.byte W17
	.byte Gs2
	.byte W18
	.byte Bn2
	.byte W17
	.byte Cs3
	.byte W18
	.byte En3
	.byte W08
	.byte TIE
	.byte Fn3
	.byte W09
	.byte VOL, 66
	.byte W18
	.byte An3
	.byte W17
	.byte Bn3
	.byte W18
	.byte Dn4
	.byte W17
	.byte En4
	.byte W17
track_72_lbl_2279a4:
	.byte VOL, 79
	.byte W06
	.byte EOT, Fn3
	.byte N96
	.byte Fs3, En6
	.byte W90
	.byte W06
	.byte Gn3
	.byte W90
	.byte W06
	.byte N90
	.byte Fs3
	.byte W90
	.byte N96
	.byte Fn3
	.byte W96
	.byte GOTO
		.word track_72_lbl_2279a4

	.byte FINE

.align 2

track_72:
	.byte 4
	.byte 0
	.byte 130
	.byte 0
	.word voice_group22
	.word track_72_0
	.word track_72_1
	.word track_72_2
	.word track_72_3

.align 2
