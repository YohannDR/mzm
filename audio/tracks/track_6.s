.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_6

track_6_0:
	.byte KEYSH, 0
	.byte TEMPO, 37
	.byte VOICE, 30
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N28
	.byte Gn4, Cn4
	.byte W36
	.byte N24
	.byte Fn4
	.byte W24
	.byte N18
	.byte As4
	.byte W12
track_6_lbl_22cdba:
	.byte N28
	.byte Gn4, Cn4
	.byte W36
	.byte N36
	.byte Fn4
	.byte W60
	.byte PEND
track_6_lbl_22cdc2:
	.byte N28
	.byte Gn4, Cn4
	.byte W36
	.byte N24
	.byte Fn4
	.byte W24
	.byte N18
	.byte As4
	.byte W12
	.byte PEND
track_6_lbl_22cdcd:
	.byte N28
	.byte Gn4, Cn4
	.byte W36
	.byte N36
	.byte An4
	.byte W60
	.byte PEND
	.byte N28
	.byte Gn4
	.byte W36
	.byte N24
	.byte Fn4
	.byte W24
	.byte N12
	.byte As4
	.byte W12
	.byte PATT
		.word track_6_lbl_22cdba
	.byte PATT
		.word track_6_lbl_22cdc2
	.byte PATT
		.word track_6_lbl_22cdcd
track_6_lbl_22cded:
	.byte VOICE, 12
	.byte N36
	.byte Cn4, Cn3
	.byte W36
	.byte Dn4
	.byte W36
track_6_lbl_22cdf5:
	.byte N24
	.byte Fn4, Cn3
	.byte W24
	.byte N06
	.byte En4
	.byte W06
	.byte Dn4
	.byte W06
	.byte An3
	.byte W06
	.byte Gn3
	.byte W06
	.byte N36
	.byte An3
	.byte W48
	.byte PEND
	.byte Cn4
	.byte W36
	.byte Dn4
	.byte W36
	.byte PATT
		.word track_6_lbl_22cdf5
	.byte VOICE, 30
	.byte N24
	.byte An4, Gs2
	.byte W24
	.byte N12
	.byte Bn4, En2
	.byte W12
	.byte N24
	.byte Gn4
	.byte W24
	.byte N12
	.byte An4, Cn2
	.byte W12
	.byte N54
	.byte Fn4
	.byte W72
	.byte N24
	.byte An4, Gs2
	.byte W24
	.byte N12
	.byte Bn4, En2
	.byte W12
	.byte N24
	.byte Gn4
	.byte W24
	.byte N12
	.byte An4, Cn2
	.byte W12
	.byte N54
	.byte Fn4
	.byte W72
track_6_lbl_22ce35:
	.byte N24
	.byte Dn5, Gs2
	.byte W24
	.byte N12
	.byte En5, En2
	.byte W12
	.byte N24
	.byte Cn5
	.byte W24
	.byte N12
	.byte Dn5, Cn2
	.byte W12
	.byte PEND
	.byte N54
	.byte As4
	.byte W72
	.byte PATT
		.word track_6_lbl_22ce35
	.byte N36
	.byte Fn5, Gs2
	.byte W36
	.byte En5, Cn3
	.byte W36
	.byte W72
	.byte W36
	.byte N48
	.byte Fn5, En2
	.byte W36
	.byte W72
	.byte W36
	.byte N48
	.byte W36
	.byte W72
	.byte W36
	.byte N48
	.byte W36
	.byte W72
	.byte W36
	.byte N48
	.byte W36
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W36
	.byte N96
	.byte W36
	.byte W72
	.byte W36
	.byte N96
	.byte W36
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte W72
	.byte W96
track_6_lbl_22ce7a:
	.byte N36
	.byte Gn4, En6
	.byte W36
	.byte N24
	.byte Fn4
	.byte W24
	.byte N12
	.byte As4
	.byte W12
	.byte PEND
track_6_lbl_22ce85:
	.byte N36
	.byte Gn4, En6
	.byte W36
	.byte N42
	.byte Fn4
	.byte W60
	.byte PEND
	.byte PATT
		.word track_6_lbl_22ce7a
track_6_lbl_22ce92:
	.byte N36
	.byte Gn4, En6
	.byte W36
	.byte N42
	.byte An4
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
	.byte N24
	.byte Dn4, Gs0
	.byte W36
	.byte Cn4
	.byte W36
	.byte As3
	.byte W36
	.byte N36
	.byte An3
	.byte W60
	.byte N24
	.byte Dn4
	.byte W36
	.byte Cn4
	.byte W36
	.byte As3
	.byte W36
	.byte N36
	.byte Fn3
	.byte W60
	.byte N24
	.byte Dn4
	.byte W36
	.byte Cn4
	.byte W36
	.byte As3
	.byte W36
	.byte N36
	.byte An3
	.byte W60
	.byte N24
	.byte Dn4
	.byte W36
	.byte Cn4
	.byte W36
track_6_lbl_22cee3:
	.byte N28
	.byte As3, Gs0
	.byte W36
	.byte N36
	.byte Fn3
	.byte W60
	.byte PEND
track_6_lbl_22ceeb:
	.byte VOICE, 28
	.byte VOL, 75
	.byte W12
	.byte N12
	.byte Cn2, Cn4
	.byte W12
	.byte N18
	.byte Dn2, Cn3
	.byte W24
	.byte N12
	.byte Dn2, Cn4
	.byte W12
	.byte N18
	.byte En2, Cn3
	.byte W12
track_6_lbl_22cf00:
	.byte W12
	.byte N12
	.byte Dn2, Cn4
	.byte W12
	.byte N32
	.byte Fn2, Cn3
	.byte W36
	.byte N24
	.byte An1, Cn4
	.byte W36
	.byte PEND
	.byte W12
	.byte N12
	.byte Cn2
	.byte W12
	.byte N18
	.byte Dn2, Cn3
	.byte W24
	.byte N12
	.byte Dn2, Cn4
	.byte W12
	.byte N18
	.byte En2, Cn3
	.byte W12
	.byte PATT
		.word track_6_lbl_22cf00
	.byte VOICE, 30
	.byte VOL, 80
	.byte N28
	.byte En3, Cn8
	.byte W36
	.byte Dn3, Gn8
	.byte W36
	.byte N36
	.byte Cn3
	.byte W72
	.byte N28
	.byte En3
	.byte W36
	.byte Dn3
	.byte W36
	.byte N36
	.byte Cn3
	.byte W72
	.byte N28
	.byte An3
	.byte W36
	.byte Gn3
	.byte W36
	.byte N36
	.byte Fn3
	.byte W72
	.byte N28
	.byte An3
	.byte W36
	.byte Gn3
	.byte W36
	.byte Dn3
	.byte W36
	.byte Cn3
	.byte W36
	.byte W72
	.byte W48
	.byte VOICE, 34
	.byte N06
	.byte Fn3
	.byte W06
	.byte Dn3
	.byte W06
	.byte Ds3
	.byte W06
	.byte Fn3
	.byte W06
track_6_lbl_22cf57:
	.byte N06
	.byte Ds3, Gn8
	.byte W02
	.byte N01
	.byte En3
	.byte W04
	.byte N06
	.byte Dn3
	.byte W66
	.byte PEND
track_6_lbl_22cf62:
	.byte W48
	.byte N06
	.byte Fn3, Gn8
	.byte W06
	.byte Dn3
	.byte W06
	.byte Ds3
	.byte W06
	.byte Fn3
	.byte W06
	.byte PEND
	.byte Ds3
	.byte W06
	.byte Dn3
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
	.byte N06
	.byte Gs3, Gn8
	.byte W06
	.byte Fn3
	.byte W06
	.byte Fs3
	.byte W06
	.byte Gs3
	.byte W06
	.byte PEND
track_6_lbl_22cf8e:
	.byte N06
	.byte Fs3, Gn8
	.byte W02
	.byte N01
	.byte Gn3
	.byte W04
	.byte N06
	.byte Fn3
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
	.byte N24
	.byte Dn4, En1
	.byte W36
	.byte Cn4
	.byte W36
	.byte As3
	.byte W36
	.byte N36
	.byte An3
	.byte W60
	.byte N24
	.byte Dn4
	.byte W36
	.byte Cn4
	.byte W36
	.byte As3
	.byte W36
	.byte N36
	.byte An3
	.byte W60
	.byte VOICE, 34
	.byte VOL, 80
	.byte N24
	.byte Dn4, Gs0
	.byte W36
	.byte Cn4
	.byte W36
	.byte As3
	.byte W36
	.byte N36
	.byte An3
	.byte W60
	.byte N24
	.byte Dn4
	.byte W36
	.byte Cn4
	.byte W36
	.byte As3
	.byte W36
	.byte N36
	.byte Fn3
	.byte W60
	.byte N24
	.byte Dn4
	.byte W36
	.byte Cn4
	.byte W36
	.byte As3
	.byte W36
	.byte N36
	.byte An3
	.byte W60
	.byte N24
	.byte Dn4
	.byte W36
	.byte Cn4
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
	.byte N24
	.byte As3, Gs0
	.byte W36
	.byte An3
	.byte W36
	.byte Ds3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte N24
	.byte As3
	.byte W36
	.byte An3
	.byte W36
	.byte Ds3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte N24
	.byte As3
	.byte W36
	.byte An3
	.byte W36
	.byte Ds3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte N24
	.byte As3
	.byte W36
	.byte An3
	.byte W36
track_6_lbl_22d039:
	.byte N28
	.byte Ds3, Gs0
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte PEND
track_6_lbl_22d041:
	.byte W72
	.byte W96
	.byte W72
	.byte W96
	.byte VOICE, 30
	.byte N28
	.byte Cn3, Cn8
	.byte W36
	.byte Bn2, Gn8
	.byte W36
	.byte N36
	.byte An2
	.byte W72
	.byte N28
	.byte Cn3
	.byte W36
	.byte Bn2
	.byte W36
	.byte N36
	.byte An2
	.byte W72
	.byte N28
	.byte Fn3
	.byte W36
	.byte En3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W72
	.byte N28
	.byte Fn3
	.byte W36
	.byte En3
	.byte W36
	.byte As2
	.byte W36
	.byte Gn2
	.byte W36
	.byte W72
	.byte W48
	.byte VOICE, 34
	.byte W24
	.byte W02
	.byte N01
	.byte En3
	.byte W68
	.byte W02
	.byte W72
	.byte W72
	.byte W72
	.byte W02
	.byte N01
	.byte W68
	.byte W02
	.byte W72
	.byte W72
	.byte W72
	.byte W02
	.byte Gn3
	.byte W68
	.byte W02
	.byte W72
	.byte W02
	.byte N01
	.byte W68
	.byte W02
	.byte W72
	.byte W02
	.byte N01
	.byte W68
	.byte W02
	.byte W72
	.byte W02
	.byte En3
	.byte W68
	.byte W02
	.byte W72
	.byte W02
	.byte N01
	.byte W68
	.byte W02
	.byte W96
	.byte N24
	.byte As3, En1
	.byte W36
	.byte An3
	.byte W36
	.byte Ds3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte N24
	.byte As3
	.byte W36
	.byte An3
	.byte W36
	.byte Ds3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte VOICE, 34
	.byte VOL, 80
	.byte N24
	.byte As3, Gs0
	.byte W36
	.byte An3
	.byte W36
	.byte Ds3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte N24
	.byte As3
	.byte W36
	.byte An3
	.byte W36
	.byte Ds3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte N24
	.byte As3
	.byte W36
	.byte An3
	.byte W36
	.byte Ds3
	.byte W36
	.byte N36
	.byte Dn3
	.byte W60
	.byte N24
	.byte As3
	.byte W36
	.byte An3
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
	.byte N28
	.byte Gn1, Gn8
	.byte W36
	.byte N36
	.byte Fn1
	.byte W36
track_6_lbl_22d0f1:
	.byte N28
	.byte Gn1, Gn8
	.byte W36
	.byte N36
	.byte Fn1
	.byte W60
	.byte PEND
track_6_lbl_22d0f9:
	.byte N28
	.byte Gn1, Gn8
	.byte W36
	.byte N36
	.byte Fn1
	.byte W36
	.byte PEND
track_6_lbl_22d101:
	.byte N28
	.byte Gn1, Gn8
	.byte W36
	.byte N36
	.byte An1
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
	.byte N36
	.byte Gn2, En3
	.byte W36
	.byte An2, Cn4
	.byte W36
track_6_lbl_22d128:
	.byte N24
	.byte Cn3, En5
	.byte W36
	.byte N06
	.byte En2
	.byte W06
	.byte Dn2
	.byte W06
	.byte N24
	.byte En2
	.byte W48
	.byte PEND
	.byte N36
	.byte Gn2, En3
	.byte W36
	.byte An2, En5
	.byte W36
	.byte PATT
		.word track_6_lbl_22d128
	.byte VOICE, 28
	.byte VOL, 75
	.byte N30
	.byte Dn2, Cn4
	.byte W36
	.byte Cn2, Cn3
	.byte W36
	.byte N48
	.byte As1, En2
	.byte W72
track_6_lbl_22d150:
	.byte N30
	.byte Dn2, Cn4
	.byte W36
	.byte Cn2, Cn3
	.byte W36
	.byte PEND
	.byte N48
	.byte As1, En2
	.byte W72
	.byte PATT
		.word track_6_lbl_22d150
	.byte N48
	.byte As1, En2
	.byte W72
	.byte PATT
		.word track_6_lbl_22d150
	.byte N48
	.byte As1, En2
	.byte W72
track_6_lbl_22d16e:
	.byte N06
	.byte Dn2, Cn7
	.byte W12
	.byte Dn2, Cn5
	.byte W12
	.byte Dn2, Cn6
	.byte W12
	.byte N13
	.byte Cn2
	.byte W12
	.byte N24
	.byte Dn2, Cn5
	.byte W24
	.byte PEND
track_6_lbl_22d180:
	.byte N12
	.byte Cn2, Cn6
	.byte W12
	.byte N04
	.byte Dn2, Cn5
	.byte W60
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d16e
	.byte N12
	.byte Cn2, Cn6
	.byte W12
	.byte N03
	.byte Dn2
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
	.byte N06
	.byte Fn2, En5
	.byte W12
	.byte Fn2, Gs5
	.byte W12
	.byte Fn2, En5
	.byte W12
	.byte N13
	.byte Ds2, Cn5
	.byte W12
	.byte N24
	.byte Fn2, Gs4
	.byte W24
	.byte PEND
track_6_lbl_22d1bc:
	.byte N12
	.byte Ds2, Cn5
	.byte W12
	.byte N04
	.byte Fn2, Cn4
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
	.byte N06
	.byte Dn2, En5
	.byte W12
	.byte Dn2, Gs5
	.byte W12
	.byte Dn2, En5
	.byte W12
	.byte N13
	.byte Cn2, Cn5
	.byte W12
	.byte N24
	.byte Dn2, Gs4
	.byte W24
	.byte N12
	.byte Cn2, Cn5
	.byte W12
	.byte N04
	.byte Dn2, Cn4
	.byte W60
	.byte PATT
		.word track_6_lbl_22d16e
	.byte PATT
		.word track_6_lbl_22d180
	.byte N36
	.byte Gn2, En1
	.byte W36
	.byte Fn2, Cn2
	.byte W36
	.byte Ds2, Gs0
	.byte W36
	.byte Dn2, Gs1
	.byte W60
	.byte Gn1, Gs6
	.byte W36
	.byte Fn1, Cn7
	.byte W36
	.byte Ds1, En5
	.byte W36
	.byte Dn1, Cn7
	.byte W60
	.byte Gn2, En3
	.byte W36
	.byte Fn2, Cn4
	.byte W36
	.byte Ds2, En2
	.byte W36
	.byte Dn2, Gs3
	.byte W60
	.byte VOICE, 28
	.byte VOL, 80
	.byte N28
	.byte Gn1, Gn8
	.byte W36
	.byte N36
	.byte Fn1
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
	.byte N36
	.byte Gn1, Gs5
	.byte W36
	.byte Fn1, En6
	.byte W36
	.byte Ds1, Gs4
	.byte W36
	.byte Dn1, Cn6
	.byte W60
	.byte W72
	.byte W96
	.byte Gn1, Cn4
	.byte W36
	.byte Fn1, Gs4
	.byte W36
	.byte Ds1, Cn3
	.byte W36
	.byte Dn1, En4
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
	.byte N24
	.byte An2, Gs2
	.byte W24
	.byte N12
	.byte Bn2
	.byte W12
	.byte N24
	.byte Gn2
	.byte W24
	.byte N12
	.byte An2
	.byte W12
	.byte N24
	.byte Fn2
	.byte W72
	.byte An2
	.byte W24
	.byte N12
	.byte Bn2
	.byte W12
	.byte N24
	.byte Gn2
	.byte W24
	.byte N12
	.byte An2
	.byte W12
	.byte N24
	.byte Fn2
	.byte W72
track_6_lbl_22d2e1:
	.byte N24
	.byte Dn3, Gs2
	.byte W24
	.byte N12
	.byte En3
	.byte W12
	.byte N24
	.byte Cn3
	.byte W24
	.byte N12
	.byte Dn3
	.byte W12
	.byte PEND
	.byte N24
	.byte As2
	.byte W72
	.byte PATT
		.word track_6_lbl_22d2e1
	.byte N24
	.byte Fn3, Cn2
	.byte W36
	.byte En3, En0
	.byte W36
	.byte VOICE, 28
	.byte N60
	.byte Dn1, Gs3
	.byte W72
	.byte W72
	.byte Dn1, En4
	.byte W72
	.byte W72
	.byte N60
	.byte W72
	.byte W72
	.byte N60
	.byte W72
	.byte W72
	.byte Fn1
	.byte W72
	.byte W72
	.byte N60
	.byte W72
	.byte W72
	.byte N60
	.byte W72
	.byte W72
	.byte Dn1
	.byte W72
	.byte W72
	.byte N60
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
	.byte N24
	.byte Fn1, Gn8
	.byte W36
	.byte Gn1
	.byte W36
track_6_lbl_22d351:
	.byte N24
	.byte As1, Gn8
	.byte W24
	.byte N06
	.byte En3, Cn1
	.byte W06
	.byte Dn3
	.byte W06
	.byte An2
	.byte W06
	.byte Gn2
	.byte W06
	.byte N36
	.byte An2
	.byte W48
	.byte PEND
	.byte N24
	.byte Fn1, Gn8
	.byte W36
	.byte Gn1
	.byte W36
	.byte PATT
		.word track_6_lbl_22d351
track_6_lbl_22d36e:
	.byte N06
	.byte En2, Gs2
	.byte W06
	.byte An1
	.byte W06
	.byte Bn1
	.byte W06
	.byte En2, Cn3
	.byte W06
	.byte N12
	.byte Fs2
	.byte W12
	.byte N06
	.byte Dn2, En3
	.byte W06
	.byte Gn1
	.byte W06
	.byte An1, Gs3
	.byte W06
	.byte Dn2
	.byte W06
	.byte N12
	.byte En2, Cn4
	.byte W12
	.byte PEND
track_6_lbl_22d38c:
	.byte N06
	.byte Cn2, Cn4
	.byte W06
	.byte An1, En4
	.byte W06
	.byte As1
	.byte W06
	.byte Cn2, Gs4
	.byte W06
	.byte As1
	.byte W06
	.byte An1
	.byte W42
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d36e
	.byte PATT
		.word track_6_lbl_22d38c
	.byte N06
	.byte An2, Gs2
	.byte W06
	.byte Dn2
	.byte W06
	.byte En2
	.byte W06
	.byte An2, Cn3
	.byte W06
	.byte N12
	.byte Bn2
	.byte W12
	.byte N06
	.byte Gn2, En3
	.byte W06
	.byte Cn2
	.byte W06
	.byte Dn2, Gs3
	.byte W06
	.byte Gn2
	.byte W06
	.byte N12
	.byte An2, Cn4
	.byte W12
	.byte N06
	.byte Fn2
	.byte W06
	.byte Dn2, En4
	.byte W06
	.byte Ds2
	.byte W06
	.byte Fn2, Gs4
	.byte W06
	.byte Ds2
	.byte W06
	.byte Dn2
	.byte W42
	.byte An2, Gs2
	.byte W06
	.byte Dn2
	.byte W06
	.byte En2
	.byte W06
	.byte An2
	.byte W06
	.byte N12
	.byte Bn2, Cn3
	.byte W12
	.byte N06
	.byte Gn2
	.byte W06
	.byte Cn2, En3
	.byte W06
	.byte Dn2
	.byte W06
	.byte Gn2
	.byte W06
	.byte N12
	.byte An2, Gs3
	.byte W12
	.byte N06
	.byte Fn2
	.byte W06
	.byte Dn2
	.byte W06
	.byte Ds2, Cn4
	.byte W06
	.byte Fn2
	.byte W06
	.byte Ds2
	.byte W06
	.byte Dn2, En4
	.byte W06
	.byte Ds2, Cn4
	.byte W06
	.byte Dn2, Gs3
	.byte W06
	.byte Ds2, Cn3
	.byte W06
	.byte Dn2, Gs2
	.byte W06
	.byte Ds2, En2
	.byte W06
	.byte Dn2, Cn2
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
	.byte N36
	.byte Gn1, Cn4
	.byte W36
	.byte Fn1, Gs4
	.byte W36
	.byte PEND
track_6_lbl_22d429:
	.byte N36
	.byte Ds1, Cn3
	.byte W36
	.byte Dn1, En4
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
	.byte N12
	.byte Cn3, En6
	.byte W36
	.byte N12
	.byte W36
	.byte N12
	.byte W14
	.byte N01
	.byte Gn2
	.byte W22
	.byte N12
	.byte Cn3
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W60
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W60
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
	.byte W36
	.byte N24
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
	.byte N06
	.byte Cn3, Cn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, En2
	.byte W06
	.byte Cn3, En1
	.byte W06
	.byte Cn3, Gs0
	.byte W12
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, Cn2
	.byte W06
	.byte Cn3, Cn1
	.byte W24
track_6_lbl_22d510:
	.byte N06
	.byte Cn3, Cn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, En2
	.byte W06
	.byte Cn3, En1
	.byte W06
	.byte Cn3, Gs0
	.byte W12
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, Cn2
	.byte W06
	.byte Cn3, Cn1
	.byte W48
	.byte PEND
track_6_lbl_22d52a:
	.byte N06
	.byte Cn3, Cn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, En2
	.byte W06
	.byte Cn3, En1
	.byte W06
	.byte Cn3, Gs0
	.byte W12
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, Cn2
	.byte W06
	.byte Cn3, Cn1
	.byte W24
	.byte PEND
track_6_lbl_22d544:
	.byte N06
	.byte Cn3, Cn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, En2
	.byte W06
	.byte Cn3, En1
	.byte W06
	.byte Cn3, Gs0
	.byte W12
	.byte Cn3, Cn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, En2
	.byte W06
	.byte Cn3, En1
	.byte W06
	.byte Cn3, Gs0
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
	.byte N06
	.byte Cn3, En1
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte PEND
track_6_lbl_22d5c5:
	.byte N06
	.byte Cn3, En1
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
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
	.byte N06
	.byte Cn3, En1
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte PEND
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte PATT
		.word track_6_lbl_22d629
	.byte PATT
		.word track_6_lbl_22d5c5
	.byte N06
	.byte Cn3, En1
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W12
	.byte N06
	.byte W36
	.byte VOICE, 32
	.byte VOL, 80
	.byte N06
	.byte Cn3, Cn4
	.byte W06
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, En2
	.byte W06
	.byte Cn3, En1
	.byte W06
	.byte Cn3, Gs0
	.byte W12
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, Cn2
	.byte W06
	.byte Cn3, Cn1
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
