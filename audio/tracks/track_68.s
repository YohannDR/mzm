.align 2

.global track_68

track_68_0:
	.byte KEYSH, 0
	.byte TEMPO, 27
	.byte VOICE, 83
	.byte PAN, c_v
	.byte PRIO, 120
	.byte VOL, 62
	.byte N03, Cn4, v044
	.byte W24
	.byte Cn4, v072 @ N03
	.byte W24
	.byte N03 @ Cn4, v072
	.byte W72
	.byte N03 @ Cn4, v072
	.byte W24
	.byte W24
	.byte N03 @ Cn4, v072
	.byte W24
	.byte N03 @ Cn4, v072
	.byte W24
	.byte N02 @ Cn4, v072
	.byte W24
	.byte N03 @ Cn4, v072
	.byte W72
	.byte N03 @ Cn4, v072
	.byte W24
	.byte N03 @ Cn4, v072
	.byte W24
track_68_lbl_2255a8:
	.byte N03, Cn4, v072
	.byte W24
	.byte N03 @ Cn4, v072
	.byte W24
	.byte GOTO
		.word track_68_lbl_2255a8
	.byte FINE

track_68_1:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte PAN, c_v
	.byte W48
track_68_lbl_2255bb:
	.byte W12
	.byte VOL, 15
	.byte N56, Dn4, v044, 2
	.byte W28
	.byte W01
	.byte VOL, 12
	.byte W06
	.byte 10 @ VOL
	.byte W07
	.byte 7 @ VOL
	.byte W06
	.byte 5 @ VOL
	.byte W06
	.byte 2 @ VOL
	.byte W30
	.byte PEND
	.byte W96
	.byte PATT
		.word track_68_lbl_2255bb
	.byte W24
track_68_lbl_2255d7:
	.byte W48
	.byte GOTO
		.word track_68_lbl_2255d7
	.byte FINE

track_68_2:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte PAN, c_v-7
	.byte W36
	.byte VOL, 2
	.byte N80, An4, v080, 2
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
track_68_lbl_225603:
	.byte VOL, 27
	.byte W02
	.byte 25 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W06
	.byte 17 @ VOL
	.byte W08
	.byte 15 @ VOL
	.byte W08
	.byte 12 @ VOL
	.byte W08
	.byte 10 @ VOL
	.byte W08
	.byte 7 @ VOL
	.byte W08
	.byte 5 @ VOL
	.byte W08
	.byte 2 @ VOL
	.byte W05
	.byte 1 @ VOL
	.byte W28
	.byte W01
	.byte PEND
	.byte W84
	.byte 2 @ VOL
	.byte N80, An4, v080, 2
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte PATT
		.word track_68_lbl_225603
	.byte W24
track_68_lbl_225642:
	.byte W48
	.byte GOTO
		.word track_68_lbl_225642
	.byte FINE

track_68_3:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte PAN, c_v
	.byte W48
track_68_lbl_225650:
	.byte VOL, 15
	.byte N68, Gs4, v048, 2
	.byte W02
	.byte VOL, 17
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W05
	.byte 20 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W06
	.byte 16 @ VOL
	.byte W07
	.byte 13 @ VOL
	.byte W06
	.byte 11 @ VOL
	.byte W06
	.byte 8 @ VOL
	.byte W07
	.byte 6 @ VOL
	.byte W06
	.byte 3 @ VOL
	.byte W06
	.byte 1 @ VOL
	.byte W28
	.byte PEND
	.byte W96
	.byte PATT
		.word track_68_lbl_225650
	.byte W24
track_68_lbl_22567e:
	.byte W48
	.byte GOTO
		.word track_68_lbl_22567e
	.byte FINE

track_68_4:
	.byte KEYSH, 0
	.byte VOICE, 64
	.byte PAN, c_v+10
	.byte PRIO, 119
	.byte W48
	.byte W72
	.byte VOL, 10
	.byte N24, An3, v088, 2
	.byte N24, An4, v068
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W03
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte N72, Gs3 @ v068
	.byte N72, Gs4, v064
	.byte W02
	.byte VOL, 65
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W04
	.byte 46 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W24
	.byte W02
	.byte W96
	.byte W24
track_68_lbl_2256f9:
	.byte W48
	.byte GOTO
		.word track_68_lbl_2256f9
	.byte FINE

track_68_5:
	.byte KEYSH, 0
	.byte VOICE, 83
	.byte PAN, c_v
	.byte PRIO, 30
	.byte VOL, 62
	.byte W48
	.byte W24
	.byte N03, Cn4, v080
	.byte W24
	.byte N03 @ Cn4, v080
	.byte W48
	.byte Cn4, v072 @ N03
	.byte W96
	.byte W24
	.byte N03 @ Cn4, v072
	.byte W24
	.byte N03 @ Cn4, v072
	.byte W48
	.byte W24
track_68_lbl_22571b:
	.byte W48
	.byte GOTO
		.word track_68_lbl_22571b
	.byte FINE

.align 2

track_68:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_68_0
	.word track_68_1
	.word track_68_2
	.word track_68_3
	.word track_68_4
	.word track_68_5

.align 2
