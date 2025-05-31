.align 2

.global track_73

track_73_0:
	.byte KEYSH, 0
	.byte TEMPO, 70
	.byte VOICE, 75
	.byte VOL, 37
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N09, Cn1, v127
	.byte W12
	.byte As0, v112 @ N09
	.byte W12
	.byte Cn1, v127 @ N09
	.byte W12
	.byte As0, v112 @ N09
	.byte W12
	.byte Cn1, v127 @ N09
	.byte W12
	.byte As0, v112 @ N09
	.byte W12
	.byte Cn1 @ N09, v112
	.byte W12
	.byte Gs0 @ N09, v112
	.byte W12
track_73_lbl_2279fb:
	.byte N09, Cn1, v127
	.byte W12
	.byte As0, v112 @ N09
	.byte W12
	.byte Cn1, v127 @ N09
	.byte W12
	.byte As0, v112 @ N09
	.byte W12
	.byte Cn1, v127 @ N09
	.byte W12
	.byte As0, v112 @ N09
	.byte W12
	.byte Cn1 @ N09, v112
	.byte W12
	.byte Gs0 @ N09, v112
	.byte W12
	.byte PEND
	.byte PATT
		.word track_73_lbl_2279fb
	.byte PATT
		.word track_73_lbl_2279fb
	.byte PATT
		.word track_73_lbl_2279fb
	.byte PATT
		.word track_73_lbl_2279fb
	.byte PATT
		.word track_73_lbl_2279fb
	.byte PATT
		.word track_73_lbl_2279fb
	.byte N09, Cn1, v127
	.byte W12
	.byte As0, v112 @ N09
	.byte W12
	.byte Cn1, v124 @ N09
	.byte W12
	.byte As0, v108 @ N09
	.byte W12
	.byte Cn1, v120 @ N09
	.byte W12
	.byte As0, v104 @ N09
	.byte W12
	.byte Cn1, v100 @ N09
	.byte W12
	.byte Gs0 @ N09, v100
	.byte W12
	.byte Cn1, v108 @ N09
	.byte W12
	.byte As0, v092 @ N09
	.byte W12
	.byte Cn1, v104 @ N09
	.byte W12
	.byte As0, v088 @ N09
	.byte W12
	.byte Cn1, v100 @ N09
	.byte W12
	.byte As0, v084 @ N09
	.byte W12
	.byte Cn1 @ N09, v084
	.byte W12
	.byte Gs0, v080 @ N09
	.byte W12
track_73_lbl_227a60:
	.byte N09, Cn1, v100
	.byte W12
	.byte As0, v080 @ N09
	.byte W12
	.byte Cn1, v100 @ N09
	.byte W12
	.byte As0, v080 @ N09
	.byte W12
	.byte Cn1, v100 @ N09
	.byte W12
	.byte As0, v080 @ N09
	.byte W12
	.byte Cn1 @ N09, v080
	.byte W12
	.byte Gs0 @ N09, v080
	.byte W12
	.byte PEND
track_73_lbl_227a78:
	.byte N09, Cs1, v100
	.byte W12
	.byte Bn0, v080 @ N09
	.byte W12
	.byte Cs1, v100 @ N09
	.byte W12
	.byte Bn0, v080 @ N09
	.byte W12
	.byte Cs1, v100 @ N09
	.byte W12
	.byte Bn0, v080 @ N09
	.byte W12
	.byte Cs1 @ N09, v080
	.byte W12
	.byte An0 @ N09, v080
	.byte W12
	.byte PEND
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a78
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte PATT
		.word track_73_lbl_227a60
	.byte GOTO
		.word track_73_lbl_227a60
	.byte FINE

track_73_1:
	.byte KEYSH, 0
	.byte VOICE, 78
	.byte VOL, 75
	.byte PAN, c_v-10
	.byte PRIO, 119
	.byte N24, Cn2, v127
	.byte W36
	.byte Cn2, v092 @ N24
	.byte W60
track_73_lbl_227b15:
	.byte W12
	.byte N24, Cn2, v127
	.byte W36
	.byte N12, Cn2, v092
	.byte W12
	.byte N24 @ Cn2, v092
	.byte W36
	.byte PEND
track_73_lbl_227b21:
	.byte N24, Cn2, v127
	.byte W36
	.byte Cn2, v092 @ N24
	.byte W60
	.byte PEND
	.byte PATT
		.word track_73_lbl_227b15
	.byte N24, Cn2, v127
	.byte W96
	.byte W12
	.byte N24 @ Cn2, v127
	.byte W36
	.byte N12 @ Cn2, v127
	.byte W12
	.byte Cn2, v092 @ N12
	.byte W36
	.byte PATT
		.word track_73_lbl_227b21
	.byte PATT
		.word track_73_lbl_227b15
	.byte PATT
		.word track_73_lbl_227b21
	.byte W12
	.byte N24, Cn2, v100
	.byte W36
	.byte N12, Cn2, v064
	.byte W12
	.byte N24, Cn2, v060
	.byte W36
track_73_lbl_227b56:
	.byte N24, Cn2, v100
	.byte W96
track_73_lbl_227b5a:
	.byte W12
	.byte N24, Cs2, v100
	.byte W36
	.byte N12 @ Cs2, v100
	.byte W12
	.byte Cs2, v060 @ N12
	.byte W36
	.byte PEND
track_73_lbl_227b65:
	.byte N24, Cs2, v100
	.byte W36
	.byte Cs2, v060 @ N24
	.byte W60
	.byte PEND
track_73_lbl_227b6d:
	.byte W12
	.byte N24, Cs2, v100
	.byte W36
	.byte N12, Cs2, v060
	.byte W12
	.byte N24 @ Cs2, v060
	.byte W36
	.byte PEND
	.byte PATT
		.word track_73_lbl_227b65
	.byte PATT
		.word track_73_lbl_227b6d
	.byte N24, Cs2, v100
	.byte W96
	.byte PATT
		.word track_73_lbl_227b5a
	.byte PATT
		.word track_73_lbl_227b65
	.byte PATT
		.word track_73_lbl_227b6d
	.byte PATT
		.word track_73_lbl_227b65
	.byte PATT
		.word track_73_lbl_227b6d
	.byte N24, Cs2, v100
	.byte W96
	.byte PATT
		.word track_73_lbl_227b5a
track_73_lbl_227ba9:
	.byte N24, Cn2, v100
	.byte W36
	.byte Cn2, v060 @ N24
	.byte W60
	.byte PEND
track_73_lbl_227bb1:
	.byte W12
	.byte N24, Cn2, v100
	.byte W36
	.byte N12, Cn2, v060
	.byte W12
	.byte N24 @ Cn2, v060
	.byte W36
	.byte PEND
	.byte PATT
		.word track_73_lbl_227ba9
	.byte PATT
		.word track_73_lbl_227bb1
	.byte N24, Cn2, v100
	.byte W96
	.byte W12
	.byte N24 @ Cn2, v100
	.byte W36
	.byte N12 @ Cn2, v100
	.byte W12
	.byte Cn2, v060 @ N12
	.byte W36
	.byte PATT
		.word track_73_lbl_227ba9
	.byte PATT
		.word track_73_lbl_227bb1
	.byte PATT
		.word track_73_lbl_227ba9
	.byte PATT
		.word track_73_lbl_227bb1
	.byte GOTO
		.word track_73_lbl_227b56
	.byte FINE

track_73_2:
	.byte KEYSH, 0
	.byte VOICE, 77
	.byte VOL, 56
	.byte PAN, c_v
	.byte N06, Cn1, v127
	.byte W12
	.byte As0, v100 @ N06
	.byte W12
	.byte Cn1, v127 @ N06
	.byte W12
	.byte As0, v100 @ N06
	.byte W12
	.byte Cn1, v127 @ N06
	.byte W12
	.byte As0, v100 @ N06
	.byte W12
	.byte Cn1, v127 @ N06
	.byte W12
	.byte Gs0, v100 @ N06
	.byte W12
track_73_lbl_227c0e:
	.byte N06, Cn1, v127
	.byte W12
	.byte As0, v100 @ N06
	.byte W12
	.byte Cn1, v127 @ N06
	.byte W12
	.byte As0, v100 @ N06
	.byte W12
	.byte Cn1, v127 @ N06
	.byte W12
	.byte As0, v100 @ N06
	.byte W12
	.byte Cn1, v127 @ N06
	.byte W12
	.byte Gs0, v100 @ N06
	.byte W12
	.byte PEND
	.byte PATT
		.word track_73_lbl_227c0e
	.byte PATT
		.word track_73_lbl_227c0e
	.byte PATT
		.word track_73_lbl_227c0e
	.byte PATT
		.word track_73_lbl_227c0e
	.byte PATT
		.word track_73_lbl_227c0e
	.byte PATT
		.word track_73_lbl_227c0e
	.byte N06, Cn1, v127
	.byte W12
	.byte As0, v100 @ N06
	.byte W12
	.byte Cn1, v124 @ N06
	.byte W12
	.byte As0, v096 @ N06
	.byte W12
	.byte Cn1, v120 @ N06
	.byte W12
	.byte As0, v092 @ N06
	.byte W12
	.byte Cn1, v116 @ N06
	.byte W12
	.byte Gs0, v088 @ N06
	.byte W12
	.byte Cn1, v112 @ N06
	.byte W12
	.byte As0, v084 @ N06
	.byte W12
	.byte Cn1, v108 @ N06
	.byte W12
	.byte As0, v080 @ N06
	.byte W12
	.byte Cn1, v104 @ N06
	.byte W12
	.byte As0, v076 @ N06
	.byte W12
	.byte Cn1, v100 @ N06
	.byte W12
	.byte Gs0, v072 @ N06
	.byte W12
track_73_lbl_227c77:
	.byte N06, Cn1, v100
	.byte W12
	.byte As0, v072 @ N06
	.byte W12
	.byte Cn1, v100 @ N06
	.byte W12
	.byte As0, v072 @ N06
	.byte W12
	.byte Cn1, v100 @ N06
	.byte W12
	.byte As0, v072 @ N06
	.byte W12
	.byte Cn1, v100 @ N06
	.byte W12
	.byte Gs0, v072 @ N06
	.byte W12
	.byte PEND
track_73_lbl_227c91:
	.byte N06, Cs1, v100
	.byte W12
	.byte Bn0, v072 @ N06
	.byte W12
	.byte Cs1, v100 @ N06
	.byte W12
	.byte Bn0, v072 @ N06
	.byte W12
	.byte Cs1, v100 @ N06
	.byte W12
	.byte Bn0, v072 @ N06
	.byte W12
	.byte Cs1, v100 @ N06
	.byte W12
	.byte An0, v072 @ N06
	.byte W12
	.byte PEND
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c91
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte PATT
		.word track_73_lbl_227c77
	.byte GOTO
		.word track_73_lbl_227c77
	.byte FINE

.align 2

track_73:
	.byte 3
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_73_0
	.word track_73_1
	.word track_73_2

.align 2
