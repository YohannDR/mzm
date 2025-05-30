.align 2

.global track_2

track_2_0:
	.byte KEYSH, 0
	.byte TEMPO, 62
	.byte VOICE, 48
	.byte VOL, 55
	.byte PAN, c_v-17
	.byte N90, Fs3, v080
	.byte W96
	.byte Cn4, v060 @ N90
	.byte W96
	.byte As3, v072 @ N90
	.byte W96
	.byte Gn3, v060 @ N90
	.byte W96
track_2_lbl_22c273:
	.byte VOICE, 56
	.byte VOL, 63
	.byte N24, Fs2, v080
	.byte W24
	.byte Gn2, v092 @ N24
	.byte W24
	.byte An2, v096 @ N24
	.byte W24
	.byte Bn2, v100 @ N24
	.byte W24
	.byte Dn3, v104 @ N24
	.byte W24
	.byte En3, v112 @ N24
	.byte W24
	.byte Fs3, v116 @ N24
	.byte W24
	.byte Gn3, v120 @ N24
	.byte W24
	.byte N66, An3 @ v120
	.byte W72
	.byte VOICE, 51
	.byte N12, Gn3, v108
	.byte W12
	.byte N10, Fs3 @ v108
	.byte W12
	.byte VOICE, 56
	.byte N66, Gn3, v104
	.byte W72
	.byte VOICE, 51
	.byte N12, Fs3, v092
	.byte W12
	.byte N10, En3 @ v092
	.byte W12
	.byte VOICE, 56
	.byte N72, Dn3, v096
	.byte W72
	.byte N24, An3, v112
	.byte W24
	.byte VOICE, 51
	.byte N84, Dn4, v080
	.byte W96
	.byte VOICE, 56
	.byte N42, As3, v120
	.byte W48
	.byte An3, v112 @ N42
	.byte W48
	.byte Gn3, v100 @ N42
	.byte W48
	.byte Fs3, v092 @ N42
	.byte W48
	.byte N72, En3, v080
	.byte W72
	.byte N24, Fs3, v092
	.byte W24
	.byte N72, An3, v100
	.byte W72
	.byte VOICE, 51
	.byte N24, Dn4, v080
	.byte W24
	.byte VOICE, 56
	.byte N66, En3, v112
	.byte W72
	.byte N24, Fs3, v088
	.byte W24
	.byte N90, Dn3, v080
	.byte W96
	.byte N48, An2 @ v080
	.byte W48
	.byte Bn2, v088 @ N48
	.byte W48
	.byte Dn3, v096 @ N48
	.byte W48
	.byte En3, v100 @ N48
	.byte W48
	.byte N66, Dn3 @ v100
	.byte W72
	.byte N24, As2, v088
	.byte W24
	.byte N84, Gn2, v080
	.byte W96
	.byte TEMPO, 62
	.byte VOICE, 13
	.byte VOL, 44
	.byte N36, En4, v116
	.byte W36
	.byte Fs4, v127 @ N36
	.byte W36
	.byte An4, v100 @ N36
	.byte W36
	.byte N30, Dn5, v072
	.byte W36
	.byte N36, Dn4, v116
	.byte W36
	.byte Fn4, v127 @ N36
	.byte W36
	.byte VOICE, 12
	.byte N32, Cn5, v060
	.byte W36
	.byte VOICE, 13
	.byte N36, An4, v100
	.byte W36
	.byte Ds4, v116 @ N36
	.byte W36
	.byte Gn4, v127 @ N36
	.byte W36
	.byte Dn5, v072 @ N36
	.byte W36
	.byte As4, v100 @ N36
	.byte W36
	.byte An4, v127 @ N36
	.byte W36
	.byte En4, v116 @ N36
	.byte W36
	.byte Bn3 @ N36, v116
	.byte W36
	.byte En4, v127 @ N36
	.byte W36
	.byte Gs4 @ N36, v127
	.byte W36
	.byte En4, v116 @ N36
	.byte W36
	.byte Bn3 @ N36, v116
	.byte W36
	.byte En4, v127 @ N36
	.byte W36
	.byte TEMPO, 62
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
	.byte VOICE, 48
	.byte VOL, 44
	.byte N90, Dn3, v080
	.byte W96
	.byte Cn4, v092 @ N90
	.byte W96
	.byte Bn3, v072 @ N90
	.byte W96
	.byte As3, v052 @ N90
	.byte W96
	.byte Fs3, v080 @ N90
	.byte W96
	.byte Cn4, v092 @ N90
	.byte W96
	.byte As3, v072 @ N90
	.byte W96
	.byte Gn3, v052 @ N90
	.byte W96
	.byte GOTO
		.word track_2_lbl_22c273
	.byte FINE

track_2_1:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_2_lbl_22c388:
	.byte VOICE, 14
	.byte VOL, 60
	.byte N66, Fs3, v060
	.byte N66, An3 @ v060
	.byte W96
	.byte N64, An3, v076
	.byte N64, Cn4 @ v076
	.byte W96
	.byte Bn3, v088 @ N64
	.byte N64, Dn4 @ v088
	.byte W96
	.byte As3, v100 @ N64
	.byte N64, Dn4 @ v100
	.byte W96
	.byte N66, Fs3, v092
	.byte N66, An3 @ v092
	.byte W96
	.byte N64, An3, v096
	.byte N64, Dn4 @ v096
	.byte W96
	.byte Dn4, v080 @ N64
	.byte N64, As4 @ v080
	.byte W96
	.byte As3, v092 @ N64
	.byte N64, Dn4 @ v092
	.byte W96
	.byte N66, Fs3 @ v092
	.byte N66, An3 @ v092
	.byte W96
	.byte N64, An3, v096
	.byte N64, Cn4 @ v096
	.byte W96
	.byte Bn3, v100 @ N64
	.byte N64, Dn4 @ v100
	.byte W96
	.byte As3, v072 @ N64
	.byte N64, Dn4 @ v072
	.byte W96
	.byte N66, Fs3 @ v072
	.byte N66, An3 @ v072
	.byte W96
	.byte N64, An3, v084
	.byte N64, Cn4 @ v084
	.byte W96
	.byte Dn3 @ N64, v084
	.byte N64, As3 @ v084
	.byte W96
	.byte As3, v072 @ N64
	.byte N64, Dn4 @ v072
	.byte W96
	.byte VOICE, 51
	.byte VOL, 44
	.byte N36, En3, v092
	.byte W36
	.byte Fs3, v100 @ N36
	.byte W36
	.byte An3, v112 @ N36
	.byte W36
	.byte Dn4 @ N36, v112
	.byte W36
	.byte Dn3, v092 @ N36
	.byte W36
	.byte Fn3, v100 @ N36
	.byte W36
	.byte Cn4, v120 @ N36
	.byte W36
	.byte An3, v112 @ N36
	.byte W36
	.byte Ds3, v092 @ N36
	.byte W36
	.byte Gn3, v100 @ N36
	.byte W36
	.byte Dn4, v120 @ N36
	.byte W36
	.byte As3, v112 @ N36
	.byte W36
	.byte An3, v127 @ N36
	.byte W36
	.byte En3, v112 @ N36
	.byte W36
	.byte Bn2 @ N36, v112
	.byte W36
	.byte En3, v127 @ N36
	.byte W36
	.byte Gs3 @ N36, v127
	.byte W36
	.byte En3, v112 @ N36
	.byte W36
	.byte Bn2 @ N36, v112
	.byte W36
	.byte En3, v127 @ N36
	.byte W36
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
	.byte GOTO
		.word track_2_lbl_22c388
	.byte FINE

track_2_2:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_2_lbl_22c446:
	.byte VOICE, 14
	.byte VOL, 49
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte N66, Dn3, v116
	.byte W96
	.byte Fs3 @ N66, v116
	.byte W96
	.byte Gn3 @ N66, v116
	.byte W96
	.byte N66 @ Gn3, v116
	.byte W96
	.byte W96
	.byte W96
	.byte Gn3, v127 @ N66
	.byte W96
	.byte N66 @ Gn3, v127
	.byte W96
	.byte W96
	.byte W96
	.byte N66 @ Gn3, v127
	.byte W96
	.byte N66 @ Gn3, v127
	.byte W96
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 18
	.byte VOL, 53
	.byte N72, Dn1, v080
	.byte W96
	.byte Dn1, v092 @ N72
	.byte W96
	.byte Dn1, v072 @ N72
	.byte W96
	.byte Dn1, v080 @ N72
	.byte W96
	.byte Dn1, v072 @ N72
	.byte W96
	.byte Dn1, v080 @ N72
	.byte W96
	.byte Dn1, v072 @ N72
	.byte W96
	.byte Dn1, v080 @ N72
	.byte W96
	.byte Dn1, v072 @ N72
	.byte W96
	.byte Dn1, v076 @ N72
	.byte W96
	.byte Dn1, v072 @ N72
	.byte W96
	.byte Dn1, v080 @ N72
	.byte W96
	.byte Dn1, v072 @ N72
	.byte W96
	.byte Dn1, v080 @ N72
	.byte W96
	.byte Dn1, v072 @ N72
	.byte W96
	.byte Dn1, v080 @ N72
	.byte W96
	.byte Dn1, v072 @ N72
	.byte W96
	.byte Dn1, v076 @ N72
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_2_lbl_22c446
	.byte FINE

track_2_3:
	.byte KEYSH, 0
	.byte VOICE, 49
	.byte VOL, 44
	.byte PAN, c_v+20
	.byte N12, An5, v100
	.byte W48
	.byte Gn5, v096 @ N12
	.byte W48
	.byte Fs5, v092 @ N12
	.byte W48
	.byte En5, v088 @ N12
	.byte W48
	.byte Gn5, v084 @ N12
	.byte W48
	.byte Fs5, v080 @ N12
	.byte W48
track_2_lbl_22c4d3:
	.byte N12, En5, v076
	.byte W48
	.byte Dn5, v072 @ N12
	.byte W48
	.byte PEND
track_2_lbl_22c4db:
	.byte N12, An5, v092
	.byte W48
	.byte Gn5, v084 @ N12
	.byte W48
	.byte PEND
track_2_lbl_22c4e3:
	.byte N12, Fs5, v076
	.byte W48
	.byte En5, v072 @ N12
	.byte W48
	.byte PEND
track_2_lbl_22c4eb:
	.byte N12, Gn5, v092
	.byte W48
	.byte Fs5, v084 @ N12
	.byte W48
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c4d3
	.byte PATT
		.word track_2_lbl_22c4db
	.byte PATT
		.word track_2_lbl_22c4e3
	.byte N12, Gn5, v120
	.byte W48
	.byte Fs5, v116 @ N12
	.byte W48
	.byte En5, v108 @ N12
	.byte W48
	.byte Dn5, v100 @ N12
	.byte W48
	.byte PATT
		.word track_2_lbl_22c4db
	.byte PATT
		.word track_2_lbl_22c4e3
	.byte PATT
		.word track_2_lbl_22c4eb
	.byte PATT
		.word track_2_lbl_22c4d3
	.byte N12, An5, v092
	.byte W48
	.byte Gn5, v088 @ N12
	.byte W48
	.byte Fs5, v084 @ N12
	.byte W48
	.byte En5 @ N12, v084
	.byte W48
	.byte Gn5, v080 @ N12
	.byte W48
	.byte Fs5, v076 @ N12
	.byte W48
	.byte En5, v072 @ N12
	.byte W48
	.byte Dn5 @ N12, v072
	.byte W48
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 19
	.byte VOL, 47
	.byte N80, An1, v044
	.byte W96
	.byte An1, v056 @ N80
	.byte W96
	.byte An1, v072 @ N80
	.byte W96
	.byte An1, v080 @ N80
	.byte W96
	.byte An1, v072 @ N80
	.byte W96
	.byte An1, v080 @ N80
	.byte W96
	.byte An1, v072 @ N80
	.byte W96
	.byte An1, v080 @ N80
	.byte W96
	.byte An1, v072 @ N80
	.byte W96
	.byte An1, v076 @ N80
	.byte W96
	.byte An1, v072 @ N80
	.byte W96
	.byte An1, v080 @ N80
	.byte W96
	.byte An1, v072 @ N80
	.byte W96
	.byte An1, v080 @ N80
	.byte W96
	.byte An1, v072 @ N80
	.byte W96
	.byte An1, v080 @ N80
	.byte W96
	.byte An1, v072 @ N80
	.byte W96
	.byte An1, v076 @ N80
	.byte W96
	.byte VOICE, 49
	.byte VOL, 70
	.byte N12, An5, v092
	.byte W48
	.byte Gn5, v084 @ N12
	.byte W48
	.byte PATT
		.word track_2_lbl_22c4e3
	.byte PATT
		.word track_2_lbl_22c4eb
	.byte PATT
		.word track_2_lbl_22c4d3
	.byte VOICE, 49
	.byte VOL, 47
	.byte N12, An5, v092
	.byte W48
	.byte Gn5, v084 @ N12
	.byte W48
	.byte PATT
		.word track_2_lbl_22c4e3
	.byte PATT
		.word track_2_lbl_22c4eb
	.byte PATT
		.word track_2_lbl_22c4d3
	.byte GOTO
		.word track_2_lbl_22c4db
	.byte FINE

track_2_4:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 22
	.byte PAN, c_v-22
	.byte W24
	.byte N12, An4, v092
	.byte W16
	.byte An4, v052 @ N12
	.byte W32
	.byte Gn4, v092 @ N12
	.byte W16
	.byte Gn4, v052 @ N12
	.byte W08
	.byte W24
	.byte Fs4, v092 @ N12
	.byte W16
	.byte Fs4, v052 @ N12
	.byte W32
	.byte En4, v092 @ N12
	.byte W16
	.byte En4, v052 @ N12
	.byte W08
	.byte W24
	.byte Gn4, v092 @ N12
	.byte W16
	.byte Gn4, v052 @ N12
	.byte W32
	.byte Fs4, v092 @ N12
	.byte W16
	.byte Fs4, v052 @ N12
	.byte W08
	.byte W24
	.byte En4, v092 @ N12
	.byte W16
	.byte En4, v052 @ N12
	.byte W32
	.byte Dn4, v092 @ N12
	.byte W16
	.byte Dn4, v052 @ N12
	.byte W08
track_2_lbl_22c5f6:
	.byte W24
	.byte N12, An4, v100
	.byte W16
	.byte An4, v072 @ N12
	.byte W32
	.byte Gn4, v100 @ N12
	.byte W16
	.byte Gn4, v072 @ N12
	.byte W08
	.byte PEND
track_2_lbl_22c605:
	.byte W24
	.byte N12, Fs4, v100
	.byte W16
	.byte Fs4, v072 @ N12
	.byte W32
	.byte En4, v100 @ N12
	.byte W16
	.byte En4, v072 @ N12
	.byte W08
	.byte PEND
track_2_lbl_22c614:
	.byte W24
	.byte N12, Gn4, v100
	.byte W16
	.byte Gn4, v072 @ N12
	.byte W32
	.byte Fs4, v100 @ N12
	.byte W16
	.byte Fs4, v072 @ N12
	.byte W08
	.byte PEND
track_2_lbl_22c623:
	.byte W24
	.byte N12, En4, v100
	.byte W16
	.byte En4, v072 @ N12
	.byte W32
	.byte Dn4, v100 @ N12
	.byte W16
	.byte Dn4, v072 @ N12
	.byte W08
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c5f6
	.byte PATT
		.word track_2_lbl_22c605
	.byte PATT
		.word track_2_lbl_22c614
	.byte PATT
		.word track_2_lbl_22c623
	.byte PATT
		.word track_2_lbl_22c5f6
	.byte PATT
		.word track_2_lbl_22c605
	.byte PATT
		.word track_2_lbl_22c614
	.byte PATT
		.word track_2_lbl_22c623
	.byte W24
	.byte N12, An4, v092
	.byte W16
	.byte N12 @ An4, v092
	.byte W32
	.byte Gn4, v088 @ N12
	.byte W16
	.byte N12 @ Gn4, v088
	.byte W08
	.byte W24
	.byte Fs4, v084 @ N12
	.byte W16
	.byte N12 @ Fs4, v084
	.byte W32
	.byte En4 @ N12, v084
	.byte W16
	.byte En4, v080 @ N12
	.byte W08
	.byte W24
	.byte Gn4 @ N12, v080
	.byte W16
	.byte N12 @ Gn4, v080
	.byte W32
	.byte Fs4, v076 @ N12
	.byte W16
	.byte N12 @ Fs4, v076
	.byte W08
	.byte W24
	.byte En4 @ N12, v076
	.byte W16
	.byte En4, v072 @ N12
	.byte W32
	.byte Dn4 @ N12, v072
	.byte W16
	.byte N12 @ Dn4, v072
	.byte W08
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 20
	.byte VOL, 22
	.byte W96
	.byte W96
track_2_lbl_22c695:
	.byte N16, Dn5, v080
	.byte W16
	.byte Dn5, v048 @ N16
	.byte W16
	.byte Dn5, v024 @ N16
	.byte W64
	.byte PEND
track_2_lbl_22c6a0:
	.byte N16, As5, v080
	.byte W16
	.byte As5, v048 @ N16
	.byte W16
	.byte As5, v024 @ N16
	.byte W64
	.byte PEND
track_2_lbl_22c6ab:
	.byte N16, Fn5, v080
	.byte W16
	.byte Fn5, v048 @ N16
	.byte W16
	.byte Fn5, v024 @ N16
	.byte W64
	.byte PEND
	.byte W96
	.byte PATT
		.word track_2_lbl_22c695
track_2_lbl_22c6bc:
	.byte N16, Cn6, v080
	.byte W16
	.byte Cn6, v048 @ N16
	.byte W16
	.byte Cn6, v024 @ N16
	.byte W64
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c6a0
	.byte W96
	.byte PATT
		.word track_2_lbl_22c695
	.byte PATT
		.word track_2_lbl_22c6a0
	.byte PATT
		.word track_2_lbl_22c6ab
	.byte W96
	.byte PATT
		.word track_2_lbl_22c695
	.byte PATT
		.word track_2_lbl_22c6bc
	.byte PATT
		.word track_2_lbl_22c6a0
	.byte W96
track_2_lbl_22c6ed:
	.byte VOICE, 20
	.byte VOL, 27
	.byte W24
	.byte N12, An4, v100
	.byte W16
	.byte An4, v072 @ N12
	.byte W32
	.byte Gn4, v100 @ N12
	.byte W16
	.byte Gn4, v072 @ N12
	.byte W08
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c605
	.byte PATT
		.word track_2_lbl_22c614
	.byte PATT
		.word track_2_lbl_22c623
	.byte PATT
		.word track_2_lbl_22c6ed
	.byte PATT
		.word track_2_lbl_22c605
	.byte PATT
		.word track_2_lbl_22c614
	.byte PATT
		.word track_2_lbl_22c623
	.byte GOTO
		.word track_2_lbl_22c5f6
	.byte W04
	.byte FINE

track_2_5:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_2_lbl_22c732:
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
	.byte VOICE, 53
	.byte VOL, 70
	.byte W12
	.byte N06, An4, v036
	.byte W18
	.byte N06 @ An4, v036
	.byte W18
	.byte N06 @ An4, v036
	.byte W18
	.byte N06 @ An4, v036
	.byte W06
track_2_lbl_22c751:
	.byte W12
	.byte N06, An4, v036
	.byte W18
	.byte N06 @ An4, v036
	.byte W18
	.byte N06 @ An4, v036
	.byte W18
	.byte N06 @ An4, v036
	.byte W06
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c751
	.byte PATT
		.word track_2_lbl_22c751
track_2_lbl_22c767:
	.byte W12
	.byte N06, As4, v036
	.byte W18
	.byte N06 @ As4, v036
	.byte W18
	.byte N06 @ As4, v036
	.byte W18
	.byte N06 @ As4, v036
	.byte W06
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c767
track_2_lbl_22c778:
	.byte N06, Bn3, v060
	.byte W06
	.byte En4 @ N06, v060
	.byte W06
	.byte An4, v036 @ N06
	.byte W24
	.byte Bn3, v060 @ N06
	.byte W06
	.byte En4 @ N06, v060
	.byte W06
	.byte An4, v036 @ N06
	.byte W24
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c778
	.byte N06, Bn3, v060
	.byte W06
	.byte En4 @ N06, v060
	.byte W06
	.byte Gs4, v036 @ N06
	.byte W24
	.byte Bn3, v056 @ N06
	.byte W06
	.byte En4 @ N06, v056
	.byte W06
	.byte Gs4, v052 @ N06
	.byte W24
	.byte Bn3, v044 @ N06
	.byte W06
	.byte En4 @ N06, v044
	.byte W06
	.byte Gs4, v040 @ N06
	.byte W24
	.byte Bn3, v036 @ N06
	.byte W06
	.byte En4, v032 @ N06
	.byte W06
	.byte Gs4 @ N06, v032
	.byte W24
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
	.byte GOTO
		.word track_2_lbl_22c732
	.byte FINE

track_2_6:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_2_lbl_22c7d8:
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
	.byte VOICE, 53
	.byte VOL, 70
	.byte N06, Dn4, v088
	.byte W24
	.byte N06 @ Dn4, v088
	.byte W18
	.byte N06 @ Dn4, v088
	.byte W18
	.byte N06 @ Dn4, v088
	.byte W12
track_2_lbl_22c7f6:
	.byte W06
	.byte N06, Dn4, v088
	.byte W18
	.byte N06 @ Dn4, v088
	.byte W18
	.byte N06 @ Dn4, v088
	.byte W18
	.byte N06 @ Dn4, v088
	.byte W12
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c7f6
	.byte PATT
		.word track_2_lbl_22c7f6
	.byte W06
	.byte N06, Dn4, v088
	.byte W18
	.byte Ds4 @ N06, v088
	.byte W18
	.byte N06 @ Ds4, v088
	.byte W18
	.byte N06 @ Ds4, v088
	.byte W12
	.byte W06
	.byte N06 @ Ds4, v088
	.byte W18
	.byte N06 @ Ds4, v088
	.byte W18
	.byte N06 @ Ds4, v088
	.byte W18
	.byte N06 @ Ds4, v088
	.byte W12
track_2_lbl_22c820:
	.byte W18
	.byte N06, Bn3, v056
	.byte W06
	.byte En4 @ N06, v056
	.byte W06
	.byte An4, v036 @ N06
	.byte W24
	.byte Bn3, v056 @ N06
	.byte W06
	.byte En4 @ N06, v056
	.byte W06
	.byte An4, v036 @ N06
	.byte W06
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c820
	.byte W18
	.byte N06, Bn3, v056
	.byte W06
	.byte En4 @ N06, v056
	.byte W06
	.byte Gs4, v036 @ N06
	.byte W24
	.byte Bn3, v056 @ N06
	.byte W06
	.byte En4 @ N06, v056
	.byte W06
	.byte Gs4, v052 @ N06
	.byte W06
	.byte W18
	.byte Bn3, v044 @ N06
	.byte W06
	.byte En4 @ N06, v044
	.byte W06
	.byte Gs4, v040 @ N06
	.byte W24
	.byte Bn3, v036 @ N06
	.byte W06
	.byte En4, v032 @ N06
	.byte W06
	.byte Gs4 @ N06, v032
	.byte W06
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
	.byte GOTO
		.word track_2_lbl_22c7d8
	.byte FINE

track_2_7:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_2_lbl_22c883:
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
	.byte VOICE, 53
	.byte VOL, 70
	.byte W18
	.byte N06, An3, v088
	.byte W18
	.byte N06 @ An3, v088
	.byte W18
	.byte N06 @ An3, v088
	.byte W18
track_2_lbl_22c8a0:
	.byte N06, An3, v088
	.byte W18
	.byte N06 @ An3, v088
	.byte W18
	.byte N06 @ An3, v088
	.byte W18
	.byte N06 @ An3, v088
	.byte W18
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c8a0
	.byte PATT
		.word track_2_lbl_22c8a0
	.byte N06, An3, v088
	.byte W18
	.byte As3 @ N06, v088
	.byte W18
	.byte N06 @ As3, v088
	.byte W18
	.byte N06 @ As3, v088
	.byte W18
	.byte N06 @ As3, v088
	.byte W18
	.byte N06 @ As3, v088
	.byte W18
	.byte N06 @ As3, v088
	.byte W18
	.byte N06 @ As3, v088
	.byte W18
	.byte W72
	.byte W72
	.byte W72
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
	.byte GOTO
		.word track_2_lbl_22c883
	.byte FINE

track_2_8:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_2_lbl_22c8f3:
	.byte VOICE, 47
	.byte VOL, 70
	.byte N96, Dn1, v072
	.byte W96
	.byte Fs1 @ N96, v072
	.byte W96
	.byte Gn1 @ N96, v072
	.byte W96
	.byte N96 @ Gn1, v072
	.byte W96
	.byte Dn1 @ N96, v072
	.byte W96
	.byte Fs1 @ N96, v072
	.byte W96
	.byte Gn1 @ N96, v072
	.byte W96
	.byte N96 @ Gn1, v072
	.byte W96
	.byte Dn1 @ N96, v072
	.byte W96
	.byte Fs1 @ N96, v072
	.byte W96
	.byte Gn1 @ N96, v072
	.byte W96
	.byte N96 @ Gn1, v072
	.byte W96
	.byte Dn1 @ N96, v072
	.byte W96
	.byte Fs1 @ N96, v072
	.byte W96
	.byte Gn1 @ N96, v072
	.byte W96
	.byte N96 @ Gn1, v072
	.byte W96
	.byte VOICE, 55
	.byte VOL, 33
	.byte N18, Dn2, v080
	.byte W24
	.byte N10, An2 @ v080
	.byte W12
	.byte N24, Dn3, v040
	.byte W36
	.byte N18, Dn2, v080
	.byte W24
	.byte N10, An2 @ v080
	.byte W12
	.byte N24, Dn3, v040
	.byte W36
track_2_lbl_22c933:
	.byte N18, As1, v080
	.byte W24
	.byte N10, Fn2 @ v080
	.byte W12
	.byte N24, Cn3, v040
	.byte W36
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c933
track_2_lbl_22c944:
	.byte N18, Ds1, v100
	.byte W24
	.byte N10, As1 @ v100
	.byte W12
	.byte N24, Ds2, v060
	.byte W36
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c944
track_2_lbl_22c955:
	.byte N18, En1, v100
	.byte W24
	.byte N10, Bn1 @ v100
	.byte W12
	.byte N24, En2, v060
	.byte W36
	.byte PEND
	.byte PATT
		.word track_2_lbl_22c955
	.byte PATT
		.word track_2_lbl_22c955
	.byte PATT
		.word track_2_lbl_22c955
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
	.byte GOTO
		.word track_2_lbl_22c8f3
	.byte FINE

.align 2

track_2:
	.byte 9
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_2_0
	.word track_2_1
	.word track_2_2
	.word track_2_3
	.word track_2_4
	.word track_2_5
	.word track_2_6
	.word track_2_7
	.word track_2_8

.align 2
