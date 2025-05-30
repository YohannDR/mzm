.align 2

.global track_6

track_6_0:
	.byte KEYSH, 0
	.byte TEMPO, 37
	.byte VOICE, 30
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N28, Gn4, v072
	.byte W36
	.byte N24, Fn4 @ v072
	.byte W24
	.byte N18, As4 @ v072
	.byte W12
track_6_lbl_22cdba:
	.byte N28, Gn4, v072
	.byte W36
	.byte N36, Fn4 @ v072
	.byte W60
	.byte PEND
track_6_lbl_22cdc2:
	.byte N28, Gn4, v072
	.byte W36
	.byte N24, Fn4 @ v072
	.byte W24
	.byte N18, As4 @ v072
	.byte W12
	.byte PEND
track_6_lbl_22cdcd:
	.byte N28, Gn4, v072
	.byte W36
	.byte N36, An4 @ v072
	.byte W60
	.byte PEND
	.byte N28, Gn4 @ v072
	.byte W36
	.byte N24, Fn4 @ v072
	.byte W24
	.byte N12, As4 @ v072
	.byte W12
	.byte PATT
		.word track_6_lbl_22cdba
	.byte PATT
		.word track_6_lbl_22cdc2
	.byte PATT
		.word track_6_lbl_22cdcd
track_6_lbl_22cded:
	.byte VOICE, 12
	.byte N36, Cn4, v060
	.byte W36
	.byte Dn4 @ N36, v060
	.byte W36
track_6_lbl_22cdf5:
	.byte N24, Fn4, v060
	.byte W24
	.byte N06, En4 @ v060
	.byte W06
	.byte Dn4 @ N06, v060
	.byte W06
	.byte An3 @ N06, v060
	.byte W06
	.byte Gn3 @ N06, v060
	.byte W06
	.byte N36, An3 @ v060
	.byte W48
	.byte PEND
	.byte Cn4 @ N36, v060
	.byte W36
	.byte Dn4 @ N36, v060
	.byte W36
	.byte PATT
		.word track_6_lbl_22cdf5
	.byte VOICE, 30
	.byte N24, An4, v056
	.byte W24
	.byte N12, Bn4, v052
	.byte W12
	.byte N24, Gn4 @ v052
	.byte W24
	.byte N12, An4, v048
	.byte W12
	.byte N54, Fn4 @ v048
	.byte W72
	.byte N24, An4, v056
	.byte W24
	.byte N12, Bn4, v052
	.byte W12
	.byte N24, Gn4 @ v052
	.byte W24
	.byte N12, An4, v048
	.byte W12
	.byte N54, Fn4 @ v048
	.byte W72
track_6_lbl_22ce35:
	.byte N24, Dn5, v056
	.byte W24
	.byte N12, En5, v052
	.byte W12
	.byte N24, Cn5 @ v052
	.byte W24
	.byte N12, Dn5, v048
	.byte W12
	.byte PEND
	.byte N54, As4 @ v048
	.byte W72
	.byte PATT
		.word track_6_lbl_22ce35
	.byte N36, Fn5, v056
	.byte W36
	.byte En5, v060 @ N36
	.byte W36
	.byte W72
	.byte W36
	.byte N48, Fn5, v052
	.byte W36
	.byte W72
	.byte W36
	.byte N48 @ Fn5, v052
	.byte W36
	.byte W72
	.byte W36
	.byte N48 @ Fn5, v052
	.byte W36
	.byte W72
	.byte W36
	.byte N48 @ Fn5, v052
	.byte W36
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W36
	.byte N96 @ Fn5, v052
	.byte W36
	.byte W72
	.byte W36
	.byte N96 @ Fn5, v052
	.byte W36
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
track_6_lbl_22ce7a:
	.byte N36, Gn4, v100
	.byte W36
	.byte N24, Fn4 @ v100
	.byte W24
	.byte N12, As4 @ v100
	.byte W12
	.byte PEND
track_6_lbl_22ce85:
	.byte N36, Gn4, v100
	.byte W36
	.byte N42, Fn4 @ v100
	.byte W60
	.byte PEND
	.byte PATT
		.word track_6_lbl_22ce7a
track_6_lbl_22ce92:
	.byte N36, Gn4, v100
	.byte W36
	.byte N42, An4 @ v100
	.byte W60
	.byte PEND
	.byte PATT
		.word track_6_lbl_22ce7a
	.byte PATT
		.word track_6_lbl_22ce85
	.byte PATT
		.word track_6_lbl_22ce7a
	.byte PATT
		.word track_6_lbl_22ce92
	.byte GOTO
		.word track_6_lbl_22cded
	.byte W72
	.byte FINE

track_6_1:
	.byte KEYSH, 0
	.byte VOICE, 34
	.byte VOL, 80
	.byte PAN, c_v+20
	.byte PRIO, 30
	.byte N24, Dn4, v032
	.byte W36
	.byte Cn4 @ N24, v032
	.byte W36
	.byte As3 @ N24, v032
	.byte W36
	.byte N36, An3 @ v032
	.byte W60
	.byte N24, Dn4 @ v032
	.byte W36
	.byte Cn4 @ N24, v032
	.byte W36
	.byte As3 @ N24, v032
	.byte W36
	.byte N36, Fn3 @ v032
	.byte W60
	.byte N24, Dn4 @ v032
	.byte W36
	.byte Cn4 @ N24, v032
	.byte W36
	.byte As3 @ N24, v032
	.byte W36
	.byte N36, An3 @ v032
	.byte W60
	.byte N24, Dn4 @ v032
	.byte W36
	.byte Cn4 @ N24, v032
	.byte W36
track_6_lbl_22cee3:
	.byte N28, As3, v032
	.byte W36
	.byte N36, Fn3 @ v032
	.byte W60
	.byte PEND
track_6_lbl_22ceeb:
	.byte VOICE, 28
	.byte VOL, 75
	.byte W12
	.byte N12, Cn2, v072
	.byte W12
	.byte N18, Dn2, v060
	.byte W24
	.byte N12, Dn2, v072
	.byte W12
	.byte N18, En2, v060
	.byte W12
track_6_lbl_22cf00:
	.byte W12
	.byte N12, Dn2, v072
	.byte W12
	.byte N32, Fn2, v060
	.byte W36
	.byte N24, An1, v072
	.byte W36
	.byte PEND
	.byte W12
	.byte N12, Cn2 @ v072
	.byte W12
	.byte N18, Dn2, v060
	.byte W24
	.byte N12, Dn2, v072
	.byte W12
	.byte N18, En2, v060
	.byte W12
	.byte PATT
		.word track_6_lbl_22cf00
	.byte VOICE, 30
	.byte VOL, 80
	.byte N28, En3, v120
	.byte W36
	.byte Dn3, v127 @ N28
	.byte W36
	.byte N36, Cn3 @ v127
	.byte W72
	.byte N28, En3 @ v127
	.byte W36
	.byte Dn3 @ N28, v127
	.byte W36
	.byte N36, Cn3 @ v127
	.byte W72
	.byte N28, An3 @ v127
	.byte W36
	.byte Gn3 @ N28, v127
	.byte W36
	.byte N36, Fn3 @ v127
	.byte W72
	.byte N28, An3 @ v127
	.byte W36
	.byte Gn3 @ N28, v127
	.byte W36
	.byte Dn3 @ N28, v127
	.byte W36
	.byte Cn3 @ N28, v127
	.byte W36
	.byte W72
	.byte W48
	.byte VOICE, 34
	.byte N06, Fn3 @ v127
	.byte W06
	.byte Dn3 @ N06, v127
	.byte W06
	.byte Ds3 @ N06, v127
	.byte W06
	.byte Fn3 @ N06, v127
	.byte W06
track_6_lbl_22cf57:
	.byte N06, Ds3, v127
	.byte W02
	.byte N01, En3 @ v127
	.byte W04
	.byte N06, Dn3 @ v127
	.byte W66
	.byte PEND
track_6_lbl_22cf62:
	.byte W48
	.byte N06, Fn3, v127
	.byte W06
	.byte Dn3 @ N06, v127
	.byte W06
	.byte Ds3 @ N06, v127
	.byte W06
	.byte Fn3 @ N06, v127
	.byte W06
	.byte PEND
	.byte Ds3 @ N06, v127
	.byte W06
	.byte Dn3 @ N06, v127
	.byte W66
	.byte PATT
		.word track_6_lbl_22cf62
	.byte PATT
		.word track_6_lbl_22cf57
	.byte PATT
		.word track_6_lbl_22cf62
	.byte W72
track_6_lbl_22cf82:
	.byte W48
	.byte N06, Gs3, v127
	.byte W06
	.byte Fn3 @ N06, v127
	.byte W06
	.byte Fs3 @ N06, v127
	.byte W06
	.byte Gs3 @ N06, v127
	.byte W06
	.byte PEND
track_6_lbl_22cf8e:
	.byte N06, Fs3, v127
	.byte W02
	.byte N01, Gn3 @ v127
	.byte W04
	.byte N06, Fn3 @ v127
	.byte W66
	.byte PEND
	.byte PATT
		.word track_6_lbl_22cf82
	.byte PATT
		.word track_6_lbl_22cf8e
	.byte PATT
		.word track_6_lbl_22cf82
	.byte PATT
		.word track_6_lbl_22cf8e
	.byte PATT
		.word track_6_lbl_22cf62
	.byte PATT
		.word track_6_lbl_22cf57
	.byte PATT
		.word track_6_lbl_22cf62
	.byte PATT
		.word track_6_lbl_22cf57
	.byte W96
	.byte N24, Dn4, v040
	.byte W36
	.byte Cn4 @ N24, v040
	.byte W36
	.byte As3 @ N24, v040
	.byte W36
	.byte N36, An3 @ v040
	.byte W60
	.byte N24, Dn4 @ v040
	.byte W36
	.byte Cn4 @ N24, v040
	.byte W36
	.byte As3 @ N24, v040
	.byte W36
	.byte N36, An3 @ v040
	.byte W60
	.byte VOICE, 34
	.byte VOL, 80
	.byte N24, Dn4, v032
	.byte W36
	.byte Cn4 @ N24, v032
	.byte W36
	.byte As3 @ N24, v032
	.byte W36
	.byte N36, An3 @ v032
	.byte W60
	.byte N24, Dn4 @ v032
	.byte W36
	.byte Cn4 @ N24, v032
	.byte W36
	.byte As3 @ N24, v032
	.byte W36
	.byte N36, Fn3 @ v032
	.byte W60
	.byte N24, Dn4 @ v032
	.byte W36
	.byte Cn4 @ N24, v032
	.byte W36
	.byte As3 @ N24, v032
	.byte W36
	.byte N36, An3 @ v032
	.byte W60
	.byte N24, Dn4 @ v032
	.byte W36
	.byte Cn4 @ N24, v032
	.byte W36
	.byte PATT
		.word track_6_lbl_22cee3
	.byte GOTO
		.word track_6_lbl_22ceeb
	.byte W72
	.byte FINE

track_6_2:
	.byte KEYSH, 0
	.byte VOICE, 34
	.byte VOL, 80
	.byte PAN, c_v-22
	.byte PRIO, 28
	.byte N24, As3, v032
	.byte W36
	.byte An3 @ N24, v032
	.byte W36
	.byte Ds3 @ N24, v032
	.byte W36
	.byte N36, Dn3 @ v032
	.byte W60
	.byte N24, As3 @ v032
	.byte W36
	.byte An3 @ N24, v032
	.byte W36
	.byte Ds3 @ N24, v032
	.byte W36
	.byte N36, Dn3 @ v032
	.byte W60
	.byte N24, As3 @ v032
	.byte W36
	.byte An3 @ N24, v032
	.byte W36
	.byte Ds3 @ N24, v032
	.byte W36
	.byte N36, Dn3 @ v032
	.byte W60
	.byte N24, As3 @ v032
	.byte W36
	.byte An3 @ N24, v032
	.byte W36
track_6_lbl_22d039:
	.byte N28, Ds3, v032
	.byte W36
	.byte N36, Dn3 @ v032
	.byte W60
	.byte PEND
track_6_lbl_22d041:
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte VOICE, 30
	.byte N28, Cn3, v120
	.byte W36
	.byte Bn2, v127 @ N28
	.byte W36
	.byte N36, An2 @ v127
	.byte W72
	.byte N28, Cn3 @ v127
	.byte W36
	.byte Bn2 @ N28, v127
	.byte W36
	.byte N36, An2 @ v127
	.byte W72
	.byte N28, Fn3 @ v127
	.byte W36
	.byte En3 @ N28, v127
	.byte W36
	.byte N36, Dn3 @ v127
	.byte W72
	.byte N28, Fn3 @ v127
	.byte W36
	.byte En3 @ N28, v127
	.byte W36
	.byte As2 @ N28, v127
	.byte W36
	.byte Gn2 @ N28, v127
	.byte W36
	.byte W72
	.byte W48
	.byte VOICE, 34
	.byte W24
	.byte W02
	.byte N01, En3 @ v127
	.byte W68
	.byte W02
	.byte W72
	.byte W72
	.byte W72
	.byte W02
	.byte N01 @ En3, v127
	.byte W68
	.byte W02
	.byte W72
	.byte W72
	.byte W72
	.byte W02
	.byte Gn3 @ N01, v127
	.byte W68
	.byte W02
	.byte W72
	.byte W02
	.byte N01 @ Gn3, v127
	.byte W68
	.byte W02
	.byte W72
	.byte W02
	.byte N01 @ Gn3, v127
	.byte W68
	.byte W02
	.byte W72
	.byte W02
	.byte En3 @ N01, v127
	.byte W68
	.byte W02
	.byte W72
	.byte W02
	.byte N01 @ En3, v127
	.byte W68
	.byte W02
	.byte W96
	.byte N24, As3, v040
	.byte W36
	.byte An3 @ N24, v040
	.byte W36
	.byte Ds3 @ N24, v040
	.byte W36
	.byte N36, Dn3 @ v040
	.byte W60
	.byte N24, As3 @ v040
	.byte W36
	.byte An3 @ N24, v040
	.byte W36
	.byte Ds3 @ N24, v040
	.byte W36
	.byte N36, Dn3 @ v040
	.byte W60
	.byte VOICE, 34
	.byte VOL, 80
	.byte N24, As3, v032
	.byte W36
	.byte An3 @ N24, v032
	.byte W36
	.byte Ds3 @ N24, v032
	.byte W36
	.byte N36, Dn3 @ v032
	.byte W60
	.byte N24, As3 @ v032
	.byte W36
	.byte An3 @ N24, v032
	.byte W36
	.byte Ds3 @ N24, v032
	.byte W36
	.byte N36, Dn3 @ v032
	.byte W60
	.byte N24, As3 @ v032
	.byte W36
	.byte An3 @ N24, v032
	.byte W36
	.byte Ds3 @ N24, v032
	.byte W36
	.byte N36, Dn3 @ v032
	.byte W60
	.byte N24, As3 @ v032
	.byte W36
	.byte An3 @ N24, v032
	.byte W36
	.byte PATT
		.word track_6_lbl_22d039
	.byte GOTO
		.word track_6_lbl_22d041
	.byte W72
	.byte FINE

track_6_3:
	.byte KEYSH, 0
	.byte VOICE, 28
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 118
	.byte N28, Gn1, v127
	.byte W36
	.byte N36, Fn1 @ v127
	.byte W36
track_6_lbl_22d0f1:
	.byte N28, Gn1, v127
	.byte W36
	.byte N36, Fn1 @ v127
	.byte W60
	.byte PEND
track_6_lbl_22d0f9:
	.byte N28, Gn1, v127
	.byte W36
	.byte N36, Fn1 @ v127
	.byte W36
	.byte PEND
track_6_lbl_22d101:
	.byte N28, Gn1, v127
	.byte W36
	.byte N36, An1 @ v127
	.byte W60
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d0f9
	.byte PATT
		.word track_6_lbl_22d0f1
	.byte PATT
		.word track_6_lbl_22d0f9
	.byte PATT
		.word track_6_lbl_22d101
track_6_lbl_22d11d:
	.byte VOICE, 33
	.byte VOL, 80
	.byte N36, Gn2, v064
	.byte W36
	.byte An2, v072 @ N36
	.byte W36
track_6_lbl_22d128:
	.byte N24, Cn3, v088
	.byte W36
	.byte N06, En2 @ v088
	.byte W06
	.byte Dn2 @ N06, v088
	.byte W06
	.byte N24, En2 @ v088
	.byte W48
	.byte PEND
	.byte N36, Gn2, v064
	.byte W36
	.byte An2, v088 @ N36
	.byte W36
	.byte PATT
		.word track_6_lbl_22d128
	.byte VOICE, 28
	.byte VOL, 75
	.byte N30, Dn2, v072
	.byte W36
	.byte Cn2, v060 @ N30
	.byte W36
	.byte N48, As1, v052
	.byte W72
track_6_lbl_22d150:
	.byte N30, Dn2, v072
	.byte W36
	.byte Cn2, v060 @ N30
	.byte W36
	.byte PEND
	.byte N48, As1, v052
	.byte W72
	.byte PATT
		.word track_6_lbl_22d150
	.byte N48, As1, v052
	.byte W72
	.byte PATT
		.word track_6_lbl_22d150
	.byte N48, As1, v052
	.byte W72
track_6_lbl_22d16e:
	.byte N06, Dn2, v108
	.byte W12
	.byte Dn2, v084 @ N06
	.byte W12
	.byte Dn2, v096 @ N06
	.byte W12
	.byte N13, Cn2 @ v096
	.byte W12
	.byte N24, Dn2, v084
	.byte W24
	.byte PEND
track_6_lbl_22d180:
	.byte N12, Cn2, v096
	.byte W12
	.byte N04, Dn2, v084
	.byte W60
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d16e
	.byte N12, Cn2, v096
	.byte W12
	.byte N03, Dn2 @ v096
	.byte W60
	.byte PATT
		.word track_6_lbl_22d16e
	.byte PATT
		.word track_6_lbl_22d180
	.byte PATT
		.word track_6_lbl_22d16e
	.byte PATT
		.word track_6_lbl_22d180
track_6_lbl_22d1a9:
	.byte N06, Fn2, v088
	.byte W12
	.byte Fn2, v092 @ N06
	.byte W12
	.byte Fn2, v088 @ N06
	.byte W12
	.byte N13, Ds2, v084
	.byte W12
	.byte N24, Fn2, v080
	.byte W24
	.byte PEND
track_6_lbl_22d1bc:
	.byte N12, Ds2, v084
	.byte W12
	.byte N04, Fn2, v072
	.byte W60
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d1a9
	.byte PATT
		.word track_6_lbl_22d1bc
	.byte PATT
		.word track_6_lbl_22d1a9
	.byte PATT
		.word track_6_lbl_22d1bc
	.byte N06, Dn2, v088
	.byte W12
	.byte Dn2, v092 @ N06
	.byte W12
	.byte Dn2, v088 @ N06
	.byte W12
	.byte N13, Cn2, v084
	.byte W12
	.byte N24, Dn2, v080
	.byte W24
	.byte N12, Cn2, v084
	.byte W12
	.byte N04, Dn2, v072
	.byte W60
	.byte PATT
		.word track_6_lbl_22d16e
	.byte PATT
		.word track_6_lbl_22d180
	.byte N36, Gn2, v040
	.byte W36
	.byte Fn2, v048 @ N36
	.byte W36
	.byte Ds2, v032 @ N36
	.byte W36
	.byte Dn2, v044 @ N36
	.byte W60
	.byte Gn1, v104 @ N36
	.byte W36
	.byte Fn1, v108 @ N36
	.byte W36
	.byte Ds1, v088 @ N36
	.byte W36
	.byte Dn1, v108 @ N36
	.byte W60
	.byte Gn2, v064 @ N36
	.byte W36
	.byte Fn2, v072 @ N36
	.byte W36
	.byte Ds2, v052 @ N36
	.byte W36
	.byte Dn2, v068 @ N36
	.byte W60
	.byte VOICE, 28
	.byte VOL, 80
	.byte N28, Gn1, v127
	.byte W36
	.byte N36, Fn1 @ v127
	.byte W36
	.byte PATT
		.word track_6_lbl_22d0f1
	.byte PATT
		.word track_6_lbl_22d0f9
	.byte PATT
		.word track_6_lbl_22d101
	.byte PATT
		.word track_6_lbl_22d0f9
	.byte PATT
		.word track_6_lbl_22d0f1
	.byte PATT
		.word track_6_lbl_22d0f9
	.byte PATT
		.word track_6_lbl_22d101
	.byte GOTO
		.word track_6_lbl_22d11d
	.byte W72
	.byte FINE

track_6_4:
	.byte KEYSH, 0
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
track_6_lbl_22d261:
	.byte W72
	.byte W96
	.byte W72
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
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 28
	.byte VOL, 75
	.byte N36, Gn1, v092
	.byte W36
	.byte Fn1, v100 @ N36
	.byte W36
	.byte Ds1, v080 @ N36
	.byte W36
	.byte Dn1, v096 @ N36
	.byte W60
	.byte W72
	.byte W96
	.byte Gn1, v072 @ N36
	.byte W36
	.byte Fn1, v080 @ N36
	.byte W36
	.byte Ds1, v060 @ N36
	.byte W36
	.byte Dn1, v076 @ N36
	.byte W60
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte GOTO
		.word track_6_lbl_22d261
	.byte W72
	.byte FINE

track_6_5:
	.byte KEYSH, 0
	.byte VOL, 75
	.byte PAN, c_v+15
	.byte PRIO, 29
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
track_6_lbl_22d2bd:
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte VOICE, 33
	.byte N24, An2, v056
	.byte W24
	.byte N12, Bn2 @ v056
	.byte W12
	.byte N24, Gn2 @ v056
	.byte W24
	.byte N12, An2 @ v056
	.byte W12
	.byte N24, Fn2 @ v056
	.byte W72
	.byte An2 @ N24, v056
	.byte W24
	.byte N12, Bn2 @ v056
	.byte W12
	.byte N24, Gn2 @ v056
	.byte W24
	.byte N12, An2 @ v056
	.byte W12
	.byte N24, Fn2 @ v056
	.byte W72
track_6_lbl_22d2e1:
	.byte N24, Dn3, v056
	.byte W24
	.byte N12, En3 @ v056
	.byte W12
	.byte N24, Cn3 @ v056
	.byte W24
	.byte N12, Dn3 @ v056
	.byte W12
	.byte PEND
	.byte N24, As2 @ v056
	.byte W72
	.byte PATT
		.word track_6_lbl_22d2e1
	.byte N24, Fn3, v048
	.byte W36
	.byte En3, v028 @ N24
	.byte W36
	.byte VOICE, 28
	.byte N60, Dn1, v068
	.byte W72
	.byte W72
	.byte Dn1, v076 @ N60
	.byte W72
	.byte W72
	.byte N60 @ Dn1, v076
	.byte W72
	.byte W72
	.byte N60 @ Dn1, v076
	.byte W72
	.byte W72
	.byte Fn1 @ N60, v076
	.byte W72
	.byte W72
	.byte N60 @ Fn1, v076
	.byte W72
	.byte W72
	.byte N60 @ Fn1, v076
	.byte W72
	.byte W72
	.byte Dn1 @ N60, v076
	.byte W72
	.byte W72
	.byte N60 @ Dn1, v076
	.byte W72
	.byte W72
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte VOL, 75
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte GOTO
		.word track_6_lbl_22d2bd
	.byte W72
	.byte FINE

track_6_6:
	.byte KEYSH, 0
	.byte VOICE, 33
	.byte VOL, 80
	.byte PAN, c_v-17
	.byte PRIO, 119
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
track_6_lbl_22d347:
	.byte VOICE, 33
	.byte VOL, 80
	.byte N24, Fn1, v127
	.byte W36
	.byte Gn1 @ N24, v127
	.byte W36
track_6_lbl_22d351:
	.byte N24, As1, v127
	.byte W24
	.byte N06, En3, v036
	.byte W06
	.byte Dn3 @ N06, v036
	.byte W06
	.byte An2 @ N06, v036
	.byte W06
	.byte Gn2 @ N06, v036
	.byte W06
	.byte N36, An2 @ v036
	.byte W48
	.byte PEND
	.byte N24, Fn1, v127
	.byte W36
	.byte Gn1 @ N24, v127
	.byte W36
	.byte PATT
		.word track_6_lbl_22d351
track_6_lbl_22d36e:
	.byte N06, En2, v056
	.byte W06
	.byte An1 @ N06, v056
	.byte W06
	.byte Bn1 @ N06, v056
	.byte W06
	.byte En2, v060 @ N06
	.byte W06
	.byte N12, Fs2 @ v060
	.byte W12
	.byte N06, Dn2, v064
	.byte W06
	.byte Gn1 @ N06, v064
	.byte W06
	.byte An1, v068 @ N06
	.byte W06
	.byte Dn2 @ N06, v068
	.byte W06
	.byte N12, En2, v072
	.byte W12
	.byte PEND
track_6_lbl_22d38c:
	.byte N06, Cn2, v072
	.byte W06
	.byte An1, v076 @ N06
	.byte W06
	.byte As1 @ N06, v076
	.byte W06
	.byte Cn2, v080 @ N06
	.byte W06
	.byte As1 @ N06, v080
	.byte W06
	.byte An1 @ N06, v080
	.byte W42
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d36e
	.byte PATT
		.word track_6_lbl_22d38c
	.byte N06, An2, v056
	.byte W06
	.byte Dn2 @ N06, v056
	.byte W06
	.byte En2 @ N06, v056
	.byte W06
	.byte An2, v060 @ N06
	.byte W06
	.byte N12, Bn2 @ v060
	.byte W12
	.byte N06, Gn2, v064
	.byte W06
	.byte Cn2 @ N06, v064
	.byte W06
	.byte Dn2, v068 @ N06
	.byte W06
	.byte Gn2 @ N06, v068
	.byte W06
	.byte N12, An2, v072
	.byte W12
	.byte N06, Fn2 @ v072
	.byte W06
	.byte Dn2, v076 @ N06
	.byte W06
	.byte Ds2 @ N06, v076
	.byte W06
	.byte Fn2, v080 @ N06
	.byte W06
	.byte Ds2 @ N06, v080
	.byte W06
	.byte Dn2 @ N06, v080
	.byte W42
	.byte An2, v056 @ N06
	.byte W06
	.byte Dn2 @ N06, v056
	.byte W06
	.byte En2 @ N06, v056
	.byte W06
	.byte An2 @ N06, v056
	.byte W06
	.byte N12, Bn2, v060
	.byte W12
	.byte N06, Gn2 @ v060
	.byte W06
	.byte Cn2, v064 @ N06
	.byte W06
	.byte Dn2 @ N06, v064
	.byte W06
	.byte Gn2 @ N06, v064
	.byte W06
	.byte N12, An2, v068
	.byte W12
	.byte N06, Fn2 @ v068
	.byte W06
	.byte Dn2 @ N06, v068
	.byte W06
	.byte Ds2, v072 @ N06
	.byte W06
	.byte Fn2 @ N06, v072
	.byte W06
	.byte Ds2 @ N06, v072
	.byte W06
	.byte Dn2, v076 @ N06
	.byte W06
	.byte Ds2, v072 @ N06
	.byte W06
	.byte Dn2, v068 @ N06
	.byte W06
	.byte Ds2, v060 @ N06
	.byte W06
	.byte Dn2, v056 @ N06
	.byte W06
	.byte Ds2, v052 @ N06
	.byte W06
	.byte Dn2, v048 @ N06
	.byte W06
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
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
track_6_lbl_22d421:
	.byte N36, Gn1, v072
	.byte W36
	.byte Fn1, v080 @ N36
	.byte W36
	.byte PEND
track_6_lbl_22d429:
	.byte N36, Ds1, v060
	.byte W36
	.byte Dn1, v076 @ N36
	.byte W60
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d421
	.byte PATT
		.word track_6_lbl_22d429
	.byte PATT
		.word track_6_lbl_22d421
	.byte PATT
		.word track_6_lbl_22d429
	.byte VOICE, 33
	.byte VOL, 80
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte GOTO
		.word track_6_lbl_22d347
	.byte W72
	.byte FINE

track_6_7:
	.byte KEYSH, 0
	.byte VOICE, 26
	.byte VOL, 80
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
track_6_lbl_22d466:
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte N12, Cn3, v100
	.byte W36
	.byte N12 @ Cn3, v100
	.byte W36
	.byte N12 @ Cn3, v100
	.byte W14
	.byte N01, Gn2 @ v100
	.byte W22
	.byte N12, Cn3 @ v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W60
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W60
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W36
	.byte N24 @ Cn3, v100
	.byte W60
	.byte VOICE, 26
	.byte VOL, 80
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte GOTO
		.word track_6_lbl_22d466
	.byte W72
	.byte FINE

track_6_8:
	.byte KEYSH, 0
	.byte VOICE, 32
	.byte VOL, 75
	.byte N06, Cn3, v072
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v052 @ N06
	.byte W06
	.byte Cn3, v040 @ N06
	.byte W06
	.byte Cn3, v032 @ N06
	.byte W12
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v048 @ N06
	.byte W06
	.byte Cn3, v036 @ N06
	.byte W24
track_6_lbl_22d510:
	.byte N06, Cn3, v072
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v052 @ N06
	.byte W06
	.byte Cn3, v040 @ N06
	.byte W06
	.byte Cn3, v032 @ N06
	.byte W12
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v048 @ N06
	.byte W06
	.byte Cn3, v036 @ N06
	.byte W48
	.byte PEND
track_6_lbl_22d52a:
	.byte N06, Cn3, v072
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v052 @ N06
	.byte W06
	.byte Cn3, v040 @ N06
	.byte W06
	.byte Cn3, v032 @ N06
	.byte W12
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v048 @ N06
	.byte W06
	.byte Cn3, v036 @ N06
	.byte W24
	.byte PEND
track_6_lbl_22d544:
	.byte N06, Cn3, v072
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v052 @ N06
	.byte W06
	.byte Cn3, v040 @ N06
	.byte W06
	.byte Cn3, v032 @ N06
	.byte W12
	.byte Cn3, v072 @ N06
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v052 @ N06
	.byte W06
	.byte Cn3, v040 @ N06
	.byte W06
	.byte Cn3, v032 @ N06
	.byte W36
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d510
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d544
track_6_lbl_22d578:
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d510
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d510
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d52a
track_6_lbl_22d5b4:
	.byte VOICE, 31
	.byte N06, Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte PEND
track_6_lbl_22d5c5:
	.byte N06, Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5b4
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d5c5
track_6_lbl_22d629:
	.byte N06, Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d629
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte N06, Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W12
	.byte N06 @ Cn3, v040
	.byte W36
	.byte VOICE, 32
	.byte VOL, 80
	.byte N06, Cn3, v072
	.byte W06
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v052 @ N06
	.byte W06
	.byte Cn3, v040 @ N06
	.byte W06
	.byte Cn3, v032 @ N06
	.byte W12
	.byte Cn3, v060 @ N06
	.byte W06
	.byte Cn3, v048 @ N06
	.byte W06
	.byte Cn3, v036 @ N06
	.byte W24
	.byte PATT
		.word track_6_lbl_22d510
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d544
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d510
	.byte PATT
		.word track_6_lbl_22d52a
	.byte PATT
		.word track_6_lbl_22d544
	.byte GOTO
		.word track_6_lbl_22d578
	.byte W72
	.byte FINE

.align 2

track_6:
	.byte 9
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_6_0
	.word track_6_1
	.word track_6_2
	.word track_6_3
	.word track_6_4
	.word track_6_5
	.word track_6_6
	.word track_6_7
	.word track_6_8

.align 2
