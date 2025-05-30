.align 2

.global track_78

track_78_0:
	.byte KEYSH, 0
track_78_lbl_22a576:
	.byte TEMPO, 65
	.byte VOICE, 66
	.byte VOL, 44
	.byte PAN, c_v+10
	.byte PRIO, 120
	.byte N48, Gs3, v040
	.byte W48
	.byte N24, Bn3 @ v040
	.byte W24
track_78_lbl_22a587:
	.byte N48, Dn4, v036
	.byte W48
	.byte N24, Ds4 @ v036
	.byte W24
	.byte PEND
	.byte N48, Gs3, v040
	.byte W48
	.byte N24, Bn3 @ v040
	.byte W24
	.byte PATT
		.word track_78_lbl_22a587
	.byte N48, En4, v036
	.byte W48
	.byte N24, Ds4 @ v036
	.byte W24
	.byte N48, En4 @ v036
	.byte W48
	.byte N24, Fn4 @ v036
	.byte W24
	.byte N48, Fs4 @ v036
	.byte W48
	.byte N24, Fn4 @ v036
	.byte W24
	.byte N48, Fs4 @ v036
	.byte W48
	.byte N24, Gn4 @ v036
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte N48, An3, v040
	.byte W48
	.byte N24, Gs3 @ v040
	.byte W24
	.byte N48, An3, v052
	.byte W48
	.byte N24, As3 @ v052
	.byte W24
	.byte VOICE, 67
	.byte VOL, 50
	.byte PAN, c_v+16
	.byte TIE, As4, v080
	.byte W72
	.byte W48
	.byte EOT @ As4, v080
	.byte N24, An4 @ v080
	.byte W24
	.byte TIE, As4 @ v080
	.byte W72
	.byte W48
	.byte EOT @ As4, v080
	.byte N24, An4 @ v080
	.byte W24
	.byte TIE, As4 @ v080
	.byte W72
	.byte W72
	.byte EOT @ As4, v080
	.byte W72
	.byte VOICE, 66
	.byte VOL, 44
	.byte PAN, c_v+10
	.byte N08, As2, v060
	.byte W08
	.byte Cs3 @ N08, v060
	.byte W08
	.byte En3 @ N08, v060
	.byte W08
	.byte Cs3, v052 @ N08
	.byte W08
	.byte En3 @ N08, v052
	.byte W08
	.byte Gn3 @ N08, v052
	.byte W08
	.byte N12, As3 @ v052
	.byte W06
	.byte Cs4, v040 @ N12
	.byte W06
	.byte En4 @ N12, v040
	.byte W06
	.byte N06, Gn4 @ v040
	.byte W06
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W32
	.byte N08, Gs2, v064
	.byte W08
	.byte Cn3 @ N08, v064
	.byte W08
	.byte Dn3 @ N08, v064
	.byte W08
	.byte Gs3, v040 @ N08
	.byte W08
	.byte Cn4 @ N08, v040
	.byte W08
	.byte GOTO
		.word track_78_lbl_22a576
	.byte FINE

track_78_1:
	.byte KEYSH, 0
track_78_lbl_22a622:
	.byte VOICE, 66
	.byte VOL, 44
	.byte PAN, c_v
	.byte PRIO, 119
	.byte W06
	.byte N06, Bn2, v048
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W06
	.byte Fn3 @ N06, v048
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W06
	.byte Fn3 @ N06, v048
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W06
	.byte Bn2 @ N06, v048
	.byte W12
	.byte Gs3 @ N06, v048
	.byte W06
	.byte Fn3 @ N06, v048
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W06
track_78_lbl_22a641:
	.byte W06
	.byte N06, Dn3, v048
	.byte W06
	.byte Fn3 @ N06, v048
	.byte W06
	.byte Gs3 @ N06, v048
	.byte W06
	.byte Bn3 @ N06, v048
	.byte W06
	.byte Gs3 @ N06, v048
	.byte W06
	.byte Fn3 @ N06, v048
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W12
	.byte Fs3 @ N06, v048
	.byte W06
	.byte An3, v036 @ N06
	.byte W06
	.byte Cn4 @ N06, v036
	.byte W06
	.byte PEND
	.byte W06
	.byte Bn2, v048 @ N06
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W06
	.byte Fn3 @ N06, v048
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W06
	.byte Fn3 @ N06, v048
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W06
	.byte Bn2 @ N06, v048
	.byte W12
	.byte Gs3 @ N06, v048
	.byte W06
	.byte Fn3 @ N06, v048
	.byte W06
	.byte Dn3 @ N06, v048
	.byte W06
	.byte PATT
		.word track_78_lbl_22a641
	.byte W06
	.byte N06, Cs4, v036
	.byte W06
	.byte As3 @ N06, v036
	.byte W06
	.byte Gn3, v048 @ N06
	.byte W06
	.byte En3 @ N06, v048
	.byte W06
	.byte Cs3 @ N06, v048
	.byte W06
	.byte En3 @ N06, v048
	.byte W06
	.byte Gn3 @ N06, v048
	.byte W12
	.byte Cn4, v036 @ N06
	.byte W06
	.byte An3, v048 @ N06
	.byte W06
	.byte Fs3 @ N06, v048
	.byte W06
	.byte W06
	.byte Cs4, v036 @ N06
	.byte W06
	.byte As3, v048 @ N06
	.byte W06
	.byte Gn3 @ N06, v048
	.byte W06
	.byte En3 @ N06, v048
	.byte W06
	.byte Cs3 @ N06, v048
	.byte W06
	.byte En3 @ N06, v048
	.byte W06
	.byte Gn3 @ N06, v048
	.byte W12
	.byte Dn4, v036 @ N06
	.byte W06
	.byte Bn3 @ N06, v036
	.byte W06
	.byte Gs3, v048 @ N06
	.byte W06
	.byte W06
	.byte Ds4, v036 @ N06
	.byte W06
	.byte Cn4 @ N06, v036
	.byte W06
	.byte An3, v048 @ N06
	.byte W06
	.byte Fs3 @ N06, v048
	.byte W06
	.byte Ds3 @ N06, v048
	.byte W06
	.byte Fs3 @ N06, v048
	.byte W06
	.byte Gn3 @ N06, v048
	.byte W12
	.byte Dn4, v036 @ N06
	.byte W06
	.byte Bn3 @ N06, v036
	.byte W06
	.byte Gs3, v048 @ N06
	.byte W06
	.byte W06
	.byte Ds4, v036 @ N06
	.byte W06
	.byte Cn4 @ N06, v036
	.byte W06
	.byte An3, v048 @ N06
	.byte W06
	.byte Fs3 @ N06, v048
	.byte W06
	.byte Ds3 @ N06, v048
	.byte W06
	.byte Fs3 @ N06, v048
	.byte W06
	.byte An3 @ N06, v048
	.byte W12
	.byte En4, v036 @ N06
	.byte W06
	.byte Cs4 @ N06, v036
	.byte W06
	.byte As3, v048 @ N06
	.byte W06
	.byte N08, Gs4, v032
	.byte W06
	.byte Fn4 @ N08, v032
	.byte W06
	.byte Dn4 @ N08, v032
	.byte W06
	.byte Bn3, v036 @ N08
	.byte W06
	.byte Fn4 @ N08, v036
	.byte W06
	.byte Dn4 @ N08, v036
	.byte W06
	.byte Bn3 @ N08, v036
	.byte W06
	.byte Gs3 @ N08, v036
	.byte W06
	.byte Dn4 @ N08, v036
	.byte W06
	.byte Bn3 @ N08, v036
	.byte W06
	.byte Gs3 @ N08, v036
	.byte W06
	.byte Fn3 @ N08, v036
	.byte W06
	.byte N12, Gs3, v056
	.byte W08
	.byte Fn3 @ N12, v056
	.byte W08
	.byte Dn3 @ N12, v056
	.byte W08
	.byte Bn2 @ N12, v056
	.byte W08
	.byte Gs2 @ N12, v056
	.byte W08
	.byte Bn2 @ N12, v056
	.byte W08
	.byte N08, Dn3 @ v056
	.byte W06
	.byte Bn2 @ N08, v056
	.byte W06
	.byte Gs2, v032 @ N08
	.byte W06
	.byte Fn2 @ N08, v032
	.byte W06
	.byte An4, v024 @ N08
	.byte W06
	.byte Fs4 @ N08, v024
	.byte W06
	.byte Ds4, v052 @ N08
	.byte W06
	.byte Cn4, v056 @ N08
	.byte W06
	.byte An3 @ N08, v056
	.byte W06
	.byte Fs3 @ N08, v056
	.byte W06
	.byte Ds3 @ N08, v056
	.byte W06
	.byte Cn3 @ N08, v056
	.byte W06
	.byte An2 @ N08, v056
	.byte W06
	.byte Fs2 @ N08, v056
	.byte W06
	.byte Ds2 @ N08, v056
	.byte W06
	.byte Cn2 @ N08, v056
	.byte W06
	.byte Ds2 @ N08, v056
	.byte W06
	.byte Fs2 @ N08, v056
	.byte W06
	.byte An2 @ N08, v056
	.byte W06
	.byte Cn3, v052 @ N08
	.byte W06
	.byte Ds3, v040 @ N08
	.byte W06
	.byte Fs3 @ N08, v040
	.byte W06
	.byte An3 @ N08, v040
	.byte W06
	.byte Cn4, v032 @ N08
	.byte W06
	.byte N12, Ds4 @ v032
	.byte W08
	.byte Fs4 @ N12, v032
	.byte W08
	.byte An4 @ N12, v032
	.byte W08
	.byte N08, Gs4 @ v032
	.byte W06
	.byte Fn4 @ N08, v032
	.byte W06
	.byte Dn4 @ N08, v032
	.byte W06
	.byte Bn3, v036 @ N08
	.byte W06
	.byte Fn4, v032 @ N08
	.byte W06
	.byte Dn4 @ N08, v032
	.byte W06
	.byte Bn3 @ N08, v032
	.byte W06
	.byte Gs3, v036 @ N08
	.byte W06
	.byte Dn4 @ N08, v036
	.byte W06
	.byte Bn3 @ N08, v036
	.byte W06
	.byte Gs3 @ N08, v036
	.byte W06
	.byte Fn3 @ N08, v036
	.byte W06
	.byte Fn2, v056 @ N08
	.byte W06
	.byte Dn2 @ N08, v056
	.byte W06
	.byte Fn2 @ N08, v056
	.byte W06
	.byte Gs2 @ N08, v056
	.byte W06
	.byte Bn2 @ N08, v056
	.byte W06
	.byte Gs2 @ N08, v056
	.byte W06
	.byte Fn2 @ N08, v056
	.byte W06
	.byte Dn2 @ N08, v056
	.byte W06
	.byte N12, Fn2 @ v056
	.byte W08
	.byte Dn2 @ N12, v056
	.byte W08
	.byte N08, Bn1 @ v056
	.byte W08
	.byte W06
	.byte N06, Fs4, v020
	.byte W06
	.byte Ds4 @ N06, v020
	.byte W06
	.byte Cn4, v048 @ N06
	.byte W06
	.byte An3, v056 @ N06
	.byte W06
	.byte Fs3 @ N06, v056
	.byte W06
	.byte Ds3 @ N06, v056
	.byte W06
	.byte Cn3 @ N06, v056
	.byte W12
	.byte Fn3 @ N06, v056
	.byte W06
	.byte Dn3 @ N06, v056
	.byte W06
	.byte Bn2 @ N06, v056
	.byte W06
	.byte W06
	.byte Fs3 @ N06, v056
	.byte W06
	.byte Ds3 @ N06, v056
	.byte W06
	.byte Cn3 @ N06, v056
	.byte W06
	.byte Ds2 @ N06, v056
	.byte W06
	.byte Cn2 @ N06, v056
	.byte W06
	.byte Ds2 @ N06, v056
	.byte W06
	.byte Fs2, v088 @ N06
	.byte W12
	.byte As2 @ N06, v088
	.byte W06
	.byte Cs3 @ N06, v088
	.byte W06
	.byte En3 @ N06, v088
	.byte W06
	.byte TIE, As3, v048
	.byte W72
	.byte W48
	.byte EOT @ As3, v048
	.byte N24, An3, v052
	.byte W24
	.byte TIE, As3, v048
	.byte W72
	.byte W48
	.byte EOT @ As3, v048
	.byte N24, An3, v052
	.byte W24
	.byte TIE, As3, v048
	.byte W72
	.byte W48
	.byte EOT @ As3, v048
	.byte W24
	.byte VOICE, 19
	.byte VOL, 44
	.byte N48, As2, v080
	.byte W24
	.byte N44, Cs3, v080, 2
	.byte W24
	.byte N24, En3, v072
	.byte W24
	.byte W72
	.byte VOICE, 66
	.byte VOL, 44
	.byte N08, Cn5, v032
	.byte W06
	.byte Gs4, v040 @ N08
	.byte W06
	.byte Fs4 @ N08, v040
	.byte W06
	.byte Dn4 @ N08, v040
	.byte W06
	.byte Cn3, v060 @ N08
	.byte W06
	.byte Gs2 @ N08, v060
	.byte W06
	.byte Fs2 @ N08, v060
	.byte W06
	.byte Dn2, v072 @ N08
	.byte W06
	.byte Cn4 @ N08, v072
	.byte W06
	.byte Gs3 @ N08, v072
	.byte W06
	.byte Fs3 @ N08, v072
	.byte W06
	.byte Dn3 @ N08, v072
	.byte W06
track_78_lbl_22a7f4:
	.byte N12, Cn3, v072
	.byte W06
	.byte Gs2 @ N12, v072
	.byte W06
	.byte Fs2 @ N12, v072
	.byte W06
	.byte Dn2 @ N12, v072
	.byte W06
	.byte Fs2 @ N12, v072
	.byte W06
	.byte Gs2 @ N12, v072
	.byte W06
	.byte Dn3 @ N12, v072
	.byte W06
	.byte Cn4, v040 @ N12
	.byte W06
	.byte Fs3 @ N12, v040
	.byte W06
	.byte Gs3 @ N12, v040
	.byte W06
	.byte Dn4 @ N12, v040
	.byte W06
	.byte Fs4 @ N12, v040
	.byte W06
	.byte PEND
	.byte N08, Cn5, v032
	.byte W06
	.byte Gs4, v040 @ N08
	.byte W06
	.byte Fs4 @ N08, v040
	.byte W06
	.byte Dn4 @ N08, v040
	.byte W06
	.byte Cn3, v060 @ N08
	.byte W06
	.byte Gs2 @ N08, v060
	.byte W06
	.byte Fs2 @ N08, v060
	.byte W06
	.byte Dn2, v072 @ N08
	.byte W06
	.byte Cn4 @ N08, v072
	.byte W06
	.byte Gs3 @ N08, v072
	.byte W06
	.byte Fs3 @ N08, v072
	.byte W06
	.byte Dn3 @ N08, v072
	.byte W06
	.byte PATT
		.word track_78_lbl_22a7f4
	.byte N08, Cn5, v032
	.byte W06
	.byte Gs4, v040 @ N08
	.byte W06
	.byte Fs4 @ N08, v040
	.byte W06
	.byte Dn4 @ N08, v040
	.byte W06
	.byte Cn3, v060 @ N08
	.byte W06
	.byte Gs2 @ N08, v060
	.byte W06
	.byte Fs2 @ N08, v060
	.byte W06
	.byte Dn2, v072 @ N08
	.byte W06
	.byte N12, Cn4, v052
	.byte W06
	.byte Gs3 @ N12, v052
	.byte W06
	.byte Fs3 @ N12, v052
	.byte W06
	.byte Dn3 @ N12, v052
	.byte W06
	.byte Cn4 @ N12, v052
	.byte W06
	.byte Gs3 @ N12, v052
	.byte W06
	.byte Fs3 @ N12, v052
	.byte W06
	.byte Dn3 @ N12, v052
	.byte W06
	.byte Cn3 @ N12, v052
	.byte W06
	.byte Gs2 @ N12, v052
	.byte W06
	.byte Fs2 @ N12, v052
	.byte W06
	.byte Dn2 @ N12, v052
	.byte W06
	.byte Fs2, v072 @ N12
	.byte W06
	.byte Gs2 @ N12, v072
	.byte W06
	.byte Dn3, v040 @ N12
	.byte W06
	.byte Fs3 @ N12, v040
	.byte W06
	.byte Cn5, v032 @ N12
	.byte W06
	.byte Gs4, v040 @ N12
	.byte W06
	.byte Fs4 @ N12, v040
	.byte W06
	.byte Dn4 @ N12, v040
	.byte W06
	.byte Cn3, v072 @ N12
	.byte W06
	.byte Gs2 @ N12, v072
	.byte W06
	.byte Fs2 @ N12, v072
	.byte W06
	.byte Dn2 @ N12, v072
	.byte W06
	.byte Fs2 @ N12, v072
	.byte W06
	.byte Gs2 @ N12, v072
	.byte W06
	.byte Dn3, v052 @ N12
	.byte W06
	.byte Fs3 @ N12, v052
	.byte W06
	.byte Cn5, v032 @ N12
	.byte W06
	.byte Gs4, v040 @ N12
	.byte W06
	.byte Fs4 @ N12, v040
	.byte W06
	.byte Dn4 @ N12, v040
	.byte W06
	.byte N08, Fs2, v064
	.byte W08
	.byte N12, Dn3 @ v064
	.byte W08
	.byte Fs3 @ N12, v064
	.byte W08
	.byte Gs3 @ N12, v064
	.byte W08
	.byte Dn4, v040 @ N12
	.byte W08
	.byte N08, Fs4 @ v040
	.byte W08
	.byte GOTO
		.word track_78_lbl_22a622
	.byte FINE

track_78_2:
	.byte KEYSH, 0
track_78_lbl_22a8aa:
	.byte PRIO, 118
	.byte W01
	.byte VOICE, 96
	.byte VOL, 69
	.byte PAN, c_v-24
	.byte TIE, Bn1, v120
	.byte W68
	.byte W03
	.byte W48
	.byte EOT @ Bn1, v120
	.byte W01
	.byte N23, Cn2 @ v120
	.byte W23
	.byte W01
	.byte TIE, Bn1 @ v120
	.byte W68
	.byte W03
	.byte W48
	.byte EOT @ Bn1, v120
	.byte W01
	.byte N23, Cn2 @ v120
	.byte W23
	.byte W01
	.byte N44, Cs2, v120, 3
	.byte W48
	.byte N23, Cn2 @ v120
	.byte W23
	.byte W01
	.byte N44, Cs2, v120, 3
	.byte W48
	.byte N23, Dn2 @ v120
	.byte W23
	.byte W01
	.byte N44, Ds2, v120, 3
	.byte W48
	.byte N23, Dn2 @ v120
	.byte W23
	.byte W01
	.byte N44, Ds2, v120, 3
	.byte W48
	.byte N23, En2 @ v120
	.byte W23
	.byte W01
	.byte TIE, Fn2 @ v120
	.byte W68
	.byte W03
	.byte W72
	.byte EOT @ Fn2, v120
	.byte W01
	.byte TIE, Fs2, v112
	.byte W68
	.byte W03
	.byte W72
	.byte EOT @ Fs2, v112
	.byte W01
	.byte TIE, Fn2, v120
	.byte W68
	.byte W03
	.byte W72
	.byte EOT @ Fn2, v120
	.byte W01
	.byte N44, Fs2, v112, 3
	.byte W48
	.byte N23, Fn2, v120
	.byte W23
	.byte W01
	.byte N44, Fs2, v112, 3
	.byte W48
	.byte N23, Gn2, v120
	.byte W23
	.byte VOICE, 101
	.byte VOL, 75
	.byte TIE, Cs4, v112
	.byte W72
	.byte W44
	.byte W01
	.byte EOT @ Cs4, v112
	.byte W04
	.byte N21, Cn4, v100
	.byte W23
	.byte TIE, Cs4, v112
	.byte W72
	.byte W44
	.byte W01
	.byte EOT @ Cs4, v112
	.byte W04
	.byte N21, Cn4, v100
	.byte W23
	.byte TIE, Cs4, v112
	.byte W72
	.byte W72
	.byte W72
	.byte W68
	.byte W01
	.byte EOT @ Cs4, v112
	.byte W03
	.byte W72
	.byte VOICE, 102
	.byte VOL, 69
	.byte W01
	.byte N72, Dn2, v116
	.byte W68
	.byte W03
	.byte W72
	.byte W01
	.byte N68, Dn2, v116, 3
	.byte W68
	.byte W03
	.byte W01
	.byte Dn2, v116, 3 @ N68
	.byte W68
	.byte W03
	.byte W01
	.byte Dn2, v116, 3 @ N68
	.byte W68
	.byte W03
	.byte W01
	.byte Dn2, v116, 3 @ N68
	.byte W68
	.byte W03
	.byte W01
	.byte N30, Dn2, v116, 1
	.byte W68
	.byte W03
	.byte GOTO
		.word track_78_lbl_22a8aa
	.byte FINE

track_78_3:
	.byte KEYSH, 0
track_78_lbl_22a972:
	.byte VOICE, 65
	.byte PRIO, 30
	.byte VOL, 50
	.byte PAN, c_v-14
	.byte TIE, Bn1, v072
	.byte W72
	.byte W48
	.byte EOT @ Bn1, v072
	.byte N24, Cn2 @ v072
	.byte W24
	.byte TIE, Bn1 @ v072
	.byte W72
	.byte W48
	.byte EOT @ Bn1, v072
	.byte N24, Cn2 @ v072
	.byte W24
	.byte N48, Cs2, v080
	.byte W48
	.byte N24, Cn2 @ v080
	.byte W24
	.byte N48, Cs2 @ v080
	.byte W48
	.byte N24, Dn2 @ v080
	.byte W24
	.byte N48, Ds2 @ v080
	.byte W48
	.byte N24, Dn2 @ v080
	.byte W24
	.byte N48, Ds2 @ v080
	.byte W48
	.byte N24, En2 @ v080
	.byte W24
	.byte VOICE, 103
	.byte TIE, Fn1, v076
	.byte W72
	.byte W72
	.byte EOT @ Fn1, v076
	.byte TIE, Fs1 @ v076
	.byte W72
	.byte W72
	.byte EOT @ Fs1, v076
	.byte TIE, Fn1 @ v076
	.byte W72
	.byte W72
	.byte EOT @ Fn1, v076
	.byte N48, Fs1 @ v076
	.byte W48
	.byte N24, Fn1 @ v076
	.byte W24
	.byte N48, Fs1 @ v076
	.byte W48
	.byte N24, Gn1 @ v076
	.byte W24
	.byte VOICE, 23
	.byte PAN, c_v+22
	.byte TIE, Cs2, v120
	.byte W72
	.byte W44
	.byte W03
	.byte EOT @ Cs2, v120
	.byte W01
	.byte N23, Cn2 @ v120
	.byte W24
	.byte TIE, Cs2 @ v120
	.byte W72
	.byte W44
	.byte W03
	.byte EOT @ Cs2, v120
	.byte W01
	.byte N23, Cn2 @ v120
	.byte W24
	.byte TIE, Cs2 @ v120
	.byte W72
	.byte W72
	.byte W72
	.byte W68
	.byte W03
	.byte EOT @ Cs2, v120
	.byte W01
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 100
	.byte PAN, c_v-14
	.byte VOL, 62
	.byte N68, Dn3, v108, 3
	.byte W72
	.byte Dn3, v108, 3 @ N68
	.byte W72
	.byte N30, Dn3, v108, 1
	.byte W72
	.byte GOTO
		.word track_78_lbl_22a972
	.byte FINE

track_78_4:
	.byte KEYSH, 0
track_78_lbl_22aa05:
	.byte VOICE, 65
	.byte VOL, 37
	.byte PAN, c_v+16
	.byte PRIO, 30
	.byte TIE, Bn2, v040
	.byte W72
	.byte W48
	.byte EOT @ Bn2, v040
	.byte N24, Cn3 @ v040
	.byte W24
	.byte TIE, Bn2 @ v040
	.byte W72
	.byte W48
	.byte EOT @ Bn2, v040
	.byte N24, Cn3 @ v040
	.byte W24
	.byte VOICE, 67
	.byte VOL, 50
	.byte N48, En5 @ v040
	.byte W48
	.byte N24, Ds5 @ v040
	.byte W24
	.byte N48, En5 @ v040
	.byte W48
	.byte N24, Fn5 @ v040
	.byte W24
	.byte N48, Fs5 @ v040
	.byte W48
	.byte N24, Fn5 @ v040
	.byte W24
	.byte N48, Fs5 @ v040
	.byte W48
	.byte N24, Gn5 @ v040
	.byte W24
	.byte VOICE, 103
	.byte VOL, 50
	.byte TIE, Dn2, v076
	.byte W72
	.byte W72
	.byte EOT @ Dn2, v076
	.byte TIE, Ds2 @ v076
	.byte W72
	.byte W72
	.byte EOT @ Ds2, v076
	.byte TIE, Dn2 @ v076
	.byte W72
	.byte W72
	.byte EOT @ Dn2, v076
	.byte N48, Ds2 @ v076
	.byte W48
	.byte N24, Dn2 @ v076
	.byte W24
	.byte N48, Ds2 @ v076
	.byte W48
	.byte N24, En2 @ v076
	.byte W24
	.byte VOICE, 66
	.byte VOL, 44
	.byte TIE, En3, v052
	.byte W72
	.byte W48
	.byte EOT @ En3, v052
	.byte N24, Ds3 @ v052
	.byte W24
	.byte TIE, En3 @ v052
	.byte W72
	.byte W48
	.byte EOT @ En3, v052
	.byte N24, Ds3 @ v052
	.byte W24
	.byte TIE, En3 @ v052
	.byte W72
	.byte W48
	.byte EOT @ En3, v052
	.byte W24
	.byte W72
	.byte VOICE, 19
	.byte VOL, 50
	.byte PAN, c_v+16
	.byte N48, Cs3, v096
	.byte W24
	.byte En3 @ N48, v096
	.byte W24
	.byte N24, Gn3 @ v096
	.byte W24
	.byte W72
	.byte VOICE, 66
	.byte VOL, 62
	.byte PAN, c_v+10
	.byte N72, Dn1, v112
	.byte W72
	.byte W72
	.byte N72 @ Dn1, v112
	.byte W72
	.byte W72
	.byte TIE @ Dn1, v112
	.byte W72
	.byte W36
	.byte EOT @ Dn1, v112
	.byte W36
	.byte W72
	.byte GOTO
		.word track_78_lbl_22aa05
	.byte FINE

track_78_5:
	.byte KEYSH, 0
track_78_lbl_22aaa2:
	.byte VOICE, 100
	.byte VOL, 56
	.byte PAN, c_v+20
	.byte PRIO, 29
	.byte TIE, Bn3, v120
	.byte W72
	.byte W48
	.byte EOT @ Bn3, v120
	.byte W02
	.byte N21, Cn4 @ v120
	.byte W22
	.byte W02
	.byte TIE, Bn3 @ v120
	.byte W68
	.byte W02
	.byte W44
	.byte W02
	.byte EOT @ Bn3, v120
	.byte W04
	.byte N21, Cn4 @ v120
	.byte W22
	.byte W02
	.byte N44, Cs4, v120, 1
	.byte W48
	.byte N21, Cn4 @ v120
	.byte W22
	.byte W02
	.byte N44, Cs4, v120, 1
	.byte W48
	.byte N21, Dn4, v112
	.byte W22
	.byte W02
	.byte N44, Ds4, v112, 1
	.byte W48
	.byte N21, Dn4 @ v112
	.byte W22
	.byte W02
	.byte N44, Ds4, v112, 1
	.byte W48
	.byte N21, En4 @ v112
	.byte W22
	.byte W02
	.byte TIE, Fn4, v120
	.byte W68
	.byte W02
	.byte W72
	.byte EOT @ Fn4, v120
	.byte W02
	.byte TIE, Fs4, v112
	.byte W68
	.byte W02
	.byte W72
	.byte EOT @ Fs4, v112
	.byte W02
	.byte TIE, Fn4, v120
	.byte W68
	.byte W02
	.byte W72
	.byte EOT @ Fn4, v120
	.byte W02
	.byte N44, Fs4, v112, 2
	.byte W48
	.byte N22, Fn4, v120
	.byte W22
	.byte W02
	.byte N44, Fs4, v100, 1
	.byte W48
	.byte N21, Gn4, v120
	.byte W22
	.byte W02
	.byte TIE, Gn4, v112
	.byte W68
	.byte W02
	.byte W44
	.byte W03
	.byte EOT @ Gn4, v112
	.byte W03
	.byte N21, Fs4 @ v112
	.byte W22
	.byte W02
	.byte TIE, Gn4 @ v112
	.byte W68
	.byte W02
	.byte W44
	.byte W03
	.byte EOT @ Gn4, v112
	.byte W03
	.byte N21, Fs4 @ v112
	.byte W22
	.byte W02
	.byte TIE, Gn4 @ v112
	.byte W68
	.byte W02
	.byte W72
	.byte W72
	.byte W68
	.byte W03
	.byte EOT @ Gn4, v112
	.byte W01
	.byte W72
	.byte VOICE, 66
	.byte VOL, 50
	.byte N72, As1, v108
	.byte W72
	.byte W72
	.byte N72 @ As1, v108
	.byte W72
	.byte W72
	.byte TIE @ As1, v108
	.byte W72
	.byte W36
	.byte EOT @ As1, v108
	.byte W36
	.byte W72
	.byte GOTO
		.word track_78_lbl_22aaa2
	.byte FINE

track_78_6:
	.byte KEYSH, 0
track_78_lbl_22ab50:
	.byte VOICE, 65
	.byte VOL, 37
	.byte PAN, c_v
	.byte PRIO, 27
	.byte TIE, Dn3, v080
	.byte W72
	.byte W48
	.byte EOT @ Dn3, v080
	.byte N24, Ds3 @ v080
	.byte W24
	.byte TIE, Dn3 @ v080
	.byte W72
	.byte W48
	.byte EOT @ Dn3, v080
	.byte N24, Ds3 @ v080
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 103
	.byte TIE, Gs2, v056
	.byte W72
	.byte W72
	.byte EOT @ Gs2, v056
	.byte TIE, An2 @ v056
	.byte W72
	.byte W72
	.byte EOT @ An2, v056
	.byte TIE, Gs2 @ v056
	.byte W72
	.byte W72
	.byte EOT @ Gs2, v056
	.byte N48, An2 @ v056
	.byte W48
	.byte N24, Gs2 @ v056
	.byte W24
	.byte N48, An2 @ v056
	.byte W48
	.byte N24, As2 @ v056
	.byte W24
	.byte VOICE, 19
	.byte VOL, 50
	.byte TIE, Cs3, v080
	.byte W72
	.byte W48
	.byte EOT @ Cs3, v080
	.byte N24, Cn3 @ v080
	.byte W24
	.byte TIE, Cs3 @ v080
	.byte W72
	.byte W48
	.byte EOT @ Cs3, v080
	.byte N24, Cn3 @ v080
	.byte W24
	.byte TIE, Cs3 @ v080
	.byte W72
	.byte W72
	.byte EOT @ Cs3, v080
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 66
	.byte VOL, 50
	.byte N72, Fs1, v108
	.byte W72
	.byte W72
	.byte N72 @ Fs1, v108
	.byte W72
	.byte W72
	.byte TIE @ Fs1, v108
	.byte W72
	.byte W36
	.byte EOT @ Fs1, v108
	.byte W36
	.byte W72
	.byte GOTO
		.word track_78_lbl_22ab50
	.byte FINE

.align 2

track_78:
	.byte 7
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_78_0
	.word track_78_1
	.word track_78_2
	.word track_78_3
	.word track_78_4
	.word track_78_5
	.word track_78_6

.align 2
