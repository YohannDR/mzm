.align 2

.global track_20

track_20_0:
	.byte KEYSH, 0
	.byte TEMPO, 69
	.byte VOICE, 46
	.byte VOL, 75
	.byte PAN, c_v
	.byte TIE, As1, v092
	.byte W48
	.byte TIE, Fn2, v112
	.byte W48
	.byte TIE, As2, v116
	.byte W96
	.byte EOT, As1, v053
	.byte W24
	.byte As2 @ EOT, v053
	.byte VOICE, 59
	.byte VOL, 15
	.byte PAN, c_v-22
	.byte W42
	.byte N01, Gs6, v036
	.byte W06
	.byte Cn6 @ N01, v036
	.byte W06
	.byte Gn6 @ N01, v036
	.byte W06
	.byte As5 @ N01, v036
	.byte W06
	.byte En6 @ N01, v036
	.byte W06
	.byte Cn7 @ N01, v036
	.byte W06
	.byte Cs7 @ N01, v036
	.byte W06
	.byte Dn6 @ N01, v036
	.byte W06
	.byte Fs6 @ N01, v036
	.byte W06
	.byte Fn6 @ N01, v036
	.byte W06
	.byte An5 @ N01, v036
	.byte W06
	.byte Fn5 @ N01, v036
	.byte W06
	.byte As6 @ N01, v036
	.byte W54
	.byte W36
	.byte Ds6 @ N01, v036
	.byte W06
	.byte Dn6 @ N01, v036
	.byte W06
	.byte Gs6 @ N01, v036
	.byte W06
	.byte As5 @ N01, v036
	.byte W06
	.byte Dn6 @ N01, v036
	.byte W06
	.byte Gn6 @ N01, v036
	.byte W06
	.byte N01 @ Gn6, v036
	.byte W06
	.byte Dn7 @ N01, v036
	.byte W06
	.byte En6 @ N01, v036
	.byte W06
	.byte Gs6 @ N01, v036
	.byte W06
	.byte Cn6 @ N01, v036
	.byte W06
	.byte Ds6 @ N01, v036
	.byte W90
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte VOICE, 74
	.byte VOL, 80
	.byte PAN, c_v-17
	.byte TIE, Dn2, v100
	.byte W72
	.byte W48
	.byte EOT @ Dn2, v100
	.byte W48
	.byte W24
	.byte TIE, Cs2 @ v100
	.byte W72
	.byte W48
	.byte EOT @ Cs2, v100
	.byte W48
	.byte W24
	.byte TIE, Fn2 @ v100
	.byte W72
	.byte W48
	.byte EOT @ Fn2, v100
	.byte W48
	.byte W24
	.byte TIE, En2 @ v100
	.byte W72
	.byte W48
	.byte TEMPO, 40
	.byte W24
	.byte EOT @ En2, v100
	.byte W24
	.byte W48
track_20_lbl_22f9ae:
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte GOTO
		.word track_20_lbl_22f9ae
	.byte FINE

track_20_1:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 75
	.byte PAN, c_v
	.byte TIE, Ds1, v092
	.byte W48
	.byte TIE, As1, v112
	.byte W48
	.byte TIE, Ds2, v116
	.byte W96
	.byte EOT, Ds1, v046
	.byte W24
	.byte Ds2 @ EOT, v046
	.byte VOICE, 59
	.byte VOL, 18
	.byte PAN, c_v+20
	.byte W72
	.byte N01, Dn5, v040
	.byte W01
	.byte An4 @ N01, v040
	.byte W02
	.byte Gn5 @ N01, v040
	.byte W01
	.byte Cs5 @ N01, v040
	.byte W02
	.byte Ds5 @ N01, v040
	.byte W01
	.byte An4 @ N01, v040
	.byte W02
	.byte Fn4 @ N01, v040
	.byte W01
	.byte Dn5 @ N01, v040
	.byte W02
	.byte Gs4 @ N01, v040
	.byte W01
	.byte Cs5 @ N01, v040
	.byte W02
	.byte Gn4 @ N01, v040
	.byte W01
	.byte As4 @ N01, v040
	.byte W02
	.byte An4 @ N01, v040
	.byte W01
	.byte Fn5 @ N01, v040
	.byte W02
	.byte Ds5 @ N01, v040
	.byte W01
	.byte Cn5 @ N01, v040
	.byte W02
	.byte Gs4 @ N01, v040
	.byte W01
	.byte Gn5 @ N01, v040
	.byte W02
	.byte An4 @ N01, v040
	.byte W01
	.byte Fn4 @ N01, v040
	.byte W02
	.byte Ds5 @ N01, v040
	.byte W24
	.byte Fs4 @ N01, v040
	.byte W01
	.byte Gs4 @ N01, v040
	.byte W02
	.byte Gn4 @ N01, v040
	.byte W01
	.byte Cs4 @ N01, v040
	.byte W02
	.byte Ds4 @ N01, v040
	.byte W01
	.byte Fn4 @ N01, v040
	.byte W02
	.byte Dn4 @ N01, v040
	.byte W01
	.byte An4 @ N01, v040
	.byte W02
	.byte Ds4 @ N01, v040
	.byte N01, En4 @ v040
	.byte W01
	.byte Gs4 @ N01, v040
	.byte W02
	.byte Cn5 @ N01, v040
	.byte W01
	.byte Cn4 @ N01, v040
	.byte W02
	.byte Fs4 @ N01, v040
	.byte W01
	.byte An4 @ N01, v040
	.byte W02
	.byte Fs4 @ N01, v040
	.byte W01
	.byte Cn5 @ N01, v040
	.byte W02
	.byte Fn4 @ N01, v040
	.byte W01
	.byte Gn4 @ N01, v040
	.byte W02
	.byte Ds4 @ N01, v040
	.byte W01
	.byte Cs5 @ N01, v040
	.byte W14
	.byte W36
	.byte W01
	.byte Ds5 @ N01, v040
	.byte W02
	.byte Ds4 @ N01, v040
	.byte W01
	.byte An4 @ N01, v040
	.byte W02
	.byte Cs4 @ N01, v040
	.byte W01
	.byte Gn4 @ N01, v040
	.byte W02
	.byte Fn4 @ N01, v040
	.byte W01
	.byte Gn5 @ N01, v040
	.byte W02
	.byte Fs4 @ N01, v040
	.byte W01
	.byte Gn4 @ N01, v040
	.byte N01, An4 @ v040
	.byte W02
	.byte Cn4 @ N01, v040
	.byte N01, Dn4 @ v040
	.byte W01
	.byte Gs5 @ N01, v040
	.byte W02
	.byte Cs4 @ N01, v040
	.byte W01
	.byte Cs5 @ N01, v040
	.byte W02
	.byte Fs4 @ N01, v040
	.byte W24
	.byte W01
	.byte N01 @ Fs4, v040
	.byte W02
	.byte Bn4 @ N01, v040
	.byte W01
	.byte Cn4 @ N01, v040
	.byte W02
	.byte Gn4 @ N01, v040
	.byte W01
	.byte Ds5 @ N01, v040
	.byte W02
	.byte Gs4 @ N01, v040
	.byte W01
	.byte Gn3 @ N01, v040
	.byte W02
	.byte En5 @ N01, v040
	.byte N01, Fn5 @ v040
	.byte W01
	.byte Ds4 @ N01, v040
	.byte W02
	.byte As5 @ N01, v040
	.byte W01
	.byte En4 @ N01, v040
	.byte W02
	.byte Fs4 @ N01, v040
	.byte W01
	.byte Gs4 @ N01, v040
	.byte W02
	.byte Cn5 @ N01, v040
	.byte W01
	.byte Cn4 @ N01, v040
	.byte W02
	.byte Fs4 @ N01, v040
	.byte W01
	.byte En4 @ N01, v040
	.byte W02
	.byte Ds5 @ N01, v040
	.byte W01
	.byte Ds4 @ N01, v040
	.byte W02
	.byte Fn4 @ N01, v040
	.byte W01
	.byte Dn5 @ N01, v040
	.byte W02
	.byte En4 @ N01, v040
	.byte W54
	.byte Ds5 @ N01, v040
	.byte W01
	.byte N01 @ Ds5, v040
	.byte W02
	.byte Ds4 @ N01, v040
	.byte W01
	.byte Gn4 @ N01, v040
	.byte W02
	.byte Dn4 @ N01, v040
	.byte W01
	.byte Dn5 @ N01, v040
	.byte W02
	.byte Fs4 @ N01, v040
	.byte W01
	.byte Bn5 @ N01, v040
	.byte W02
	.byte Cs5 @ N01, v040
	.byte W01
	.byte Dn5 @ N01, v040
	.byte W02
	.byte Cn5 @ N01, v040
	.byte W01
	.byte Cn6 @ N01, v040
	.byte W02
	.byte Gn4 @ N01, v040
	.byte W01
	.byte Cs5 @ N01, v040
	.byte W02
	.byte Ds5 @ N01, v040
	.byte W01
	.byte Gs4 @ N01, v040
	.byte W02
	.byte Bn4 @ N01, v040
	.byte W01
	.byte Bn3 @ N01, v040
	.byte W02
	.byte Ds4 @ N01, v040
	.byte W01
	.byte As3 @ N01, v040
	.byte W02
	.byte Gs4 @ N01, v040
	.byte W01
	.byte Fn4 @ N01, v040
	.byte N01, Gn4 @ v040
	.byte W02
	.byte Dn5 @ N01, v040
	.byte W01
	.byte Fs4 @ N01, v040
	.byte W02
	.byte Fn5 @ N01, v040
	.byte W01
	.byte Gs4 @ N01, v040
	.byte W80
	.byte W03
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 74
	.byte VOL, 80
	.byte PAN, c_v+15
	.byte TIE, Gn1, v127
	.byte W96
	.byte W24
	.byte EOT @ Gn1, v127
	.byte W72
	.byte TIE @ Gn1, v127
	.byte W96
	.byte W24
	.byte EOT @ Gn1, v127
	.byte W72
	.byte TIE @ Gn1, v127
	.byte W96
	.byte W24
	.byte EOT @ Gn1, v127
	.byte W72
	.byte TIE @ Gn1, v127
	.byte W96
	.byte W24
	.byte EOT @ Gn1, v127
	.byte W72
	.byte W48
track_20_lbl_22fadf:
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte GOTO
		.word track_20_lbl_22fadf
	.byte FINE

track_20_2:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte VOICE, 67
	.byte VOL, 62
	.byte PAN, c_v
	.byte N92, Cn3, v127
	.byte W72
	.byte W24
	.byte N92 @ Cn3, v127
	.byte W72
	.byte W24
	.byte VOICE, 68
	.byte N92 @ Cn3, v127
	.byte W72
	.byte W24
	.byte N92 @ Cn3, v127
	.byte W72
	.byte W24
	.byte VOICE, 69
	.byte N92 @ Cn3, v127
	.byte W72
	.byte W24
	.byte N92 @ Cn3, v127
	.byte W72
	.byte W24
	.byte VOICE, 70
	.byte TIE @ Cn3, v127
	.byte W72
	.byte W72
	.byte EOT @ Cn3, v127
	.byte W24
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
track_20_lbl_22fb25:
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte GOTO
		.word track_20_lbl_22fb25
	.byte FINE

track_20_3:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W24
	.byte VOICE, 22
	.byte VOL, 15
	.byte PAN, c_v
	.byte W48
	.byte N06, Fs5, v028
	.byte W24
	.byte W24
	.byte N06 @ Fs5, v028
	.byte W48
	.byte N06 @ Fs5, v028
	.byte W24
	.byte N06 @ Fs5, v028
	.byte W24
	.byte N06 @ Fs5, v028
	.byte W24
	.byte N06 @ Fs5, v028
	.byte W48
	.byte W96
	.byte W96
	.byte W22
	.byte VOICE, 25
	.byte VOL, 80
	.byte PAN, c_v
	.byte N48, Cn3, v127
	.byte W72
	.byte W02
	.byte W22
	.byte N48 @ Cn3, v127
	.byte W72
	.byte W02
	.byte W22
	.byte N48 @ Cn3, v127
	.byte W72
	.byte W02
	.byte W22
	.byte N48 @ Cn3, v127
	.byte W72
	.byte W02
	.byte W22
	.byte N48 @ Cn3, v127
	.byte W72
	.byte W02
	.byte W24
	.byte N48 @ Cn3, v127
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
track_20_lbl_22fb7a:
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte GOTO
		.word track_20_lbl_22fb7a
	.byte FINE

track_20_4:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W24
	.byte VOICE, 14
	.byte VOL, 75
	.byte PAN, c_v-17
	.byte N96, Dn3, v100
	.byte W72
	.byte W60
	.byte N96 @ Dn3, v100
	.byte W36
	.byte W96
	.byte W36
	.byte N84 @ Dn3, v100
	.byte W60
	.byte W24
	.byte VOICE, 23
	.byte VOL, 69
	.byte PAN, c_v
	.byte N12, Cn2, v080
	.byte W12
	.byte N06, Cs2, v084
	.byte W12
	.byte Gn2, v088 @ N06
	.byte W12
	.byte Fs2, v092 @ N06
	.byte W12
	.byte N12, Cs2 @ v092
	.byte W12
	.byte N06, Dn2, v096
	.byte W12
	.byte Gs2, v100 @ N06
	.byte W12
	.byte Gn2, v104 @ N06
	.byte W12
	.byte N12, Dn2, v108
	.byte W12
	.byte N06, Ds2 @ v108
	.byte W12
	.byte An2, v112 @ N06
	.byte W12
	.byte Gs2, v116 @ N06
	.byte W12
	.byte N12, Ds2, v120
	.byte W12
	.byte N06, En2 @ v120
	.byte W12
	.byte As2, v124 @ N06
	.byte W12
	.byte An2, v127 @ N06
	.byte W12
	.byte N12, Fn2, v080
	.byte W12
	.byte N06, Fs2, v084
	.byte W12
	.byte Cn3, v088 @ N06
	.byte W12
	.byte Bn2, v092 @ N06
	.byte W12
	.byte N12, Fs2 @ v092
	.byte W12
	.byte N06, Gn2, v096
	.byte W12
	.byte Cs3, v100 @ N06
	.byte W12
	.byte Cn3, v104 @ N06
	.byte W12
	.byte N12, Gn2, v108
	.byte W12
	.byte N06, Gs2 @ v108
	.byte W12
	.byte Dn3, v112 @ N06
	.byte W12
	.byte Cs3, v116 @ N06
	.byte W12
	.byte N12, Gs2, v120
	.byte W12
	.byte N06, An2 @ v120
	.byte W12
	.byte Ds3, v124 @ N06
	.byte W12
	.byte Dn3, v127 @ N06
	.byte W12
	.byte N12, As2, v080
	.byte W12
	.byte N06, Bn2, v084
	.byte W12
	.byte Fn3, v088 @ N06
	.byte W12
	.byte En3, v092 @ N06
	.byte W12
	.byte N12, As2 @ v092
	.byte W12
	.byte N06, Bn2, v096
	.byte W12
	.byte Fn3, v100 @ N06
	.byte W12
	.byte En3, v104 @ N06
	.byte W12
	.byte N12, As2, v108
	.byte W12
	.byte N06, Bn2 @ v108
	.byte W12
	.byte Fn3, v112 @ N06
	.byte W12
	.byte En3, v116 @ N06
	.byte W12
	.byte N12, As2, v120
	.byte W12
	.byte N06, Bn2 @ v120
	.byte W12
	.byte Fn3, v124 @ N06
	.byte W12
	.byte En3, v127 @ N06
	.byte W84
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
track_20_lbl_22fc4f:
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte GOTO
		.word track_20_lbl_22fc4f
	.byte FINE

track_20_5:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W24
	.byte VOICE, 19
	.byte VOL, 37
	.byte PAN, c_v+15
	.byte N96, AsM1, v092
	.byte W72
	.byte W60
	.byte N96 @ AsM1, v092
	.byte W36
	.byte W96
	.byte W36
	.byte N84 @ AsM1, v092
	.byte W60
	.byte W24
	.byte VOICE, 13
	.byte VOL, 50
	.byte PAN, c_v+20
	.byte N36, An4, v072
	.byte W48
	.byte N42, As4, v080
	.byte W24
	.byte W24
	.byte N36, An4 @ v080
	.byte W48
	.byte N42, Gs4, v072
	.byte W24
	.byte W24
	.byte N36 @ Gs4, v072
	.byte W48
	.byte N42, An4, v080
	.byte W24
	.byte W24
	.byte N36, Gs4 @ v080
	.byte W48
	.byte N42, Gn4, v072
	.byte W24
	.byte W24
	.byte TIE, As4, v104
	.byte W72
	.byte W96
	.byte W24
	.byte EOT @ As4, v104
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
track_20_lbl_22fcad:
	.byte N96, Gn2, v104
	.byte W48
	.byte W44
	.byte Gs2, v096 @ N96
	.byte W52
	.byte W48
	.byte Gn2, v104 @ N96
	.byte W48
	.byte W48
	.byte Fs2 @ N96, v104
	.byte W48
	.byte W48
	.byte TIE, Gn2 @ v104
	.byte W48
	.byte W96
	.byte W48
	.byte EOT @ Gn2, v104
	.byte W48
	.byte W96
	.byte W48
	.byte GOTO
		.word track_20_lbl_22fcad
	.byte FINE

track_20_6:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W24
	.byte VOICE, 0
	.byte VOL, 75
	.byte PAN, c_v
	.byte TIE, Cn2, v120
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte EOT @ Cn2, v120
	.byte VOICE, 13
	.byte VOL, 56
	.byte PAN, c_v-22
	.byte N36, Fs4, v072
	.byte W48
	.byte N42, Gn4, v080
	.byte W24
	.byte W24
	.byte N36, Fs4 @ v080
	.byte W48
	.byte N42, Fn4, v072
	.byte W24
	.byte W24
	.byte N36 @ Fn4, v072
	.byte W48
	.byte N42, Fs4, v080
	.byte W24
	.byte W24
	.byte N36, Fn4 @ v080
	.byte W48
	.byte N42, En4, v072
	.byte W24
	.byte W24
	.byte TIE, Gn4, v092
	.byte W72
	.byte W96
	.byte W24
	.byte EOT @ Gn4, v092
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
track_20_lbl_22fd18:
	.byte VOICE, 71
	.byte VOL, 18
	.byte N96, Gn4, v104
	.byte W48
	.byte W44
	.byte Gs4, v096 @ N96
	.byte W52
	.byte W48
	.byte Gn4, v104 @ N96
	.byte W48
	.byte W48
	.byte Fs4 @ N96, v104
	.byte W48
	.byte W48
	.byte TIE, Gn4 @ v104
	.byte W48
	.byte W96
	.byte W48
	.byte EOT @ Gn4, v104
	.byte W48
	.byte W96
	.byte W48
	.byte GOTO
		.word track_20_lbl_22fd18
	.byte FINE

track_20_7:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
track_20_lbl_22fd54:
	.byte VOICE, 72
	.byte VOL, 56
	.byte PAN, c_v
	.byte N72, En3, v060
	.byte N72, Gn3 @ v060
	.byte N72, Cn4 @ v060
	.byte W48
	.byte W48
	.byte Ds3, v072 @ N72
	.byte N72, Gs3 @ v072
	.byte N72, Cn4 @ v072
	.byte W48
	.byte W48
	.byte En3 @ N72, v072
	.byte N72, Gn3 @ v072
	.byte N72, Cn4 @ v072
	.byte W48
	.byte W48
	.byte Ds3, v060 @ N72
	.byte N72, Fs3 @ v060
	.byte N72, Cn4 @ v060
	.byte W48
	.byte W48
	.byte En3 @ N72, v060
	.byte N72, Gn3 @ v060
	.byte N72, Cn4 @ v060
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte GOTO
		.word track_20_lbl_22fd54
	.byte FINE

track_20_8:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 27
	.byte VOL, 62
	.byte PAN, c_v
	.byte W48
track_20_lbl_22fda9:
	.byte N24, Cn2, v080
	.byte W48
	.byte N30, Cn2, v096
	.byte W48
	.byte N28, Cn2, v100
	.byte W48
	.byte Cn2, v108 @ N28
	.byte W48
	.byte N30, Cn2, v080
	.byte W48
	.byte N32, Cn2, v088
	.byte W48
	.byte N30, Cn2, v092
	.byte W48
	.byte N24, Cn2, v096
	.byte W48
	.byte Cn2, v104 @ N24
	.byte W48
	.byte Cn2, v108 @ N24
	.byte W48
	.byte Cn2, v080 @ N24
	.byte W48
	.byte Cn2, v088 @ N24
	.byte W48
	.byte N28, Cn2, v092
	.byte W48
	.byte Cn2, v096 @ N28
	.byte W48
	.byte N30, Cn2, v104
	.byte W48
	.byte Cn2, v108 @ N30
	.byte W48
	.byte GOTO
		.word track_20_lbl_22fda9
	.byte FINE

.align 2

track_20:
	.byte 9
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_20_0
	.word track_20_1
	.word track_20_2
	.word track_20_3
	.word track_20_4
	.word track_20_5
	.word track_20_6
	.word track_20_7
	.word track_20_8

.align 2
