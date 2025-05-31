.align 2

.global track_8

track_8_0:
	.byte KEYSH, 0
track_8_lbl_22e47a:
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 86
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N48, Gn3, v052
	.byte W48
	.byte As3, v064 @ N48
	.byte W48
	.byte N72, An3, v068
	.byte W96
track_8_lbl_22e48f:
	.byte N48, Gn3, v052
	.byte W48
	.byte As3, v064 @ N48
	.byte W48
	.byte PEND
	.byte N72, An3, v072
	.byte W96
	.byte PATT
		.word track_8_lbl_22e48f
	.byte N72, An3, v068
	.byte W96
	.byte PATT
		.word track_8_lbl_22e48f
	.byte N72, An3, v072
	.byte W96
track_8_lbl_22e4ad:
	.byte N60, Cn3, v056
	.byte W72
	.byte N08, Gn2, v060
	.byte W08
	.byte Cn3, v052 @ N08
	.byte W08
	.byte Ds3, v064 @ N08
	.byte W08
	.byte PEND
	.byte N72, Dn3, v056
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72, Dn3, v056
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72, Dn3, v056
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72, Dn3, v056
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72, Dn3, v056
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72, Dn3, v056
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72, Dn3, v056
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72, Dn3, v056
	.byte W96
	.byte GOTO
		.word track_8_lbl_22e47a
	.byte FINE

track_8_1:
	.byte KEYSH, 0
track_8_lbl_22e507:
	.byte VOICE, 47
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 119
	.byte N48, Dn3, v048
	.byte W48
	.byte Fn3, v056 @ N48
	.byte W48
	.byte N72, Cs3, v064
	.byte W96
track_8_lbl_22e51a:
	.byte N48, Dn3, v052
	.byte W48
	.byte Fn3, v060 @ N48
	.byte W48
	.byte PEND
	.byte N72, Cs3, v072
	.byte W96
	.byte N48, Dn3, v048
	.byte W48
	.byte Fn3, v056 @ N48
	.byte W48
	.byte N72, Cs3, v064
	.byte W96
	.byte PATT
		.word track_8_lbl_22e51a
	.byte N72, Cs3, v072
	.byte W96
	.byte An2, v060 @ N72
	.byte W96
	.byte Gs2, v072 @ N72
	.byte W96
	.byte An2, v060 @ N72
	.byte W96
track_8_lbl_22e543:
	.byte N60, Gs2, v072
	.byte W72
	.byte N08, Gn2, v064
	.byte W08
	.byte Fs2 @ N08, v064
	.byte W08
	.byte Fn2 @ N08, v064
	.byte W08
	.byte PEND
track_8_lbl_22e550:
	.byte N72, En2, v060
	.byte W72
	.byte N24, Fn2, v064
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e543
track_8_lbl_22e55e:
	.byte N72, Gn2, v068
	.byte W72
	.byte N24 @ Gn2, v068
	.byte W24
	.byte PEND
track_8_lbl_22e565:
	.byte N08, Fn2, v064
	.byte W08
	.byte En2, v060 @ N08
	.byte W08
	.byte Fn2, v064 @ N08
	.byte W08
	.byte Gn2 @ N08, v064
	.byte W08
	.byte Fn2, v060 @ N08
	.byte W08
	.byte Gn2, v064 @ N08
	.byte W08
	.byte An2 @ N08, v064
	.byte W08
	.byte Gn2, v060 @ N08
	.byte W08
	.byte An2, v064 @ N08
	.byte W08
	.byte Bn2 @ N08, v064
	.byte W08
	.byte An2, v060 @ N08
	.byte W08
	.byte Bn2, v064 @ N08
	.byte W08
	.byte PEND
	.byte N72, An2, v060
	.byte W96
	.byte Gs2, v072 @ N72
	.byte W96
	.byte An2, v060 @ N72
	.byte W96
	.byte PATT
		.word track_8_lbl_22e543
	.byte PATT
		.word track_8_lbl_22e550
	.byte PATT
		.word track_8_lbl_22e543
	.byte PATT
		.word track_8_lbl_22e55e
	.byte PATT
		.word track_8_lbl_22e565
	.byte GOTO
		.word track_8_lbl_22e507
	.byte FINE

track_8_2:
	.byte KEYSH, 0
track_8_lbl_22e5b3:
	.byte VOICE, 45
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 118
	.byte N24, Gn1, v127
	.byte W24
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N24 @ Gn1, v127
	.byte W24
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N08 @ Gn1, v127
	.byte W08
track_8_lbl_22e5cd:
	.byte N24, Gn1, v127
	.byte W24
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N24 @ Gn1, v127
	.byte W24
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N08 @ Gn1, v127
	.byte W08
	.byte N08 @ Gn1, v127
	.byte W08
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e5cd
	.byte PATT
		.word track_8_lbl_22e5cd
	.byte PATT
		.word track_8_lbl_22e5cd
	.byte PATT
		.word track_8_lbl_22e5cd
	.byte PATT
		.word track_8_lbl_22e5cd
	.byte PATT
		.word track_8_lbl_22e5cd
track_8_lbl_22e5fe:
	.byte N24, An0, v127
	.byte W24
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N08 @ An0, v127
	.byte W08
	.byte N24 @ An0, v127
	.byte W24
	.byte N24 @ An0, v127
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e5fe
	.byte PATT
		.word track_8_lbl_22e5fe
	.byte PATT
		.word track_8_lbl_22e5fe
track_8_lbl_22e61c:
	.byte N24, Gn0, v127
	.byte W24
	.byte N08 @ Gn0, v127
	.byte W08
	.byte N08 @ Gn0, v127
	.byte W08
	.byte N08 @ Gn0, v127
	.byte W08
	.byte N24 @ Gn0, v127
	.byte W24
	.byte N08 @ Gn0, v127
	.byte W08
	.byte N08 @ Gn0, v127
	.byte W08
	.byte N08 @ Gn0, v127
	.byte W08
	.byte PEND
track_8_lbl_22e62f:
	.byte N24, Fn0, v127
	.byte W24
	.byte N08 @ Fn0, v127
	.byte W08
	.byte N08 @ Fn0, v127
	.byte W08
	.byte N08 @ Fn0, v127
	.byte W08
	.byte N24 @ Fn0, v127
	.byte W24
	.byte N08 @ Fn0, v127
	.byte W08
	.byte N08 @ Fn0, v127
	.byte W08
	.byte N08 @ Fn0, v127
	.byte W08
	.byte PEND
track_8_lbl_22e642:
	.byte N24, En0, v127
	.byte W24
	.byte N08 @ En0, v127
	.byte W08
	.byte N08 @ En0, v127
	.byte W08
	.byte N08 @ En0, v127
	.byte W08
	.byte N24 @ En0, v127
	.byte W24
	.byte N08 @ En0, v127
	.byte W08
	.byte N08 @ En0, v127
	.byte W08
	.byte N08 @ En0, v127
	.byte W08
	.byte PEND
track_8_lbl_22e655:
	.byte N08, Dn1, v127
	.byte W08
	.byte Cn1 @ N08, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte En1 @ N08, v127
	.byte W08
	.byte Dn1 @ N08, v127
	.byte W08
	.byte En1 @ N08, v127
	.byte W08
	.byte Fn1 @ N08, v127
	.byte W08
	.byte En1 @ N08, v127
	.byte W08
	.byte Fn1 @ N08, v127
	.byte W08
	.byte Gn1 @ N08, v127
	.byte W08
	.byte Fn1 @ N08, v127
	.byte W08
	.byte Gn1 @ N08, v127
	.byte W08
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e5fe
	.byte PATT
		.word track_8_lbl_22e5fe
	.byte PATT
		.word track_8_lbl_22e5fe
	.byte PATT
		.word track_8_lbl_22e5fe
	.byte PATT
		.word track_8_lbl_22e61c
	.byte PATT
		.word track_8_lbl_22e62f
	.byte PATT
		.word track_8_lbl_22e642
	.byte PATT
		.word track_8_lbl_22e655
	.byte GOTO
		.word track_8_lbl_22e5b3
	.byte FINE

track_8_3:
	.byte KEYSH, 0
track_8_lbl_22e6a0:
	.byte VOICE, 27
	.byte VOL, 70
	.byte PAN, c_v-17
	.byte PRIO, 29
	.byte N36, Dn2, v088
	.byte W48
	.byte Dn2, v092 @ N36
	.byte W48
	.byte N72, En2, v080
	.byte W96
	.byte N36, Dn2, v088
	.byte W48
	.byte Dn2, v084 @ N36
	.byte W48
	.byte N72, En2, v088
	.byte W96
	.byte N36, Dn2, v084
	.byte W48
	.byte Dn2, v076 @ N36
	.byte W48
	.byte N72, En2, v080
	.byte W96
	.byte N36, Dn2, v092
	.byte W48
	.byte Dn2, v084 @ N36
	.byte W48
	.byte N72, En2, v080
	.byte W96
	.byte Ds2, v084 @ N72
	.byte W96
	.byte Dn2, v080 @ N72
	.byte W96
	.byte Ds2, v084 @ N72
	.byte W96
	.byte Dn2, v080 @ N72
	.byte W96
	.byte Ds2, v072 @ N72
	.byte W96
	.byte Dn2, v080 @ N72
	.byte W96
	.byte Ds2 @ N72, v080
	.byte W96
	.byte Dn2, v084 @ N72
	.byte W96
	.byte Ds2, v072 @ N72
	.byte W96
	.byte Dn2, v080 @ N72
	.byte W96
	.byte Ds2 @ N72, v080
	.byte W96
	.byte Dn2 @ N72, v080
	.byte W96
	.byte Ds2, v072 @ N72
	.byte W96
	.byte Dn2, v080 @ N72
	.byte W96
	.byte Ds2 @ N72, v080
	.byte W96
	.byte Fs2 @ N72, v080
	.byte W96
	.byte GOTO
		.word track_8_lbl_22e6a0
	.byte FINE

track_8_4:
	.byte KEYSH, 0
track_8_lbl_22e707:
	.byte VOICE, 27
	.byte VOL, 86
	.byte PAN, c_v+15
	.byte PRIO, 28
	.byte N36, As1, v080
	.byte W48
	.byte As1, v088 @ N36
	.byte W48
	.byte N72, An1, v080
	.byte W96
	.byte N36, As1, v076
	.byte W48
	.byte As1, v068 @ N36
	.byte W48
	.byte N72, An1, v092
	.byte W96
	.byte N36, As1, v072
	.byte W48
	.byte As1, v080 @ N36
	.byte W48
	.byte N72, An1 @ v080
	.byte W96
	.byte N36, As1, v084
	.byte W48
	.byte As1, v076 @ N36
	.byte W48
	.byte N72, An1, v080
	.byte W96
	.byte Gn1, v096 @ N72
	.byte W96
	.byte Gs1, v076 @ N72
	.byte W96
	.byte Gn1, v092 @ N72
	.byte W96
	.byte Gs1, v076 @ N72
	.byte W96
	.byte Gn1, v092 @ N72
	.byte W96
	.byte Gs1, v076 @ N72
	.byte W96
	.byte Gn1, v092 @ N72
	.byte W96
	.byte N72 @ Gn1, v092
	.byte W96
	.byte N72 @ Gn1, v092
	.byte W96
	.byte Gs1, v076 @ N72
	.byte W96
	.byte Gn1, v092 @ N72
	.byte W96
	.byte Gs1, v076 @ N72
	.byte W96
	.byte Gn1, v092 @ N72
	.byte W96
	.byte Gs1, v076 @ N72
	.byte W96
	.byte Gn1, v092 @ N72
	.byte W96
	.byte An1 @ N72, v092
	.byte W96
	.byte GOTO
		.word track_8_lbl_22e707
	.byte FINE

track_8_5:
	.byte KEYSH, 0
track_8_lbl_22e76f:
	.byte VOICE, 25
	.byte VOL, 70
	.byte PAN, c_v
	.byte PRIO, 30
	.byte W24
	.byte N36, Cn3, v112
	.byte W48
	.byte N36 @ Cn3, v112
	.byte W24
track_8_lbl_22e77e:
	.byte W24
	.byte N36, Cn3, v116
	.byte W48
	.byte Cn3, v112 @ N36
	.byte W24
	.byte PEND
track_8_lbl_22e787:
	.byte W24
	.byte N36, Cn3, v124
	.byte W48
	.byte Cn3, v112 @ N36
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e77e
track_8_lbl_22e795:
	.byte W24
	.byte N36, Cn3, v120
	.byte W48
	.byte Cn3, v112 @ N36
	.byte W24
	.byte PEND
	.byte W24
	.byte Cn3, v120 @ N36
	.byte W48
	.byte Cn3, v116 @ N36
	.byte W24
	.byte W24
	.byte Cn3, v124 @ N36
	.byte W48
	.byte Cn3, v116 @ N36
	.byte W24
	.byte PATT
		.word track_8_lbl_22e795
	.byte PATT
		.word track_8_lbl_22e787
	.byte PATT
		.word track_8_lbl_22e795
	.byte W24
	.byte N36, Cn3, v127
	.byte W48
	.byte Cn3, v112 @ N36
	.byte W24
	.byte PATT
		.word track_8_lbl_22e787
	.byte W24
	.byte N36, Cn3, v124
	.byte W48
	.byte Cn3, v104 @ N36
	.byte W24
	.byte PATT
		.word track_8_lbl_22e795
track_8_lbl_22e7d5:
	.byte W24
	.byte N36, Cn3, v120
	.byte W48
	.byte Cn3, v108 @ N36
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e795
	.byte PATT
		.word track_8_lbl_22e7d5
track_8_lbl_22e7e8:
	.byte W24
	.byte N36, Cn3, v116
	.byte W48
	.byte Cn3, v108 @ N36
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e795
	.byte PATT
		.word track_8_lbl_22e77e
	.byte PATT
		.word track_8_lbl_22e7e8
	.byte W24
	.byte N36, Cn3, v112
	.byte W48
	.byte Cn3, v108 @ N36
	.byte W24
	.byte PATT
		.word track_8_lbl_22e77e
	.byte PATT
		.word track_8_lbl_22e77e
	.byte GOTO
		.word track_8_lbl_22e76f
	.byte W12
	.byte FINE

track_8_6:
	.byte KEYSH, 0
track_8_lbl_22e81b:
	.byte VOICE, 26
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 27
	.byte N36, Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
track_8_lbl_22e829:
	.byte N36, Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte PEND
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W48
track_8_lbl_22e844:
	.byte N36, Cn3, v100
	.byte W48
	.byte N36 @ Cn3, v100
	.byte W24
	.byte N08, Gn3, v084
	.byte W08
	.byte N08 @ Gn3, v084
	.byte W08
	.byte Gn3, v096 @ N08
	.byte W08
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e844
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e844
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e844
	.byte PATT
		.word track_8_lbl_22e829
track_8_lbl_22e877:
	.byte N36, Cn3, v100
	.byte W24
	.byte N08, Fn3, v084
	.byte W08
	.byte N08 @ Fn3, v084
	.byte W08
	.byte Fn3, v096 @ N08
	.byte W08
	.byte N36, Cn3, v100
	.byte W24
	.byte N08, Fn3, v084
	.byte W08
	.byte N08 @ Fn3, v084
	.byte W08
	.byte Fn3, v096 @ N08
	.byte W08
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e829
	.byte PATT
		.word track_8_lbl_22e877
	.byte GOTO
		.word track_8_lbl_22e81b
	.byte FINE

.align 2

track_8:
	.byte 7
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_8_0
	.word track_8_1
	.word track_8_2
	.word track_8_3
	.word track_8_4
	.word track_8_5
	.word track_8_6

.align 2
