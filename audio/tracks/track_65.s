.align 2

.global track_65

track_65_0:
	.byte KEYSH, 0
	.byte TEMPO, 123
	.byte VOICE, 38
	.byte VOL, 88
	.byte PAN, c_v-10
	.byte PRIO, 120
	.byte N12, Ds3, v060
	.byte N12, Ds4 @ v060
	.byte W12
	.byte Dn3 @ N12, v060
	.byte N12, Dn4 @ v060
	.byte W12
	.byte Fs3, v080 @ N12
	.byte N12, Fs4 @ v080
	.byte W12
	.byte Fn3 @ N12, v080
	.byte N12, Fn4 @ v080
	.byte W12
	.byte Ds3, v100 @ N12
	.byte N12, Ds4 @ v100
	.byte W12
	.byte Dn3 @ N12, v100
	.byte N12, Dn4 @ v100
	.byte W12
	.byte Fs3, v120 @ N12
	.byte N12, Fs4 @ v120
	.byte W12
	.byte Fn3 @ N12, v120
	.byte N12, Fn4 @ v120
	.byte W12
track_65_lbl_22396d:
	.byte VOICE, 36
	.byte VOL, 74
	.byte PAN, c_v-34
	.byte BEND, c_v
	.byte N24, Cn5, v100
	.byte W36
	.byte N24 @ Cn5, v100
	.byte W36
	.byte N20, Cs5 @ v100
	.byte W24
	.byte As4 @ N20, v100
	.byte W24
track_65_lbl_223980:
	.byte N24, Cn5, v100
	.byte W36
	.byte N24 @ Cn5, v100
	.byte W36
	.byte N20, Cs5 @ v100
	.byte W24
	.byte As4 @ N20, v100
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte N24, Ds5, v100
	.byte W36
	.byte N24 @ Ds5, v100
	.byte W36
	.byte N20, En5, v096
	.byte W24
	.byte Cs5 @ N20, v096
	.byte W24
	.byte N24, Ds5, v092
	.byte W36
	.byte N24 @ Ds5, v092
	.byte W36
	.byte N20, En5, v088
	.byte W24
	.byte Cs5 @ N20, v088
	.byte W24
	.byte N24, Ds5 @ v088
	.byte W36
	.byte Ds5, v084 @ N24
	.byte W36
	.byte N20, En5, v080
	.byte W24
	.byte Cs5 @ N20, v080
	.byte W24
	.byte N24, Ds5 @ v080
	.byte W36
	.byte Ds5, v076 @ N24
	.byte W36
	.byte N20, En5 @ v076
	.byte W24
	.byte Cs5, v072 @ N20
	.byte W24
track_65_lbl_2239da:
	.byte N24, Ds5, v100
	.byte W36
	.byte N24 @ Ds5, v100
	.byte W36
	.byte N20, En5 @ v100
	.byte W24
	.byte Cs5 @ N20, v100
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_2239da
	.byte PATT
		.word track_65_lbl_2239da
	.byte PATT
		.word track_65_lbl_2239da
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte VOICE, 36
	.byte VOL, 74
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte W36
	.byte N24, Ds5, v084
	.byte W36
	.byte N20, En5, v088
	.byte W24
	.byte Cs5 @ N20, v088
	.byte W24
	.byte N24, Ds5, v092
	.byte W36
	.byte Ds5, v096 @ N24
	.byte W36
	.byte N20, En5 @ v096
	.byte W24
	.byte Cs5, v100 @ N20
	.byte W24
	.byte PATT
		.word track_65_lbl_2239da
	.byte N24, Ds5, v100
	.byte W36
	.byte Ds5, v096 @ N24
	.byte W36
	.byte N20, En5, v088
	.byte W24
	.byte Cs5, v084 @ N20
	.byte W24
	.byte PATT
		.word track_65_lbl_223980
	.byte PATT
		.word track_65_lbl_223980
	.byte N24, Cn5, v100
	.byte W36
	.byte N24 @ Cn5, v100
	.byte W36
	.byte N20, Cs5, v096
	.byte W24
	.byte As4, v092 @ N20
	.byte W24
	.byte N24, Cn5 @ v092
	.byte W36
	.byte Cn5, v088 @ N24
	.byte W36
	.byte N20, Cs5, v084
	.byte W24
	.byte As4 @ N20, v084
	.byte W24
	.byte VOICE, 2
	.byte PAN, c_v-10
	.byte VOL, 88
	.byte N48, As2, v120
	.byte W48
	.byte N24, An2 @ v120
	.byte W24
track_65_lbl_223a80:
	.byte N48, Fs2, v120
	.byte W48
	.byte N24, An2 @ v120
	.byte W24
	.byte PEND
	.byte N48, As2 @ v120
	.byte W48
	.byte N24, An2 @ v120
	.byte W24
	.byte PATT
		.word track_65_lbl_223a80
	.byte N48, Cs3, v127
	.byte W48
	.byte N24, Cn3 @ v127
	.byte W24
	.byte N48, An2 @ v127
	.byte W48
	.byte N24, Cn3 @ v127
	.byte W24
	.byte N48, Ds3 @ v127
	.byte W48
	.byte N08, Dn3 @ v127
	.byte W08
	.byte Ds3 @ N08, v127
	.byte W08
	.byte Dn3 @ N08, v127
	.byte W08
	.byte N48, Fs3 @ v127
	.byte W48
	.byte N08, Fn3 @ v127
	.byte W08
	.byte Fs3 @ N08, v127
	.byte W08
	.byte Fn3 @ N08, v127
	.byte W08
	.byte VOICE, 38
	.byte VOL, 88
	.byte PAN, c_v-10
	.byte N12, Ds3, v060
	.byte N12, Ds4 @ v060
	.byte W12
	.byte Dn3, v072 @ N12
	.byte N12, Dn4 @ v072
	.byte W12
	.byte Fs3, v080 @ N12
	.byte N12, Fs4 @ v080
	.byte W12
	.byte Fn3, v092 @ N12
	.byte N12, Fn4 @ v092
	.byte W12
	.byte Ds3 @ N12, v092
	.byte N12, Ds4 @ v092
	.byte W12
	.byte Dn3 @ N12, v092
	.byte N12, Dn4 @ v092
	.byte W12
	.byte Fs3, v112 @ N12
	.byte N12, Fs4 @ v112
	.byte W12
	.byte Fn3, v120 @ N12
	.byte N12, Fn4 @ v120
	.byte W12
	.byte GOTO
		.word track_65_lbl_22396d
	.byte FINE

track_65_1:
	.byte KEYSH, 0
	.byte VOICE, 36
	.byte VOL, 74
	.byte PAN, c_v-14
	.byte PRIO, 119
	.byte N36, Ds4, v100
	.byte W36
	.byte Fs4, v112 @ N36
	.byte W36
	.byte N24, An4, v127
	.byte W24
track_65_lbl_223afc:
	.byte VOICE, 2
	.byte VOL, 88
	.byte PAN, c_v-14
	.byte BENDR, 20
	.byte N12, Cn4, v120
	.byte W12
	.byte Cn3 @ N12, v120
	.byte W12
	.byte Cn2, v127 @ N12
	.byte W12
	.byte Cn1 @ N12, v127
	.byte W12
	.byte Cn2 @ N12, v127
	.byte W12
	.byte Cn3, v120 @ N12
	.byte W12
	.byte Cs4 @ N12, v120
	.byte W12
	.byte Cs3 @ N12, v120
	.byte W12
	.byte As2 @ N12, v120
	.byte W12
	.byte As1, v127 @ N12
	.byte W12
track_65_lbl_223b1d:
	.byte N12, Cn4, v120
	.byte W12
	.byte Cn3 @ N12, v120
	.byte W12
	.byte Cn2, v127 @ N12
	.byte W12
	.byte Cn1 @ N12, v127
	.byte W12
	.byte Cn2 @ N12, v127
	.byte W12
	.byte Cn3, v120 @ N12
	.byte W12
	.byte Cs4 @ N12, v120
	.byte W12
	.byte Cs3 @ N12, v120
	.byte W12
	.byte As2 @ N12, v120
	.byte W12
	.byte As1, v127 @ N12
	.byte W12
	.byte PEND
	.byte PATT
		.word track_65_lbl_223b1d
	.byte PATT
		.word track_65_lbl_223b1d
track_65_lbl_223b41:
	.byte VOICE, 4
	.byte VOL, 81
	.byte PAN, c_v
	.byte BEND, c_v
	.byte W96
	.byte W24
	.byte PEND
	.byte BENDR, 20
	.byte N12, Cn2, v072
	.byte W12
	.byte Fn2 @ N12, v072
	.byte W12
	.byte Gn2, v080 @ N12
	.byte W12
	.byte Cn3 @ N12, v080
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte Fn2 @ N12, v100
	.byte W12
	.byte Gn2, v108 @ N12
	.byte W12
	.byte Cn3, v112 @ N12
	.byte W12
	.byte Cn2 @ N12, v112
	.byte W12
	.byte Fn2 @ N12, v112
	.byte W12
	.byte Gn2 @ N12, v112
	.byte W12
	.byte Cn3, v124 @ N12
	.byte W12
	.byte Cn2 @ N12, v124
	.byte W12
	.byte Fn2 @ N12, v124
	.byte W12
	.byte Gn2 @ N12, v124
	.byte W12
	.byte Cn3 @ N12, v124
	.byte W12
	.byte Cn2 @ N12, v124
	.byte W12
	.byte Fn2 @ N12, v124
	.byte W12
	.byte Gn2 @ N12, v124
	.byte W12
	.byte Cn3 @ N12, v124
	.byte W12
	.byte Cn2 @ N12, v124
	.byte W12
	.byte Fn2 @ N12, v124
	.byte W12
	.byte Gn2 @ N12, v124
	.byte W12
	.byte Cn3 @ N12, v124
	.byte W12
	.byte Cn2 @ N12, v124
	.byte W12
	.byte Fn2 @ N12, v124
	.byte W12
	.byte Gn2 @ N12, v124
	.byte W12
	.byte Cn3 @ N12, v124
	.byte W36
	.byte VOICE, 2
	.byte VOL, 74
	.byte PAN, c_v-10
	.byte N12, Ds3, v112
	.byte W12
	.byte Ds2 @ N12, v112
	.byte W12
	.byte Ds1 @ N12, v112
	.byte W12
	.byte Ds2 @ N12, v112
	.byte W12
	.byte Ds3 @ N12, v112
	.byte W12
	.byte Ds4 @ N12, v112
	.byte W12
	.byte En3 @ N12, v112
	.byte W12
	.byte En2 @ N12, v112
	.byte W12
	.byte Cs2 @ N12, v112
	.byte W12
	.byte Cs1 @ N12, v112
	.byte W12
	.byte VOICE, 4
	.byte VOL, 74
	.byte PAN, c_v+16
	.byte BEND, c_v
	.byte N08, Ds3, v072
	.byte W12
	.byte N08 @ Ds3, v072
	.byte W24
	.byte N08 @ Ds3, v072
	.byte W12
	.byte N08 @ Ds3, v072
	.byte W24
	.byte En3, v060 @ N08
	.byte W12
	.byte En2 @ N08, v060
	.byte W12
	.byte Cs3 @ N08, v060
	.byte W12
	.byte Gs2 @ N08, v060
	.byte W12
	.byte W12
	.byte Ds3 @ N08, v060
	.byte W36
	.byte N08 @ Ds3, v060
	.byte W24
	.byte VOICE, 2
	.byte VOL, 74
	.byte PAN, c_v-14
	.byte N12, En3, v112
	.byte W12
	.byte En2 @ N12, v112
	.byte W12
	.byte Cs2 @ N12, v112
	.byte W12
	.byte Cs1 @ N12, v112
	.byte W12
track_65_lbl_223bd9:
	.byte N12, Ds3, v120
	.byte W12
	.byte Ds2 @ N12, v120
	.byte W12
	.byte Ds1 @ N12, v120
	.byte W12
	.byte Ds2 @ N12, v120
	.byte W12
	.byte Ds3 @ N12, v120
	.byte W12
	.byte Ds4 @ N12, v120
	.byte W12
	.byte En3 @ N12, v120
	.byte W12
	.byte En2 @ N12, v120
	.byte W12
	.byte Cs2 @ N12, v120
	.byte W12
	.byte Cs1 @ N12, v120
	.byte W12
	.byte PEND
	.byte W96
	.byte W24
	.byte VOICE, 4
	.byte VOL, 74
	.byte PAN, c_v+16
	.byte BEND, c_v
	.byte N08, Ds3, v072
	.byte W12
	.byte N08 @ Ds3, v072
	.byte W24
	.byte N08 @ Ds3, v072
	.byte W12
	.byte N08 @ Ds3, v072
	.byte W24
	.byte As2, v060 @ N08
	.byte W12
	.byte En3 @ N08, v060
	.byte W12
	.byte Cs3 @ N08, v060
	.byte W12
	.byte Gs2 @ N08, v060
	.byte W12
	.byte W12
	.byte Ds3 @ N08, v060
	.byte W36
	.byte N08 @ Ds3, v060
	.byte W72
	.byte W12
	.byte N08 @ Ds3, v060
	.byte W36
	.byte N08 @ Ds3, v060
	.byte W72
	.byte VOICE, 2
	.byte VOL, 74
	.byte PAN, c_v-14
	.byte N12, Cn4, v120
	.byte W12
	.byte Cn3 @ N12, v120
	.byte W12
	.byte Cn2, v127 @ N12
	.byte W12
	.byte Cn1 @ N12, v127
	.byte W12
	.byte Cn2 @ N12, v127
	.byte W12
	.byte Cn3, v120 @ N12
	.byte W12
	.byte Cs4 @ N12, v120
	.byte W12
	.byte Cs3 @ N12, v120
	.byte W12
	.byte As2 @ N12, v120
	.byte W12
	.byte As1, v127 @ N12
	.byte W12
	.byte PATT
		.word track_65_lbl_223b1d
	.byte N12, Cn3, v120
	.byte W12
	.byte Cn2, v127 @ N12
	.byte W12
	.byte Cn1 @ N12, v127
	.byte W12
	.byte Cn2 @ N12, v127
	.byte W12
	.byte Cn3, v120 @ N12
	.byte W12
	.byte Cn2, v127 @ N12
	.byte W12
	.byte Cs1 @ N12, v127
	.byte W12
	.byte Cs2, v120 @ N12
	.byte W12
	.byte As2 @ N12, v120
	.byte W12
	.byte As0, v127 @ N12
	.byte W12
	.byte Cn2 @ N12, v127
	.byte W12
	.byte Cn3, v120 @ N12
	.byte W12
	.byte Cn2, v127 @ N12
	.byte W12
	.byte Cn1 @ N12, v127
	.byte W12
	.byte Cn2 @ N12, v127
	.byte W12
	.byte Cn3 @ N12, v127
	.byte W12
	.byte Cs3 @ N12, v127
	.byte W12
	.byte Cs2 @ N12, v127
	.byte W12
	.byte As0 @ N12, v127
	.byte W12
	.byte As1 @ N12, v127
	.byte W12
	.byte PATT
		.word track_65_lbl_223b41
	.byte N12, Cn2, v060
	.byte W12
	.byte Fn2 @ N12, v060
	.byte W12
	.byte Gn2, v068 @ N12
	.byte W12
	.byte Cn3 @ N12, v068
	.byte W12
	.byte Cn2, v092 @ N12
	.byte W12
	.byte Fn2 @ N12, v092
	.byte W12
	.byte Gn2, v096 @ N12
	.byte W12
	.byte Cn3, v100 @ N12
	.byte W12
	.byte Cn2 @ N12, v100
	.byte W12
	.byte Fn2 @ N12, v100
	.byte W12
track_65_lbl_223c8b:
	.byte N12, Gn2, v100
	.byte W12
	.byte Cn3, v112 @ N12
	.byte W12
	.byte Cn2, v120 @ N12
	.byte W12
	.byte Fn2 @ N12, v120
	.byte W12
	.byte Gn2 @ N12, v120
	.byte W12
	.byte Cn3, v112 @ N12
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte Fn2 @ N12, v100
	.byte W12
	.byte Gn2 @ N12, v100
	.byte W12
	.byte Cn3 @ N12, v100
	.byte W12
	.byte PEND
	.byte Cn2, v092 @ N12
	.byte W12
	.byte Fn2 @ N12, v092
	.byte W12
	.byte Gn2, v072 @ N12
	.byte W12
	.byte Cn3 @ N12, v072
	.byte W84
	.byte VOICE, 2
	.byte VOL, 88
	.byte PAN, c_v-14
	.byte N12, Fs3, v112
	.byte W12
	.byte Cn3 @ N12, v112
	.byte W12
	.byte Ds3 @ N12, v112
	.byte W12
	.byte N60, Gn2 @ v112
	.byte W60
	.byte N12, Gs2 @ v112
	.byte W12
	.byte As2 @ N12, v112
	.byte W12
	.byte Cn3 @ N12, v112
	.byte W12
	.byte N60, Gn3 @ v112
	.byte W60
	.byte N12, Fs3 @ v112
	.byte W12
	.byte Dn3 @ N12, v112
	.byte W12
	.byte N72, An3 @ v112
	.byte W72
	.byte W72
	.byte W48
	.byte VOICE, 2
	.byte VOL, 74
	.byte N12, Ds3, v092
	.byte W12
	.byte Ds4 @ N12, v092
	.byte W12
	.byte En3 @ N12, v092
	.byte W12
	.byte En2 @ N12, v092
	.byte W12
	.byte Cs2 @ N12, v092
	.byte W12
	.byte Cs1 @ N12, v092
	.byte W12
	.byte W96
	.byte W24
	.byte W72
	.byte En3, v112 @ N12
	.byte W12
	.byte En2 @ N12, v112
	.byte W12
	.byte Cs2 @ N12, v112
	.byte W12
	.byte Cs1 @ N12, v112
	.byte W12
	.byte PATT
		.word track_65_lbl_223bd9
	.byte W96
	.byte W24
	.byte VOICE, 4
	.byte VOL, 88
	.byte N12, Cn2, v040
	.byte W12
	.byte Fn2, v076 @ N12
	.byte W12
	.byte Gn2, v080 @ N12
	.byte W12
	.byte Cn3 @ N12, v080
	.byte W12
	.byte Cn2, v088 @ N12
	.byte W12
	.byte Fn2 @ N12, v088
	.byte W12
	.byte Gn2, v092 @ N12
	.byte W12
	.byte Cn3, v096 @ N12
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte Fn2 @ N12, v100
	.byte W12
	.byte PATT
		.word track_65_lbl_223c8b
	.byte N12, Cn2, v092
	.byte W12
	.byte Fn2 @ N12, v092
	.byte W12
	.byte Gn2, v080 @ N12
	.byte W12
	.byte Cn3 @ N12, v080
	.byte W84
	.byte VOICE, 36
	.byte VOL, 74
	.byte N72, Ds3, v120
	.byte W72
	.byte Cn3 @ N72, v120
	.byte W72
	.byte Ds3 @ N72, v120
	.byte W72
	.byte Fs3 @ N72, v120
	.byte W72
	.byte An3 @ N72, v120
	.byte W72
	.byte Fs3 @ N72, v120
	.byte W72
	.byte An3 @ N72, v120
	.byte W72
	.byte Cn4, v112 @ N72
	.byte W72
	.byte VOICE, 36
	.byte VOL, 74
	.byte PAN, c_v-14
	.byte N36, Ds4, v120
	.byte W36
	.byte Fs4 @ N36, v120
	.byte W36
	.byte N24, An4, v127
	.byte W24
	.byte GOTO
		.word track_65_lbl_223afc
	.byte FINE

track_65_2:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 74
	.byte PAN, c_v+10
	.byte PRIO, 118
	.byte W96
track_65_lbl_223d62:
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 35
	.byte VOL, 88
	.byte PAN, c_v-34
	.byte N96, Cn4, v112
	.byte W96
	.byte Cs4 @ N96, v112
	.byte W96
	.byte VOICE, 4
	.byte PAN, c_v
	.byte W24
	.byte VOL, 74
	.byte BENDR, 20
	.byte BEND, c_v
	.byte N72, An3, v072
	.byte W06
	.byte VOL, 34
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W04
	.byte 65 @ VOL
	.byte W03
	.byte 68 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 80 @ VOL
	.byte W20
	.byte VOICE, 38
	.byte PAN, c_v
	.byte VOL, 81
	.byte BEND, c_v
	.byte N36, Fs3, v064
	.byte N36, As3 @ v064
	.byte W36
	.byte N56, Gn3, v076
	.byte N56, Bn3 @ v076
	.byte W16
	.byte VOL, 79
	.byte W02
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 78
	.byte W01
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 76
	.byte W01
	.byte BEND, c_v-8
	.byte W02
	.byte VOL, 75
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 74
	.byte BEND, c_v-13
	.byte W02
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 72
	.byte W01
	.byte BEND, c_v-18
	.byte W01
	.byte VOL, 71
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 69
	.byte W01
	.byte BEND, c_v-23
	.byte W02
	.byte PAN, c_v+10
	.byte VOL, 68
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 66
	.byte BEND, c_v-28
	.byte W02
	.byte c_v-31 @ BEND
	.byte W01
	.byte VOL, 65
	.byte W01
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 63
	.byte W01
	.byte BEND, c_v-36
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v-39
	.byte W02
	.byte VOL, 60
	.byte BEND, c_v-41
	.byte W02
	.byte c_v-44 @ BEND
	.byte W01
	.byte VOL, 59
	.byte W01
	.byte BEND, c_v-46
	.byte W01
	.byte VOL, 57
	.byte W01
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 56
	.byte W01
	.byte BEND, c_v-52
	.byte W02
	.byte c_v-54 @ BEND
	.byte W02
	.byte c_v-57 @ BEND
	.byte W02
	.byte c_v-59 @ BEND
	.byte W01
	.byte c_v-60 @ BEND
	.byte W09
	.byte c_v @ BEND
	.byte W84
	.byte VOICE, 4
	.byte VOL, 74
	.byte BEND, c_v
	.byte N08, Ds3, v072
	.byte W12
	.byte As2 @ N08, v072
	.byte W24
	.byte Ds3 @ N08, v072
	.byte W12
	.byte N08 @ Ds3, v072
	.byte W24
	.byte As2, v060 @ N08
	.byte W12
	.byte En3 @ N08, v060
	.byte W12
	.byte Cs3 @ N08, v060
	.byte W12
	.byte Gs2 @ N08, v060
	.byte W12
	.byte W12
	.byte Ds3 @ N08, v060
	.byte W36
	.byte N08 @ Ds3, v060
	.byte W72
	.byte W96
	.byte W24
	.byte VOICE, 4
	.byte VOL, 88
	.byte BENDR, 20
	.byte TIE, Cn1, v120
	.byte W96
	.byte W24
	.byte EOT @ Cn1, v120
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 4
	.byte VOL, 74
	.byte N05, Fs3, v060
	.byte W12
	.byte N05 @ Fs3, v060
	.byte W24
	.byte N05 @ Fs3, v060
	.byte W12
	.byte N05 @ Fs3, v060
	.byte W24
	.byte N05 @ Fs3, v060
	.byte W12
	.byte N05 @ Fs3, v060
	.byte W12
	.byte N05 @ Fs3, v060
	.byte W12
	.byte N05 @ Fs3, v060
	.byte W24
	.byte N05 @ Fs3, v060
	.byte W12
	.byte W12
	.byte Fs3, v064 @ N05
	.byte W24
	.byte Fs3, v068 @ N05
	.byte W12
	.byte Fs3, v072 @ N05
	.byte W24
	.byte Fs3, v076 @ N05
	.byte W12
	.byte Fs3, v080 @ N05
	.byte W24
	.byte Fs3, v084 @ N05
	.byte W24
	.byte Fs3, v088 @ N05
	.byte W12
	.byte W12
	.byte Fs3, v092 @ N05
	.byte W24
	.byte Fs3, v100 @ N05
	.byte W36
	.byte W24
	.byte N06, An4, v072
	.byte W08
	.byte As4 @ N06, v072
	.byte W08
	.byte Dn5, v080 @ N06
	.byte W08
	.byte Fs3 @ N06, v080
	.byte W08
	.byte As4 @ N06, v080
	.byte W08
	.byte Gn4 @ N06, v080
	.byte W08
	.byte As2 @ N06, v080
	.byte W08
	.byte Fn3 @ N06, v080
	.byte W08
	.byte Bn4 @ N06, v080
	.byte W08
	.byte Fs3 @ N06, v080
	.byte W08
	.byte En3 @ N06, v080
	.byte W08
	.byte Gn4 @ N06, v080
	.byte W32
	.byte VOICE, 6
	.byte N72, Cn3, v052
	.byte W72
	.byte VOICE, 6
	.byte VOL, 74
	.byte PAN, c_v+10
	.byte W96
	.byte GOTO
		.word track_65_lbl_223d62
	.byte FINE

track_65_3:
	.byte KEYSH, 0
	.byte VOICE, 35
	.byte VOL, 88
	.byte PAN, c_v+26
	.byte PRIO, 118
	.byte W96
track_65_lbl_223ef7:
	.byte VOICE, 35
	.byte VOL, 88
	.byte PAN, c_v+26
	.byte BEND, c_v
	.byte N32, Cn4, v120, 2
	.byte W36
	.byte Cn4, v120, 2 @ N32
	.byte W36
	.byte N22, Cs4 @ v120
	.byte W24
	.byte As3 @ N22, v120
	.byte W24
track_65_lbl_223f0d:
	.byte N32, Cn4, v120, 2
	.byte W36
	.byte Cn4, v120, 2 @ N32
	.byte W36
	.byte N22, Cs4 @ v120
	.byte W24
	.byte As3 @ N22, v120
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
track_65_lbl_223f35:
	.byte N32, Cn4, v120, 2
	.byte W36
	.byte Cn4, v120, 2 @ N32
	.byte W36
	.byte N18, Cs4 @ v120
	.byte W24
	.byte As3 @ N18, v120
	.byte W24
	.byte PEND
	.byte N32, Ds4, v100, 2
	.byte W36
	.byte Ds4, v100, 2 @ N32
	.byte W36
	.byte N22, En4, v096
	.byte W24
	.byte Cs4 @ N22, v096
	.byte W24
	.byte N32, Ds4, v092, 2
	.byte W36
	.byte Ds4, v092, 2 @ N32
	.byte W36
	.byte N22, En4, v088
	.byte W24
	.byte Cs4 @ N22, v088
	.byte W24
	.byte N32, Ds4, v088, 2
	.byte W36
	.byte Ds4, v084, 2 @ N32
	.byte W36
	.byte N22, En4, v080
	.byte W24
	.byte Cs4 @ N22, v080
	.byte W24
	.byte N32, Ds4, v080, 2
	.byte W36
	.byte Ds4, v076, 2 @ N32
	.byte W36
	.byte N22, En4 @ v076
	.byte W24
	.byte Cs4, v072 @ N22
	.byte W24
track_65_lbl_223f80:
	.byte N32, Ds4, v120, 2
	.byte W36
	.byte Ds4, v120, 2 @ N32
	.byte W36
	.byte N22, En4 @ v120
	.byte W24
	.byte Cs4 @ N22, v120
	.byte W24
	.byte PEND
track_65_lbl_223f8f:
	.byte N32, Ds4, v100, 2
	.byte W36
	.byte Ds4, v100, 2 @ N32
	.byte W36
	.byte N22, En4 @ v100
	.byte W24
	.byte Cs4 @ N22, v100
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_223f8f
	.byte PATT
		.word track_65_lbl_223f8f
	.byte VOICE, 35
	.byte N32, Cn4, v120, 2
	.byte W36
	.byte Cn4, v120, 2 @ N32
	.byte W36
	.byte N22, Cs4 @ v120
	.byte W24
	.byte As3 @ N22, v120
	.byte W24
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f35
	.byte N96, Fs4, v112
	.byte W96
	.byte Gn4 @ N96, v112
	.byte W96
	.byte Gs4, v120 @ N96
	.byte W96
	.byte N32, Fn5, v120, 2
	.byte W36
	.byte En5, v120, 2 @ N32
	.byte W36
	.byte VOICE, 35
	.byte BEND, c_v
	.byte N32, Ds4, v096, 2
	.byte W36
	.byte Ds4, v100, 2 @ N32
	.byte W36
	.byte N22, En4, v104
	.byte W24
	.byte Cs4, v108 @ N22
	.byte W24
	.byte N32, Ds4, v108, 2
	.byte W36
	.byte Ds4, v112, 2 @ N32
	.byte W36
	.byte N22, En4, v116
	.byte W24
	.byte Cs4, v120 @ N22
	.byte W24
	.byte PATT
		.word track_65_lbl_223f80
	.byte N32, Ds4, v120, 2
	.byte W36
	.byte Ds4, v116, 2 @ N32
	.byte W36
	.byte N22, En4, v108
	.byte W24
	.byte Cs4, v104 @ N22
	.byte W24
	.byte PATT
		.word track_65_lbl_223f0d
	.byte PATT
		.word track_65_lbl_223f0d
	.byte N32, Cn4, v120, 2
	.byte W36
	.byte Cn4, v116, 2 @ N32
	.byte W36
	.byte N22, Cs4 @ v116
	.byte W24
	.byte As3, v112 @ N22
	.byte W24
	.byte N32, Cn4, v108, 2
	.byte W36
	.byte Cn4, v104, 2 @ N32
	.byte W36
	.byte N22, Cs4 @ v104
	.byte W24
	.byte As3, v100 @ N22
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 35
	.byte VOL, 88
	.byte PAN, c_v+26
	.byte W96
	.byte GOTO
		.word track_65_lbl_223ef7
	.byte FINE

track_65_4:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 74
	.byte PAN, c_v+6
	.byte PRIO, 30
	.byte W96
track_65_lbl_22406e:
	.byte PAN, c_v+6
	.byte BEND, c_v
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
track_65_lbl_22407c:
	.byte VOICE, 6
	.byte VOL, 74
	.byte N72, Cn1, v060
	.byte W72
	.byte N24, Cs1 @ v060
	.byte W24
	.byte As0 @ N24, v060
	.byte W24
	.byte PEND
track_65_lbl_22408a:
	.byte N72, Cn1, v072
	.byte W72
	.byte N24, Cs1 @ v072
	.byte W24
	.byte As0 @ N24, v072
	.byte W24
	.byte PEND
track_65_lbl_224094:
	.byte N72, Cn1, v080
	.byte W72
	.byte N24, Cs1 @ v080
	.byte W24
	.byte As0 @ N24, v080
	.byte W24
	.byte PEND
	.byte W96
	.byte W24
	.byte VOICE, 4
	.byte VOL, 74
	.byte N08, As2, v072
	.byte W12
	.byte N08 @ As2, v072
	.byte W24
	.byte N08 @ As2, v072
	.byte W12
	.byte N08 @ As2, v072
	.byte W72
track_65_lbl_2240ae:
	.byte W12
	.byte N08, As2, v060
	.byte W36
	.byte N08 @ As2, v060
	.byte W72
	.byte PEND
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte As2, v072 @ N08
	.byte W12
	.byte N08 @ As2, v072
	.byte W24
	.byte N08 @ As2, v072
	.byte W12
	.byte N08 @ As2, v072
	.byte W72
	.byte PATT
		.word track_65_lbl_2240ae
	.byte PATT
		.word track_65_lbl_2240ae
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte PATT
		.word track_65_lbl_22407c
	.byte PATT
		.word track_65_lbl_22408a
	.byte PATT
		.word track_65_lbl_224094
	.byte W96
	.byte W96
	.byte VOICE, 35
	.byte VOL, 88
	.byte N96, Dn4, v112
	.byte W96
	.byte VOICE, 4
	.byte PAN, c_v
	.byte VOL, 80
	.byte BENDR, 20
	.byte BEND, c_v
	.byte N36, Cn3, v080
	.byte W36
	.byte N56, Cs3, v092
	.byte W16
	.byte VOL, 79
	.byte W02
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 78
	.byte W01
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 76
	.byte W01
	.byte BEND, c_v-8
	.byte W02
	.byte VOL, 75
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 74
	.byte BEND, c_v-13
	.byte W02
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 72
	.byte W01
	.byte BEND, c_v-18
	.byte W01
	.byte VOL, 71
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 69
	.byte W01
	.byte BEND, c_v-23
	.byte W02
	.byte VOL, 68
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 66
	.byte BEND, c_v-28
	.byte W02
	.byte c_v-31 @ BEND
	.byte W01
	.byte VOL, 65
	.byte W01
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 63
	.byte W01
	.byte BEND, c_v-36
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v-39
	.byte W02
	.byte VOL, 60
	.byte BEND, c_v-41
	.byte W02
	.byte c_v-44 @ BEND
	.byte W01
	.byte VOL, 59
	.byte W01
	.byte BEND, c_v-46
	.byte W01
	.byte VOL, 57
	.byte W01
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 56
	.byte W01
	.byte BEND, c_v-52
	.byte W02
	.byte c_v-54 @ BEND
	.byte W02
	.byte c_v-57 @ BEND
	.byte W02
	.byte c_v-59 @ BEND
	.byte W01
	.byte c_v-60 @ BEND
	.byte W09
	.byte c_v @ BEND
	.byte W84
	.byte VOICE, 4
	.byte PAN, c_v+6
	.byte VOL, 74
	.byte N08, Ds3, v072
	.byte W12
	.byte As2 @ N08, v072
	.byte W24
	.byte N08 @ As2, v072
	.byte W12
	.byte N08 @ As2, v072
	.byte W24
	.byte As2, v060 @ N08
	.byte W12
	.byte En3 @ N08, v060
	.byte W12
	.byte Cs3 @ N08, v060
	.byte W12
	.byte Gs2 @ N08, v060
	.byte W12
	.byte W12
	.byte As2 @ N08, v060
	.byte W36
	.byte N08 @ As2, v060
	.byte W72
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 6
	.byte VOL, 56
	.byte BENDR, 20
	.byte N72, Cn1, v080
	.byte W72
	.byte N24, Cs1, v092
	.byte W24
	.byte As0 @ N24, v092
	.byte W24
	.byte N72, Cn1, v100
	.byte W72
	.byte N24, Cs1, v092
	.byte W24
	.byte As0, v080 @ N24
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 1
	.byte VOL, 74
	.byte N12, Cn3, v012
	.byte W12
	.byte Cn3, v016 @ N12
	.byte W12
	.byte Cn3, v024 @ N12
	.byte W12
	.byte Cn3, v032 @ N12
	.byte W12
	.byte Cn3, v036 @ N12
	.byte W12
	.byte Cn3, v044 @ N12
	.byte W12
track_65_lbl_2241c8:
	.byte N12, Cn3, v052
	.byte W12
	.byte Cn3, v056 @ N12
	.byte W12
	.byte Cn3, v076 @ N12
	.byte W12
	.byte Cn3, v080 @ N12
	.byte W12
	.byte Dn3, v088 @ N12
	.byte W12
	.byte Gn3, v096 @ N12
	.byte W12
	.byte PEND
track_65_lbl_2241dc:
	.byte N12, Gn3, v100
	.byte W12
	.byte Gn3, v076 @ N12
	.byte W12
	.byte Dn3 @ N12, v076
	.byte W12
	.byte Cn3, v072 @ N12
	.byte W12
	.byte Cn3, v056 @ N12
	.byte W12
	.byte Cn3, v048 @ N12
	.byte W12
	.byte PEND
track_65_lbl_2241ef:
	.byte N12, Cn3, v048
	.byte W12
	.byte Cn3, v044 @ N12
	.byte W12
	.byte Cn3, v036 @ N12
	.byte W12
	.byte Cn3, v032 @ N12
	.byte W12
	.byte Cn3, v024 @ N12
	.byte W12
	.byte Cn3, v016 @ N12
	.byte W12
	.byte PEND
	.byte Cn3, v012 @ N12
	.byte W12
	.byte Cn3, v016 @ N12
	.byte W12
	.byte Cn3, v024 @ N12
	.byte W12
	.byte Cn3, v032 @ N12
	.byte W12
	.byte Cn3, v036 @ N12
	.byte W12
	.byte Cn3, v044 @ N12
	.byte W12
	.byte PATT
		.word track_65_lbl_2241c8
	.byte PATT
		.word track_65_lbl_2241dc
	.byte PATT
		.word track_65_lbl_2241ef
	.byte VOICE, 1
	.byte VOL, 74
	.byte PAN, c_v+6
	.byte W96
	.byte GOTO
		.word track_65_lbl_22406e
	.byte FINE

track_65_5:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 51
	.byte PAN, c_v
	.byte PRIO, 29
	.byte W96
track_65_lbl_22423c:
	.byte VOICE, 37
	.byte VOL, 81
	.byte PAN, c_v+28
	.byte BEND, c_v
	.byte N32, Gn1, v120, 2
	.byte W36
	.byte Gn1, v120, 2 @ N32
	.byte W36
	.byte N22, Gs1 @ v120
	.byte W24
	.byte Fn1 @ N22, v120
	.byte W24
track_65_lbl_224252:
	.byte N32, Gn1, v120, 2
	.byte W36
	.byte Gn1, v120, 2 @ N32
	.byte W36
	.byte N22, Gs1 @ v120
	.byte W24
	.byte Fn1 @ N22, v120
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_224252
	.byte PATT
		.word track_65_lbl_224252
track_65_lbl_22426b:
	.byte N32, Gn1, v112, 2
	.byte W36
	.byte Gn1, v112, 2 @ N32
	.byte W36
	.byte N22, Gs1 @ v112
	.byte W24
	.byte Fn1 @ N22, v112
	.byte W24
	.byte PEND
track_65_lbl_22427a:
	.byte N32, Gn1, v100, 2
	.byte W36
	.byte Gn1, v100, 2 @ N32
	.byte W36
	.byte N22, Gs1 @ v100
	.byte W24
	.byte Fn1 @ N22, v100
	.byte W24
	.byte PEND
track_65_lbl_224289:
	.byte N32, Gn1, v092, 2
	.byte W36
	.byte Gn1, v092, 2 @ N32
	.byte W36
	.byte N22, Gs1 @ v092
	.byte W24
	.byte Fn1 @ N22, v092
	.byte W24
	.byte PEND
track_65_lbl_224298:
	.byte N32, Gn1, v080, 2
	.byte W36
	.byte Gn1, v080, 2 @ N32
	.byte W36
	.byte N18, Gs1 @ v080
	.byte W24
	.byte N20, Fn1 @ v080
	.byte W24
	.byte PEND
	.byte N32, As1, v100, 2
	.byte W36
	.byte As1, v100, 2 @ N32
	.byte W36
	.byte N22, Bn1, v096
	.byte W24
	.byte Gs1 @ N22, v096
	.byte W24
	.byte N32, As1, v092, 2
	.byte W36
	.byte As1, v092, 2 @ N32
	.byte W36
	.byte N22, Bn1, v088
	.byte W24
	.byte Gs1 @ N22, v088
	.byte W24
	.byte N32, As1, v088, 2
	.byte W36
	.byte As1, v084, 2 @ N32
	.byte W36
	.byte N22, Bn1, v080
	.byte W24
	.byte Gs1 @ N22, v080
	.byte W24
	.byte N32, As1, v080, 2
	.byte W36
	.byte As1, v076, 2 @ N32
	.byte W36
	.byte N22, Bn1 @ v076
	.byte W24
	.byte Gs1, v072 @ N22
	.byte W24
track_65_lbl_2242e4:
	.byte N32, As1, v120, 2
	.byte W36
	.byte As1, v120, 2 @ N32
	.byte W36
	.byte N22, Bn1 @ v120
	.byte W24
	.byte Gs1 @ N22, v120
	.byte W24
	.byte PEND
track_65_lbl_2242f3:
	.byte N32, As1, v100, 2
	.byte W36
	.byte As1, v100, 2 @ N32
	.byte W36
	.byte N22, Bn1 @ v100
	.byte W24
	.byte Gs1 @ N22, v100
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_2242f3
	.byte PATT
		.word track_65_lbl_2242f3
	.byte PATT
		.word track_65_lbl_224252
	.byte PATT
		.word track_65_lbl_224252
	.byte PATT
		.word track_65_lbl_224252
	.byte PATT
		.word track_65_lbl_224252
	.byte PATT
		.word track_65_lbl_22426b
	.byte PATT
		.word track_65_lbl_22427a
	.byte PATT
		.word track_65_lbl_224289
	.byte PATT
		.word track_65_lbl_224298
	.byte VOICE, 37
	.byte VOL, 81
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte N32, As1, v096, 2
	.byte W36
	.byte As1, v100, 2 @ N32
	.byte W36
	.byte N22, Bn1, v104
	.byte W24
	.byte Gs1, v108 @ N22
	.byte W24
	.byte N32, As1, v108, 2
	.byte W36
	.byte As1, v112, 2 @ N32
	.byte W36
	.byte N22, Bn1, v116
	.byte W24
	.byte Gs1, v120 @ N22
	.byte W24
	.byte PATT
		.word track_65_lbl_2242e4
	.byte N32, As1, v120, 2
	.byte W36
	.byte As1, v116, 2 @ N32
	.byte W36
	.byte N22, Bn1, v108
	.byte W24
	.byte Gs1, v104 @ N22
	.byte W24
	.byte PATT
		.word track_65_lbl_22426b
	.byte PATT
		.word track_65_lbl_22426b
	.byte N32, Gn1, v120, 2
	.byte W36
	.byte Gn1, v116, 2 @ N32
	.byte W36
	.byte N22, Gs1 @ v116
	.byte W24
	.byte Fn1, v112 @ N22
	.byte W24
	.byte N32, Gn1, v108, 2
	.byte W36
	.byte Gn1, v104, 2 @ N32
	.byte W36
	.byte N22, Gs1 @ v104
	.byte W24
	.byte Fn1, v100 @ N22
	.byte W24
	.byte VOICE, 5
	.byte VOL, 51
	.byte PAN, c_v
	.byte W12
	.byte N12, Fs3, v084
	.byte W12
	.byte An3 @ N12, v084
	.byte W12
	.byte Cn4 @ N12, v084
	.byte W12
	.byte Ds4 @ N12, v084
	.byte W12
	.byte Fs4 @ N12, v084
	.byte W12
	.byte N10, An4, v104
	.byte W10
	.byte Fs3 @ N10, v104
	.byte W10
	.byte An3 @ N10, v104
	.byte W10
	.byte Cn4 @ N10, v104
	.byte W10
	.byte Ds4 @ N10, v104
	.byte W10
	.byte Fs4 @ N10, v104
	.byte W10
	.byte An4 @ N10, v104
	.byte W12
	.byte An4, v096 @ N10
	.byte W10
	.byte Fs3 @ N10, v096
	.byte W10
	.byte An3 @ N10, v096
	.byte W10
	.byte Cn4 @ N10, v096
	.byte W10
	.byte Ds4 @ N10, v096
	.byte W10
	.byte Fs4 @ N10, v096
	.byte W10
	.byte An4 @ N10, v096
	.byte W12
	.byte An4, v084 @ N10
	.byte W10
	.byte Fs3 @ N10, v084
	.byte W10
	.byte An3 @ N10, v084
	.byte W10
	.byte Cn4 @ N10, v084
	.byte W10
	.byte Ds4 @ N10, v084
	.byte W10
	.byte Fs4 @ N10, v084
	.byte W10
	.byte An4 @ N10, v084
	.byte W12
	.byte W72
	.byte VOICE, 9
	.byte N48, An2, v100
	.byte W48
	.byte N24, An1, v120
	.byte W24
	.byte N48, Ds3, v100
	.byte W48
	.byte N24, Ds2, v120
	.byte W24
	.byte Fs2 @ N24, v120
	.byte W24
	.byte N24 @ Fs2, v120
	.byte W24
	.byte Fn2 @ N24, v120
	.byte W24
	.byte VOICE, 9
	.byte VOL, 51
	.byte PAN, c_v
	.byte W96
	.byte GOTO
		.word track_65_lbl_22423c
	.byte FINE

track_65_6:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 66
	.byte PAN, c_v
	.byte PRIO, 28
	.byte W96
track_65_lbl_22440b:
	.byte VOICE, 0
	.byte VOL, 81
	.byte PAN, c_v
	.byte W96
	.byte W24
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte En1, v092 @ N06
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte N18, Cs2, v072
	.byte W24
	.byte N06, Fs1, v052
	.byte W12
	.byte En1, v072 @ N06
	.byte W12
track_65_lbl_22442f:
	.byte N06, En1, v072
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W24
	.byte Fs1, v052 @ N06
	.byte W12
	.byte En1, v072 @ N06
	.byte W12
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v012
	.byte W12
	.byte En1, v092 @ N06
	.byte W12
	.byte Cs2, v052 @ N06
	.byte W12
	.byte PEND
track_65_lbl_22444e:
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte En1, v092 @ N06
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W24
	.byte Fs1, v052 @ N06
	.byte W24
	.byte PEND
track_65_lbl_224466:
	.byte N18, Cs2, v112
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v032 @ N06
	.byte W12
	.byte En1, v072 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte As1 @ N06, v020
	.byte W12
	.byte En1, v072 @ N06
	.byte W24
	.byte PEND
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOL, 66
	.byte N06, An1 @ v072
	.byte W24
	.byte Fs1, v020 @ N06
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v032 @ N06
	.byte W12
	.byte An1, v072 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte N18, Cs2, v040
	.byte W36
	.byte W96
	.byte W24
	.byte W84
	.byte N06, As1 @ v040
	.byte W24
	.byte Cs2, v052 @ N06
	.byte W12
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v040
	.byte W12
	.byte Fs1, v052 @ N06
	.byte W12
	.byte An1, v092 @ N06
	.byte W12
	.byte Fs1, v060 @ N06
	.byte W12
	.byte Fs1, v072 @ N06
	.byte W12
	.byte Cs2, v084 @ N06
	.byte W36
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 0
	.byte VOL, 66
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte En1, v092 @ N06
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte N18, Cs2, v072
	.byte W24
	.byte N06, Fs1, v052
	.byte W12
	.byte En1, v072 @ N06
	.byte W12
	.byte PATT
		.word track_65_lbl_22442f
	.byte PATT
		.word track_65_lbl_22444e
	.byte PATT
		.word track_65_lbl_224466
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte VOICE, 36
	.byte VOL, 74
	.byte N24, Ds5, v084
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 0
	.byte VOL, 66
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte An1, v092 @ N06
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte Cs2, v052 @ N06
	.byte W12
	.byte Fs1 @ N06, v052
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W72
	.byte Fs1, v020 @ N06
	.byte W24
	.byte Fs1, v052 @ N06
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 0
	.byte VOL, 66
	.byte PAN, c_v
	.byte W96
	.byte GOTO
		.word track_65_lbl_22440b
	.byte FINE

track_65_7:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte PAN, c_v+10
	.byte VOL, 66
	.byte PRIO, 27
	.byte N12, En1, v100
	.byte W36
	.byte En1, v080 @ N12
	.byte W24
	.byte Cs2, v127 @ N12
	.byte W12
	.byte Cn4 @ N12, v127
	.byte W24
track_65_lbl_224563:
	.byte VOICE, 0
	.byte PAN, c_v
	.byte VOL, 81
	.byte N06, En1, v072
	.byte N18, Cs2, v112
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v032 @ N06
	.byte W12
	.byte En1, v072 @ N06
	.byte N06, Fs1, v012
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N12, Cn4, v100
	.byte W12
	.byte N18, As1, v020
	.byte W12
	.byte N06, En1, v072
	.byte N06, Fs1, v052
	.byte W24
track_65_lbl_224591:
	.byte W36
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v032
	.byte W24
	.byte Fs1, v020 @ N06
	.byte N12, Cn4, v100
	.byte W48
	.byte PEND
track_65_lbl_2245a1:
	.byte N12, Cn4, v100
	.byte W84
	.byte N06, As1, v040
	.byte W24
	.byte N18, As1, v012
	.byte W12
	.byte PEND
track_65_lbl_2245ae:
	.byte W48
	.byte N06, Fs1, v032
	.byte W24
	.byte N12, Cn4, v100
	.byte W48
	.byte PEND
track_65_lbl_2245b8:
	.byte N06, En1, v072
	.byte N12, Cn4, v100
	.byte W60
	.byte N06, Fs1, v012
	.byte W12
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v052
	.byte W24
	.byte PEND
track_65_lbl_2245cc:
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, En1, v092
	.byte N06, Fs1, v032
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte N18, Cs2, v072
	.byte N12, Cn4, v100
	.byte W36
	.byte N06, En1, v072
	.byte W12
	.byte PEND
track_65_lbl_2245f0:
	.byte N06, En1, v072
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v012
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W24
	.byte Fs1, v052 @ N06
	.byte W12
	.byte En1, v072 @ N06
	.byte W12
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v012
	.byte N06, As1, v040
	.byte W12
	.byte En1, v092 @ N06
	.byte W12
	.byte N18, As1, v012
	.byte N06, Cs2, v052
	.byte W12
	.byte PEND
track_65_lbl_22461a:
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte En1, v092 @ N06
	.byte N06, Fs1, v032
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v052
	.byte W24
	.byte PEND
	.byte VOL, 66
	.byte N12, Cn4, v100
	.byte W36
	.byte N12 @ Cn4, v100
	.byte W24
	.byte N06, Fs1, v012
	.byte W24
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v052
	.byte W24
track_65_lbl_22464d:
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v032 @ N06
	.byte N06, An1, v092
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte N18, Cs2, v072
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v052
	.byte W12
	.byte An1, v072 @ N06
	.byte W12
	.byte PEND
	.byte N06 @ An1, v072
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v052
	.byte W12
	.byte An1, v072 @ N06
	.byte W24
	.byte Fs1, v012 @ N06
	.byte N12, Cn4, v100
	.byte W24
	.byte N18, As1, v012
	.byte N12, Cn4, v100
	.byte W12
	.byte PATT
		.word track_65_lbl_2245ae
	.byte N06, An1, v072
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v032
	.byte W12
	.byte Fs1, v012 @ N06
	.byte N06, An1, v072
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte N18, Cs2, v040
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v052
	.byte W24
	.byte PATT
		.word track_65_lbl_22464d
	.byte N06, An1, v072
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v052
	.byte W12
	.byte An1, v072 @ N06
	.byte W24
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Cs2, v052
	.byte N12, Cn4, v100
	.byte W12
	.byte N12 @ Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v032 @ N06
	.byte N06, An1, v092
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N12, Cn4, v100
	.byte W24
	.byte N06 @ Cn4, v100
	.byte W12
	.byte Cn4, v072 @ N06
	.byte W12
	.byte En1 @ N06, v072
	.byte N18, Cs2, v112
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v032 @ N06
	.byte W12
	.byte En1, v072 @ N06
	.byte N06, Fs1, v012
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N12, Cn4, v100
	.byte W12
	.byte N18, As1, v020
	.byte W12
	.byte N06, En1, v072
	.byte N06, Fs1, v052
	.byte W24
	.byte PATT
		.word track_65_lbl_224591
	.byte PATT
		.word track_65_lbl_2245a1
	.byte PATT
		.word track_65_lbl_2245ae
	.byte PATT
		.word track_65_lbl_2245b8
	.byte PATT
		.word track_65_lbl_2245cc
	.byte PATT
		.word track_65_lbl_2245f0
	.byte PATT
		.word track_65_lbl_22461a
	.byte N06, En1, v080
	.byte N06, Cs2, v112
	.byte N06, Cn4, v100
	.byte W24
	.byte Fs1, v032 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N06, Cn4, v100
	.byte W12
	.byte Fs1, v040 @ N06
	.byte W12
	.byte En1, v080 @ N06
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v032 @ N06
	.byte N06, Cs2, v060
	.byte W12
	.byte Cn4, v100 @ N06
	.byte W12
	.byte En1, v080 @ N06
	.byte N06, Cn4, v100
	.byte W24
	.byte Fs1, v032 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N06, Cn4, v100
	.byte W12
	.byte Fs1, v040 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N06, An1, v092
	.byte W12
	.byte Fs1, v032 @ N06
	.byte N12, Cs2, v060
	.byte W12
	.byte N06, Cn4, v100
	.byte W12
	.byte En1, v080 @ N06
	.byte N06, Cn4, v100
	.byte W24
	.byte Fs1, v032 @ N06
	.byte N11, An1, v100
	.byte W12
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v040 @ N06
	.byte N06, Cn4, v100
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N06, An1, v100
	.byte W12
	.byte Fs1, v032 @ N06
	.byte N12, Cs2, v060
	.byte W12
	.byte N06, Cn4, v100
	.byte W12
	.byte N12, Cs2, v112
	.byte W12
	.byte Cn4, v100 @ N12
	.byte W12
	.byte N06, Fs1, v032
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N11, Cs2, v092
	.byte W12
	.byte N06, Fs1, v040
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v020
	.byte N11, Cs2, v100
	.byte W12
	.byte N06, An1, v072
	.byte W24
	.byte Fs1, v020 @ N06
	.byte W12
	.byte Fs1, v012 @ N06
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v032
	.byte W12
	.byte Fs1, v012 @ N06
	.byte N06, An1, v072
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte N18, Cs2, v040
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v052
	.byte W24
	.byte PATT
		.word track_65_lbl_22464d
	.byte N06, An1, v072
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v020 @ N06
	.byte W12
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, Fs1, v052
	.byte W12
	.byte An1, v072 @ N06
	.byte W24
	.byte Fs1, v012 @ N06
	.byte N06, As1, v040
	.byte N12, Cn4, v100
	.byte W24
	.byte N18, As1, v012
	.byte N06, Cs2, v052
	.byte N12, Cn4, v100
	.byte W12
	.byte PATT
		.word track_65_lbl_2245ae
	.byte N18, Cs2, v112
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte Fs1, v032 @ N06
	.byte W12
	.byte En1, v072 @ N06
	.byte N06, Fs1, v012
	.byte W12
	.byte Fs1, v020 @ N06
	.byte N12, Cn4, v100
	.byte W12
	.byte N18, As1, v020
	.byte W12
	.byte N06, En1, v072
	.byte W24
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte N12, Cn4, v100
	.byte W12
	.byte N06, En1, v092
	.byte N06, Fs1, v032
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte N18, Cs2, v072
	.byte N12, Cn4, v100
	.byte W36
	.byte N06, En1, v072
	.byte W12
	.byte PATT
		.word track_65_lbl_2245f0
	.byte N12, Cn4, v100
	.byte W24
	.byte N06, Fs1, v020
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W12
	.byte En1, v092 @ N06
	.byte N06, Fs1, v032
	.byte W12
	.byte Fs1, v012 @ N06
	.byte W60
	.byte PAN, c_v+10
	.byte N12, Cn4, v120
	.byte W72
	.byte VOICE, 36
	.byte VOL, 74
	.byte N72, Cn4, v092
	.byte W72
	.byte Ds4 @ N72, v092
	.byte W72
	.byte Fs4 @ N72, v092
	.byte W72
	.byte An4, v060 @ N72
	.byte W72
	.byte Fs4 @ N72, v060
	.byte W72
	.byte An4 @ N72, v060
	.byte W72
	.byte Cn5, v080 @ N72
	.byte W72
	.byte VOICE, 0
	.byte PAN, c_v+10
	.byte VOL, 66
	.byte N12, En1, v100
	.byte W36
	.byte En1, v080 @ N12
	.byte W24
	.byte Cs2, v127 @ N12
	.byte W12
	.byte Cn4 @ N12, v127
	.byte W24
	.byte GOTO
		.word track_65_lbl_224563
	.byte FINE

track_65_8:
	.byte KEYSH, 0
	.byte VOICE, 36
	.byte PAN, c_v+16
	.byte VOL, 51
	.byte PRIO, 26
	.byte N36, Ds5, v092
	.byte W36
	.byte Fs5, v100 @ N36
	.byte W36
	.byte N24, An5, v112
	.byte W24
track_65_lbl_2248da:
	.byte PAN, c_v+16
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 4
	.byte VOL, 74
	.byte N05, Cn3, v060
	.byte W12
	.byte N05 @ Cn3, v060
	.byte W24
	.byte N05 @ Cn3, v060
	.byte W12
	.byte N05 @ Cn3, v060
	.byte W24
	.byte N05 @ Cn3, v060
	.byte W12
	.byte N05 @ Cn3, v060
	.byte W12
	.byte N05 @ Cn3, v060
	.byte W12
	.byte N05 @ Cn3, v060
	.byte W24
	.byte N05 @ Cn3, v060
	.byte W12
	.byte W12
	.byte Cn3, v064 @ N05
	.byte W24
	.byte Cn3, v068 @ N05
	.byte W12
	.byte Cn3, v072 @ N05
	.byte W24
	.byte Cn3, v076 @ N05
	.byte W12
	.byte Cn3, v080 @ N05
	.byte W24
	.byte Cn3, v084 @ N05
	.byte W24
	.byte Cn3, v088 @ N05
	.byte W12
	.byte W12
	.byte Cn3, v092 @ N05
	.byte W24
	.byte Cn3, v100 @ N05
	.byte W36
	.byte W24
	.byte N06, Fs3, v072
	.byte W08
	.byte Gn4 @ N06, v072
	.byte W08
	.byte Bn2, v080 @ N06
	.byte W08
	.byte Gn2 @ N06, v080
	.byte W08
	.byte Dn3 @ N06, v080
	.byte W08
	.byte As3 @ N06, v080
	.byte W08
	.byte An2 @ N06, v080
	.byte W08
	.byte Bn2 @ N06, v080
	.byte W08
	.byte Fn4 @ N06, v080
	.byte W08
	.byte Gn2 @ N06, v080
	.byte W08
	.byte Dn3 @ N06, v080
	.byte W08
	.byte Bn3 @ N06, v080
	.byte W32
	.byte W72
	.byte VOICE, 36
	.byte PAN, c_v+16
	.byte VOL, 51
	.byte N36, Ds5, v100
	.byte W36
	.byte Fs5 @ N36, v100
	.byte W36
	.byte N24, An5, v112
	.byte W24
	.byte GOTO
		.word track_65_lbl_2248da
	.byte FINE

track_65_9:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte PAN, c_v-14
	.byte VOL, 17
	.byte PRIO, 25
	.byte N84, Ds3, v112
	.byte N84, Fs3 @ v112
	.byte W02
	.byte VOL, 2
	.byte W03
	.byte 5 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W04
	.byte 17 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W04
	.byte 23 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W04
	.byte 42 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W04
	.byte 50 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W04
	.byte 56 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W04
	.byte 62 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W04
	.byte 68 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W02
	.byte 72 @ VOL
	.byte W13
track_65_lbl_2249cb:
	.byte PAN, c_v-14
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 36
	.byte VOL, 74
	.byte N72, Ds4, v092
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 6
	.byte VOL, 94
	.byte BENDR, 0
	.byte N96, Ds3, v032
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 6
	.byte PAN, c_v-14
	.byte VOL, 17
	.byte N84, Ds3, v112
	.byte N84, Fs3 @ v112
	.byte W02
	.byte VOL, 2
	.byte W03
	.byte 5 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W04
	.byte 17 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W04
	.byte 23 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W04
	.byte 42 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W04
	.byte 50 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W04
	.byte 56 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W04
	.byte 62 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W04
	.byte 68 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W02
	.byte 72 @ VOL
	.byte W13
	.byte GOTO
		.word track_65_lbl_2249cb
	.byte FINE

track_65_10:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 74
	.byte PAN, c_v
	.byte PRIO, 30
	.byte N36, Ds2, v100
	.byte W36
	.byte Fs2, v112 @ N36
	.byte W36
	.byte N24, An2 @ v112
	.byte W24
track_65_lbl_224a82:
	.byte VOICE, 8
	.byte VOL, 88
	.byte PAN, c_v
	.byte N16, Cn1, v120
	.byte W36
	.byte N16 @ Cn1, v120
	.byte W36
	.byte Cs1 @ N16, v120
	.byte W48
track_65_lbl_224a90:
	.byte N16, Cn1, v120
	.byte W36
	.byte N16 @ Cn1, v120
	.byte W36
	.byte Cs1 @ N16, v120
	.byte W48
	.byte PEND
	.byte PATT
		.word track_65_lbl_224a90
	.byte PATT
		.word track_65_lbl_224a90
track_65_lbl_224aa3:
	.byte N16, Cn1, v108
	.byte W36
	.byte N16 @ Cn1, v108
	.byte W36
	.byte Cs1 @ N16, v108
	.byte W48
	.byte PEND
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
track_65_lbl_224abb:
	.byte N12, Ds1, v108
	.byte W36
	.byte N12 @ Ds1, v108
	.byte W36
	.byte En1 @ N12, v108
	.byte W48
	.byte PEND
	.byte PATT
		.word track_65_lbl_224abb
	.byte PATT
		.word track_65_lbl_224abb
	.byte N12, Ds1, v100
	.byte W36
	.byte Ds1, v108 @ N12
	.byte W36
	.byte En1, v116 @ N12
	.byte W48
	.byte PATT
		.word track_65_lbl_224abb
	.byte PATT
		.word track_65_lbl_224abb
	.byte PATT
		.word track_65_lbl_224abb
	.byte PATT
		.word track_65_lbl_224abb
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
	.byte PATT
		.word track_65_lbl_224aa3
	.byte VOL, 88
	.byte N96, Fs0, v080
	.byte W96
	.byte Gn0 @ N96, v080
	.byte W96
	.byte Gs0, v084 @ N96
	.byte W96
	.byte N32, Fn2, v100, 2
	.byte W36
	.byte En2, v100, 2 @ N32
	.byte W36
	.byte PATT
		.word track_65_lbl_224abb
	.byte PATT
		.word track_65_lbl_224abb
	.byte PATT
		.word track_65_lbl_224abb
	.byte PATT
		.word track_65_lbl_224abb
track_65_lbl_224b3c:
	.byte N12, Cn1, v108
	.byte W36
	.byte N12 @ Cn1, v108
	.byte W36
	.byte Cs1 @ N12, v108
	.byte W48
	.byte PEND
	.byte PATT
		.word track_65_lbl_224b3c
	.byte PATT
		.word track_65_lbl_224b3c
	.byte PATT
		.word track_65_lbl_224b3c
	.byte VOL, 74
	.byte N72, Ds1, v112
	.byte W72
	.byte Cn1 @ N72, v112
	.byte W72
	.byte Ds1 @ N72, v112
	.byte W72
	.byte Fs1 @ N72, v112
	.byte W72
	.byte An1 @ N72, v112
	.byte W72
	.byte Fs1 @ N72, v112
	.byte W72
	.byte An1 @ N72, v112
	.byte W72
	.byte Cn2 @ N72, v112
	.byte W72
	.byte VOICE, 8
	.byte VOL, 74
	.byte PAN, c_v
	.byte N36, Ds2, v100
	.byte W36
	.byte Fs2 @ N36, v100
	.byte W36
	.byte N24, An2, v112
	.byte W24
	.byte GOTO
		.word track_65_lbl_224a82
	.byte FINE

track_65_11:
	.byte KEYSH, 0
	.byte VOICE, 16
	.byte VOL, 88
	.byte PAN, c_v
	.byte PRIO, 29
	.byte W96
track_65_lbl_224b89:
	.byte VOICE, 16
	.byte VOL, 88
	.byte PAN, c_v
	.byte N12, Cn1, v120
	.byte W12
	.byte Cn2, v112 @ N12
	.byte W48
	.byte Cn1 @ N12, v112
	.byte W24
	.byte Cs1 @ N12, v112
	.byte W12
	.byte As1 @ N12, v112
	.byte W24
track_65_lbl_224b9c:
	.byte N12, Cn1, v120
	.byte W12
	.byte Cn2, v112 @ N12
	.byte W48
	.byte Cn1 @ N12, v112
	.byte W24
	.byte Cs1 @ N12, v112
	.byte W12
	.byte As1 @ N12, v112
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_224b9c
	.byte PATT
		.word track_65_lbl_224b9c
	.byte PATT
		.word track_65_lbl_224b9c
	.byte PATT
		.word track_65_lbl_224b9c
	.byte PATT
		.word track_65_lbl_224b9c
	.byte PATT
		.word track_65_lbl_224b9c
track_65_lbl_224bc8:
	.byte N12, Ds1, v112
	.byte W12
	.byte N10, Ds2, v100
	.byte W48
	.byte Ds1 @ N10, v100
	.byte W24
	.byte En1 @ N10, v100
	.byte W12
	.byte Cs2 @ N10, v100
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_224bc8
	.byte PATT
		.word track_65_lbl_224bc8
track_65_lbl_224be1:
	.byte N12, Ds1, v100
	.byte W12
	.byte N10, Ds2, v104
	.byte W48
	.byte Ds1, v112 @ N10
	.byte W24
	.byte En1, v120 @ N10
	.byte W12
	.byte Cs2 @ N10, v120
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_224bc8
	.byte PATT
		.word track_65_lbl_224bc8
	.byte PATT
		.word track_65_lbl_224bc8
	.byte PATT
		.word track_65_lbl_224bc8
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
track_65_lbl_224c0e:
	.byte N12, Cn1, v112
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W48
	.byte Cn1 @ N12, v100
	.byte W24
	.byte Cs1 @ N12, v100
	.byte W12
	.byte As1 @ N12, v100
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_224c0e
	.byte PATT
		.word track_65_lbl_224c0e
	.byte PATT
		.word track_65_lbl_224c0e
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte PATT
		.word track_65_lbl_224bc8
	.byte PATT
		.word track_65_lbl_224bc8
	.byte PATT
		.word track_65_lbl_224bc8
	.byte PATT
		.word track_65_lbl_224be1
track_65_lbl_224c43:
	.byte N12, Cn1, v112
	.byte W12
	.byte N10, Cn2, v100
	.byte W48
	.byte Cn1 @ N10, v100
	.byte W24
	.byte Cs1 @ N10, v100
	.byte W12
	.byte As1 @ N10, v100
	.byte W24
	.byte PEND
	.byte PATT
		.word track_65_lbl_224c43
	.byte PATT
		.word track_65_lbl_224c43
	.byte PATT
		.word track_65_lbl_224c43
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 16
	.byte VOL, 88
	.byte PAN, c_v
	.byte W96
	.byte GOTO
		.word track_65_lbl_224b89
	.byte FINE

.align 2

track_65:
	.byte 12
	.byte 0
	.byte 130
	.byte 0
	.word voice_group22
	.word track_65_0
	.word track_65_1
	.word track_65_2
	.word track_65_3
	.word track_65_4
	.word track_65_5
	.word track_65_6
	.word track_65_7
	.word track_65_8
	.word track_65_9
	.word track_65_10
	.word track_65_11

.align 2
