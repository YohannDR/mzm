.align 2

.global track_16

track_16_0:
	.byte KEYSH, 0
	.byte TEMPO, 69
	.byte VOICE, 46
	.byte VOL, 75
	.byte PAN, c_v+15
	.byte TIE, As1, v092
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT @ As1, v092
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
	.byte W30
	.byte W60
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
	.byte W66
	.byte W12
	.byte N01 @ Ds6, v036
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
	.byte W18
	.byte W96
	.byte W96
	.byte W96
	.byte FINE

track_16_1:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 75
	.byte PAN, c_v-17
	.byte TIE, Ds1, v092
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT @ Ds1, v092
	.byte VOICE, 59
	.byte VOL, 18
	.byte PAN, c_v+20
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte FINE

track_16_2:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte VOICE, 22
	.byte VOL, 15
	.byte PAN, c_v
	.byte W48
	.byte N06, Fs5, v028
	.byte W48
	.byte N06 @ Fs5, v028
	.byte W48
track_16_lbl_22f447:
	.byte N06, Fs5, v028
	.byte W24
	.byte N06 @ Fs5, v028
	.byte W24
	.byte N06 @ Fs5, v028
	.byte W24
	.byte N06 @ Fs5, v028
	.byte W24
	.byte PEND
	.byte PATT
		.word track_16_lbl_22f447
	.byte PATT
		.word track_16_lbl_22f447
	.byte W96
	.byte W96
	.byte W96
	.byte FINE

track_16_3:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte VOICE, 0
	.byte VOL, 75
	.byte PAN, c_v
	.byte TIE, Cn2, v120
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT @ Cn2, v120
	.byte W48
	.byte W96
	.byte W96
	.byte FINE

track_16_4:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte VOICE, 14
	.byte VOL, 75
	.byte PAN, c_v-17
	.byte N96, Dn3, v100
	.byte W48
	.byte W84
	.byte N96 @ Dn3, v100
	.byte W12
	.byte W96
	.byte W60
	.byte N84 @ Dn3, v100
	.byte W36
	.byte W60
	.byte N84 @ Dn3, v100
	.byte W36
	.byte W96
	.byte W48
	.byte VOICE, 14
	.byte VOL, 80
	.byte PAN, c_v
	.byte N96 @ Dn3, v100
	.byte W48
	.byte W96
	.byte FINE

track_16_5:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte VOICE, 19
	.byte VOL, 37
	.byte PAN, c_v+15
	.byte N96, AsM1, v092
	.byte W48
	.byte W84
	.byte N96 @ AsM1, v092
	.byte W12
	.byte W96
	.byte W60
	.byte N84 @ AsM1, v092
	.byte W36
	.byte W60
	.byte N84 @ AsM1, v092
	.byte W36
	.byte W96
	.byte W48
	.byte VOICE, 19
	.byte VOL, 80
	.byte PAN, c_v
	.byte N96 @ AsM1, v092
	.byte W48
	.byte W96
	.byte FINE

track_16_6:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte VOICE, 74
	.byte VOL, 80
	.byte PAN, c_v-17
	.byte TIE, Dn2, v127
	.byte W24
	.byte W96
	.byte EOT @ Dn2, v127
	.byte W72
	.byte TIE, Cs2 @ v127
	.byte W24
	.byte W96
	.byte EOT @ Cs2, v127
	.byte W72
	.byte TIE, Fn2 @ v127
	.byte W24
	.byte W96
	.byte EOT @ Fn2, v127
	.byte W72
	.byte TIE, En2 @ v127
	.byte W24
	.byte W96
	.byte W24
	.byte EOT @ En2, v127
	.byte FINE

track_16_7:
	.byte KEYSH, 0
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte VOICE, 74
	.byte VOL, 80
	.byte PAN, c_v+15
	.byte TIE, Gn1, v127
	.byte W48
	.byte W72
	.byte EOT @ Gn1, v127
	.byte W24
	.byte W48
	.byte TIE @ Gn1, v127
	.byte W48
	.byte W72
	.byte EOT @ Gn1, v127
	.byte W24
	.byte W48
	.byte TIE @ Gn1, v127
	.byte W48
	.byte W72
	.byte EOT @ Gn1, v127
	.byte W24
	.byte W48
	.byte TIE @ Gn1, v127
	.byte W48
	.byte W72
	.byte EOT @ Gn1, v127
	.byte W24
	.byte FINE

.align 2

track_16:
	.byte 8
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_16_0
	.word track_16_1
	.word track_16_2
	.word track_16_3
	.word track_16_4
	.word track_16_5
	.word track_16_6
	.word track_16_7

.align 2
