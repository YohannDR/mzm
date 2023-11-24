.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_8

track_8_0:
	.byte KEYSH, 0
track_8_lbl_22e47a:
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 86
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N48
	.byte Gn3, En2
	.byte W48
	.byte As3, En3
	.byte W48
	.byte N72
	.byte An3, Gs3
	.byte W96
track_8_lbl_22e48f:
	.byte N48
	.byte Gn3, En2
	.byte W48
	.byte As3, En3
	.byte W48
	.byte PEND
	.byte N72
	.byte An3, Cn4
	.byte W96
	.byte PATT
		.word track_8_lbl_22e48f
	.byte N72
	.byte An3, Gs3
	.byte W96
	.byte PATT
		.word track_8_lbl_22e48f
	.byte N72
	.byte An3, Cn4
	.byte W96
track_8_lbl_22e4ad:
	.byte N60
	.byte Cn3, Gs2
	.byte W72
	.byte N08
	.byte Gn2, Cn3
	.byte W08
	.byte Cn3, En2
	.byte W08
	.byte Ds3, En3
	.byte W08
	.byte PEND
	.byte N72
	.byte Dn3, Gs2
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72
	.byte Dn3, Gs2
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72
	.byte Dn3, Gs2
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72
	.byte Dn3, Gs2
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72
	.byte Dn3, Gs2
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72
	.byte Dn3, Gs2
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72
	.byte Dn3, Gs2
	.byte W96
	.byte PATT
		.word track_8_lbl_22e4ad
	.byte N72
	.byte Dn3, Gs2
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
	.byte N48
	.byte Dn3, Cn2
	.byte W48
	.byte Fn3, Gs2
	.byte W48
	.byte N72
	.byte Cs3, En3
	.byte W96
track_8_lbl_22e51a:
	.byte N48
	.byte Dn3, En2
	.byte W48
	.byte Fn3, Cn3
	.byte W48
	.byte PEND
	.byte N72
	.byte Cs3, Cn4
	.byte W96
	.byte N48
	.byte Dn3, Cn2
	.byte W48
	.byte Fn3, Gs2
	.byte W48
	.byte N72
	.byte Cs3, En3
	.byte W96
	.byte PATT
		.word track_8_lbl_22e51a
	.byte N72
	.byte Cs3, Cn4
	.byte W96
	.byte An2, Cn3
	.byte W96
	.byte Gs2, Cn4
	.byte W96
	.byte An2, Cn3
	.byte W96
track_8_lbl_22e543:
	.byte N60
	.byte Gs2, Cn4
	.byte W72
	.byte N08
	.byte Gn2, En3
	.byte W08
	.byte Fs2
	.byte W08
	.byte Fn2
	.byte W08
	.byte PEND
track_8_lbl_22e550:
	.byte N72
	.byte En2, Cn3
	.byte W72
	.byte N24
	.byte Fn2, En3
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e543
track_8_lbl_22e55e:
	.byte N72
	.byte Gn2, Gs3
	.byte W72
	.byte N24
	.byte W24
	.byte PEND
track_8_lbl_22e565:
	.byte N08
	.byte Fn2, En3
	.byte W08
	.byte En2, Cn3
	.byte W08
	.byte Fn2, En3
	.byte W08
	.byte Gn2
	.byte W08
	.byte Fn2, Cn3
	.byte W08
	.byte Gn2, En3
	.byte W08
	.byte An2
	.byte W08
	.byte Gn2, Cn3
	.byte W08
	.byte An2, En3
	.byte W08
	.byte Bn2
	.byte W08
	.byte An2, Cn3
	.byte W08
	.byte Bn2, En3
	.byte W08
	.byte PEND
	.byte N72
	.byte An2, Cn3
	.byte W96
	.byte Gs2, Cn4
	.byte W96
	.byte An2, Cn3
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
	.byte N24
	.byte Gn1, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
track_8_lbl_22e5cd:
	.byte N24
	.byte Gn1, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
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
	.byte N24
	.byte An0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N24
	.byte W24
	.byte N24
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e5fe
	.byte PATT
		.word track_8_lbl_22e5fe
	.byte PATT
		.word track_8_lbl_22e5fe
track_8_lbl_22e61c:
	.byte N24
	.byte Gn0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte PEND
track_8_lbl_22e62f:
	.byte N24
	.byte Fn0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte PEND
track_8_lbl_22e642:
	.byte N24
	.byte En0, Gn8
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N24
	.byte W24
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte PEND
track_8_lbl_22e655:
	.byte N08
	.byte Dn1, Gn8
	.byte W08
	.byte Cn1
	.byte W08
	.byte Dn1
	.byte W08
	.byte En1
	.byte W08
	.byte Dn1
	.byte W08
	.byte En1
	.byte W08
	.byte Fn1
	.byte W08
	.byte En1
	.byte W08
	.byte Fn1
	.byte W08
	.byte Gn1
	.byte W08
	.byte Fn1
	.byte W08
	.byte Gn1
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
	.byte N36
	.byte Dn2, En5
	.byte W48
	.byte Dn2, Gs5
	.byte W48
	.byte N72
	.byte En2, Gs4
	.byte W96
	.byte N36
	.byte Dn2, En5
	.byte W48
	.byte Dn2, Cn5
	.byte W48
	.byte N72
	.byte En2, En5
	.byte W96
	.byte N36
	.byte Dn2, Cn5
	.byte W48
	.byte Dn2, En4
	.byte W48
	.byte N72
	.byte En2, Gs4
	.byte W96
	.byte N36
	.byte Dn2, Gs5
	.byte W48
	.byte Dn2, Cn5
	.byte W48
	.byte N72
	.byte En2, Gs4
	.byte W96
	.byte Ds2, Cn5
	.byte W96
	.byte Dn2, Gs4
	.byte W96
	.byte Ds2, Cn5
	.byte W96
	.byte Dn2, Gs4
	.byte W96
	.byte Ds2, Cn4
	.byte W96
	.byte Dn2, Gs4
	.byte W96
	.byte Ds2
	.byte W96
	.byte Dn2, Cn5
	.byte W96
	.byte Ds2, Cn4
	.byte W96
	.byte Dn2, Gs4
	.byte W96
	.byte Ds2
	.byte W96
	.byte Dn2
	.byte W96
	.byte Ds2, Cn4
	.byte W96
	.byte Dn2, Gs4
	.byte W96
	.byte Ds2
	.byte W96
	.byte Fs2
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
	.byte N36
	.byte As1, Gs4
	.byte W48
	.byte As1, En5
	.byte W48
	.byte N72
	.byte An1, Gs4
	.byte W96
	.byte N36
	.byte As1, En4
	.byte W48
	.byte As1, Gs3
	.byte W48
	.byte N72
	.byte An1, Gs5
	.byte W96
	.byte N36
	.byte As1, Cn4
	.byte W48
	.byte As1, Gs4
	.byte W48
	.byte N72
	.byte An1
	.byte W96
	.byte N36
	.byte As1, Cn5
	.byte W48
	.byte As1, En4
	.byte W48
	.byte N72
	.byte An1, Gs4
	.byte W96
	.byte Gn1, Cn6
	.byte W96
	.byte Gs1, En4
	.byte W96
	.byte Gn1, Gs5
	.byte W96
	.byte Gs1, En4
	.byte W96
	.byte Gn1, Gs5
	.byte W96
	.byte Gs1, En4
	.byte W96
	.byte Gn1, Gs5
	.byte W96
	.byte N72
	.byte W96
	.byte N72
	.byte W96
	.byte Gs1, En4
	.byte W96
	.byte Gn1, Gs5
	.byte W96
	.byte Gs1, En4
	.byte W96
	.byte Gn1, Gs5
	.byte W96
	.byte Gs1, En4
	.byte W96
	.byte Gn1, Gs5
	.byte W96
	.byte An1
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
	.byte N36
	.byte Cn3, En7
	.byte W48
	.byte N36
	.byte W24
track_8_lbl_22e77e:
	.byte W24
	.byte N36
	.byte Cn3, Gs7
	.byte W48
	.byte Cn3, En7
	.byte W24
	.byte PEND
track_8_lbl_22e787:
	.byte W24
	.byte N36
	.byte Cn3, En8
	.byte W48
	.byte Cn3, En7
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e77e
track_8_lbl_22e795:
	.byte W24
	.byte N36
	.byte Cn3, Cn8
	.byte W48
	.byte Cn3, En7
	.byte W24
	.byte PEND
	.byte W24
	.byte Cn3, Cn8
	.byte W48
	.byte Cn3, Gs7
	.byte W24
	.byte W24
	.byte Cn3, En8
	.byte W48
	.byte Cn3, Gs7
	.byte W24
	.byte PATT
		.word track_8_lbl_22e795
	.byte PATT
		.word track_8_lbl_22e787
	.byte PATT
		.word track_8_lbl_22e795
	.byte W24
	.byte N36
	.byte Cn3, Gn8
	.byte W48
	.byte Cn3, En7
	.byte W24
	.byte PATT
		.word track_8_lbl_22e787
	.byte W24
	.byte N36
	.byte Cn3, En8
	.byte W48
	.byte Cn3, Gs6
	.byte W24
	.byte PATT
		.word track_8_lbl_22e795
track_8_lbl_22e7d5:
	.byte W24
	.byte N36
	.byte Cn3, Cn8
	.byte W48
	.byte Cn3, Cn7
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e795
	.byte PATT
		.word track_8_lbl_22e7d5
track_8_lbl_22e7e8:
	.byte W24
	.byte N36
	.byte Cn3, Gs7
	.byte W48
	.byte Cn3, Cn7
	.byte W24
	.byte PEND
	.byte PATT
		.word track_8_lbl_22e795
	.byte PATT
		.word track_8_lbl_22e77e
	.byte PATT
		.word track_8_lbl_22e7e8
	.byte W24
	.byte N36
	.byte Cn3, En7
	.byte W48
	.byte Cn3, Cn7
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
	.byte N36
	.byte Cn3, En6
	.byte W48
	.byte N36
	.byte W48
track_8_lbl_22e829:
	.byte N36
	.byte Cn3, En6
	.byte W48
	.byte N36
	.byte W48
	.byte PEND
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
	.byte N36
	.byte W48
track_8_lbl_22e844:
	.byte N36
	.byte Cn3, En6
	.byte W48
	.byte N36
	.byte W24
	.byte N08
	.byte Gn3, Cn5
	.byte W08
	.byte N08
	.byte W08
	.byte Gn3, Cn6
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
	.byte N36
	.byte Cn3, En6
	.byte W24
	.byte N08
	.byte Fn3, Cn5
	.byte W08
	.byte N08
	.byte W08
	.byte Fn3, Cn6
	.byte W08
	.byte N36
	.byte Cn3, En6
	.byte W24
	.byte N08
	.byte Fn3, Cn5
	.byte W08
	.byte N08
	.byte W08
	.byte Fn3, Cn6
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
