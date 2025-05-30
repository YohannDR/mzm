.align 2

.global track_27

track_27_0:
	.byte KEYSH, 0
	.byte TEMPO, 63
	.byte VOICE, 78
	.byte VOL, 80
	.byte PAN, c_v+20
	.byte N90, An2, v092
	.byte W96
	.byte Cn3, v112 @ N90
	.byte W96
	.byte Bn2 @ N90, v112
	.byte W96
	.byte As2, v100 @ N90
	.byte W96
	.byte An2, v092 @ N90
	.byte W96
	.byte Cn3, v112 @ N90
	.byte W96
	.byte Bn2 @ N90, v112
	.byte W96
	.byte As2, v100 @ N90
	.byte W96
	.byte An2 @ N90, v100
	.byte W96
	.byte N90 @ An2, v100
	.byte W96
	.byte VOICE, 89
	.byte VOL, 37
	.byte PAN, c_v+10
	.byte N06, Fs3, v092
	.byte W06
	.byte An3, v084 @ N06
	.byte W06
	.byte Dn4, v076 @ N06
	.byte W06
	.byte Fs4, v068 @ N06
	.byte W06
	.byte N19, An4, v060
	.byte W24
	.byte VOICE, 88
	.byte N24, Gn4 @ v060
	.byte W24
	.byte N20, Fs4, v072
	.byte W24
	.byte N72, Dn4, v080
	.byte W96
track_27_lbl_230a11:
	.byte VOICE, 89
	.byte N42, Bn3, v100
	.byte W48
	.byte N18, An3, v092
	.byte W24
	.byte N06, Gn4, v060
	.byte W06
	.byte Fs4, v072 @ N06
	.byte W06
	.byte Dn4, v080 @ N06
	.byte W06
	.byte An3, v092 @ N06
	.byte W06
	.byte PEND
track_27_lbl_230a29:
	.byte N48, Gn3, v092
	.byte W48
	.byte VOICE, 88
	.byte N42, Dn4, v100
	.byte W48
	.byte PEND
	.byte VOICE, 89
	.byte N06, Fs3, v092
	.byte W06
	.byte An3, v084 @ N06
	.byte W06
	.byte Dn4, v076 @ N06
	.byte W06
	.byte Fs4, v068 @ N06
	.byte W06
	.byte N19, An4, v060
	.byte W24
	.byte VOICE, 88
	.byte N24, Gn4 @ v060
	.byte W24
	.byte N20, Fs4, v072
	.byte W24
	.byte N72, Dn4, v080
	.byte W96
	.byte PATT
		.word track_27_lbl_230a11
	.byte PATT
		.word track_27_lbl_230a29
	.byte N42, Cs4, v080
	.byte W48
	.byte N24, Dn4, v092
	.byte W24
	.byte N18, An3 @ v092
	.byte W24
track_27_lbl_230a69:
	.byte N18, Fs4, v092
	.byte W24
	.byte En4, v080 @ N18
	.byte W24
	.byte Gn4, v100 @ N18
	.byte W24
	.byte Fs4, v092 @ N18
	.byte W24
	.byte PEND
track_27_lbl_230a77:
	.byte VOICE, 89
	.byte N12, En4, v108
	.byte W12
	.byte Dn4, v104 @ N12
	.byte W12
	.byte As3, v100 @ N12
	.byte W12
	.byte Gn3, v096 @ N12
	.byte W12
	.byte N18, Fs3, v092
	.byte W24
	.byte Dn4, v100 @ N18
	.byte W24
	.byte PEND
track_27_lbl_230a8e:
	.byte N12, Gs3, v092
	.byte W12
	.byte Bn3 @ N12, v092
	.byte W12
	.byte N24, En4, v096
	.byte W24
	.byte Dn4, v100 @ N24
	.byte W24
	.byte N18, En4, v104
	.byte W24
	.byte PEND
	.byte VOICE, 88
	.byte N48, Cs4, v080
	.byte W48
	.byte N24, Dn4, v092
	.byte W24
	.byte An3 @ N24, v092
	.byte W24
	.byte PATT
		.word track_27_lbl_230a69
	.byte PATT
		.word track_27_lbl_230a77
	.byte PATT
		.word track_27_lbl_230a8e
	.byte VOICE, 79
	.byte VOL, 44
	.byte N18, Fs3, v072
	.byte W24
	.byte An3, v084 @ N18
	.byte W24
	.byte Dn4, v092 @ N18
	.byte W24
	.byte An3, v072 @ N18
	.byte W24
track_27_lbl_230acc:
	.byte N18, Gn3, v072
	.byte W24
	.byte An3, v084 @ N18
	.byte W24
	.byte Dn4, v092 @ N18
	.byte W24
	.byte Gn3, v072 @ N18
	.byte W24
	.byte PEND
	.byte Fs3 @ N18, v072
	.byte W24
	.byte An3, v084 @ N18
	.byte W24
	.byte Dn4, v092 @ N18
	.byte W24
	.byte An3, v072 @ N18
	.byte W24
	.byte PATT
		.word track_27_lbl_230acc
	.byte N18, Fs3, v084
	.byte W24
	.byte An3, v092 @ N18
	.byte W24
	.byte Dn4, v100 @ N18
	.byte W24
	.byte An3, v084 @ N18
	.byte W24
	.byte Gn3 @ N18, v084
	.byte W24
	.byte An3, v092 @ N18
	.byte W24
	.byte Dn4, v100 @ N18
	.byte W24
	.byte Gn3, v084 @ N18
	.byte W24
	.byte Fs3, v092 @ N18
	.byte W24
	.byte An3, v100 @ N18
	.byte W24
	.byte Dn4, v108 @ N18
	.byte W24
	.byte An3, v092 @ N18
	.byte W24
	.byte Gn3 @ N18, v092
	.byte W24
	.byte An3, v100 @ N18
	.byte W24
	.byte Dn4, v108 @ N18
	.byte W24
	.byte Gn3, v092 @ N18
	.byte W24
	.byte VOICE, 49
	.byte VOL, 31
	.byte N12, An5, v076
	.byte W24
	.byte Gn5 @ N12, v076
	.byte W24
	.byte Fs5 @ N12, v076
	.byte W24
	.byte En5 @ N12, v076
	.byte W24
track_27_lbl_230b27:
	.byte N12, Gn5, v068
	.byte W24
	.byte Fs5, v064 @ N12
	.byte W24
	.byte Dn5 @ N12, v064
	.byte W24
	.byte En5 @ N12, v064
	.byte W24
	.byte PEND
	.byte An5, v076 @ N12
	.byte W24
	.byte Gn5 @ N12, v076
	.byte W24
	.byte Fs5 @ N12, v076
	.byte W24
	.byte En5, v064 @ N12
	.byte W24
	.byte PATT
		.word track_27_lbl_230b27
	.byte VOL, 31
	.byte N12, An5, v056
	.byte W24
	.byte Gn5 @ N12, v056
	.byte W24
	.byte Fs5 @ N12, v056
	.byte W24
	.byte En5 @ N12, v056
	.byte W24
track_27_lbl_230b4e:
	.byte N12, Gn5, v048
	.byte W24
	.byte Fs5 @ N12, v048
	.byte W24
	.byte Dn5 @ N12, v048
	.byte W24
	.byte En5 @ N12, v048
	.byte W24
	.byte PEND
track_27_lbl_230b59:
	.byte N12, An5, v048
	.byte W24
	.byte Gn5 @ N12, v048
	.byte W24
	.byte Fs5, v044 @ N12
	.byte W24
	.byte En5 @ N12, v044
	.byte W24
	.byte PEND
track_27_lbl_230b65:
	.byte N12, Gn5, v040
	.byte W24
	.byte Fs5 @ N12, v040
	.byte W24
	.byte Dn5 @ N12, v040
	.byte W24
	.byte En5 @ N12, v040
	.byte W24
	.byte PEND
	.byte PATT
		.word track_27_lbl_230b59
	.byte PATT
		.word track_27_lbl_230b65
	.byte N12, An5, v068
	.byte W24
	.byte Gn5, v064 @ N12
	.byte W24
	.byte Fs5 @ N12, v064
	.byte W24
	.byte En5 @ N12, v064
	.byte W24
track_27_lbl_230b85:
	.byte N12, Gn5, v056
	.byte W24
	.byte Fs5 @ N12, v056
	.byte W24
	.byte Dn5 @ N12, v056
	.byte W24
	.byte En5 @ N12, v056
	.byte W24
	.byte PEND
	.byte VOICE, 49
	.byte VOL, 31
	.byte N12, An5, v068
	.byte W24
	.byte Gn5, v064 @ N12
	.byte W24
	.byte Fs5 @ N12, v064
	.byte W24
	.byte En5 @ N12, v064
	.byte W24
	.byte PATT
		.word track_27_lbl_230b85
	.byte N12, An5, v056
	.byte W24
	.byte Gn5 @ N12, v056
	.byte W24
	.byte Fs5 @ N12, v056
	.byte W24
	.byte En5 @ N12, v056
	.byte W24
	.byte PATT
		.word track_27_lbl_230b4e
	.byte PATT
		.word track_27_lbl_230b59
	.byte PATT
		.word track_27_lbl_230b65
	.byte PATT
		.word track_27_lbl_230b59
	.byte PATT
		.word track_27_lbl_230b65
	.byte VOICE, 51
	.byte VOL, 62
	.byte N84, An3, v112
	.byte W96
	.byte N42, Dn4, v120
	.byte W48
	.byte N32, Cs4, v116
	.byte W36
	.byte N10, Bn3, v112
	.byte W12
	.byte N84, An3 @ v112
	.byte W96
	.byte N42, Dn3, v120
	.byte W48
	.byte N32, Gn3 @ v120
	.byte W36
	.byte N10, Fs3, v116
	.byte W12
	.byte N84, An3, v112
	.byte W96
	.byte N42, Dn4 @ v112
	.byte W48
	.byte N32, Cs4, v120
	.byte W36
	.byte N10, Bn3, v116
	.byte W12
	.byte N90, An3, v112
	.byte W96
	.byte N42, Dn3, v127
	.byte W48
	.byte N32, Gn3 @ v127
	.byte W36
	.byte N10, Fs3 @ v127
	.byte W12
	.byte VOICE, 79
	.byte VOL, 62
	.byte N03, An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W24
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W12
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W12
track_27_lbl_230c22:
	.byte N03, Fn3, v120
	.byte W06
	.byte N03 @ Fn3, v120
	.byte W06
	.byte N03 @ Fn3, v120
	.byte W24
	.byte N03 @ Fn3, v120
	.byte W06
	.byte N03 @ Fn3, v120
	.byte W06
	.byte Gn3 @ N03, v120
	.byte W12
	.byte N03 @ Gn3, v120
	.byte W06
	.byte N03 @ Gn3, v120
	.byte W06
	.byte N03 @ Gn3, v120
	.byte W06
	.byte N03 @ Gn3, v120
	.byte W06
	.byte N03 @ Gn3, v120
	.byte W12
	.byte PEND
track_27_lbl_230c3b:
	.byte N03, An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W24
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W12
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W06
	.byte N03 @ An3, v120
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_230c22
	.byte PATT
		.word track_27_lbl_230c3b
	.byte PATT
		.word track_27_lbl_230c22
	.byte PATT
		.word track_27_lbl_230c3b
	.byte PATT
		.word track_27_lbl_230c3b
	.byte N72, An3, v120
	.byte W96
	.byte W12
	.byte N06, Dn3, v100
	.byte W12
	.byte N03 @ Dn3, v100
	.byte W06
	.byte N04 @ Dn3, v100
	.byte W06
	.byte N07 @ Dn3, v100
	.byte W60
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_230c80:
	.byte VOICE, 78
	.byte VOL, 80
	.byte PAN, c_v+20
	.byte N90, An2, v092
	.byte W72
	.byte W24
	.byte Cn3, v112 @ N90
	.byte W72
	.byte W24
	.byte Bn2 @ N90, v112
	.byte W72
	.byte W24
	.byte As2, v100 @ N90
	.byte W72
	.byte W24
	.byte TIE, An2, v092
	.byte W72
	.byte W66
	.byte EOT @ An2, v092
	.byte W30
	.byte W96
	.byte W96
	.byte W24
	.byte GOTO
		.word track_27_lbl_230c80
	.byte FINE

track_27_1:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 80
	.byte PAN, c_v-22
	.byte N90, En2, v092
	.byte W96
	.byte An2, v112 @ N90
	.byte W96
	.byte Gs2 @ N90, v112
	.byte W96
	.byte Gn2, v100 @ N90
	.byte W96
	.byte En2, v092 @ N90
	.byte W96
	.byte An2, v112 @ N90
	.byte W96
	.byte Gs2 @ N90, v112
	.byte W96
	.byte Gn2, v100 @ N90
	.byte W96
	.byte En2 @ N90, v100
	.byte W96
	.byte N90 @ En2, v100
	.byte W96
	.byte VOICE, 89
	.byte VOL, 37
	.byte PAN, c_v-10
	.byte N06, Dn3 @ v100
	.byte W06
	.byte Fs3, v076 @ N06
	.byte W06
	.byte An3, v080 @ N06
	.byte W06
	.byte Dn4, v084 @ N06
	.byte W06
	.byte N19, Fs4 @ v084
	.byte W24
	.byte VOICE, 88
	.byte N24, En4, v088
	.byte W24
	.byte N20, Dn4, v080
	.byte W24
	.byte N72, An3, v072
	.byte W96
track_27_lbl_230cec:
	.byte VOICE, 89
	.byte N06, En3, v072
	.byte W06
	.byte Fs3, v076 @ N06
	.byte W06
	.byte Gn3, v080 @ N06
	.byte W06
	.byte An3, v084 @ N06
	.byte W06
	.byte N24, Dn4 @ v084
	.byte W24
	.byte Dn3, v064 @ N24
	.byte W24
	.byte N06, En4, v052
	.byte W06
	.byte Dn4, v056 @ N06
	.byte W06
	.byte An3, v064 @ N06
	.byte W06
	.byte Fs3, v072 @ N06
	.byte W06
	.byte PEND
	.byte VOICE, 88
	.byte N42, En3 @ v072
	.byte W48
	.byte Bn3, v080 @ N42
	.byte W48
	.byte VOICE, 89
	.byte N06, Dn3, v072
	.byte W06
	.byte Fs3, v076 @ N06
	.byte W06
	.byte An3, v080 @ N06
	.byte W06
	.byte Dn4, v084 @ N06
	.byte W06
	.byte N19, Fs4 @ v084
	.byte W24
	.byte VOICE, 88
	.byte N24, En4, v088
	.byte W24
	.byte N20, Dn4, v080
	.byte W24
	.byte N72, An3, v072
	.byte W96
	.byte PATT
		.word track_27_lbl_230cec
	.byte N42, En3, v072
	.byte W48
	.byte Bn3, v080 @ N42
	.byte W48
	.byte VOL, 44
	.byte N48, En3 @ v080
	.byte W48
	.byte N18, Fs3, v092
	.byte W24
	.byte Dn3, v080 @ N18
	.byte W24
	.byte VOICE, 88
	.byte N18, Dn3, v092
	.byte W24
	.byte Cn3, v080 @ N18
	.byte W24
	.byte En3, v100 @ N18
	.byte W24
	.byte Dn3, v080 @ N18
	.byte W24
	.byte VOICE, 89
	.byte N18, As3, v088
	.byte W24
	.byte Gn3, v080 @ N18
	.byte W24
	.byte Dn3, v072 @ N18
	.byte W24
	.byte An3 @ N18, v072
	.byte W24
	.byte N12, Fn3 @ v072
	.byte W12
	.byte Gs3, v080 @ N12
	.byte W12
	.byte N18, Bn3, v092
	.byte W24
	.byte Gn3, v072 @ N18
	.byte W24
	.byte N18 @ Gn3, v072
	.byte W24
	.byte N48, En3, v080
	.byte W48
	.byte N18, Fs3, v092
	.byte W24
	.byte Dn3, v072 @ N18
	.byte W24
	.byte Dn3, v088 @ N18
	.byte W24
	.byte Cn3, v080 @ N18
	.byte W24
	.byte En3, v072 @ N18
	.byte W24
	.byte Dn3 @ N18, v072
	.byte W24
	.byte As3, v088 @ N18
	.byte W24
	.byte Gn3, v080 @ N18
	.byte W24
	.byte Dn3, v072 @ N18
	.byte W24
	.byte An3 @ N18, v072
	.byte W24
	.byte N12, Fn3, v080
	.byte W12
	.byte Gs3, v088 @ N12
	.byte W12
	.byte N18, Bn3, v092
	.byte W24
	.byte Gn3, v072 @ N18
	.byte W24
	.byte N18 @ Gn3, v072
	.byte W24
	.byte VOICE, 46
	.byte VOL, 50
	.byte N42, An2, v096
	.byte W48
	.byte Cn3, v112 @ N42
	.byte W48
	.byte Bn2 @ N42, v112
	.byte W48
	.byte As2, v100 @ N42
	.byte W48
	.byte An2, v108 @ N42
	.byte W48
	.byte Cn3, v120 @ N42
	.byte W48
	.byte Bn2 @ N42, v120
	.byte W48
	.byte As2, v112 @ N42
	.byte W48
track_27_lbl_230dc7:
	.byte N42, An2, v116
	.byte W48
	.byte Cn3, v127 @ N42
	.byte W48
	.byte PEND
track_27_lbl_230dcf:
	.byte N42, Bn2, v127
	.byte W48
	.byte As2, v120 @ N42
	.byte W48
	.byte PEND
	.byte PATT
		.word track_27_lbl_230dc7
	.byte PATT
		.word track_27_lbl_230dcf
	.byte VOICE, 81
	.byte VOL, 25
	.byte N90, Dn3, v112
	.byte W96
	.byte N42, En3, v120
	.byte W48
	.byte Gn3 @ N42, v120
	.byte W48
	.byte N90, Fs3, v112
	.byte W96
	.byte N42, Gn3, v120
	.byte W48
	.byte As3 @ N42, v120
	.byte W48
	.byte N32, Dn3, v112
	.byte W36
	.byte VOICE, 81
	.byte VOL, 69
	.byte N12, An2, v096
	.byte W12
	.byte N84, Dn2, v092
	.byte W48
	.byte W48
	.byte N36, Gn2, v112
	.byte W36
	.byte N12, Fs2, v092
	.byte W12
	.byte VOICE, 80
	.byte N16, Dn1, v072
	.byte W16
	.byte An1, v076 @ N16
	.byte W16
	.byte Dn2, v084 @ N16
	.byte W16
	.byte Fs2, v088 @ N16
	.byte W16
	.byte An2, v096 @ N16
	.byte W16
	.byte Dn3, v100 @ N16
	.byte W16
	.byte VOICE, 81
	.byte N36, En3, v092
	.byte W36
	.byte N12, As2, v084
	.byte W12
	.byte N48, Gn2, v080
	.byte W48
	.byte N84, An2, v072
	.byte W96
	.byte VOICE, 80
	.byte N16, Gn2, v112
	.byte W16
	.byte Fs2, v104 @ N16
	.byte W16
	.byte Dn2, v100 @ N16
	.byte W16
	.byte En2, v092 @ N16
	.byte W16
	.byte Dn2, v088 @ N16
	.byte W16
	.byte En2, v080 @ N16
	.byte W16
	.byte VOICE, 81
	.byte N84, Dn2 @ v080
	.byte W96
	.byte VOICE, 80
	.byte N16, Gn2, v072
	.byte W16
	.byte As2, v080 @ N16
	.byte W16
	.byte Dn3, v088 @ N16
	.byte W16
	.byte Gn3, v096 @ N16
	.byte W16
	.byte As3, v104 @ N16
	.byte W16
	.byte Dn4, v112 @ N16
	.byte W16
	.byte VOICE, 80
	.byte VOL, 37
	.byte N03, Fs3, v080
	.byte W06
	.byte An3, v084 @ N03
	.byte W06
	.byte Fs3 @ N03, v084
	.byte W06
	.byte An3 @ N03, v084
	.byte W06
	.byte An3, v088 @ N03
	.byte W06
	.byte Bn3 @ N03, v088
	.byte W06
	.byte An3 @ N03, v088
	.byte W06
	.byte Bn3, v092 @ N03
	.byte W06
	.byte Dn4 @ N03, v092
	.byte W06
	.byte En4 @ N03, v092
	.byte W06
	.byte Dn4, v096 @ N03
	.byte W06
	.byte En4 @ N03, v096
	.byte W06
	.byte N03 @ En4, v096
	.byte W06
	.byte Fs4, v100 @ N03
	.byte W06
	.byte En4 @ N03, v100
	.byte W06
	.byte Fs4 @ N03, v100
	.byte W06
track_27_lbl_230e93:
	.byte N03, Fs3, v080
	.byte W06
	.byte An3, v084 @ N03
	.byte W06
	.byte Fs3 @ N03, v084
	.byte W06
	.byte An3 @ N03, v084
	.byte W06
	.byte An3, v088 @ N03
	.byte W06
	.byte Bn3 @ N03, v088
	.byte W06
	.byte An3 @ N03, v088
	.byte W06
	.byte Bn3, v092 @ N03
	.byte W06
	.byte Dn4 @ N03, v092
	.byte W06
	.byte En4 @ N03, v092
	.byte W06
	.byte Dn4, v096 @ N03
	.byte W06
	.byte En4 @ N03, v096
	.byte W06
	.byte N03 @ En4, v096
	.byte W06
	.byte Fs4, v100 @ N03
	.byte W06
	.byte En4 @ N03, v100
	.byte W06
	.byte Fs4 @ N03, v100
	.byte W06
	.byte PEND
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
	.byte PATT
		.word track_27_lbl_230e93
track_27_lbl_230ef7:
	.byte N03, Fs3, v080
	.byte W06
	.byte An3, v084 @ N03
	.byte W06
	.byte Fs3, v088 @ N03
	.byte W06
	.byte An3 @ N03, v088
	.byte W06
	.byte An3, v092 @ N03
	.byte W06
	.byte Bn3, v096 @ N03
	.byte W06
	.byte An3 @ N03, v096
	.byte W06
	.byte Bn3, v100 @ N03
	.byte W06
	.byte Dn4, v104 @ N03
	.byte W06
	.byte En4 @ N03, v104
	.byte W06
	.byte Dn4, v108 @ N03
	.byte W06
	.byte En4, v112 @ N03
	.byte W06
	.byte N03 @ En4, v112
	.byte W06
	.byte Fs4, v116 @ N03
	.byte W06
	.byte En4, v120 @ N03
	.byte W06
	.byte Fs4 @ N03, v120
	.byte W06
	.byte PEND
	.byte PATT
		.word track_27_lbl_230ef7
	.byte VOICE, 47
	.byte VOL, 75
	.byte N92, An2, v127
	.byte W96
	.byte N16, As1, v100
	.byte W16
	.byte Fn2, v104 @ N16
	.byte W16
	.byte As2, v108 @ N16
	.byte W16
	.byte Dn2, v116 @ N16
	.byte W16
	.byte Gn2, v120 @ N16
	.byte W16
	.byte Cn3, v124 @ N16
	.byte W16
	.byte N92, Dn3, v127
	.byte W96
	.byte N16, Fn3, v092
	.byte W16
	.byte Cn3, v104 @ N16
	.byte W16
	.byte Gn2, v108 @ N16
	.byte W16
	.byte Gn3, v092 @ N16
	.byte W16
	.byte En3, v120 @ N16
	.byte W16
	.byte Cn3, v092 @ N16
	.byte W16
	.byte N92, Dn3, v127
	.byte W96
	.byte N24, Dn2, v100
	.byte W24
	.byte An2, v108 @ N24
	.byte W24
	.byte Gn2, v120 @ N24
	.byte W24
	.byte Cn3, v127 @ N24
	.byte W24
track_27_lbl_230f6c:
	.byte N03, En3, v127
	.byte W06
	.byte N03 @ En3, v127
	.byte W06
	.byte N03 @ En3, v127
	.byte W24
	.byte N03 @ En3, v127
	.byte W06
	.byte N03 @ En3, v127
	.byte W06
	.byte N03 @ En3, v127
	.byte W12
	.byte N03 @ En3, v127
	.byte W06
	.byte N03 @ En3, v127
	.byte W06
	.byte N03 @ En3, v127
	.byte W06
	.byte N03 @ En3, v127
	.byte W06
	.byte N03 @ En3, v127
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_230f6c
	.byte N72, En3, v092
	.byte W96
	.byte W12
	.byte N05, Fs2, v100
	.byte W12
	.byte N03 @ Fs2, v100
	.byte W06
	.byte N03 @ Fs2, v100
	.byte W06
	.byte N06 @ Fs2, v100
	.byte W60
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_230f9d:
	.byte VOICE, 46
	.byte VOL, 80
	.byte PAN, c_v-22
	.byte N90, En2, v092
	.byte W72
	.byte W24
	.byte An2, v112 @ N90
	.byte W72
	.byte W24
	.byte Gs2 @ N90, v112
	.byte W72
	.byte W24
	.byte Gn2, v100 @ N90
	.byte W72
	.byte W24
	.byte TIE, En2, v092
	.byte W72
	.byte W66
	.byte EOT @ En2, v092
	.byte W30
	.byte W96
	.byte W96
	.byte W24
	.byte GOTO
		.word track_27_lbl_230f9d
	.byte FINE

track_27_2:
	.byte KEYSH, 0
	.byte VOICE, 28
	.byte VOL, 69
	.byte PAN, c_v
	.byte N54, En2, v112
	.byte W96
	.byte An2, v060 @ N54
	.byte W96
	.byte Gs2 @ N54, v060
	.byte W96
	.byte Gn2 @ N54, v060
	.byte W96
	.byte En2, v112 @ N54
	.byte W96
	.byte An2, v060 @ N54
	.byte W96
	.byte Gs2 @ N54, v060
	.byte W96
	.byte Gn2 @ N54, v060
	.byte W96
	.byte En2, v100 @ N54
	.byte W96
	.byte En2, v112 @ N54
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
	.byte VOICE, 87
	.byte VOL, 69
	.byte PAN, c_v-17
	.byte N24, Fs5, v036
	.byte W24
	.byte PAN, c_v+15
	.byte N24, An5, v040
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6 @ v040
	.byte W24
	.byte PAN, c_v+10
	.byte N24, An5, v044
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Gn5 @ v044
	.byte W24
	.byte PAN, c_v+15
	.byte N24, An5, v048
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6 @ v048
	.byte W24
	.byte PAN, c_v+10
	.byte N24, Gn5 @ v048
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Fs5, v052
	.byte W24
	.byte PAN, c_v+15
	.byte N24, An5 @ v052
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6, v056
	.byte W24
	.byte PAN, c_v+10
	.byte N24, An5 @ v056
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Gn5 @ v056
	.byte W24
	.byte PAN, c_v+15
	.byte N24, An5, v060
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6 @ v060
	.byte W24
	.byte PAN, c_v+10
	.byte N24, Gn5, v064
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Fs5 @ v064
	.byte W24
	.byte PAN, c_v+15
	.byte N24, An5, v068
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6 @ v068
	.byte W24
	.byte PAN, c_v+10
	.byte N24, An5 @ v068
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Gn5, v072
	.byte W24
	.byte PAN, c_v+15
	.byte N24, An5 @ v072
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6, v076
	.byte W24
	.byte PAN, c_v+10
	.byte N24, Gn5 @ v076
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Fs5 @ v076
	.byte W24
	.byte PAN, c_v+15
	.byte N24, An5, v080
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6 @ v080
	.byte W24
	.byte PAN, c_v+10
	.byte N24, An5, v084
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Gn5 @ v084
	.byte W24
	.byte PAN, c_v+15
	.byte N24, An5, v088
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6 @ v088
	.byte W24
	.byte PAN, c_v+10
	.byte N24, Gn5 @ v088
	.byte W24
	.byte VOICE, 87
	.byte VOL, 44
	.byte PAN, c_v-17
	.byte N24, An6, v080
	.byte W24
	.byte PAN, c_v+15
	.byte N24, Gn6, v084
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Fs6, v088
	.byte W24
	.byte PAN, c_v+10
	.byte N24, En6 @ v088
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Gn6, v092
	.byte W24
	.byte PAN, c_v+15
	.byte N24, Fs6 @ v092
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6, v096
	.byte W24
	.byte PAN, c_v+10
	.byte N24, En6, v100
	.byte W24
	.byte PAN, c_v-17
	.byte N24, An6 @ v100
	.byte W24
	.byte PAN, c_v+15
	.byte N24, Gn6, v104
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Fs6, v108
	.byte W24
	.byte PAN, c_v+10
	.byte N24, En6 @ v108
	.byte W24
	.byte PAN, c_v-17
	.byte N24, Gn6, v112
	.byte W24
	.byte PAN, c_v+15
	.byte N24, Fs6 @ v112
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6, v116
	.byte W24
	.byte PAN, c_v+10
	.byte N24, En6, v120
	.byte W24
track_27_lbl_231107:
	.byte PAN, c_v-17
	.byte N24, An6, v127
	.byte W24
	.byte PAN, c_v+15
	.byte N24, Gn6, v120
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Fs6, v112
	.byte W24
	.byte PAN, c_v+10
	.byte N24, En6, v100
	.byte W24
	.byte PEND
track_27_lbl_231120:
	.byte PAN, c_v-17
	.byte N24, Gn6, v127
	.byte W24
	.byte PAN, c_v+15
	.byte N24, Fs6, v120
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6, v112
	.byte W24
	.byte PAN, c_v+10
	.byte N24, En6, v120
	.byte W24
	.byte PEND
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte VOICE, 87
	.byte VOL, 37
	.byte PAN, c_v-17
	.byte N24, An6, v127
	.byte W24
	.byte PAN, c_v+15
	.byte N24, Gn6, v120
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Fs6, v112
	.byte W24
	.byte PAN, c_v+10
	.byte N24, En6, v100
	.byte W24
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PATT
		.word track_27_lbl_231120
	.byte PATT
		.word track_27_lbl_231107
	.byte PAN, c_v-17
	.byte N24, Gn6, v127
	.byte W24
	.byte PAN, c_v+15
	.byte N24, Fs6, v120
	.byte W24
	.byte PAN, c_v-10
	.byte N24, Dn6, v112
	.byte W48
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
	.byte W24
track_27_lbl_2311d9:
	.byte VOICE, 28
	.byte VOL, 69
	.byte PAN, c_v
	.byte N54, En2, v112
	.byte W72
	.byte W24
	.byte An2, v060 @ N54
	.byte W72
	.byte W24
	.byte Gs2 @ N54, v060
	.byte W72
	.byte W24
	.byte Gn2 @ N54, v060
	.byte W72
	.byte W24
	.byte TIE, En2, v112
	.byte W72
	.byte W54
	.byte EOT @ En2, v112
	.byte W42
	.byte W96
	.byte W96
	.byte W24
	.byte GOTO
		.word track_27_lbl_2311d9
	.byte FINE

track_27_3:
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
	.byte VOICE, 95
	.byte VOL, 69
	.byte PAN, c_v
	.byte N44, Cs3, v112
	.byte W48
	.byte Dn3 @ N44, v112
	.byte W48
	.byte En3 @ N44, v112
	.byte W48
	.byte Dn3 @ N44, v112
	.byte W48
	.byte N44 @ Dn3, v112
	.byte W48
	.byte N42, Fs3, v100
	.byte W48
	.byte N44, Fn3, v120
	.byte W48
	.byte N42, En3, v100
	.byte W48
	.byte N44, Cs3, v112
	.byte W48
	.byte Dn3 @ N44, v112
	.byte W48
	.byte En3 @ N44, v112
	.byte W48
	.byte Dn3 @ N44, v112
	.byte W48
	.byte Fn3, v100 @ N44
	.byte W48
	.byte N36, Fs3, v112
	.byte W48
	.byte N44, Fn3 @ v112
	.byte W48
	.byte N36, En3, v100
	.byte W48
	.byte VOICE, 95
	.byte VOL, 50
	.byte PAN, c_v+20
	.byte N92, An3 @ v100
	.byte W96
	.byte N84, Gn3, v092
	.byte W96
	.byte N92, An3, v100
	.byte W96
	.byte N84, Gn3, v092
	.byte W96
	.byte N92, An3, v112
	.byte W96
	.byte N84, Gn3, v100
	.byte W96
	.byte N92, An3, v120
	.byte W96
	.byte N84, Gn3, v112
	.byte W96
	.byte VOICE, 72
	.byte VOL, 50
	.byte N96, Fs4, v032
	.byte W96
	.byte N48, Bn4 @ v032
	.byte W48
	.byte Cs5 @ N48, v032
	.byte W48
	.byte N96, Fs4 @ v032
	.byte W96
	.byte N48, Gn4 @ v032
	.byte W48
	.byte N48 @ Gn4, v032
	.byte W48
	.byte N96, Fs4, v052
	.byte W96
	.byte W03
	.byte N48, En4, v064
	.byte W44
	.byte W01
	.byte Cs4, v068 @ N48
	.byte W48
	.byte N96, Fs4, v076
	.byte W96
	.byte N48, Bn3, v088
	.byte W48
	.byte As3, v096 @ N48
	.byte W48
	.byte N96, Dn4, v100
	.byte W96
	.byte W03
	.byte N48, En4 @ v100
	.byte W44
	.byte W01
	.byte Cs4 @ N48, v100
	.byte W48
	.byte N96, Dn4 @ v100
	.byte W96
	.byte N48, As3, v080
	.byte W48
	.byte As3, v100 @ N48
	.byte W48
	.byte VOICE, 95
	.byte VOL, 56
	.byte N96, Dn4 @ v100
	.byte W96
track_27_lbl_2312b6:
	.byte W03
	.byte N48, En4, v084
	.byte W44
	.byte W01
	.byte Cs4, v100 @ N48
	.byte W48
	.byte PEND
	.byte N96, Dn4 @ v100
	.byte W96
track_27_lbl_2312c3:
	.byte N48, Bn3, v080
	.byte W48
	.byte As3, v100 @ N48
	.byte W48
	.byte PEND
	.byte N96, Dn4 @ v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2312b6
	.byte N96, Dn4, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2312c3
	.byte VOL, 56
	.byte N96, Dn4, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2312b6
	.byte N96, Dn4, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2312c3
	.byte N96, Dn4, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2312b6
	.byte N96, Dn4, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2312c3
	.byte N96, Dn4, v120
	.byte W96
track_27_lbl_231306:
	.byte N48, Dn4, v100
	.byte W48
	.byte En4, v120 @ N48
	.byte W48
	.byte PEND
	.byte N92, Dn4 @ v120
	.byte W96
	.byte PATT
		.word track_27_lbl_231306
	.byte N92, Dn4, v120
	.byte W96
	.byte N48, Dn4, v100
	.byte W48
	.byte En4, v092 @ N48
	.byte W48
	.byte N92, En4, v096
	.byte W96
	.byte N96 @ En4, v096
	.byte W96
	.byte N72, En4, v052
	.byte W96
	.byte W12
	.byte N06, Fs4 @ v052
	.byte W12
	.byte N03 @ Fs4, v052
	.byte W06
	.byte N04 @ Fs4, v052
	.byte W06
	.byte N07 @ Fs4, v052
	.byte W60
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_231339:
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte GOTO
		.word track_27_lbl_231339
	.byte FINE

track_27_4:
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
	.byte VOICE, 51
	.byte VOL, 69
	.byte PAN, c_v
	.byte N36, Fs3, v092
	.byte W48
	.byte N42, En3 @ v092
	.byte W48
	.byte N44, Dn3 @ v092
	.byte W48
	.byte Cs3 @ N44, v092
	.byte W48
track_27_lbl_231366:
	.byte N36, Bn2, v112
	.byte W48
	.byte N44, An2, v100
	.byte W48
	.byte PEND
	.byte Gn2, v112 @ N44
	.byte W48
	.byte N48, An2, v100
	.byte W48
	.byte N36, Fs3, v112
	.byte W48
	.byte N42, En3 @ v112
	.byte W48
	.byte N44, Dn3, v100
	.byte W48
	.byte Cs3, v092 @ N44
	.byte W48
	.byte PATT
		.word track_27_lbl_231366
	.byte N36, Gn2, v112
	.byte W48
	.byte N48, An2, v100
	.byte W48
	.byte VOL, 69
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 95
	.byte VOL, 50
	.byte PAN, c_v-22
	.byte N92, Dn3 @ v100
	.byte W96
	.byte N84, Dn3, v092
	.byte W96
	.byte N92, Dn3, v100
	.byte W96
	.byte N84, Dn3, v092
	.byte W96
	.byte N92, Dn3, v112
	.byte W96
	.byte N84, Dn3, v100
	.byte W96
	.byte N92, Dn3, v120
	.byte W96
	.byte N84, Dn3, v112
	.byte W96
	.byte VOICE, 72
	.byte VOL, 50
	.byte N96, Dn4, v032
	.byte W96
	.byte N48, En4 @ v032
	.byte W48
	.byte An4 @ N48, v032
	.byte W48
	.byte N96, Dn4 @ v032
	.byte W96
	.byte N48, Bn3 @ v032
	.byte W48
	.byte As3 @ N48, v032
	.byte W48
	.byte N96, Dn4, v052
	.byte W96
	.byte N48, Gn3, v064
	.byte W48
	.byte An3, v068 @ N48
	.byte W48
	.byte N96, Dn4, v076
	.byte W96
	.byte N48, Gn3, v088
	.byte W48
	.byte Gn3, v096 @ N48
	.byte W48
	.byte N96, Fs3, v100
	.byte W96
	.byte N48, Gn3 @ v100
	.byte W48
	.byte An3 @ N48, v100
	.byte W48
	.byte N96, Fs3 @ v100
	.byte W96
track_27_lbl_2313f7:
	.byte N48, Gn3, v080
	.byte W48
	.byte Gn3, v100 @ N48
	.byte W48
	.byte PEND
	.byte VOICE, 95
	.byte VOL, 56
	.byte N96, Fs3 @ v100
	.byte W96
track_27_lbl_231406:
	.byte N48, Gn3, v080
	.byte W48
	.byte An3, v100 @ N48
	.byte W48
	.byte PEND
	.byte N96, Fs3 @ v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2313f7
	.byte N96, Fs3, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_231406
	.byte N96, Fs3, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2313f7
	.byte VOL, 56
	.byte N96, Fs3, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_231406
	.byte N96, Fs3, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2313f7
	.byte N96, Fs3, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_231406
	.byte N96, Fs3, v100
	.byte W96
	.byte PATT
		.word track_27_lbl_2313f7
	.byte N96, Fs3, v120
	.byte W96
track_27_lbl_231452:
	.byte N48, As3, v100
	.byte W48
	.byte Cn4, v120 @ N48
	.byte W48
	.byte PEND
	.byte N92, Fs3 @ v120
	.byte W96
	.byte PATT
		.word track_27_lbl_231452
	.byte N92, Fs3, v120
	.byte W96
	.byte N48, As3, v100
	.byte W48
	.byte Cn4, v092 @ N48
	.byte W48
	.byte N92, An3, v096
	.byte W96
	.byte N96 @ An3, v096
	.byte W96
	.byte N72, An3, v052
	.byte W96
	.byte W12
	.byte N05, Bn3 @ v052
	.byte W12
	.byte N03 @ Bn3, v052
	.byte W06
	.byte N03 @ Bn3, v052
	.byte W06
	.byte N06 @ Bn3, v052
	.byte W60
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_231485:
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte GOTO
		.word track_27_lbl_231485
	.byte FINE

track_27_5:
	.byte KEYSH, 0
	.byte VOICE, 84
	.byte VOL, 80
	.byte PAN, c_v
	.byte N04, An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W24
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W12
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W12
track_27_lbl_2314b4:
	.byte N04, An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W24
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W12
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_2314b4
	.byte PATT
		.word track_27_lbl_2314b4
	.byte PATT
		.word track_27_lbl_2314b4
	.byte PATT
		.word track_27_lbl_2314b4
	.byte PATT
		.word track_27_lbl_2314b4
	.byte PATT
		.word track_27_lbl_2314b4
	.byte PATT
		.word track_27_lbl_2314b4
	.byte PATT
		.word track_27_lbl_2314b4
	.byte VOICE, 100
	.byte VOL, 80
	.byte N12, Dn2, v127
	.byte W24
	.byte Dn2, v124 @ N12
	.byte W24
	.byte Cs2 @ N12, v124
	.byte W24
	.byte Cs2, v120 @ N12
	.byte W24
track_27_lbl_231505:
	.byte N12, Bn1, v120
	.byte W24
	.byte Bn1, v116 @ N12
	.byte W24
	.byte An1, v112 @ N12
	.byte W24
	.byte N12 @ An1, v112
	.byte W24
	.byte PEND
track_27_lbl_231512:
	.byte N12, Gn1, v112
	.byte W24
	.byte N12 @ Gn1, v112
	.byte W24
	.byte Fs1, v116 @ N12
	.byte W24
	.byte Fs1, v120 @ N12
	.byte W24
	.byte PEND
track_27_lbl_23151f:
	.byte N12, En1, v120
	.byte W24
	.byte En1, v124 @ N12
	.byte W24
	.byte An1 @ N12, v124
	.byte W24
	.byte An1, v127 @ N12
	.byte W24
	.byte PEND
	.byte Dn2 @ N12, v127
	.byte W24
	.byte Dn2, v124 @ N12
	.byte W24
	.byte Cs2 @ N12, v124
	.byte W24
	.byte Cs2, v120 @ N12
	.byte W24
	.byte PATT
		.word track_27_lbl_231505
	.byte PATT
		.word track_27_lbl_231512
	.byte PATT
		.word track_27_lbl_23151f
	.byte PATT
		.word track_27_lbl_231512
track_27_lbl_23154a:
	.byte N12, Cn2, v120
	.byte W24
	.byte Cn2, v124 @ N12
	.byte W24
	.byte Bn1 @ N12, v124
	.byte W24
	.byte Bn1, v127 @ N12
	.byte W24
	.byte PEND
	.byte As1 @ N12, v127
	.byte W24
	.byte As1, v124 @ N12
	.byte W24
	.byte An1 @ N12, v124
	.byte W24
	.byte An1, v120 @ N12
	.byte W24
	.byte Gs1 @ N12, v120
	.byte W24
	.byte Gs1, v116 @ N12
	.byte W24
	.byte An1, v112 @ N12
	.byte W24
	.byte N12 @ An1, v112
	.byte W24
	.byte PATT
		.word track_27_lbl_231512
	.byte PATT
		.word track_27_lbl_23154a
	.byte N12, As1, v127
	.byte W24
	.byte N12 @ As1, v127
	.byte W24
	.byte An1 @ N12, v127
	.byte W24
	.byte N12 @ An1, v127
	.byte W24
	.byte Gs1 @ N12, v127
	.byte W24
	.byte N12 @ Gs1, v127
	.byte W24
	.byte An1 @ N12, v127
	.byte W24
	.byte N12 @ An1, v127
	.byte W24
	.byte VOICE, 84
	.byte VOL, 80
	.byte N04, Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W24
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W12
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W12
track_27_lbl_2315a3:
	.byte N04, Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W24
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W12
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W06
	.byte N04 @ Dn1, v100
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_2315a3
	.byte PATT
		.word track_27_lbl_2315a3
	.byte PATT
		.word track_27_lbl_2315a3
	.byte PATT
		.word track_27_lbl_2315a3
	.byte PATT
		.word track_27_lbl_2315a3
	.byte PATT
		.word track_27_lbl_2315a3
	.byte VOICE, 86
	.byte VOL, 44
	.byte N03, Dn4, v052
	.byte W06
	.byte N03 @ Dn4, v052
	.byte W06
	.byte An4 @ N03, v052
	.byte W06
	.byte N03 @ An4, v052
	.byte W06
	.byte Dn5 @ N03, v052
	.byte W06
	.byte N03 @ Dn5, v052
	.byte W06
	.byte An4 @ N03, v052
	.byte W06
	.byte N03 @ An4, v052
	.byte W06
	.byte Dn4 @ N03, v052
	.byte W06
	.byte N03 @ Dn4, v052
	.byte W06
	.byte An4 @ N03, v052
	.byte W06
	.byte N03 @ An4, v052
	.byte W06
	.byte Dn5 @ N03, v052
	.byte W06
	.byte N03 @ Dn5, v052
	.byte W06
	.byte An4 @ N03, v052
	.byte W06
	.byte N03 @ An4, v052
	.byte W06
	.byte Dn4 @ N03, v052
	.byte W06
	.byte N03 @ Dn4, v052
	.byte W06
	.byte An4 @ N03, v052
	.byte W06
	.byte N03 @ An4, v052
	.byte W06
	.byte Dn5, v056 @ N03
	.byte W06
	.byte N03 @ Dn5, v056
	.byte W06
	.byte An4 @ N03, v056
	.byte W06
	.byte N03 @ An4, v056
	.byte W06
	.byte Dn4 @ N03, v056
	.byte W06
	.byte N03 @ Dn4, v056
	.byte W06
	.byte An4 @ N03, v056
	.byte W06
	.byte N03 @ An4, v056
	.byte W06
	.byte Dn5 @ N03, v056
	.byte W06
	.byte N03 @ Dn5, v056
	.byte W06
	.byte An4 @ N03, v056
	.byte W06
	.byte N03 @ An4, v056
	.byte W06
	.byte Dn4 @ N03, v056
	.byte W06
	.byte N03 @ Dn4, v056
	.byte W06
	.byte An4 @ N03, v056
	.byte W06
	.byte N03 @ An4, v056
	.byte W06
	.byte Dn5 @ N03, v056
	.byte W06
	.byte N03 @ Dn5, v056
	.byte W06
	.byte An4 @ N03, v056
	.byte W06
	.byte N03 @ An4, v056
	.byte W06
	.byte Dn4 @ N03, v056
	.byte W06
	.byte N03 @ Dn4, v056
	.byte W06
	.byte An4 @ N03, v056
	.byte W06
	.byte N03 @ An4, v056
	.byte W06
	.byte Dn5 @ N03, v056
	.byte W06
	.byte Dn5, v060 @ N03
	.byte W06
	.byte An4 @ N03, v060
	.byte W06
	.byte N03 @ An4, v060
	.byte W06
	.byte Dn4 @ N03, v060
	.byte W06
	.byte N03 @ Dn4, v060
	.byte W06
	.byte An4 @ N03, v060
	.byte W06
	.byte N03 @ An4, v060
	.byte W06
	.byte Dn5 @ N03, v060
	.byte W06
	.byte N03 @ Dn5, v060
	.byte W06
	.byte An4 @ N03, v060
	.byte W06
	.byte N03 @ An4, v060
	.byte W06
	.byte Dn4 @ N03, v060
	.byte W06
	.byte N03 @ Dn4, v060
	.byte W06
	.byte An4 @ N03, v060
	.byte W06
	.byte N03 @ An4, v060
	.byte W06
	.byte Dn5 @ N03, v060
	.byte W06
	.byte N03 @ Dn5, v060
	.byte W06
	.byte An4 @ N03, v060
	.byte W06
	.byte N03 @ An4, v060
	.byte W06
	.byte VOL, 44
	.byte N03, Dn4, v064
	.byte W06
	.byte N03 @ Dn4, v064
	.byte W06
	.byte An4 @ N03, v064
	.byte W06
	.byte N03 @ An4, v064
	.byte W06
	.byte Dn5 @ N03, v064
	.byte W06
	.byte N03 @ Dn5, v064
	.byte W06
	.byte An4 @ N03, v064
	.byte W06
	.byte N03 @ An4, v064
	.byte W06
	.byte Dn4 @ N03, v064
	.byte W06
	.byte N03 @ Dn4, v064
	.byte W06
	.byte An4 @ N03, v064
	.byte W06
	.byte N03 @ An4, v064
	.byte W06
	.byte Dn5 @ N03, v064
	.byte W06
	.byte N03 @ Dn5, v064
	.byte W06
	.byte An4 @ N03, v064
	.byte W06
	.byte N03 @ An4, v064
	.byte W06
	.byte Dn4 @ N03, v064
	.byte W06
	.byte N03 @ Dn4, v064
	.byte W06
	.byte An4 @ N03, v064
	.byte W06
	.byte N03 @ An4, v064
	.byte W06
	.byte Dn5 @ N03, v064
	.byte W06
	.byte N03 @ Dn5, v064
	.byte W06
	.byte An4 @ N03, v064
	.byte W06
	.byte N03 @ An4, v064
	.byte W06
	.byte Dn4 @ N03, v064
	.byte W06
	.byte N03 @ Dn4, v064
	.byte W06
	.byte An4 @ N03, v064
	.byte W06
	.byte N03 @ An4, v064
	.byte W06
	.byte Dn5, v068 @ N03
	.byte W06
	.byte N03 @ Dn5, v068
	.byte W06
	.byte An4 @ N03, v068
	.byte W06
	.byte N03 @ An4, v068
	.byte W06
	.byte Dn4 @ N03, v068
	.byte W06
	.byte N03 @ Dn4, v068
	.byte W06
	.byte An4 @ N03, v068
	.byte W06
	.byte N03 @ An4, v068
	.byte W06
	.byte Dn5 @ N03, v068
	.byte W06
	.byte N03 @ Dn5, v068
	.byte W06
	.byte An4 @ N03, v068
	.byte W06
	.byte N03 @ An4, v068
	.byte W06
	.byte Dn4 @ N03, v068
	.byte W06
	.byte N03 @ Dn4, v068
	.byte W06
	.byte An4 @ N03, v068
	.byte W06
	.byte N03 @ An4, v068
	.byte W06
	.byte Dn5 @ N03, v068
	.byte W06
	.byte N03 @ Dn5, v068
	.byte W06
	.byte An4 @ N03, v068
	.byte W06
	.byte N03 @ An4, v068
	.byte W06
	.byte Dn4 @ N03, v068
	.byte W06
	.byte N03 @ Dn4, v068
	.byte W06
	.byte An4 @ N03, v068
	.byte W06
	.byte N03 @ An4, v068
	.byte W06
	.byte Dn5 @ N03, v068
	.byte W06
	.byte N03 @ Dn5, v068
	.byte W06
	.byte An4 @ N03, v068
	.byte W06
	.byte N03 @ An4, v068
	.byte W06
	.byte Dn4, v072 @ N03
	.byte W06
	.byte N03 @ Dn4, v072
	.byte W06
	.byte An4 @ N03, v072
	.byte W06
	.byte N03 @ An4, v072
	.byte W06
	.byte Dn5 @ N03, v072
	.byte W06
	.byte N03 @ Dn5, v072
	.byte W06
	.byte An4 @ N03, v072
	.byte W06
	.byte N03 @ An4, v072
	.byte W06
	.byte Dn4 @ N03, v072
	.byte W06
	.byte N03 @ Dn4, v072
	.byte W06
	.byte An4 @ N03, v072
	.byte W06
	.byte N03 @ An4, v072
	.byte W06
	.byte Dn5 @ N03, v072
	.byte W06
	.byte N03 @ Dn5, v072
	.byte W06
	.byte An4 @ N03, v072
	.byte W06
	.byte N03 @ An4, v072
	.byte W06
	.byte Dn4 @ N03, v072
	.byte W06
	.byte N03 @ Dn4, v072
	.byte W06
	.byte An4 @ N03, v072
	.byte W06
	.byte N03 @ An4, v072
	.byte W06
	.byte Dn5 @ N03, v072
	.byte W06
	.byte N03 @ Dn5, v072
	.byte W06
	.byte An4 @ N03, v072
	.byte W06
	.byte N03 @ An4, v072
	.byte W06
	.byte Dn4 @ N03, v072
	.byte W06
	.byte N03 @ Dn4, v072
	.byte W06
	.byte An4 @ N03, v072
	.byte W06
	.byte N03 @ An4, v072
	.byte W06
	.byte Dn5, v076 @ N03
	.byte W06
	.byte N03 @ Dn5, v076
	.byte W06
	.byte An4 @ N03, v076
	.byte W06
	.byte N03 @ An4, v076
	.byte W06
	.byte Dn4 @ N03, v076
	.byte W06
	.byte N03 @ Dn4, v076
	.byte W06
	.byte An4 @ N03, v076
	.byte W06
	.byte N03 @ An4, v076
	.byte W06
	.byte Dn5 @ N03, v076
	.byte W06
	.byte N03 @ Dn5, v076
	.byte W06
	.byte An4 @ N03, v076
	.byte W06
	.byte N03 @ An4, v076
	.byte W06
	.byte Dn4 @ N03, v076
	.byte W06
	.byte N03 @ Dn4, v076
	.byte W06
	.byte An4 @ N03, v076
	.byte W06
	.byte N03 @ An4, v076
	.byte W06
	.byte Dn5 @ N03, v076
	.byte W06
	.byte N03 @ Dn5, v076
	.byte W06
	.byte An4 @ N03, v076
	.byte W06
	.byte N03 @ An4, v076
	.byte W06
	.byte Dn4 @ N03, v076
	.byte W06
	.byte N03 @ Dn4, v076
	.byte W06
	.byte An4 @ N03, v076
	.byte W06
	.byte N03 @ An4, v076
	.byte W06
	.byte Dn5 @ N03, v076
	.byte W06
	.byte N03 @ Dn5, v076
	.byte W06
	.byte An4 @ N03, v076
	.byte W06
	.byte N03 @ An4, v076
	.byte W06
	.byte Dn4, v080 @ N03
	.byte W06
	.byte N03 @ Dn4, v080
	.byte W06
	.byte An4 @ N03, v080
	.byte W06
	.byte N03 @ An4, v080
	.byte W06
	.byte Dn5 @ N03, v080
	.byte W06
	.byte N03 @ Dn5, v080
	.byte W06
	.byte An4 @ N03, v080
	.byte W06
	.byte N03 @ An4, v080
	.byte W06
	.byte Dn4 @ N03, v080
	.byte W06
	.byte N03 @ Dn4, v080
	.byte W06
	.byte An4 @ N03, v080
	.byte W06
	.byte N03 @ An4, v080
	.byte W06
	.byte Dn5 @ N03, v080
	.byte W06
	.byte N03 @ Dn5, v080
	.byte W06
	.byte An4 @ N03, v080
	.byte W06
	.byte N03 @ An4, v080
	.byte W06
	.byte VOICE, 101
	.byte VOL, 80
	.byte N12, Dn1, v127
	.byte W12
	.byte N12 @ Dn1, v127
	.byte W12
	.byte N12 @ Dn1, v127
	.byte W12
	.byte N12 @ Dn1, v127
	.byte W24
	.byte Fs1 @ N12, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
track_27_lbl_23177e:
	.byte N12, En1, v127
	.byte W12
	.byte N12 @ En1, v127
	.byte W12
	.byte N12 @ En1, v127
	.byte W12
	.byte N12 @ En1, v127
	.byte W12
	.byte An1 @ N12, v127
	.byte W12
	.byte N12 @ An1, v127
	.byte W12
	.byte N12 @ An1, v127
	.byte W12
	.byte N12 @ An1, v127
	.byte W12
	.byte PEND
track_27_lbl_231791:
	.byte W12
	.byte N12, Fs1, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte PEND
track_27_lbl_2317a3:
	.byte N16, Gn1, v127
	.byte W16
	.byte Dn1 @ N16, v127
	.byte W16
	.byte En1 @ N16, v127
	.byte W16
	.byte As1 @ N16, v127
	.byte W16
	.byte An1 @ N16, v127
	.byte W16
	.byte Gn1 @ N16, v127
	.byte W16
	.byte PEND
track_27_lbl_2317b2:
	.byte N12, Dn1, v127
	.byte W12
	.byte N12 @ Dn1, v127
	.byte W12
	.byte N12 @ Dn1, v127
	.byte W12
	.byte N12 @ Dn1, v127
	.byte W24
	.byte Fs1 @ N12, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte N12 @ Fs1, v127
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_23177e
	.byte PATT
		.word track_27_lbl_231791
	.byte PATT
		.word track_27_lbl_2317a3
	.byte PATT
		.word track_27_lbl_2317b2
	.byte PATT
		.word track_27_lbl_23177e
	.byte PATT
		.word track_27_lbl_231791
	.byte PATT
		.word track_27_lbl_2317a3
	.byte PATT
		.word track_27_lbl_2317b2
	.byte PATT
		.word track_27_lbl_23177e
	.byte PATT
		.word track_27_lbl_231791
	.byte PATT
		.word track_27_lbl_2317a3
track_27_lbl_2317fa:
	.byte N04, Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W24
	.byte N04 @ Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W12
	.byte N04 @ Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W12
	.byte PEND
track_27_lbl_231813:
	.byte N04, As0, v127
	.byte W06
	.byte N04 @ As0, v127
	.byte W06
	.byte N04 @ As0, v127
	.byte W24
	.byte N04 @ As0, v127
	.byte W06
	.byte N04 @ As0, v127
	.byte W06
	.byte Cn1 @ N04, v127
	.byte W12
	.byte N04 @ Cn1, v127
	.byte W06
	.byte N04 @ Cn1, v127
	.byte W06
	.byte N04 @ Cn1, v127
	.byte W06
	.byte N04 @ Cn1, v127
	.byte W06
	.byte N04 @ Cn1, v127
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_2317fa
	.byte PATT
		.word track_27_lbl_231813
	.byte PATT
		.word track_27_lbl_2317fa
	.byte PATT
		.word track_27_lbl_231813
	.byte PATT
		.word track_27_lbl_2317fa
	.byte PATT
		.word track_27_lbl_2317fa
	.byte N72, Dn1, v100
	.byte W96
	.byte W12
	.byte N06, Dn1, v127
	.byte W12
	.byte N03 @ Dn1, v127
	.byte W06
	.byte N04 @ Dn1, v127
	.byte W06
	.byte N07 @ Dn1, v127
	.byte W60
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_23185d:
	.byte VOICE, 84
	.byte VOL, 80
	.byte N04, An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W24
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W12
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
track_27_lbl_231873:
	.byte N04, An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W12
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W24
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W12
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte PEND
	.byte PATT
		.word track_27_lbl_231873
	.byte PATT
		.word track_27_lbl_231873
	.byte PATT
		.word track_27_lbl_231873
	.byte PATT
		.word track_27_lbl_231873
	.byte PATT
		.word track_27_lbl_231873
	.byte PATT
		.word track_27_lbl_231873
	.byte N04, An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W06
	.byte N04 @ An0, v127
	.byte W12
	.byte GOTO
		.word track_27_lbl_23185d
	.byte FINE

track_27_6:
	.byte KEYSH, 0
	.byte VOICE, 83
	.byte VOL, 69
	.byte N06, Dn3, v080
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W24
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
	.byte Dn3, v080 @ N06
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
track_27_lbl_2318d9:
	.byte N06, Dn3, v080
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W24
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
	.byte Dn3, v080 @ N06
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_2318d9
	.byte PATT
		.word track_27_lbl_2318d9
	.byte PATT
		.word track_27_lbl_2318d9
	.byte PATT
		.word track_27_lbl_2318d9
	.byte PATT
		.word track_27_lbl_2318d9
	.byte PATT
		.word track_27_lbl_2318d9
	.byte PATT
		.word track_27_lbl_2318d9
	.byte PATT
		.word track_27_lbl_2318d9
track_27_lbl_23191d:
	.byte VOICE, 92
	.byte N48, Gn2, v080
	.byte W48
	.byte N48 @ Gn2, v080
	.byte W48
	.byte PEND
track_27_lbl_231926:
	.byte N48, Gn2, v080
	.byte W48
	.byte N48 @ Gn2, v080
	.byte W48
	.byte PEND
track_27_lbl_23192d:
	.byte N48, Gn2, v080
	.byte W24
	.byte VOICE, 92
	.byte W24
	.byte N48 @ Gn2, v080
	.byte W24
	.byte VOICE, 92
	.byte W24
	.byte PEND
track_27_lbl_23193a:
	.byte N48, Gn2, v080
	.byte W24
	.byte VOICE, 92
	.byte W24
	.byte N48 @ Gn2, v080
	.byte W48
	.byte PEND
	.byte PATT
		.word track_27_lbl_23191d
	.byte PATT
		.word track_27_lbl_231926
	.byte PATT
		.word track_27_lbl_23192d
	.byte PATT
		.word track_27_lbl_23193a
	.byte PATT
		.word track_27_lbl_23191d
	.byte PATT
		.word track_27_lbl_23191d
	.byte PATT
		.word track_27_lbl_23192d
	.byte PATT
		.word track_27_lbl_23191d
	.byte PATT
		.word track_27_lbl_23191d
	.byte PATT
		.word track_27_lbl_231926
	.byte PATT
		.word track_27_lbl_23192d
	.byte PATT
		.word track_27_lbl_23193a
	.byte VOICE, 83
	.byte VOL, 69
	.byte N12, Bn2, v100
	.byte W12
	.byte VOICE, 83
	.byte N06, Cn3, v040
	.byte W06
	.byte N06 @ Cn3, v040
	.byte W06
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W06
	.byte Cn3, v044 @ N06
	.byte W54
	.byte VOICE, 83
	.byte N12, Bn2, v100
	.byte W12
	.byte VOICE, 83
	.byte N06, Cn3, v044
	.byte W06
	.byte Cn3, v048 @ N06
	.byte W06
	.byte N06 @ Cn3, v048
	.byte W12
	.byte N06 @ Cn3, v048
	.byte W06
	.byte N06 @ Cn3, v048
	.byte W54
	.byte VOICE, 83
	.byte N12, Bn2, v100
	.byte W12
	.byte VOICE, 83
	.byte N06, Cn3, v052
	.byte W06
	.byte N06 @ Cn3, v052
	.byte W06
	.byte N06 @ Cn3, v052
	.byte W12
	.byte N06 @ Cn3, v052
	.byte W06
	.byte N06 @ Cn3, v052
	.byte W54
	.byte VOICE, 83
	.byte N12, Bn2, v100
	.byte W12
	.byte VOICE, 83
	.byte N06, Cn3, v056
	.byte W06
	.byte N06 @ Cn3, v056
	.byte W06
	.byte N06 @ Cn3, v056
	.byte W12
	.byte N06 @ Cn3, v056
	.byte W06
	.byte N06 @ Cn3, v056
	.byte W54
	.byte VOICE, 83
	.byte N12, Bn2, v100
	.byte W12
	.byte VOICE, 83
	.byte N06, Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
	.byte Cn3, v064 @ N06
	.byte W06
	.byte N06 @ Cn3, v064
	.byte W54
	.byte VOICE, 83
	.byte N12, Bn2, v100
	.byte W12
	.byte VOICE, 83
	.byte N06, Cn3, v068
	.byte W06
	.byte N06 @ Cn3, v068
	.byte W06
	.byte N06 @ Cn3, v068
	.byte W12
	.byte N06 @ Cn3, v068
	.byte W06
	.byte N06 @ Cn3, v068
	.byte W54
track_27_lbl_2319fd:
	.byte VOICE, 83
	.byte N12, Bn2, v100
	.byte W12
	.byte VOICE, 83
	.byte N06, Cn3, v072
	.byte W06
	.byte N06 @ Cn3, v072
	.byte W06
	.byte N06 @ Cn3, v072
	.byte W12
	.byte N06 @ Cn3, v072
	.byte W06
	.byte N06 @ Cn3, v072
	.byte W54
	.byte PEND
	.byte PATT
		.word track_27_lbl_2319fd
	.byte VOICE, 102
	.byte N12, Cn3, v044
	.byte W12
	.byte N06, Cn3, v028
	.byte W06
	.byte N06 @ Cn3, v028
	.byte W06
	.byte N12, Cn3, v044
	.byte W12
	.byte N06, Cn3, v028
	.byte W06
	.byte N06 @ Cn3, v028
	.byte W06
	.byte N12, Cn3, v044
	.byte W12
	.byte N06, Cn3, v028
	.byte W06
	.byte N06 @ Cn3, v028
	.byte W06
	.byte N12, Cn3, v044
	.byte W12
	.byte N06, Cn3, v028
	.byte W06
	.byte N06 @ Cn3, v028
	.byte W06
track_27_lbl_231a41:
	.byte N12, Cn3, v044
	.byte W12
	.byte N06, Cn3, v028
	.byte W06
	.byte N06 @ Cn3, v028
	.byte W06
	.byte N12, Cn3, v044
	.byte W12
	.byte N06, Cn3, v028
	.byte W06
	.byte N06 @ Cn3, v028
	.byte W06
	.byte N12, Cn3, v044
	.byte W12
	.byte N06, Cn3, v028
	.byte W06
	.byte N06 @ Cn3, v028
	.byte W06
	.byte N12, Cn3, v044
	.byte W12
	.byte N06, Cn3, v028
	.byte W06
	.byte N06 @ Cn3, v028
	.byte W06
	.byte PEND
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte PATT
		.word track_27_lbl_231a41
	.byte VOICE, 83
	.byte VOL, 69
	.byte W24
	.byte N06, Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
track_27_lbl_231ab5:
	.byte N06, Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N12 @ Gn2, v080
	.byte W12
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N12 @ Gn2, v080
	.byte W12
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N12 @ Gn2, v080
	.byte W12
	.byte N06, Bn2 @ v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W12
	.byte PEND
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte PATT
		.word track_27_lbl_231ab5
track_27_lbl_231aee:
	.byte W24
	.byte N06, Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte PEND
track_27_lbl_231b04:
	.byte N06, Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N12 @ Gn2, v080
	.byte W12
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N12 @ Gn2, v080
	.byte W12
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N12 @ Gn2, v080
	.byte W12
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_231aee
track_27_lbl_231b24:
	.byte N06, Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N12 @ Gn2, v080
	.byte W12
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N06 @ Gn2, v080
	.byte W06
	.byte N12 @ Gn2, v080
	.byte W12
	.byte N06, Bn2 @ v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N12 @ Bn2, v080
	.byte W12
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W06
	.byte N06 @ Bn2, v080
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_231aee
	.byte PATT
		.word track_27_lbl_231b04
	.byte PATT
		.word track_27_lbl_231aee
	.byte PATT
		.word track_27_lbl_231b24
	.byte PATT
		.word track_27_lbl_231aee
	.byte PATT
		.word track_27_lbl_231b24
	.byte PATT
		.word track_27_lbl_231aee
	.byte PATT
		.word track_27_lbl_231b04
track_27_lbl_231b68:
	.byte N04, Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W24
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W12
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_231b68
track_27_lbl_231b86:
	.byte W36
	.byte N04, Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W12
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W06
	.byte N04 @ Bn2, v080
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_231b68
	.byte PATT
		.word track_27_lbl_231b86
	.byte PATT
		.word track_27_lbl_231b68
	.byte PATT
		.word track_27_lbl_231b86
	.byte PATT
		.word track_27_lbl_231b86
	.byte N48, Bn2, v080
	.byte W96
	.byte W12
	.byte N05, Bn2, v120
	.byte W12
	.byte N03 @ Bn2, v120
	.byte W06
	.byte N03 @ Bn2, v120
	.byte W06
	.byte N06 @ Bn2, v120
	.byte W60
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_231bc6:
	.byte VOICE, 83
	.byte VOL, 69
	.byte N06, Dn3, v080
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W24
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
track_27_lbl_231bdd:
	.byte N06, Dn3, v080
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
	.byte Dn3, v080 @ N06
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W24
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
	.byte N06 @ Cn3, v060
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W06
	.byte PEND
	.byte PATT
		.word track_27_lbl_231bdd
	.byte PATT
		.word track_27_lbl_231bdd
	.byte PATT
		.word track_27_lbl_231bdd
	.byte PATT
		.word track_27_lbl_231bdd
	.byte PATT
		.word track_27_lbl_231bdd
	.byte PATT
		.word track_27_lbl_231bdd
	.byte N06, Dn3, v080
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte N06 @ Cn3, v060
	.byte W12
	.byte GOTO
		.word track_27_lbl_231bc6
	.byte FINE

track_27_7:
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
	.byte VOICE, 25
	.byte VOL, 80
	.byte PAN, c_v
	.byte N48, Cn3, v127
	.byte W48
	.byte VOICE, 92
	.byte W48
	.byte Gs5 @ N48, v127
	.byte W96
	.byte Gs5 @ N48, v127
	.byte W48
	.byte Gs5 @ N48, v127
	.byte W48
	.byte Gs5 @ N48, v127
	.byte W96
track_27_lbl_231c47:
	.byte VOICE, 25
	.byte N48, Cn3, v127
	.byte W48
	.byte VOICE, 92
	.byte W48
	.byte PEND
	.byte Gs5 @ N48, v127
	.byte W96
	.byte Gs5 @ N48, v127
	.byte W48
	.byte Gs5 @ N48, v127
	.byte W48
	.byte Gs5 @ N48, v127
	.byte W96
	.byte PATT
		.word track_27_lbl_231c47
	.byte VOICE, 92
	.byte W96
	.byte PATT
		.word track_27_lbl_231c47
	.byte VOICE, 92
	.byte W96
	.byte PATT
		.word track_27_lbl_231c47
	.byte PATT
		.word track_27_lbl_231c47
	.byte PATT
		.word track_27_lbl_231c47
	.byte PATT
		.word track_27_lbl_231c47
	.byte W48
	.byte VOICE, 25
	.byte N48, Cn3, v127
	.byte W48
	.byte W48
	.byte VOICE, 25
	.byte N48 @ Cn3, v127
	.byte W48
	.byte W48
	.byte VOICE, 25
	.byte N48 @ Cn3, v127
	.byte W48
	.byte W48
	.byte VOICE, 25
	.byte N48 @ Cn3, v127
	.byte W48
	.byte W48
	.byte VOICE, 25
	.byte N48 @ Cn3, v127
	.byte W48
	.byte W48
	.byte VOICE, 25
	.byte N48 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N48 @ Cn3, v127
	.byte W48
	.byte W48
	.byte N48 @ Cn3, v127
	.byte W48
	.byte W48
	.byte VOICE, 25
	.byte W48
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
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte N24 @ Cn3, v127
	.byte W96
	.byte N48 @ Cn3, v127
	.byte W96
	.byte W36
	.byte N24 @ Cn3, v127
	.byte W60
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_231cdf:
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte GOTO
		.word track_27_lbl_231cdf
	.byte FINE

track_27_8:
	.byte KEYSH, 0
	.byte VOICE, 90
	.byte VOL, 69
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
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte N01, Gn4, v040
	.byte W12
	.byte N01 @ Gn4, v040
	.byte W06
	.byte N01 @ Gn4, v040
	.byte W06
	.byte N01 @ Gn4, v040
	.byte W12
	.byte N01 @ Gn4, v040
	.byte W06
	.byte Gn4, v044 @ N01
	.byte W06
	.byte Gn4, v040 @ N01
	.byte W12
	.byte N01 @ Gn4, v040
	.byte W06
	.byte N01 @ Gn4, v040
	.byte W06
	.byte N01 @ Gn4, v040
	.byte W12
	.byte N01 @ Gn4, v040
	.byte W06
	.byte Gn4, v044 @ N01
	.byte W06
	.byte N01 @ Gn4, v044
	.byte W12
	.byte N01 @ Gn4, v044
	.byte W06
	.byte Gn4, v048 @ N01
	.byte W06
	.byte N01 @ Gn4, v048
	.byte W12
	.byte N01 @ Gn4, v048
	.byte W06
	.byte N01 @ Gn4, v048
	.byte W06
	.byte Gn4, v040 @ N01
	.byte W12
	.byte N01 @ Gn4, v040
	.byte W06
	.byte N01 @ Gn4, v040
	.byte W06
	.byte N01 @ Gn4, v040
	.byte W12
	.byte N01 @ Gn4, v040
	.byte W06
	.byte Gn4, v044 @ N01
	.byte W06
	.byte Gn4, v052 @ N01
	.byte W12
	.byte N01 @ Gn4, v052
	.byte W06
	.byte N01 @ Gn4, v052
	.byte W06
	.byte N01 @ Gn4, v052
	.byte W12
	.byte N01 @ Gn4, v052
	.byte W06
	.byte N01 @ Gn4, v052
	.byte W06
	.byte Gn4, v040 @ N01
	.byte W12
	.byte N01 @ Gn4, v040
	.byte W06
	.byte N01 @ Gn4, v040
	.byte W06
	.byte N01 @ Gn4, v040
	.byte W12
	.byte N01 @ Gn4, v040
	.byte W06
	.byte Gn4, v044 @ N01
	.byte W06
	.byte Gn4, v056 @ N01
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte Gn4, v060 @ N01
	.byte W12
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W12
	.byte Gn4, v064 @ N01
	.byte W06
	.byte N01 @ Gn4, v064
	.byte W06
	.byte Gn4, v056 @ N01
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte Gn4, v064 @ N01
	.byte W12
	.byte Gn4, v068 @ N01
	.byte W06
	.byte N01 @ Gn4, v068
	.byte W06
	.byte N01 @ Gn4, v068
	.byte W12
	.byte N01 @ Gn4, v068
	.byte W06
	.byte N01 @ Gn4, v068
	.byte W06
	.byte Gn4, v056 @ N01
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
track_27_lbl_231db0:
	.byte N01, Gn4, v072
	.byte W12
	.byte N01 @ Gn4, v072
	.byte W06
	.byte N01 @ Gn4, v072
	.byte W06
	.byte N01 @ Gn4, v072
	.byte W12
	.byte N01 @ Gn4, v072
	.byte W06
	.byte N01 @ Gn4, v072
	.byte W06
	.byte Gn4, v056 @ N01
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W12
	.byte N01 @ Gn4, v056
	.byte W06
	.byte N01 @ Gn4, v056
	.byte W06
	.byte PEND
	.byte PATT
		.word track_27_lbl_231db0
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
track_27_lbl_231ddd:
	.byte N01, Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W12
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W12
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W12
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
	.byte PATT
		.word track_27_lbl_231ddd
track_27_lbl_231e43:
	.byte N01, Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W24
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W12
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W06
	.byte N01 @ Gn4, v060
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_231e43
	.byte PATT
		.word track_27_lbl_231e43
	.byte PATT
		.word track_27_lbl_231e43
	.byte PATT
		.word track_27_lbl_231e43
	.byte PATT
		.word track_27_lbl_231e43
	.byte PATT
		.word track_27_lbl_231e43
	.byte PATT
		.word track_27_lbl_231e43
	.byte N01, Gn4, v060
	.byte W96
	.byte W12
	.byte Gn4, v100 @ N01
	.byte W12
	.byte N01 @ Gn4, v100
	.byte W06
	.byte N01 @ Gn4, v100
	.byte W06
	.byte N01 @ Gn4, v100
	.byte W60
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_231e91:
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte GOTO
		.word track_27_lbl_231e91
	.byte FINE

track_27_9:
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
	.byte VOICE, 83
	.byte VOL, 69
	.byte N06, Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
track_27_lbl_231eca:
	.byte N06, Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte Gn3, v072 @ N06
	.byte W06
	.byte Fn3, v056 @ N06
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte PEND
track_27_lbl_231ee9:
	.byte N06, Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte PEND
track_27_lbl_231f04:
	.byte N06, Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte N06 @ Fn3, v056
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W06
	.byte Gn3, v072 @ N06
	.byte W06
	.byte Fn3, v056 @ N06
	.byte W06
	.byte N06 @ Fn3, v056
	.byte W12
	.byte PEND
	.byte PATT
		.word track_27_lbl_231ee9
	.byte PATT
		.word track_27_lbl_231eca
	.byte PATT
		.word track_27_lbl_231ee9
	.byte PATT
		.word track_27_lbl_231eca
	.byte PATT
		.word track_27_lbl_231eca
	.byte PATT
		.word track_27_lbl_231eca
	.byte PATT
		.word track_27_lbl_231eca
	.byte PATT
		.word track_27_lbl_231f04
	.byte VOICE, 83
	.byte VOL, 69
	.byte N04, Dn3, v100
	.byte W06
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W24
	.byte N04 @ Cn3, v064
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W06
	.byte Dn3, v084 @ N04
	.byte W12
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W06
	.byte Dn3, v084 @ N04
	.byte W06
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W12
track_27_lbl_231f6a:
	.byte N04, Dn3, v084
	.byte W06
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W24
	.byte N04 @ Cn3, v064
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W06
	.byte Dn3, v084 @ N04
	.byte W12
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W06
	.byte Dn3, v084 @ N04
	.byte W06
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W12
	.byte PEND
	.byte Dn3, v100 @ N04
	.byte W06
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W24
	.byte N04 @ Cn3, v064
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W06
	.byte Dn3, v084 @ N04
	.byte W12
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W06
	.byte Dn3, v084 @ N04
	.byte W06
	.byte Cn3, v064 @ N04
	.byte W06
	.byte N04 @ Cn3, v064
	.byte W12
	.byte PATT
		.word track_27_lbl_231f6a
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
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W24
track_27_lbl_231fdb:
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte GOTO
		.word track_27_lbl_231fdb
	.byte FINE

.align 2

track_27:
	.byte 10
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_27_0
	.word track_27_1
	.word track_27_2
	.word track_27_3
	.word track_27_4
	.word track_27_5
	.word track_27_6
	.word track_27_7
	.word track_27_8
	.word track_27_9

.align 2
