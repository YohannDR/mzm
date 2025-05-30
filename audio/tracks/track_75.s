.align 2

.global track_75

track_75_0:
	.byte KEYSH, 0
	.byte TEMPO, 95
	.byte VOICE, 11
	.byte VOL, 75
	.byte PRIO, 120
	.byte PAN, c_v
	.byte N12, Cn2, v120
	.byte W36
	.byte N36, Bn2 @ v120
	.byte W60
	.byte N06, As2 @ v120
	.byte W24
	.byte En2 @ N06, v120
	.byte W24
	.byte An2 @ N06, v120
	.byte W24
	.byte Cn2 @ N06, v120
	.byte W12
	.byte N12, Cs2, v127
	.byte W36
	.byte N36, Bn2, v100
	.byte W60
	.byte N06, As2, v120
	.byte W24
	.byte En2 @ N06, v120
	.byte W24
	.byte An2 @ N06, v120
	.byte W24
	.byte Cs2 @ N06, v120
	.byte W12
	.byte N12, Dn2 @ v120
	.byte W36
	.byte N36, Cn3 @ v120
	.byte W60
	.byte N06, Bn2 @ v120
	.byte W24
	.byte Fn2 @ N06, v120
	.byte W24
	.byte As2 @ N06, v120
	.byte W24
	.byte Dn2 @ N06, v120
	.byte W12
	.byte Ds2 @ N06, v120
	.byte W36
	.byte N36, Cs3, v127
	.byte W60
track_75_lbl_227ea3:
	.byte N06, Cn3, v120
	.byte W24
	.byte Fs2 @ N06, v120
	.byte W24
	.byte Bn2, v127 @ N06
	.byte W24
	.byte Ds2, v112 @ N06
	.byte W12
	.byte PEND
	.byte VOICE, 11
	.byte VOL, 75
	.byte N12, Cn2, v120
	.byte W36
	.byte N36, Bn2 @ v120
	.byte W60
	.byte N06, As2, v092
	.byte W24
	.byte En2 @ N06, v092
	.byte W24
	.byte An2 @ N06, v092
	.byte W24
	.byte Cn2 @ N06, v092
	.byte W12
	.byte N12, Cs2, v120
	.byte W36
	.byte N36, Bn2, v112
	.byte W60
	.byte N06, As2, v100
	.byte W24
	.byte En2 @ N06, v100
	.byte W24
	.byte An2 @ N06, v100
	.byte W24
	.byte Cs2 @ N06, v100
	.byte W12
	.byte N12, Dn2, v108
	.byte W36
	.byte N36, Cn3, v120
	.byte W60
	.byte N06, Bn2, v100
	.byte W24
	.byte Fn2 @ N06, v100
	.byte W24
	.byte As2 @ N06, v100
	.byte W24
	.byte Dn2 @ N06, v100
	.byte W12
	.byte Ds2, v108 @ N06
	.byte W36
	.byte N36, Cs3, v127
	.byte W60
	.byte PATT
		.word track_75_lbl_227ea3
	.byte VOICE, 14
	.byte VOL, 62
	.byte N12, As4, v080
	.byte W12
	.byte N10, An4, v064
	.byte W36
	.byte N12, Dn4, v040
	.byte W12
	.byte N10, Cs4, v032
	.byte W36
	.byte N12, Cs3, v056
	.byte W36
	.byte Dn3, v072 @ N12
	.byte W36
	.byte Ds3, v096 @ N12
	.byte W24
	.byte N09, En3, v100
	.byte W24
	.byte N12, Ds3, v036
	.byte W12
	.byte En3, v052 @ N12
	.byte W12
	.byte Fn3, v076 @ N12
	.byte W12
	.byte Fs3, v092 @ N12
	.byte W12
	.byte Fn3, v060 @ N12
	.byte W12
	.byte En3, v040 @ N12
	.byte W12
	.byte W96
	.byte W96
	.byte VOICE, 11
	.byte VOL, 35
	.byte TIE, Ds2, v120
	.byte W13
	.byte VOL, 37
	.byte W12
	.byte 40 @ VOL
	.byte W11
	.byte 42 @ VOL
	.byte W11
	.byte 45 @ VOL
	.byte W12
	.byte 47 @ VOL
	.byte W11
	.byte 50 @ VOL
	.byte W11
	.byte 52 @ VOL
	.byte W11
	.byte 55 @ VOL
	.byte W04
	.byte W08
	.byte 57 @ VOL
	.byte W11
	.byte 60 @ VOL
	.byte W11
	.byte 62 @ VOL
	.byte W11
	.byte 65 @ VOL
	.byte W12
	.byte 68 @ VOL
	.byte W11
	.byte 70 @ VOL
	.byte W11
	.byte 73 @ VOL
	.byte W12
	.byte 75 @ VOL
	.byte W03
	.byte EOT @ Ds2, v120
	.byte W05
	.byte VOL, 77
	.byte W01
	.byte TIE, Ds2, v100
	.byte W96
	.byte W12
	.byte EOT @ Ds2, v100
	.byte N12, Gn2, v060
	.byte W12
	.byte An2 @ N12, v060
	.byte W12
	.byte Bn2 @ N12, v060
	.byte W12
	.byte N54, Ds2, v080
	.byte W48
	.byte W12
	.byte N12, Gn2, v112
	.byte W12
	.byte An2 @ N12, v112
	.byte W12
	.byte Bn2 @ N12, v112
	.byte W12
	.byte N54, Ds2 @ v112
	.byte W48
	.byte W12
	.byte N12, Gn2, v127
	.byte W12
	.byte An2 @ N12, v127
	.byte W12
	.byte Bn2 @ N12, v127
	.byte W12
	.byte N48, Ds2 @ v127
	.byte W48
	.byte VOICE, 11
	.byte VOL, 75
	.byte PAN, c_v
	.byte N12, Cn2, v120
	.byte W36
	.byte N36, Bn2 @ v120
	.byte W60
	.byte N06, As2, v080
	.byte W24
	.byte En2 @ N06, v080
	.byte W24
	.byte An2 @ N06, v080
	.byte W24
	.byte Cn2 @ N06, v080
	.byte W12
	.byte N12, Cs2, v127
	.byte W12
	.byte W24
	.byte N36, Bn2, v100
	.byte W60
	.byte N06, As2, v092
	.byte W24
	.byte En2 @ N06, v092
	.byte W24
	.byte An2 @ N06, v092
	.byte W24
	.byte Cs2 @ N06, v092
	.byte W12
	.byte N12, Dn2, v100
	.byte W12
	.byte W24
	.byte N36, Cn3, v120
	.byte W60
	.byte N06, Bn2, v100
	.byte W24
	.byte Fn2 @ N06, v100
	.byte W24
	.byte As2 @ N06, v100
	.byte W24
	.byte Dn2 @ N06, v100
	.byte W12
	.byte Ds2, v108 @ N06
	.byte W12
	.byte W24
	.byte N36, Cs3, v127
	.byte W60
	.byte GOTO
		.word track_75_lbl_227ea3
	.byte FINE

track_75_1:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 75
	.byte PRIO, 119
	.byte PAN, c_v-34
	.byte N24, Cn2, v108
	.byte W36
	.byte Cn2, v112 @ N24
	.byte W36
	.byte N24 @ Cn2, v112
	.byte W24
	.byte W24
	.byte N24 @ Cn2, v112
	.byte W36
	.byte N24 @ Cn2, v112
	.byte W24
track_75_lbl_227fe8:
	.byte N24, Cs2, v112
	.byte W36
	.byte N24 @ Cs2, v112
	.byte W36
	.byte N24 @ Cs2, v112
	.byte W24
	.byte PEND
track_75_lbl_227ff1:
	.byte W24
	.byte N24, Cs2, v112
	.byte W36
	.byte N24 @ Cs2, v112
	.byte W24
	.byte PEND
track_75_lbl_227ff9:
	.byte N24, Dn2, v112
	.byte W36
	.byte N24 @ Dn2, v112
	.byte W36
	.byte N24 @ Dn2, v112
	.byte W24
	.byte PEND
track_75_lbl_228002:
	.byte W24
	.byte N24, Dn2, v112
	.byte W24
	.byte N24 @ Dn2, v112
	.byte W36
	.byte PEND
track_75_lbl_22800a:
	.byte N24, Ds2, v112
	.byte W36
	.byte N24 @ Ds2, v112
	.byte W36
	.byte N24 @ Ds2, v112
	.byte W24
	.byte PEND
track_75_lbl_228013:
	.byte W24
	.byte N12, Ds2, v112
	.byte W24
	.byte N10 @ Ds2, v112
	.byte W12
	.byte N10 @ Ds2, v112
	.byte W24
	.byte PEND
	.byte VOICE, 13
	.byte N24, Cn2, v108
	.byte W36
	.byte Cn2, v112 @ N24
	.byte W36
	.byte N24 @ Cn2, v112
	.byte W24
	.byte W24
	.byte N24 @ Cn2, v112
	.byte W36
	.byte N24 @ Cn2, v112
	.byte W24
	.byte PATT
		.word track_75_lbl_227fe8
	.byte PATT
		.word track_75_lbl_227ff1
	.byte PATT
		.word track_75_lbl_227ff9
	.byte PATT
		.word track_75_lbl_228002
	.byte PATT
		.word track_75_lbl_22800a
	.byte PATT
		.word track_75_lbl_228013
	.byte W24
	.byte N10, Cn2, v120
	.byte W12
	.byte Cn1 @ N10, v120
	.byte W36
	.byte Cn2 @ N10, v120
	.byte W12
	.byte Cn1 @ N10, v120
	.byte W12
	.byte Cn1, v100 @ N10
	.byte W12
	.byte N10 @ Cn1, v100
	.byte W12
	.byte Cn1, v112 @ N10
	.byte W12
	.byte N10 @ Cn1, v112
	.byte W12
	.byte Cn1, v120 @ N10
	.byte W12
	.byte N10 @ Cn1, v120
	.byte W12
	.byte N10 @ Cn1, v120
	.byte W12
	.byte N10 @ Cn1, v120
	.byte W12
	.byte N10 @ Cn1, v120
	.byte W24
	.byte W72
track_75_lbl_22806c:
	.byte N36, Ds1, v092
	.byte W36
	.byte N48, An1 @ v092
	.byte W60
	.byte PEND
	.byte PATT
		.word track_75_lbl_22806c
track_75_lbl_228079:
	.byte N36, Ds1, v096
	.byte W36
	.byte N48, An1 @ v096
	.byte W60
	.byte PEND
	.byte PATT
		.word track_75_lbl_228079
track_75_lbl_228086:
	.byte N36, Ds1, v108
	.byte W36
	.byte N48, An1 @ v108
	.byte W60
	.byte PEND
	.byte PATT
		.word track_75_lbl_228086
	.byte N36, Ds1, v112
	.byte W36
	.byte N48, An1 @ v112
	.byte W60
	.byte N36, Ds1, v120
	.byte W36
	.byte N24, An1 @ v120
	.byte W24
	.byte N12, Bn2, v100
	.byte W12
	.byte Cn3 @ N12, v100
	.byte W12
	.byte Cs3 @ N12, v100
	.byte W12
	.byte VOICE, 13
	.byte VOL, 75
	.byte PAN, c_v-34
	.byte N24, Cn2, v108
	.byte W36
	.byte Cn2, v112 @ N24
	.byte W36
	.byte N24 @ Cn2, v112
	.byte W24
	.byte W24
	.byte N24 @ Cn2, v112
	.byte W36
	.byte N24 @ Cn2, v112
	.byte W24
	.byte Cs2 @ N24, v112
	.byte W12
	.byte W24
	.byte N24 @ Cs2, v112
	.byte W36
	.byte N24 @ Cs2, v112
	.byte W24
	.byte W24
	.byte N24 @ Cs2, v112
	.byte W36
	.byte N24 @ Cs2, v112
	.byte W24
	.byte Dn2 @ N24, v112
	.byte W12
	.byte W24
	.byte N24 @ Dn2, v112
	.byte W36
	.byte N24 @ Dn2, v112
	.byte W24
	.byte W24
	.byte N24 @ Dn2, v112
	.byte W24
	.byte N24 @ Dn2, v112
	.byte W36
	.byte Ds2 @ N24, v112
	.byte W12
	.byte W24
	.byte N24 @ Ds2, v112
	.byte W36
	.byte N24 @ Ds2, v112
	.byte W24
	.byte GOTO
		.word track_75_lbl_228013
	.byte FINE

track_75_2:
	.byte KEYSH, 0
	.byte VOL, 75
	.byte PAN, c_v-10
	.byte PRIO, 118
	.byte N12, Gn2, v100
	.byte W36
	.byte Gn2, v072 @ N12
	.byte W36
	.byte N12 @ Gn2, v072
	.byte W24
	.byte W24
	.byte Gn2, v100 @ N12
	.byte W36
	.byte Gn2, v060 @ N12
	.byte W24
	.byte Gs2, v100 @ N12
	.byte W36
	.byte Gs2, v080 @ N12
	.byte W36
	.byte N12 @ Gs2, v080
	.byte W24
	.byte W24
	.byte Gs2, v100 @ N12
	.byte W36
	.byte Gs2, v060 @ N12
	.byte W24
	.byte An2, v100 @ N12
	.byte W36
	.byte An2, v072 @ N12
	.byte W36
	.byte N12 @ An2, v072
	.byte W24
	.byte W24
	.byte An2, v100 @ N12
	.byte W36
	.byte N12 @ An2, v100
	.byte W24
	.byte As2 @ N12, v100
	.byte W36
	.byte N12 @ As2, v100
	.byte W36
	.byte N12 @ As2, v100
	.byte W24
track_75_lbl_22811d:
	.byte W24
	.byte N12, As2, v100
	.byte W36
	.byte As2, v060 @ N12
	.byte W24
	.byte VOICE, 11
	.byte N12, Gn2, v092
	.byte W36
	.byte Gn2, v060 @ N12
	.byte W36
	.byte N12 @ Gn2, v060
	.byte W24
	.byte W24
	.byte Gn2, v092 @ N12
	.byte W36
	.byte Gn2, v052 @ N12
	.byte W24
	.byte Gs2, v092 @ N12
	.byte W36
	.byte Gs2, v072 @ N12
	.byte W36
	.byte N12 @ Gs2, v072
	.byte W24
	.byte W24
	.byte Gs2, v092 @ N12
	.byte W36
	.byte Gs2, v052 @ N12
	.byte W24
	.byte An2, v092 @ N12
	.byte W36
	.byte An2, v060 @ N12
	.byte W36
	.byte N12 @ An2, v060
	.byte W24
	.byte W24
	.byte An2, v092 @ N12
	.byte W36
	.byte N12 @ An2, v092
	.byte W24
	.byte As2, v112 @ N12
	.byte W36
	.byte N12 @ As2, v112
	.byte W36
	.byte N12 @ As2, v112
	.byte W24
	.byte W24
	.byte N12 @ As2, v112
	.byte W36
	.byte As2, v072 @ N12
	.byte W24
	.byte VOICE, 11
	.byte BENDR, 20
	.byte VOL, 71
	.byte BEND, c_v
	.byte N90, As2, v112
	.byte W24
	.byte BEND, c_v-1
	.byte W01
	.byte c_v-2 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W03
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W03
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W02
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-18 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-20 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W02
	.byte c_v-26 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-30 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-38 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-44 @ BEND
	.byte W01
	.byte c_v-45 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-51 @ BEND
	.byte W01
	.byte c_v-52 @ BEND
	.byte W01
	.byte c_v-54 @ BEND
	.byte W01
	.byte c_v-56 @ BEND
	.byte W01
	.byte c_v-58 @ BEND
	.byte W01
	.byte c_v-60 @ BEND
	.byte W01
	.byte c_v-62 @ BEND
	.byte W09
	.byte W72
	.byte W24
	.byte c_v @ BEND
	.byte W24
	.byte W72
	.byte VOICE, 15
	.byte VOL, 18
	.byte TIE, Ds3, v080
	.byte W96
	.byte W36
	.byte W01
	.byte VOL, 15
	.byte W36
	.byte 13 @ VOL
	.byte W23
	.byte EOT @ Ds3, v080
	.byte TIE, En3 @ v080
	.byte W01
	.byte VOL, 11
	.byte W92
	.byte W03
	.byte W68
	.byte 13 @ VOL
	.byte W28
	.byte EOT @ En3, v080
	.byte TIE, Fn3 @ v080
	.byte W30
	.byte VOL, 16
	.byte W44
	.byte W01
	.byte 18 @ VOL
	.byte W21
	.byte W02
	.byte 21 @ VOL
	.byte W19
	.byte 23 @ VOL
	.byte W15
	.byte 26 @ VOL
	.byte W13
	.byte 28 @ VOL
	.byte W09
	.byte 31 @ VOL
	.byte W09
	.byte 34 @ VOL
	.byte W08
	.byte 36 @ VOL
	.byte W07
	.byte 39 @ VOL
	.byte W05
	.byte 41 @ VOL
	.byte W05
	.byte 44 @ VOL
	.byte W04
	.byte EOT @ Fn3, v080
	.byte TIE, Fs3, v064
	.byte W02
	.byte VOL, 46
	.byte W12
	.byte 49 @ VOL
	.byte W17
	.byte 51 @ VOL
	.byte W16
	.byte 54 @ VOL
	.byte W17
	.byte 56 @ VOL
	.byte W17
	.byte 59 @ VOL
	.byte W12
	.byte 61 @ VOL
	.byte W03
	.byte W54
	.byte EOT @ Fs3, v064
	.byte W06
	.byte VOICE, 11
	.byte VOL, 52
	.byte N12, Gn3, v127
	.byte W12
	.byte Gs3 @ N12, v127
	.byte W12
	.byte An3 @ N12, v127
	.byte W12
	.byte VOL, 75
	.byte N12, Gn2, v100
	.byte W36
	.byte Gn2, v072 @ N12
	.byte W36
	.byte N12 @ Gn2, v072
	.byte W24
	.byte W24
	.byte Gn2, v100 @ N12
	.byte W36
	.byte Gn2, v060 @ N12
	.byte W24
	.byte Gs2, v100 @ N12
	.byte W12
	.byte W24
	.byte Gs2, v080 @ N12
	.byte W36
	.byte N12 @ Gs2, v080
	.byte W24
	.byte W24
	.byte Gs2, v100 @ N12
	.byte W36
	.byte Gs2, v060 @ N12
	.byte W24
	.byte An2, v100 @ N12
	.byte W12
	.byte W24
	.byte An2, v072 @ N12
	.byte W36
	.byte N12 @ An2, v072
	.byte W24
	.byte W24
	.byte An2, v100 @ N12
	.byte W36
	.byte N12 @ An2, v100
	.byte W24
	.byte As2 @ N12, v100
	.byte W12
	.byte W24
	.byte N12 @ As2, v100
	.byte W36
	.byte N12 @ As2, v100
	.byte W24
	.byte GOTO
		.word track_75_lbl_22811d
	.byte FINE

track_75_3:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte PRIO, 30
	.byte VOL, 75
	.byte PAN, c_v+36
	.byte N12, Cn1, v112
	.byte W36
	.byte N12 @ Cn1, v112
	.byte W36
	.byte N12 @ Cn1, v112
	.byte W24
	.byte W24
	.byte N12 @ Cn1, v112
	.byte W36
	.byte N12 @ Cn1, v112
	.byte W24
	.byte Cs1 @ N12, v112
	.byte W36
	.byte N12 @ Cs1, v112
	.byte W36
	.byte N12 @ Cs1, v112
	.byte W24
	.byte W24
	.byte N12 @ Cs1, v112
	.byte W36
	.byte N12 @ Cs1, v112
	.byte W24
	.byte Dn1 @ N12, v112
	.byte W36
	.byte N12 @ Dn1, v112
	.byte W36
	.byte N12 @ Dn1, v112
	.byte W24
	.byte W24
	.byte N12 @ Dn1, v112
	.byte W24
	.byte N12 @ Dn1, v112
	.byte W36
	.byte Ds1 @ N12, v112
	.byte W36
	.byte N12 @ Ds1, v112
	.byte W36
	.byte N12 @ Ds1, v112
	.byte W24
track_75_lbl_2282a4:
	.byte W24
	.byte N12, Ds1, v112
	.byte W24
	.byte N10, Ds1, v100
	.byte W12
	.byte N10 @ Ds1, v100
	.byte W24
	.byte N12, Cn1 @ v100
	.byte W36
	.byte N12 @ Cn1, v100
	.byte W36
	.byte N12 @ Cn1, v100
	.byte W24
	.byte W24
	.byte N12 @ Cn1, v100
	.byte W36
	.byte N12 @ Cn1, v100
	.byte W24
	.byte Cs1 @ N12, v100
	.byte W36
	.byte N12 @ Cs1, v100
	.byte W36
	.byte N12 @ Cs1, v100
	.byte W24
	.byte W24
	.byte N12 @ Cs1, v100
	.byte W36
	.byte N12 @ Cs1, v100
	.byte W24
	.byte Dn1 @ N12, v100
	.byte W36
	.byte N12 @ Dn1, v100
	.byte W36
	.byte N12 @ Dn1, v100
	.byte W24
	.byte W24
	.byte N12 @ Dn1, v100
	.byte W24
	.byte N12 @ Dn1, v100
	.byte W36
	.byte Ds1 @ N12, v100
	.byte W36
	.byte N12 @ Ds1, v100
	.byte W36
	.byte N12 @ Ds1, v100
	.byte W24
	.byte W24
	.byte N12 @ Ds1, v100
	.byte W24
	.byte N10, Ds1, v092
	.byte W12
	.byte N10 @ Ds1, v092
	.byte W24
	.byte VOICE, 14
	.byte N12, En4, v080
	.byte W12
	.byte N10, Ds4 @ v080
	.byte W36
	.byte N12, Gs3, v056
	.byte W12
	.byte N10, Gn3, v044
	.byte W36
	.byte N12, Gn2, v056
	.byte W36
	.byte Gs2, v072 @ N12
	.byte W36
	.byte An2, v096 @ N12
	.byte W24
	.byte N09, As2 @ v096
	.byte W24
	.byte N12, An2, v040
	.byte W12
	.byte As2, v056 @ N12
	.byte W12
	.byte Bn2, v072 @ N12
	.byte W12
	.byte Cn3, v088 @ N12
	.byte W12
	.byte Bn2, v064 @ N12
	.byte W12
	.byte As2, v040 @ N12
	.byte W12
	.byte VOICE, 15
	.byte VOL, 18
	.byte TIE, Gn2, v072
	.byte W96
	.byte W09
	.byte VOL, 17
	.byte W36
	.byte W01
	.byte 15 @ VOL
	.byte W36
	.byte W01
	.byte 12 @ VOL
	.byte W13
	.byte EOT @ Gn2, v072
	.byte TIE, Gs2 @ v072
	.byte W01
	.byte VOL, 11
	.byte W92
	.byte W03
	.byte W24
	.byte W02
	.byte 12 @ VOL
	.byte W68
	.byte W02
	.byte EOT @ Gs2, v072
	.byte TIE, An2 @ v072
	.byte W03
	.byte VOL, 15
	.byte W48
	.byte 17 @ VOL
	.byte W36
	.byte W02
	.byte 20 @ VOL
	.byte W07
	.byte W12
	.byte 22 @ VOL
	.byte W17
	.byte 25 @ VOL
	.byte W13
	.byte 27 @ VOL
	.byte W12
	.byte 30 @ VOL
	.byte W09
	.byte 32 @ VOL
	.byte W08
	.byte 35 @ VOL
	.byte W07
	.byte 37 @ VOL
	.byte W07
	.byte 40 @ VOL
	.byte W04
	.byte 42 @ VOL
	.byte W06
	.byte 45 @ VOL
	.byte W01
	.byte EOT @ An2, v072
	.byte TIE, As2, v064
	.byte W06
	.byte VOL, 47
	.byte W16
	.byte 50 @ VOL
	.byte W17
	.byte 52 @ VOL
	.byte W17
	.byte 55 @ VOL
	.byte W16
	.byte 57 @ VOL
	.byte W21
	.byte 61 @ VOL
	.byte W03
	.byte W54
	.byte EOT @ As2, v064
	.byte W42
	.byte VOICE, 13
	.byte VOL, 75
	.byte PAN, c_v+36
	.byte N12, Cn1, v100
	.byte W36
	.byte N12 @ Cn1, v100
	.byte W36
	.byte N12 @ Cn1, v100
	.byte W24
	.byte W24
	.byte N12 @ Cn1, v100
	.byte W36
	.byte N12 @ Cn1, v100
	.byte W24
	.byte Cs1 @ N12, v100
	.byte W12
	.byte W24
	.byte N12 @ Cs1, v100
	.byte W36
	.byte N12 @ Cs1, v100
	.byte W24
	.byte W24
	.byte N12 @ Cs1, v100
	.byte W36
	.byte N12 @ Cs1, v100
	.byte W24
	.byte Dn1 @ N12, v100
	.byte W12
	.byte W24
	.byte N12 @ Dn1, v100
	.byte W36
	.byte N12 @ Dn1, v100
	.byte W24
	.byte W24
	.byte N12 @ Dn1, v100
	.byte W24
	.byte N12 @ Dn1, v100
	.byte W36
	.byte Ds1 @ N12, v100
	.byte W12
	.byte W24
	.byte N12 @ Ds1, v100
	.byte W36
	.byte N12 @ Ds1, v100
	.byte W24
	.byte GOTO
		.word track_75_lbl_2282a4
	.byte FINE

track_75_4:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 75
	.byte PAN, c_v+10
	.byte PRIO, 29
	.byte N12, Fn2, v092
	.byte N12, Cs3 @ v092
	.byte W36
	.byte Fn2, v060 @ N12
	.byte N12, Cs3 @ v060
	.byte W36
	.byte Fn2 @ N12, v060
	.byte N12, Cs3 @ v060
	.byte W24
	.byte W24
	.byte Fn2, v092 @ N12
	.byte N12, Cs3 @ v092
	.byte W36
	.byte Fn2, v052 @ N12
	.byte N12, Cs3 @ v052
	.byte W24
	.byte Fs2, v092 @ N12
	.byte N12, Dn3 @ v092
	.byte W36
	.byte Fs2, v072 @ N12
	.byte N12, Dn3 @ v072
	.byte W36
	.byte Fs2 @ N12, v072
	.byte N12, Dn3 @ v072
	.byte W24
	.byte W24
	.byte Fs2, v092 @ N12
	.byte N12, Dn3 @ v092
	.byte W36
	.byte Fs2, v052 @ N12
	.byte N12, Dn3 @ v052
	.byte W24
	.byte Gn2, v092 @ N12
	.byte N12, Ds3 @ v092
	.byte W36
	.byte Gn2, v060 @ N12
	.byte N12, Ds3 @ v060
	.byte W36
	.byte Gn2 @ N12, v060
	.byte N12, Ds3 @ v060
	.byte W24
	.byte W24
	.byte Gn2, v092 @ N12
	.byte N12, Ds3 @ v092
	.byte W36
	.byte Gn2 @ N12, v092
	.byte N12, Ds3 @ v092
	.byte W24
	.byte Gs2 @ N12, v092
	.byte N12, En3 @ v092
	.byte W36
	.byte Gs2 @ N12, v092
	.byte N12, En3 @ v092
	.byte W36
	.byte Gs2 @ N12, v092
	.byte N12, En3 @ v092
	.byte W24
track_75_lbl_2283ff:
	.byte W24
	.byte N12, Gs2, v092
	.byte N12, En3 @ v092
	.byte W36
	.byte Gs2, v052 @ N12
	.byte N12, En3 @ v052
	.byte W24
	.byte VOICE, 11
	.byte N12, Fn2, v080
	.byte N12, Cs3 @ v080
	.byte W36
	.byte Fn2, v052 @ N12
	.byte N12, Cs3 @ v052
	.byte W36
	.byte Fn2 @ N12, v052
	.byte N12, Cs3 @ v052
	.byte W24
	.byte W24
	.byte Fn2, v080 @ N12
	.byte N12, Cs3 @ v080
	.byte W36
	.byte Fn2, v040 @ N12
	.byte N12, Cs3 @ v040
	.byte W24
	.byte Fs2, v080 @ N12
	.byte N12, Dn3 @ v080
	.byte W36
	.byte Fs2, v060 @ N12
	.byte N12, Dn3 @ v060
	.byte W36
	.byte Fs2 @ N12, v060
	.byte N12, Dn3 @ v060
	.byte W24
	.byte W24
	.byte Fs2, v080 @ N12
	.byte N12, Dn3 @ v080
	.byte W36
	.byte Fs2, v040 @ N12
	.byte N12, Dn3 @ v040
	.byte W24
	.byte Gn2, v080 @ N12
	.byte N12, Ds3 @ v080
	.byte W36
	.byte Gn2, v052 @ N12
	.byte N12, Ds3 @ v052
	.byte W36
	.byte Gn2 @ N12, v052
	.byte N12, Ds3 @ v052
	.byte W24
	.byte W24
	.byte Gn2, v080 @ N12
	.byte N12, Ds3 @ v080
	.byte W36
	.byte Gn2 @ N12, v080
	.byte N12, Ds3 @ v080
	.byte W24
	.byte Gs2 @ N12, v080
	.byte N12, En3 @ v080
	.byte W36
	.byte Gs2 @ N12, v080
	.byte N12, En3 @ v080
	.byte W36
	.byte Gs2 @ N12, v080
	.byte N12, En3 @ v080
	.byte W24
	.byte W24
	.byte Gs2 @ N12, v080
	.byte N12, En3 @ v080
	.byte W36
	.byte Gs2, v040 @ N12
	.byte N12, En3 @ v040
	.byte W24
	.byte VOICE, 11
	.byte BENDR, 20
	.byte VOL, 71
	.byte BEND, c_v
	.byte N90, En2, v092
	.byte W24
	.byte BEND, c_v-1
	.byte W01
	.byte c_v-2 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W03
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W03
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W02
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-18 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-20 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W02
	.byte c_v-26 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-30 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-38 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-44 @ BEND
	.byte W01
	.byte c_v-45 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-51 @ BEND
	.byte W01
	.byte c_v-52 @ BEND
	.byte W01
	.byte c_v-54 @ BEND
	.byte W01
	.byte c_v-56 @ BEND
	.byte W01
	.byte c_v-58 @ BEND
	.byte W01
	.byte c_v-60 @ BEND
	.byte W01
	.byte c_v-62 @ BEND
	.byte W09
	.byte W72
	.byte W24
	.byte c_v @ BEND
	.byte W24
	.byte W72
	.byte VOICE, 15
	.byte VOL, 18
	.byte TIE, An2, v080
	.byte W96
	.byte W24
	.byte W03
	.byte VOL, 16
	.byte W36
	.byte W01
	.byte 13 @ VOL
	.byte W28
	.byte 11 @ VOL
	.byte W04
	.byte EOT @ An2, v080
	.byte TIE, As2 @ v080
	.byte W13
	.byte VOL, 10
	.byte W80
	.byte W03
	.byte W68
	.byte 13 @ VOL
	.byte W28
	.byte EOT @ As2, v080
	.byte TIE, Bn2 @ v080
	.byte W30
	.byte VOL, 16
	.byte W44
	.byte W01
	.byte 18 @ VOL
	.byte W21
	.byte W02
	.byte 21 @ VOL
	.byte W19
	.byte 23 @ VOL
	.byte W15
	.byte 26 @ VOL
	.byte W13
	.byte 28 @ VOL
	.byte W09
	.byte 31 @ VOL
	.byte W09
	.byte 34 @ VOL
	.byte W08
	.byte 36 @ VOL
	.byte W07
	.byte 39 @ VOL
	.byte W05
	.byte 41 @ VOL
	.byte W05
	.byte 44 @ VOL
	.byte W04
	.byte EOT @ Bn2, v080
	.byte TIE, Cn3, v064
	.byte W02
	.byte VOL, 46
	.byte W12
	.byte 49 @ VOL
	.byte W17
	.byte 51 @ VOL
	.byte W16
	.byte 54 @ VOL
	.byte W17
	.byte 56 @ VOL
	.byte W17
	.byte 59 @ VOL
	.byte W12
	.byte 61 @ VOL
	.byte W03
	.byte W54
	.byte EOT @ Cn3, v064
	.byte W06
	.byte VOICE, 11
	.byte VOL, 52
	.byte N12, Cs3, v127
	.byte W12
	.byte Dn3 @ N12, v127
	.byte W12
	.byte Ds3 @ N12, v127
	.byte W12
	.byte VOICE, 11
	.byte VOL, 75
	.byte PAN, c_v+10
	.byte N12, Fn2, v080
	.byte N12, Cs3 @ v080
	.byte W36
	.byte Fn2, v052 @ N12
	.byte N12, Cs3 @ v052
	.byte W36
	.byte Fn2 @ N12, v052
	.byte N12, Cs3 @ v052
	.byte W24
	.byte W24
	.byte Fn2, v080 @ N12
	.byte N12, Cs3 @ v080
	.byte W36
	.byte Fn2, v040 @ N12
	.byte N12, Cs3 @ v040
	.byte W24
	.byte Fs2, v080 @ N12
	.byte N12, Dn3 @ v080
	.byte W12
	.byte W24
	.byte Fs2, v060 @ N12
	.byte N12, Dn3 @ v060
	.byte W36
	.byte Fs2 @ N12, v060
	.byte N12, Dn3 @ v060
	.byte W24
	.byte W24
	.byte Fs2, v080 @ N12
	.byte N12, Dn3 @ v080
	.byte W36
	.byte Fs2, v040 @ N12
	.byte N12, Dn3 @ v040
	.byte W24
	.byte Gn2, v080 @ N12
	.byte N12, Ds3 @ v080
	.byte W12
	.byte W24
	.byte Gn2, v052 @ N12
	.byte N12, Ds3 @ v052
	.byte W36
	.byte Gn2 @ N12, v052
	.byte N12, Ds3 @ v052
	.byte W24
	.byte W24
	.byte Gn2, v080 @ N12
	.byte N12, Ds3 @ v080
	.byte W36
	.byte Gn2 @ N12, v080
	.byte N12, Ds3 @ v080
	.byte W24
	.byte Gs2 @ N12, v080
	.byte N12, En3 @ v080
	.byte W12
	.byte W24
	.byte Gs2 @ N12, v080
	.byte N12, En3 @ v080
	.byte W36
	.byte Gs2 @ N12, v080
	.byte N12, En3 @ v080
	.byte W24
	.byte GOTO
		.word track_75_lbl_2283ff
	.byte FINE

track_75_5:
	.byte KEYSH, 0
	.byte PRIO, 28
	.byte W96
	.byte W84
	.byte W96
	.byte W84
	.byte W96
	.byte W84
	.byte W96
track_75_lbl_2285b4:
	.byte W84
	.byte W96
	.byte W84
	.byte W96
	.byte W84
	.byte W96
	.byte W84
	.byte W96
	.byte W84
	.byte VOICE, 11
	.byte BENDR, 20
	.byte VOL, 71
	.byte BEND, c_v
	.byte N90, Ds3, v092
	.byte W24
	.byte BEND, c_v-1
	.byte W01
	.byte c_v-2 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W03
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W03
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W02
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-18 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-20 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W02
	.byte c_v-26 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-30 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-38 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-44 @ BEND
	.byte W01
	.byte c_v-45 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-51 @ BEND
	.byte W01
	.byte c_v-52 @ BEND
	.byte W01
	.byte c_v-54 @ BEND
	.byte W01
	.byte c_v-56 @ BEND
	.byte W01
	.byte c_v-58 @ BEND
	.byte W01
	.byte c_v-60 @ BEND
	.byte W01
	.byte c_v-62 @ BEND
	.byte W09
	.byte W72
	.byte W24
	.byte c_v @ BEND
	.byte W24
	.byte W72
	.byte VOICE, 16
	.byte VOL, 37
	.byte N32, Gn3, v032, 1
	.byte W36
	.byte N24, Fn4 @ v032
	.byte W30
	.byte Bn3 @ N24, v032
	.byte W30
	.byte N32, Gn4, v032, 1
	.byte W36
	.byte Bn3, v032, 1 @ N32
	.byte W36
	.byte N21, Gn3 @ v032
	.byte W24
	.byte N32, Gs3, v032, 1
	.byte W36
	.byte N24, Gn4 @ v032
	.byte W30
	.byte Cn4 @ N24, v032
	.byte W30
	.byte N32, Gs4, v032, 1
	.byte W36
	.byte Cn4, v032, 1 @ N32
	.byte W36
	.byte N21, Gs3 @ v032
	.byte W24
	.byte N32, An4, v040, 1
	.byte W36
	.byte Fn4, v040, 1 @ N32
	.byte W36
	.byte N21, Bn3, v052
	.byte W24
	.byte N32, An4, v040, 1
	.byte W36
	.byte N36, Fn4 @ v040
	.byte W42
	.byte N12, Bn3 @ v040
	.byte W18
	.byte N09, As4, v020
	.byte W12
	.byte Fs4, v024 @ N09
	.byte W12
	.byte En4, v028 @ N09
	.byte W12
	.byte Cn4 @ N09, v028
	.byte W12
	.byte As4, v032 @ N09
	.byte W12
	.byte Fs4, v036 @ N09
	.byte W12
	.byte En4, v040 @ N09
	.byte W12
	.byte Cn4 @ N09, v040
	.byte W12
	.byte As4 @ N09, v040
	.byte W12
	.byte Fs4 @ N09, v040
	.byte W12
	.byte En4 @ N09, v040
	.byte W12
	.byte Cn4 @ N09, v040
	.byte W12
	.byte As4 @ N09, v040
	.byte W48
	.byte W96
	.byte W96
	.byte W84
	.byte W96
	.byte W84
	.byte W96
	.byte W84
	.byte GOTO
		.word track_75_lbl_2285b4
	.byte FINE

.align 2

track_75:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_75_0
	.word track_75_1
	.word track_75_2
	.word track_75_3
	.word track_75_4
	.word track_75_5

.align 2
