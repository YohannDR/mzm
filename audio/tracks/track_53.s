.align 2

.global track_53

track_53_0:
	.byte KEYSH, 0
track_53_lbl_2204be:
	.byte TEMPO, 127
	.byte VOICE, 14
	.byte BENDR, 1
	.byte PAN, c_v
	.byte PRIO, 120
	.byte VOL, 86
	.byte N12, Cn3, v127
	.byte W36
	.byte N12 @ Cn3, v127
	.byte W36
	.byte Cs3 @ N12, v127
	.byte W24
	.byte As2 @ N12, v127
	.byte W24
track_53_lbl_2204d4:
	.byte N12, Cn3, v127
	.byte W36
	.byte N12 @ Cn3, v127
	.byte W36
	.byte Cs3 @ N12, v127
	.byte W24
	.byte As2 @ N12, v127
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_2204d4
	.byte PATT
		.word track_53_lbl_2204d4
	.byte VOICE, 17
	.byte VOL, 72
	.byte N06, Fs3, v116
	.byte W12
	.byte Cn3 @ N06, v116
	.byte W12
	.byte Ds3 @ N06, v116
	.byte W12
	.byte N60, Gn2 @ v116
	.byte W60
track_53_lbl_2204f8:
	.byte N06, Gs2, v116
	.byte W12
	.byte As2 @ N06, v116
	.byte W12
	.byte Cn3 @ N06, v116
	.byte W12
	.byte N60, Gn3 @ v116
	.byte W60
	.byte PEND
track_53_lbl_220504:
	.byte N06, Fs3, v116
	.byte W12
	.byte Dn3 @ N06, v116
	.byte W12
	.byte N72, An3 @ v116
	.byte W72
	.byte PEND
track_53_lbl_22050e:
	.byte N36, As3, v124
	.byte W36
	.byte N30, Bn3 @ v124
	.byte W36
	.byte PEND
	.byte VOICE, 14
	.byte VOL, 86
	.byte N12, Ds3, v127
	.byte W36
	.byte N12 @ Ds3, v127
	.byte W36
	.byte En3 @ N12, v127
	.byte W24
	.byte Cs3 @ N12, v127
	.byte W24
	.byte Ds3 @ N12, v127
	.byte W36
	.byte N12 @ Ds3, v127
	.byte W36
	.byte En3 @ N12, v127
	.byte W24
	.byte Cs3 @ N12, v127
	.byte W24
track_53_lbl_22052c:
	.byte N12, Ds3, v100
	.byte W36
	.byte N12 @ Ds3, v100
	.byte W36
	.byte En3 @ N12, v100
	.byte W24
	.byte Cs3 @ N12, v100
	.byte W24
	.byte PEND
track_53_lbl_220537:
	.byte N12, Ds3, v120
	.byte W36
	.byte N12 @ Ds3, v120
	.byte W36
	.byte En3 @ N12, v120
	.byte W24
	.byte Cs3 @ N12, v120
	.byte W24
	.byte PEND
track_53_lbl_220542:
	.byte N12, Cn3, v112
	.byte W36
	.byte N12 @ Cn3, v112
	.byte W36
	.byte Cs3 @ N12, v112
	.byte W24
	.byte As2 @ N12, v112
	.byte W24
	.byte PEND
track_53_lbl_22054d:
	.byte N12, Cn3, v100
	.byte W36
	.byte N12 @ Cn3, v100
	.byte W36
	.byte Cs3 @ N12, v100
	.byte W24
	.byte As2 @ N12, v100
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_2204d4
	.byte PATT
		.word track_53_lbl_2204d4
	.byte VOICE, 17
	.byte N06, Fs3, v116
	.byte W12
	.byte Cn3 @ N06, v116
	.byte W12
	.byte Ds3 @ N06, v116
	.byte W12
	.byte N60, Gn2 @ v116
	.byte W60
	.byte PATT
		.word track_53_lbl_2204f8
	.byte PATT
		.word track_53_lbl_220504
	.byte PATT
		.word track_53_lbl_22050e
	.byte VOICE, 14
	.byte N12, Ds3, v127
	.byte W36
	.byte N12 @ Ds3, v127
	.byte W36
	.byte En3 @ N12, v127
	.byte W24
	.byte Cs3 @ N12, v127
	.byte W24
	.byte Ds3, v112 @ N12
	.byte W36
	.byte N12 @ Ds3, v112
	.byte W36
	.byte En3 @ N12, v112
	.byte W24
	.byte Cs3 @ N12, v112
	.byte W24
	.byte PATT
		.word track_53_lbl_22052c
	.byte PATT
		.word track_53_lbl_220537
	.byte PATT
		.word track_53_lbl_220542
	.byte PATT
		.word track_53_lbl_22054d
	.byte N12, Cn3, v092
	.byte W36
	.byte N12 @ Cn3, v092
	.byte W36
	.byte Cs3 @ N12, v092
	.byte W24
	.byte As2 @ N12, v092
	.byte W24
	.byte Cn3, v120 @ N12
	.byte W36
	.byte N12 @ Cn3, v120
	.byte W36
	.byte Cs3, v127 @ N12
	.byte W24
	.byte As2 @ N12, v127
	.byte W24
	.byte VOICE, 25
	.byte VOL, 82
	.byte N48, As2, v060
	.byte W48
	.byte N08, An2 @ v060
	.byte W08
	.byte As2 @ N08, v060
	.byte W08
	.byte An2 @ N08, v060
	.byte W08
track_53_lbl_2205ca:
	.byte N48, Fs2, v060
	.byte W48
	.byte N24, An2 @ v060
	.byte W24
	.byte PEND
	.byte N48, As2 @ v060
	.byte W48
	.byte N08, An2 @ v060
	.byte W08
	.byte As2 @ N08, v060
	.byte W08
	.byte An2 @ N08, v060
	.byte W08
	.byte PATT
		.word track_53_lbl_2205ca
	.byte N48, Cs3, v080
	.byte W48
	.byte N08, Cn3 @ v080
	.byte W08
	.byte Cs3 @ N08, v080
	.byte W08
	.byte Cn3 @ N08, v080
	.byte W08
	.byte N48, An2 @ v080
	.byte W48
	.byte N24, Cn3 @ v080
	.byte W24
	.byte N48, Ds3, v092
	.byte W48
	.byte N08, Dn3 @ v092
	.byte W08
	.byte Ds3 @ N08, v092
	.byte W08
	.byte Dn3 @ N08, v092
	.byte W08
	.byte N48, Fs3, v108
	.byte W48
	.byte N08, Fn3 @ v108
	.byte W08
	.byte Fs3 @ N08, v108
	.byte W08
	.byte Fn3 @ N08, v108
	.byte W08
	.byte N12, Ds3 @ v108
	.byte W12
	.byte Dn3 @ N12, v108
	.byte W12
	.byte Fs3 @ N12, v108
	.byte W12
	.byte Fn3, v120 @ N12
	.byte W12
	.byte Ds3 @ N12, v120
	.byte W12
	.byte Dn3, v127 @ N12
	.byte W12
	.byte Fs3 @ N12, v127
	.byte W12
	.byte N06, Fn3 @ v127
	.byte W06
	.byte GOTO
		.word track_53_lbl_2204be
	.byte FINE

track_53_1:
	.byte KEYSH, 0
track_53_lbl_220624:
	.byte VOICE, 13
	.byte PAN, c_v+22
	.byte PRIO, 119
	.byte VOL, 69
	.byte N12, As2, v112
	.byte W36
	.byte N12 @ As2, v112
	.byte W36
	.byte Bn2 @ N12, v112
	.byte W24
	.byte Gs2 @ N12, v112
	.byte W24
track_53_lbl_220636:
	.byte N12, As2, v112
	.byte W36
	.byte N12 @ As2, v112
	.byte W36
	.byte Bn2 @ N12, v112
	.byte W24
	.byte Gs2 @ N12, v112
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_220636
	.byte PATT
		.word track_53_lbl_220636
track_53_lbl_22064b:
	.byte VOICE, 14
	.byte VOL, 67
	.byte N96, Fs2, v112
	.byte W96
	.byte PEND
	.byte Gn2 @ N96, v112
	.byte W96
track_53_lbl_220656:
	.byte N24, Gs2, v112
	.byte W24
	.byte N72, An2 @ v112
	.byte W72
	.byte PEND
track_53_lbl_22065e:
	.byte PAN, c_v+36
	.byte N36, As2, v127
	.byte W36
	.byte N30, Bn2 @ v127
	.byte W36
	.byte PEND
	.byte VOICE, 13
	.byte PAN, c_v+20
	.byte VOL, 69
	.byte N12, Cs3, v112
	.byte W36
	.byte N12 @ Cs3, v112
	.byte W36
	.byte Dn3 @ N12, v112
	.byte W24
	.byte Bn2 @ N12, v112
	.byte W24
	.byte Cs3 @ N12, v112
	.byte W36
	.byte N12 @ Cs3, v112
	.byte W36
	.byte Dn3 @ N12, v112
	.byte W24
	.byte Bn2 @ N12, v112
	.byte W24
track_53_lbl_220680:
	.byte VOICE, 14
	.byte VOL, 31
	.byte TIE, Ds4, v100
	.byte W12
	.byte VOL, 34
	.byte W14
	.byte 38 @ VOL
	.byte W07
	.byte 39 @ VOL
	.byte W14
	.byte 43 @ VOL
	.byte W14
	.byte 46 @ VOL
	.byte W14
	.byte 50 @ VOL
	.byte W14
	.byte 53 @ VOL
	.byte W14
	.byte 57 @ VOL
	.byte W14
	.byte 60 @ VOL
	.byte W03
	.byte PEND
	.byte EOT @ Ds4, v100
track_53_lbl_22069d:
	.byte TIE, Ds4, v100
	.byte W11
	.byte VOL, 64
	.byte W14
	.byte 67 @ VOL
	.byte W14
	.byte 71 @ VOL
	.byte W14
	.byte 74 @ VOL
	.byte W14
	.byte 77 @ VOL
	.byte W18
	.byte 82 @ VOL
	.byte W10
	.byte 82 @ VOL
	.byte W14
	.byte 82 @ VOL
	.byte W11
	.byte PEND
	.byte EOT @ Ds4, v100
	.byte N12, Dn4, v096
	.byte W72
	.byte VOICE, 13
	.byte VOL, 32
	.byte N12, Bn2, v100
	.byte W24
	.byte Gs2 @ N12, v100
	.byte W24
track_53_lbl_2206c2:
	.byte N12, As2, v112
	.byte W36
	.byte As2, v100 @ N12
	.byte W36
	.byte Bn2 @ N12, v100
	.byte W24
	.byte Gs2 @ N12, v100
	.byte W24
	.byte PEND
	.byte As2 @ N12, v100
	.byte W36
	.byte N12 @ As2, v100
	.byte W36
	.byte Bn2 @ N12, v100
	.byte W24
	.byte Gs2 @ N12, v100
	.byte W24
	.byte As2, v127 @ N12
	.byte W36
	.byte N12 @ As2, v127
	.byte W36
	.byte Bn2 @ N12, v127
	.byte W24
	.byte Gs2 @ N12, v127
	.byte W24
	.byte PATT
		.word track_53_lbl_22064b
	.byte N96, Gn2, v112
	.byte W96
	.byte PATT
		.word track_53_lbl_220656
	.byte PATT
		.word track_53_lbl_22065e
	.byte VOICE, 13
	.byte PAN, c_v+20
	.byte VOL, 32
	.byte N12, Cs3, v112
	.byte W36
	.byte N12 @ Cs3, v112
	.byte W36
	.byte Dn3 @ N12, v112
	.byte W24
	.byte Bn2 @ N12, v112
	.byte W24
	.byte Cs3, v092 @ N12
	.byte W36
	.byte N12 @ Cs3, v092
	.byte W36
	.byte Dn3 @ N12, v092
	.byte W24
	.byte Bn2 @ N12, v092
	.byte W24
	.byte PATT
		.word track_53_lbl_220680
	.byte EOT, Ds4 @ v092
	.byte PATT
		.word track_53_lbl_22069d
	.byte EOT, Ds4 @ v092
	.byte N12, Dn4, v088
	.byte W72
	.byte VOICE, 13
	.byte VOL, 32
	.byte N12, Bn2, v092
	.byte W24
	.byte Gs2 @ N12, v092
	.byte W24
	.byte PATT
		.word track_53_lbl_2206c2
	.byte N12, As2, v092
	.byte W36
	.byte N12 @ As2, v092
	.byte W36
	.byte Bn2 @ N12, v092
	.byte W24
	.byte Gs2 @ N12, v092
	.byte W24
	.byte As2, v116 @ N12
	.byte W36
	.byte N12 @ As2, v116
	.byte W36
	.byte Bn2 @ N12, v116
	.byte W24
	.byte Gs2 @ N12, v116
	.byte W24
	.byte VOICE, 14
	.byte VOL, 67
	.byte N72, Cn3, v040
	.byte W72
	.byte Ds3, v032 @ N72
	.byte W72
	.byte Fs3, v024 @ N72
	.byte W72
	.byte An3 @ N72, v024
	.byte W72
	.byte Ds3 @ N72, v024
	.byte W72
	.byte Fs3 @ N72, v024
	.byte W72
	.byte An3, v036 @ N72
	.byte W72
	.byte Cn4, v044 @ N72
	.byte W72
	.byte N36, Ds4, v116
	.byte W36
	.byte N28, Fs4 @ v116
	.byte W28
	.byte N24, An4, v116, 2
	.byte W08
	.byte W18
	.byte GOTO
		.word track_53_lbl_220624
	.byte FINE

track_53_2:
	.byte KEYSH, 0
track_53_lbl_22076e:
	.byte VOICE, 23
	.byte VOL, 86
	.byte PAN, c_v-24
	.byte PRIO, 118
	.byte N72, Cn2, v116
	.byte W72
	.byte N24, Cs2 @ v116
	.byte W24
	.byte As1 @ N24, v116
	.byte W24
track_53_lbl_22077f:
	.byte N72, Cn2, v116
	.byte W72
	.byte N24, Cs2 @ v116
	.byte W24
	.byte As1 @ N24, v116
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_22077f
	.byte PATT
		.word track_53_lbl_22077f
	.byte N96, Gn1, v116
	.byte W96
	.byte Gs1 @ N96, v116
	.byte W96
	.byte An1, v124 @ N96
	.byte W96
track_53_lbl_22079c:
	.byte N36, As1, v127
	.byte W36
	.byte Bn1 @ N36, v127
	.byte W36
	.byte PEND
track_53_lbl_2207a3:
	.byte N72, Ds2, v116
	.byte W72
	.byte N24, En2 @ v116
	.byte W24
	.byte Cs2 @ N24, v116
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_2207a3
	.byte PATT
		.word track_53_lbl_2207a3
	.byte PATT
		.word track_53_lbl_2207a3
	.byte PATT
		.word track_53_lbl_22077f
	.byte PATT
		.word track_53_lbl_22077f
	.byte PATT
		.word track_53_lbl_22077f
	.byte PATT
		.word track_53_lbl_22077f
	.byte N96, Gn1, v116
	.byte W96
	.byte Gs1 @ N96, v116
	.byte W96
	.byte An1, v124 @ N96
	.byte W96
	.byte PATT
		.word track_53_lbl_22079c
	.byte PATT
		.word track_53_lbl_2207a3
	.byte PATT
		.word track_53_lbl_2207a3
	.byte PATT
		.word track_53_lbl_2207a3
	.byte PATT
		.word track_53_lbl_2207a3
	.byte PATT
		.word track_53_lbl_22077f
	.byte PATT
		.word track_53_lbl_22077f
	.byte PATT
		.word track_53_lbl_22077f
	.byte PATT
		.word track_53_lbl_22077f
	.byte VOICE, 23
	.byte VOL, 67
	.byte N72, Ds2, v064
	.byte W72
	.byte Cn2 @ N72, v064
	.byte W72
	.byte Ds2 @ N72, v064
	.byte W72
	.byte Fs2 @ N72, v064
	.byte W72
	.byte An2, v076 @ N72
	.byte W72
	.byte Fs2 @ N72, v076
	.byte W72
	.byte An2, v084 @ N72
	.byte W72
	.byte Cn3, v100 @ N72
	.byte W72
	.byte N36, Ds2, v127
	.byte W36
	.byte N28, Fs2 @ v127
	.byte W28
	.byte N24, An2, v127, 2
	.byte W08
	.byte W18
	.byte GOTO
		.word track_53_lbl_22076e
	.byte FINE

track_53_3:
	.byte KEYSH, 0
track_53_lbl_220834:
	.byte PAN, c_v+20
	.byte PRIO, 30
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 44
	.byte VOL, 32
	.byte N96, Cn4, v112
	.byte W96
	.byte Cs4 @ N96, v112
	.byte W96
track_53_lbl_22084a:
	.byte N24, Dn4, v112
	.byte W24
	.byte N72, Ds4 @ v112
	.byte W72
	.byte PEND
track_53_lbl_220852:
	.byte PAN, c_v-38
	.byte N36, En4, v127
	.byte W36
	.byte N30, Fn4 @ v127
	.byte W36
	.byte PEND
	.byte N18, Ds1 @ v127
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 14
	.byte PAN, c_v-38
	.byte VOL, 43
	.byte TIE, Cs4, v100
	.byte W11
	.byte VOL, 32
	.byte W14
	.byte 36 @ VOL
	.byte W14
	.byte 39 @ VOL
	.byte W13
	.byte 43 @ VOL
	.byte W14
	.byte 46 @ VOL
	.byte W14
	.byte 50 @ VOL
	.byte W13
	.byte 53 @ VOL
	.byte W14
	.byte 57 @ VOL
	.byte W13
	.byte EOT @ Cs4, v100
track_53_lbl_22087e:
	.byte TIE, Cs4, v100
	.byte W01
	.byte VOL, 60
	.byte W13
	.byte 64 @ VOL
	.byte W14
	.byte 67 @ VOL
	.byte W13
	.byte 71 @ VOL
	.byte W14
	.byte 74 @ VOL
	.byte W14
	.byte 77 @ VOL
	.byte W13
	.byte 81 @ VOL
	.byte W14
	.byte 82 @ VOL
	.byte W14
	.byte 82 @ VOL
	.byte W10
	.byte PEND
	.byte EOT @ Cs4, v100
	.byte N12, Cn4, v104
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 44
	.byte PAN, c_v+20
	.byte VOL, 32
	.byte N96, Cn4, v112
	.byte W96
	.byte Cs4 @ N96, v112
	.byte W96
	.byte PATT
		.word track_53_lbl_22084a
	.byte PATT
		.word track_53_lbl_220852
	.byte N18, Ds1, v127
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 14
	.byte VOL, 43
	.byte TIE, Cs4, v100
	.byte W11
	.byte VOL, 32
	.byte W14
	.byte 36 @ VOL
	.byte W14
	.byte 39 @ VOL
	.byte W13
	.byte 43 @ VOL
	.byte W14
	.byte 46 @ VOL
	.byte W14
	.byte 50 @ VOL
	.byte W13
	.byte 53 @ VOL
	.byte W14
	.byte 57 @ VOL
	.byte W13
	.byte EOT @ Cs4, v100
	.byte PATT
		.word track_53_lbl_22087e
	.byte EOT, Cs4 @ v100
	.byte N12, Cn4, v104
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 44
	.byte VOL, 50
	.byte N72, Cn4, v076
	.byte W72
	.byte N72 @ Cn4, v076
	.byte W72
	.byte N72 @ Cn4, v076
	.byte W72
	.byte N72 @ Cn4, v076
	.byte W72
	.byte Fs4 @ N72, v076
	.byte W72
	.byte Ds4 @ N72, v076
	.byte W72
	.byte Fs4 @ N72, v076
	.byte W72
	.byte An4, v084 @ N72
	.byte W72
	.byte VOICE, 14
	.byte VOL, 67
	.byte N36, An3, v104
	.byte W36
	.byte N28, Cn4 @ v104
	.byte W28
	.byte N24, Ds4, v116, 2
	.byte W08
	.byte W18
	.byte GOTO
		.word track_53_lbl_220834
	.byte FINE

track_53_4:
	.byte KEYSH, 0
track_53_lbl_22091b:
	.byte VOICE, 44
	.byte PAN, c_v+10
	.byte PRIO, 30
	.byte VOL, 72
	.byte N12, Cn4, v127
	.byte W36
	.byte N12 @ Cn4, v127
	.byte W36
	.byte Cs4 @ N12, v127
	.byte W24
	.byte As3 @ N12, v127
	.byte W24
track_53_lbl_22092d:
	.byte N12, Cn4, v127
	.byte W36
	.byte N12 @ Cn4, v127
	.byte W36
	.byte Cs4 @ N12, v127
	.byte W24
	.byte As3 @ N12, v127
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_22092d
	.byte PATT
		.word track_53_lbl_22092d
	.byte W96
	.byte W96
	.byte W96
	.byte W72
track_53_lbl_220946:
	.byte W36
	.byte N12, Ds4, v127
	.byte W36
	.byte En4 @ N12, v127
	.byte W24
	.byte Cs4 @ N12, v127
	.byte W24
	.byte PEND
	.byte Ds4 @ N12, v127
	.byte W36
	.byte N12 @ Ds4, v127
	.byte W36
	.byte En4 @ N12, v127
	.byte W24
	.byte Cs4 @ N12, v127
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
track_53_lbl_22095c:
	.byte W36
	.byte N12, Cn4, v127
	.byte W36
	.byte Cs4 @ N12, v127
	.byte W24
	.byte As3 @ N12, v127
	.byte W24
	.byte PEND
track_53_lbl_220966:
	.byte N12, Cn4, v116
	.byte W36
	.byte N12 @ Cn4, v116
	.byte W36
	.byte Cs4 @ N12, v116
	.byte W24
	.byte As3 @ N12, v116
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_220966
	.byte PATT
		.word track_53_lbl_22092d
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte PATT
		.word track_53_lbl_220946
	.byte N12, Ds4, v116
	.byte W36
	.byte N12 @ Ds4, v116
	.byte W36
	.byte En4 @ N12, v116
	.byte W24
	.byte Cs4 @ N12, v116
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte PATT
		.word track_53_lbl_22095c
	.byte PATT
		.word track_53_lbl_220966
	.byte N12, Cn4, v108
	.byte W36
	.byte N12 @ Cn4, v108
	.byte W36
	.byte Cs4 @ N12, v108
	.byte W24
	.byte As3 @ N12, v108
	.byte W24
	.byte Cn4 @ N12, v108
	.byte W36
	.byte N12 @ Cn4, v108
	.byte W36
	.byte Cs4, v127 @ N12
	.byte W24
	.byte As3 @ N12, v127
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W18
	.byte GOTO
		.word track_53_lbl_22091b
	.byte FINE

track_53_5:
	.byte KEYSH, 0
track_53_lbl_2209c1:
	.byte VOICE, 23
	.byte VOL, 72
	.byte PAN, c_v-16
	.byte PRIO, 29
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
track_53_lbl_2209d1:
	.byte VOICE, 19
	.byte VOL, 41
	.byte N96, Fs2, v060
	.byte W96
	.byte PEND
	.byte Gn2 @ N96, v060
	.byte W96
track_53_lbl_2209dc:
	.byte N24, Gs2, v080
	.byte W24
	.byte N72, An2 @ v080
	.byte W72
	.byte PEND
	.byte N36, As2, v112
	.byte W36
	.byte N30, Bn2 @ v112
	.byte W36
track_53_lbl_2209eb:
	.byte VOICE, 23
	.byte VOL, 67
	.byte N72, As2, v084
	.byte W72
	.byte N24, Bn2 @ v084
	.byte W24
	.byte Gs2 @ N24, v084
	.byte W24
	.byte PEND
	.byte N72, As2 @ v084
	.byte W72
	.byte N24, Bn2 @ v084
	.byte W24
	.byte Gs2 @ N24, v084
	.byte W24
track_53_lbl_220a01:
	.byte N72, As2, v064
	.byte W72
	.byte N24, Bn2 @ v064
	.byte W24
	.byte Gs2 @ N24, v064
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_220a01
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte PATT
		.word track_53_lbl_2209d1
	.byte N96, Gn2, v060
	.byte W96
	.byte PATT
		.word track_53_lbl_2209dc
	.byte N36, As2, v108
	.byte W36
	.byte N30, Bn2 @ v108
	.byte W36
	.byte PATT
		.word track_53_lbl_2209eb
	.byte N72, As2, v076
	.byte W72
	.byte N24, Bn2 @ v076
	.byte W24
	.byte Gs2 @ N24, v076
	.byte W24
	.byte PATT
		.word track_53_lbl_220a01
	.byte PATT
		.word track_53_lbl_220a01
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 19
	.byte VOL, 15
	.byte TIE, An2, v060
	.byte W72
	.byte W72
	.byte EOT @ An2, v060
	.byte TIE, Cn3 @ v060
	.byte W72
	.byte W72
	.byte EOT @ Cn3, v060
	.byte VOICE, 44
	.byte VOL, 58
	.byte N36, An3, v080
	.byte W36
	.byte N28, Cn4 @ v080
	.byte W28
	.byte VOICE, 19
	.byte N24, Ds3, v127, 2
	.byte W08
	.byte W18
	.byte GOTO
		.word track_53_lbl_2209c1
	.byte FINE

track_53_6:
	.byte KEYSH, 0
track_53_lbl_220a7b:
	.byte VOICE, 21
	.byte VOL, 72
	.byte PAN, c_v-10
	.byte PRIO, 29
	.byte W12
	.byte N06, Cn2, v100
	.byte W12
	.byte Cn3 @ N06, v100
	.byte W24
	.byte Cn2 @ N06, v100
	.byte W12
	.byte Cn3 @ N06, v100
	.byte W24
	.byte Cs3 @ N06, v100
	.byte W24
	.byte As2 @ N06, v100
	.byte W12
track_53_lbl_220a92:
	.byte W12
	.byte N06, Cn2, v100
	.byte W12
	.byte Cn3 @ N06, v100
	.byte W24
	.byte Cn2 @ N06, v100
	.byte W12
	.byte Cn3 @ N06, v100
	.byte W12
	.byte Cs2 @ N06, v100
	.byte W12
	.byte Cs3 @ N06, v100
	.byte W12
	.byte As1 @ N06, v100
	.byte W12
	.byte As2 @ N06, v100
	.byte W12
	.byte PEND
	.byte PATT
		.word track_53_lbl_220a92
	.byte PATT
		.word track_53_lbl_220a92
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
	.byte PATT
		.word track_53_lbl_220a92
	.byte PATT
		.word track_53_lbl_220a92
	.byte PATT
		.word track_53_lbl_220a92
	.byte PATT
		.word track_53_lbl_220a92
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
	.byte W12
	.byte N06, Cn2, v080
	.byte W12
	.byte Cn3 @ N06, v080
	.byte W24
	.byte Cn2 @ N06, v080
	.byte W12
	.byte Cn3 @ N06, v080
	.byte W12
	.byte Cs2, v072 @ N06
	.byte W12
	.byte Cs3 @ N06, v072
	.byte W12
	.byte As1 @ N06, v072
	.byte W12
	.byte As2 @ N06, v072
	.byte W12
	.byte W12
	.byte Cn2, v040 @ N06
	.byte W12
	.byte Cn3, v032 @ N06
	.byte W24
	.byte Cn2, v040 @ N06
	.byte W12
	.byte Cn3, v032 @ N06
	.byte W12
	.byte Cs2, v040 @ N06
	.byte W12
	.byte Cs3, v032 @ N06
	.byte W12
	.byte As1, v040 @ N06
	.byte W12
	.byte As2, v032 @ N06
	.byte W12
	.byte W12
	.byte Cn2, v040 @ N06
	.byte W12
	.byte Cn3 @ N06, v040
	.byte W24
	.byte Cn2 @ N06, v040
	.byte W12
	.byte Cn3 @ N06, v040
	.byte W12
	.byte Cs2 @ N06, v040
	.byte W12
	.byte Cs3 @ N06, v040
	.byte W12
	.byte As1 @ N06, v040
	.byte W12
	.byte As2 @ N06, v040
	.byte W12
	.byte W12
	.byte Cn2, v060 @ N06
	.byte W12
	.byte Cn3 @ N06, v060
	.byte W24
	.byte Cn2 @ N06, v060
	.byte W12
	.byte Cn3, v064 @ N06
	.byte W12
	.byte Cs2, v092 @ N06
	.byte W12
	.byte Cs3 @ N06, v092
	.byte W12
	.byte As1, v100 @ N06
	.byte W12
	.byte As2 @ N06, v100
	.byte W12
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W18
	.byte GOTO
		.word track_53_lbl_220a7b
	.byte FINE

track_53_7:
	.byte KEYSH, 0
track_53_lbl_220b42:
	.byte VOICE, 0
	.byte PAN, c_v
	.byte PRIO, 28
	.byte VOL, 87
	.byte N72, Cs2, v120
	.byte W72
	.byte VOL, 72
	.byte N04, Fs1, v036
	.byte W24
	.byte Fs1, v040 @ N04
	.byte W24
	.byte W12
	.byte Fs1, v032 @ N04
	.byte W12
	.byte N04 @ Fs1, v032
	.byte W12
	.byte N04 @ Fs1, v032
	.byte W12
	.byte N04 @ Fs1, v032
	.byte W12
	.byte N04 @ Fs1, v032
	.byte W24
	.byte N04 @ Fs1, v032
	.byte W24
	.byte N04 @ Fs1, v032
	.byte W12
	.byte W12
	.byte Fs1, v028 @ N04
	.byte W12
	.byte N04 @ Fs1, v028
	.byte W12
	.byte N04 @ Fs1, v028
	.byte W12
	.byte N04 @ Fs1, v028
	.byte W36
	.byte N04 @ Fs1, v028
	.byte W12
	.byte N04 @ Fs1, v028
	.byte W24
track_53_lbl_220b75:
	.byte W12
	.byte N04, Fs1, v032
	.byte W12
	.byte N04 @ Fs1, v032
	.byte W12
	.byte Fs1, v044 @ N04
	.byte W12
	.byte Fs1, v040 @ N04
	.byte W12
	.byte Fs1, v052 @ N04
	.byte W24
	.byte Fs1, v036 @ N04
	.byte W24
	.byte Fs1, v056 @ N04
	.byte W12
	.byte PEND
track_53_lbl_220b8c:
	.byte W12
	.byte N04, Fs1, v020
	.byte W12
	.byte N04 @ Fs1, v020
	.byte W12
	.byte Fs1, v028 @ N04
	.byte W12
	.byte Fs1, v024 @ N04
	.byte W12
	.byte Fs1, v032 @ N04
	.byte W12
	.byte N48, Cs2, v036
	.byte W24
	.byte PEND
track_53_lbl_220ba1:
	.byte W24
	.byte N04, Fs1, v032
	.byte W12
	.byte Fs1, v044 @ N04
	.byte W12
	.byte Fs1, v040 @ N04
	.byte W12
	.byte Fs1, v048 @ N04
	.byte W12
	.byte N48, Cs2, v052
	.byte W24
	.byte PEND
track_53_lbl_220bb4:
	.byte W24
	.byte N12, Cs2, v092
	.byte W24
	.byte N04, Fs1, v032
	.byte W12
	.byte Fs1, v048 @ N04
	.byte W24
	.byte Fs1, v032 @ N04
	.byte W12
	.byte PEND
track_53_lbl_220bc4:
	.byte N18, Cs2, v120
	.byte W36
	.byte N18 @ Cs2, v120
	.byte W36
	.byte PEND
track_53_lbl_220bcb:
	.byte VOL, 67
	.byte N48, Cs2, v112
	.byte W24
	.byte W01
	.byte VOL, 65
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W05
	.byte 67 @ VOL
	.byte N04, Fs1, v032
	.byte W12
	.byte Fs1, v036 @ N04
	.byte W12
	.byte Fs1, v032 @ N04
	.byte W24
	.byte Fs1, v036 @ N04
	.byte W24
	.byte PEND
track_53_lbl_220bf8:
	.byte W12
	.byte N04, Fs1, v020
	.byte W12
	.byte N04 @ Fs1, v020
	.byte W12
	.byte N04 @ Fs1, v020
	.byte W12
	.byte N04 @ Fs1, v020
	.byte W12
	.byte N04 @ Fs1, v020
	.byte W24
	.byte N04 @ Fs1, v020
	.byte W24
	.byte N04 @ Fs1, v020
	.byte W12
	.byte PEND
track_53_lbl_220c0a:
	.byte W12
	.byte N04, Fs1, v020
	.byte W12
	.byte N04 @ Fs1, v020
	.byte W12
	.byte Fs1, v024 @ N04
	.byte W12
	.byte Fs1, v020 @ N04
	.byte W12
	.byte Fs1, v028 @ N04
	.byte W24
	.byte Fs1, v020 @ N04
	.byte W12
	.byte Fs1, v028 @ N04
	.byte W24
	.byte PEND
track_53_lbl_220c21:
	.byte W12
	.byte N04, Fs1, v032
	.byte W12
	.byte N04 @ Fs1, v032
	.byte W12
	.byte Fs1, v044 @ N04
	.byte W12
	.byte Fs1, v040 @ N04
	.byte W12
	.byte Fs1, v048 @ N04
	.byte W60
	.byte PEND
track_53_lbl_220c32:
	.byte VOL, 67
	.byte N72, Cs2, v127
	.byte W36
	.byte W01
	.byte VOL, 64
	.byte W02
	.byte 62 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W06
	.byte 67 @ VOL
	.byte N04, Fs1, v040
	.byte W24
	.byte Fs1, v048 @ N04
	.byte W24
	.byte PEND
	.byte PATT
		.word track_53_lbl_220bf8
	.byte PATT
		.word track_53_lbl_220c0a
	.byte PATT
		.word track_53_lbl_220b75
	.byte PATT
		.word track_53_lbl_220b8c
	.byte PATT
		.word track_53_lbl_220ba1
	.byte PATT
		.word track_53_lbl_220bb4
	.byte PATT
		.word track_53_lbl_220bc4
	.byte PATT
		.word track_53_lbl_220bcb
	.byte PATT
		.word track_53_lbl_220bf8
	.byte PATT
		.word track_53_lbl_220c0a
	.byte PATT
		.word track_53_lbl_220c21
	.byte PATT
		.word track_53_lbl_220c32
	.byte PATT
		.word track_53_lbl_220bf8
	.byte PATT
		.word track_53_lbl_220c0a
	.byte PATT
		.word track_53_lbl_220b75
	.byte VOICE, 0
	.byte VOL, 67
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W12
	.byte N06, Fs1, v024
	.byte W24
	.byte Fs1, v028 @ N06
	.byte W36
	.byte Fs1, v052 @ N06
	.byte W24
	.byte Fs1, v056 @ N06
	.byte W12
	.byte Fs1, v032 @ N06
	.byte W24
	.byte Fs1, v024 @ N06
	.byte W12
	.byte W12
	.byte Fs1, v032 @ N06
	.byte W12
	.byte N06 @ Fs1, v032
	.byte W24
	.byte N06 @ Fs1, v032
	.byte W12
	.byte N30, Cs2, v127
	.byte W12
	.byte W18
	.byte GOTO
		.word track_53_lbl_220b42
	.byte FINE

track_53_8:
	.byte KEYSH, 0
track_53_lbl_220cd7:
	.byte VOICE, 22
	.byte VOL, 72
	.byte PAN, c_v
	.byte PRIO, 28
	.byte W96
	.byte W12
	.byte N06, Cn3, v072
	.byte W12
	.byte Dn2, v092 @ N06
	.byte W96
	.byte Fn2, v076 @ N06
	.byte W24
	.byte Dn2, v060 @ N06
	.byte W60
	.byte Cn3, v048 @ N06
	.byte W48
	.byte Fn2, v044 @ N06
	.byte W12
track_53_lbl_220cf4:
	.byte N06, Dn2, v060
	.byte W96
	.byte Dn2, v084 @ N06
	.byte W24
	.byte PEND
	.byte Dn2, v072 @ N06
	.byte W96
	.byte Dn2, v092 @ N06
	.byte W96
	.byte Dn2, v112 @ N06
	.byte W96
	.byte W72
track_53_lbl_220d06:
	.byte W96
	.byte W12
	.byte N06, Cn3, v060
	.byte W12
	.byte PEND
track_53_lbl_220d0d:
	.byte N06, Dn2, v060
	.byte W96
	.byte Fn2, v056 @ N06
	.byte W24
	.byte PEND
track_53_lbl_220d15:
	.byte N06, Dn2, v072
	.byte W96
	.byte W12
	.byte Fn2, v064 @ N06
	.byte W12
	.byte PEND
track_53_lbl_220d1e:
	.byte N06, Dn2, v112
	.byte W84
	.byte Fn2, v072 @ N06
	.byte W12
	.byte Dn2, v084 @ N06
	.byte W12
	.byte Cn3, v060 @ N06
	.byte W12
	.byte PEND
	.byte W96
	.byte W12
	.byte N06 @ Cn3, v060
	.byte W12
	.byte Dn2 @ N06, v060
	.byte W96
	.byte Fn2, v056 @ N06
	.byte W24
	.byte PATT
		.word track_53_lbl_220d15
	.byte PATT
		.word track_53_lbl_220cf4
	.byte N06, Dn2, v072
	.byte W96
	.byte Dn2, v092 @ N06
	.byte W96
	.byte Dn2, v112 @ N06
	.byte W96
	.byte W72
	.byte W96
	.byte W12
	.byte Cn3, v060 @ N06
	.byte W12
	.byte Dn2 @ N06, v060
	.byte W96
	.byte Fn2, v056 @ N06
	.byte W24
	.byte PATT
		.word track_53_lbl_220d15
	.byte PATT
		.word track_53_lbl_220d1e
	.byte PATT
		.word track_53_lbl_220d06
	.byte PATT
		.word track_53_lbl_220d0d
	.byte PATT
		.word track_53_lbl_220d15
	.byte PATT
		.word track_53_lbl_220cf4
	.byte W72
	.byte W36
	.byte VOICE, 22
	.byte VOL, 67
	.byte N06, Cn3, v036
	.byte W12
	.byte Dn2 @ N06, v036
	.byte W24
	.byte W72
	.byte Fn2, v040 @ N06
	.byte W24
	.byte Dn2, v052 @ N06
	.byte W48
	.byte W60
	.byte Fn2, v056 @ N06
	.byte W12
	.byte Dn2, v072 @ N06
	.byte W72
	.byte W24
	.byte Cn3, v040 @ N06
	.byte W48
	.byte W48
	.byte Dn2, v092 @ N06
	.byte W24
	.byte N06 @ Dn2, v092
	.byte W36
	.byte N06 @ Dn2, v092
	.byte W36
	.byte W18
	.byte GOTO
		.word track_53_lbl_220cd7
	.byte FINE

track_53_9:
	.byte KEYSH, 0
track_53_lbl_220da1:
	.byte VOICE, 20
	.byte PAN, c_v+10
	.byte PRIO, 27
	.byte VOL, 72
	.byte W24
	.byte N06, Cn3, v112
	.byte W36
	.byte N06 @ Cn3, v112
	.byte W24
	.byte Cs3 @ N06, v112
	.byte W24
	.byte As2 @ N06, v112
	.byte W12
track_53_lbl_220db4:
	.byte W24
	.byte N06, Cn3, v112
	.byte W36
	.byte N06 @ Cn3, v112
	.byte W24
	.byte Cs3 @ N06, v112
	.byte W24
	.byte As2 @ N06, v112
	.byte W12
	.byte PEND
	.byte PATT
		.word track_53_lbl_220db4
	.byte PATT
		.word track_53_lbl_220db4
	.byte W96
	.byte W96
	.byte W96
	.byte W72
track_53_lbl_220dce:
	.byte W24
	.byte N06, Ds3, v112
	.byte W36
	.byte N06 @ Ds3, v112
	.byte W24
	.byte En3 @ N06, v112
	.byte W24
	.byte Cs3 @ N06, v112
	.byte W12
	.byte PEND
	.byte PATT
		.word track_53_lbl_220dce
track_53_lbl_220ddf:
	.byte VOICE, 44
	.byte VOL, 67
	.byte N12, Ds4, v116
	.byte W36
	.byte N12 @ Ds4, v116
	.byte W36
	.byte En4 @ N12, v116
	.byte W24
	.byte Cs4 @ N12, v116
	.byte W24
	.byte PEND
track_53_lbl_220dee:
	.byte N12, Ds4, v116
	.byte W36
	.byte N12 @ Ds4, v116
	.byte W36
	.byte En4 @ N12, v116
	.byte W24
	.byte Cs4 @ N12, v116
	.byte W24
	.byte PEND
track_53_lbl_220df9:
	.byte VOICE, 20
	.byte VOL, 67
	.byte N12, Cs4, v116
	.byte W24
	.byte N06, Cn3, v112
	.byte W36
	.byte N06 @ Cn3, v112
	.byte W24
	.byte Cs3 @ N06, v112
	.byte W24
	.byte As2 @ N06, v112
	.byte W12
	.byte PEND
track_53_lbl_220e0c:
	.byte W24
	.byte N06, Cn3, v100
	.byte W36
	.byte N06 @ Cn3, v100
	.byte W24
	.byte Cs3 @ N06, v100
	.byte W24
	.byte As2 @ N06, v100
	.byte W12
	.byte PEND
track_53_lbl_220e18:
	.byte W24
	.byte N06, Cn3, v092
	.byte W36
	.byte N06 @ Cn3, v092
	.byte W24
	.byte Cs3 @ N06, v092
	.byte W24
	.byte As2 @ N06, v092
	.byte W12
	.byte PEND
	.byte PATT
		.word track_53_lbl_220db4
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte PATT
		.word track_53_lbl_220dce
	.byte W24
	.byte N06, Ds3, v100
	.byte W36
	.byte N06 @ Ds3, v100
	.byte W24
	.byte En3 @ N06, v100
	.byte W24
	.byte Cs3 @ N06, v100
	.byte W12
	.byte PATT
		.word track_53_lbl_220ddf
	.byte PATT
		.word track_53_lbl_220dee
	.byte PATT
		.word track_53_lbl_220df9
	.byte PATT
		.word track_53_lbl_220e0c
	.byte PATT
		.word track_53_lbl_220e18
	.byte PATT
		.word track_53_lbl_220db4
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte N06, An2, v052
	.byte W12
	.byte N12, An1, v068
	.byte W24
	.byte N06, An2, v048
	.byte W12
	.byte N12, An1, v068
	.byte W12
	.byte N06, An2, v048
	.byte W12
	.byte N12, Cn2, v080
	.byte W24
	.byte N06, Cn3, v048
	.byte W12
	.byte N12, Cn2, v076
	.byte W24
	.byte N06, Cn3, v052
	.byte W12
	.byte N12, An1, v076
	.byte W12
	.byte N06, An2, v028
	.byte W24
	.byte N12, An1, v076
	.byte W12
	.byte N06, An2, v056
	.byte W24
	.byte N12, Cn2, v108
	.byte W24
	.byte N06, Cn3, v076
	.byte W12
	.byte N12, Cn2, v104
	.byte W24
	.byte N06, Cn3, v076
	.byte W12
	.byte N12, Ds2, v108
	.byte W24
	.byte N06, Ds3, v084
	.byte W12
	.byte N12, Fs2, v124
	.byte W12
	.byte N06, Fs3, v092
	.byte W12
	.byte An1, v127 @ N06
	.byte W12
	.byte W18
	.byte GOTO
		.word track_53_lbl_220da1
	.byte FINE

track_53_10:
	.byte KEYSH, 0
track_53_lbl_220ebf:
	.byte VOICE, 57
	.byte PAN, c_v
	.byte VOL, 72
	.byte N12, Cn1, v112
	.byte W24
	.byte N06 @ Cn1, v112
	.byte W12
	.byte N12 @ Cn1, v112
	.byte W24
	.byte N06 @ Cn1, v112
	.byte W12
	.byte N12, Cs1 @ v112
	.byte W12
	.byte N06 @ Cs1, v112
	.byte W12
	.byte N12 @ Cs1, v112
	.byte W12
	.byte N06 @ Cs1, v112
	.byte W12
track_53_lbl_220ed8:
	.byte N12, Cn1, v112
	.byte W24
	.byte N06 @ Cn1, v112
	.byte W12
	.byte N12 @ Cn1, v112
	.byte W24
	.byte N06 @ Cn1, v112
	.byte W12
	.byte N12, Cs1 @ v112
	.byte W12
	.byte N06 @ Cs1, v112
	.byte W12
	.byte N12 @ Cs1, v112
	.byte W12
	.byte N06 @ Cs1, v112
	.byte W12
	.byte PEND
	.byte PATT
		.word track_53_lbl_220ed8
	.byte PATT
		.word track_53_lbl_220ed8
	.byte N96, Fs1, v092
	.byte W96
	.byte Gn1 @ N96, v092
	.byte W96
track_53_lbl_220efc:
	.byte N24, Gs1, v100
	.byte W24
	.byte N72, An1 @ v100
	.byte W72
	.byte PEND
track_53_lbl_220f04:
	.byte N36, As1, v127
	.byte W36
	.byte N30, Bn1 @ v127
	.byte W36
	.byte PEND
track_53_lbl_220f0c:
	.byte N12, Ds1, v112
	.byte W24
	.byte N06 @ Ds1, v112
	.byte W12
	.byte N12 @ Ds1, v112
	.byte W24
	.byte N06 @ Ds1, v112
	.byte W12
	.byte N12, En1 @ v112
	.byte W12
	.byte N06 @ En1, v112
	.byte W12
	.byte N12 @ En1, v112
	.byte W12
	.byte N06 @ En1, v112
	.byte W12
	.byte PEND
	.byte PATT
		.word track_53_lbl_220f0c
	.byte PATT
		.word track_53_lbl_220f0c
	.byte PATT
		.word track_53_lbl_220f0c
	.byte PATT
		.word track_53_lbl_220ed8
	.byte PATT
		.word track_53_lbl_220ed8
	.byte PATT
		.word track_53_lbl_220ed8
	.byte PATT
		.word track_53_lbl_220ed8
	.byte N96, Fs1, v092
	.byte W96
	.byte Gn1 @ N96, v092
	.byte W96
	.byte PATT
		.word track_53_lbl_220efc
	.byte PATT
		.word track_53_lbl_220f04
	.byte PATT
		.word track_53_lbl_220f0c
	.byte PATT
		.word track_53_lbl_220f0c
	.byte PATT
		.word track_53_lbl_220f0c
	.byte PATT
		.word track_53_lbl_220f0c
	.byte PATT
		.word track_53_lbl_220ed8
	.byte PATT
		.word track_53_lbl_220ed8
	.byte PATT
		.word track_53_lbl_220ed8
	.byte PATT
		.word track_53_lbl_220ed8
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte N06, An1, v080
	.byte W12
	.byte N12 @ An1, v080
	.byte W24
	.byte N06 @ An1, v080
	.byte W12
	.byte N12 @ An1, v080
	.byte W12
	.byte N06 @ An1, v080
	.byte W12
	.byte N12, Cn2 @ v080
	.byte W24
	.byte N06 @ Cn2, v080
	.byte W12
	.byte N12 @ Cn2, v080
	.byte W24
	.byte N06 @ Cn2, v080
	.byte W12
	.byte N12, An1 @ v080
	.byte W12
	.byte N06 @ An1, v080
	.byte W24
	.byte N12 @ An1, v080
	.byte W12
	.byte N06 @ An1, v080
	.byte W24
	.byte N12, Cn2, v112
	.byte W24
	.byte N06 @ Cn2, v112
	.byte W12
	.byte N12 @ Cn2, v112
	.byte W24
	.byte N06 @ Cn2, v112
	.byte W12
	.byte N12, Ds1 @ v112
	.byte W24
	.byte N06 @ Ds1, v112
	.byte W12
	.byte N12, Fs1, v120
	.byte W12
	.byte N06 @ Fs1, v120
	.byte W12
	.byte An1, v127 @ N06
	.byte W12
	.byte W18
	.byte GOTO
		.word track_53_lbl_220ebf
	.byte FINE

.align 2

track_53:
	.byte 11
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_53_0
	.word track_53_1
	.word track_53_2
	.word track_53_3
	.word track_53_4
	.word track_53_5
	.word track_53_6
	.word track_53_7
	.word track_53_8
	.word track_53_9
	.word track_53_10

.align 2
