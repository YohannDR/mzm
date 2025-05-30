.align 2

.global track_63

track_63_0:
	.byte KEYSH, 0
	.byte TEMPO, 118
	.byte PAN, c_v+20
	.byte PRIO, 120
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte VOICE, 2
	.byte MOD, 100
	.byte BENDR, 2
	.byte LFOS, 80
	.byte MODT, mod_tre
	.byte BEND, c_v-10
	.byte W24
	.byte W96
	.byte W24
	.byte W15
	.byte VOL, 14
	.byte LFOS, 70
	.byte TIE, Fs5, v020
	.byte W09
	.byte VOL, 16
	.byte LFOS, 72
	.byte W09
	.byte VOL, 17
	.byte W03
	.byte LFOS, 74
	.byte W03
	.byte VOL, 18
	.byte W06
	.byte 20 @ VOL
	.byte LFOS, 76
	.byte W06
	.byte VOL, 21
	.byte W06
	.byte 22 @ VOL
	.byte LFOS, 78
	.byte W06
	.byte VOL, 23
	.byte W03
	.byte LFOS, 80
	.byte W06
	.byte VOL, 25
	.byte W06
	.byte 26 @ VOL
	.byte LFOS, 82
	.byte W06
	.byte VOL, 27
	.byte W06
	.byte 28 @ VOL
	.byte LFOS, 84
	.byte W06
	.byte VOL, 30
	.byte W03
	.byte LFOS, 86
	.byte W06
	.byte VOL, 31
	.byte W06
	.byte 32 @ VOL
	.byte LFOS, 88
	.byte W06
	.byte VOL, 34
	.byte W03
	.byte W03
	.byte 35 @ VOL
	.byte LFOS, 90
	.byte W06
	.byte VOL, 36
	.byte W03
	.byte LFOS, 92
	.byte W03
	.byte VOL, 37
	.byte LFOS, 90
	.byte W06
	.byte 88 @ VOL
	.byte VOL, 35
	.byte W03
	.byte LFOS, 86
	.byte W03
	.byte VOL, 34
	.byte W03
	.byte LFOS, 84
	.byte W06
	.byte 82 @ VOL
	.byte VOL, 32
	.byte W06
	.byte 31 @ VOL
	.byte W03
	.byte LFOS, 78
	.byte W06
	.byte 76 @ VOL
	.byte VOL, 30
	.byte W06
	.byte LFOS, 74
	.byte VOL, 28
	.byte W03
	.byte LFOS, 72
	.byte W06
	.byte 70 @ VOL
	.byte VOL, 27
	.byte W06
	.byte LFOS, 68
	.byte W03
	.byte VOL, 26
	.byte W06
	.byte LFOS, 64
	.byte VOL, 25
	.byte W06
	.byte LFOS, 62
	.byte W03
	.byte VOL, 23
	.byte W03
	.byte LFOS, 60
	.byte W03
	.byte 58 @ VOL
	.byte VOL, 22
	.byte W06
	.byte LFOS, 56
	.byte W03
	.byte 50 @ VOL
	.byte VOL, 21
	.byte W03
	.byte LFOS, 48
	.byte W03
	.byte 46 @ VOL
	.byte VOL, 20
	.byte W03
	.byte LFOS, 44
	.byte W06
	.byte 41 @ VOL
	.byte VOL, 18
	.byte W03
	.byte LFOS, 39
	.byte W03
	.byte VOL, 17
	.byte W03
	.byte LFOS, 35
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte VOL, 16
	.byte W03
	.byte LFOS, 29
	.byte W03
	.byte 27 @ VOL
	.byte VOL, 15
	.byte W03
	.byte LFOS, 25
	.byte W06
	.byte EOT @ Fs5, v020
	.byte W21
	.byte VOL, 10
	.byte W68
	.byte W01
	.byte W96
	.byte W24
	.byte W96
	.byte W15
	.byte 14 @ VOL
	.byte LFOS, 80
	.byte TIE @ Fs5, v020
	.byte W09
track_63_lbl_222b31:
	.byte VOL, 16
	.byte LFOS, 72
	.byte W09
	.byte VOL, 17
	.byte W03
	.byte LFOS, 74
	.byte W03
	.byte VOL, 18
	.byte W06
	.byte 20 @ VOL
	.byte LFOS, 76
	.byte W06
	.byte VOL, 21
	.byte W06
	.byte 22 @ VOL
	.byte LFOS, 78
	.byte W06
	.byte VOL, 23
	.byte W03
	.byte LFOS, 80
	.byte W06
	.byte VOL, 25
	.byte W06
	.byte 26 @ VOL
	.byte LFOS, 82
	.byte W06
	.byte VOL, 27
	.byte W06
	.byte 28 @ VOL
	.byte LFOS, 84
	.byte W06
	.byte VOL, 30
	.byte W03
	.byte LFOS, 86
	.byte W06
	.byte VOL, 31
	.byte W06
	.byte 32 @ VOL
	.byte LFOS, 88
	.byte W06
	.byte VOL, 34
	.byte W06
	.byte 35 @ VOL
	.byte LFOS, 90
	.byte W06
	.byte VOL, 36
	.byte W03
	.byte LFOS, 92
	.byte W03
	.byte VOL, 37
	.byte LFOS, 90
	.byte W06
	.byte 88 @ VOL
	.byte VOL, 35
	.byte W03
	.byte PEND
track_63_lbl_222b82:
	.byte LFOS, 86
	.byte W03
	.byte VOL, 34
	.byte W03
	.byte LFOS, 84
	.byte W06
	.byte 82 @ VOL
	.byte VOL, 32
	.byte W06
	.byte 31 @ VOL
	.byte W03
	.byte LFOS, 78
	.byte W06
	.byte 76 @ VOL
	.byte VOL, 30
	.byte W06
	.byte LFOS, 74
	.byte VOL, 28
	.byte W03
	.byte LFOS, 72
	.byte W06
	.byte 70 @ VOL
	.byte VOL, 27
	.byte W06
	.byte LFOS, 68
	.byte W03
	.byte VOL, 26
	.byte W06
	.byte LFOS, 64
	.byte VOL, 25
	.byte W06
	.byte LFOS, 62
	.byte W03
	.byte VOL, 23
	.byte W03
	.byte LFOS, 60
	.byte W03
	.byte 58 @ VOL
	.byte VOL, 22
	.byte W06
	.byte LFOS, 56
	.byte W03
	.byte 50 @ VOL
	.byte VOL, 21
	.byte W03
	.byte LFOS, 48
	.byte W03
	.byte 46 @ VOL
	.byte VOL, 20
	.byte W03
	.byte LFOS, 44
	.byte W06
	.byte 41 @ VOL
	.byte VOL, 18
	.byte W03
	.byte LFOS, 39
	.byte W03
	.byte VOL, 17
	.byte W03
	.byte LFOS, 35
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte VOL, 16
	.byte W03
	.byte LFOS, 29
	.byte W03
	.byte 27 @ VOL
	.byte VOL, 15
	.byte W03
	.byte PEND
	.byte LFOS, 25
	.byte W06
	.byte EOT, Fs5 @ v020
	.byte W21
	.byte VOL, 10
	.byte W92
	.byte W01
	.byte W96
	.byte W24
track_63_lbl_222bf4:
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte VOICE, 2
	.byte BEND, c_v-10
	.byte W96
	.byte W15
	.byte VOL, 14
	.byte LFOS, 80
	.byte TIE, Fs5, v020
	.byte W09
	.byte PATT
		.word track_63_lbl_222b31
	.byte PATT
		.word track_63_lbl_222b82
	.byte LFOS, 25
	.byte W06
	.byte EOT, Fs5 @ v020
	.byte W21
	.byte VOL, 10
	.byte W92
	.byte W01
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte GOTO
		.word track_63_lbl_222bf4
	.byte FINE

track_63_1:
	.byte KEYSH, 0
	.byte PRIO, 120
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
track_63_lbl_222c5a:
	.byte VOICE, 27
	.byte VOL, 12
	.byte TIE, En4, v040
	.byte W11
	.byte VOL, 15
	.byte W09
	.byte 17 @ VOL
	.byte W09
	.byte 20 @ VOL
	.byte W10
	.byte 22 @ VOL
	.byte W09
	.byte 25 @ VOL
	.byte W09
	.byte 27 @ VOL
	.byte W09
	.byte 30 @ VOL
	.byte W10
	.byte 32 @ VOL
	.byte W04
	.byte 34 @ VOL
	.byte W40
	.byte W96
	.byte EOT @ En4, v040
	.byte N48, Fs4, v052
	.byte W24
	.byte W24
	.byte TIE, Fn4 @ v052
	.byte W96
	.byte W48
	.byte EOT @ Fn4, v052
	.byte TIE, En4 @ v052
	.byte W72
	.byte W72
	.byte EOT @ En4, v052
	.byte TIE, Ds4, v040
	.byte W48
	.byte W80
	.byte VOL, 31
	.byte W24
	.byte W01
	.byte 28 @ VOL
	.byte W15
	.byte W11
	.byte 26 @ VOL
	.byte W24
	.byte W02
	.byte 23 @ VOL
	.byte W24
	.byte W01
	.byte 21 @ VOL
	.byte W24
	.byte W02
	.byte 18 @ VOL
	.byte W24
	.byte W02
	.byte 16 @ VOL
	.byte W06
	.byte EOT @ Ds4, v040
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte GOTO
		.word track_63_lbl_222c5a
	.byte FINE

track_63_2:
	.byte KEYSH, 0
	.byte VOICE, 47
	.byte VOL, 31
	.byte PRIO, 119
	.byte W96
	.byte W24
track_63_lbl_222cc3:
	.byte N24, An3, v032
	.byte W24
	.byte Dn4, v036 @ N24
	.byte W24
	.byte Gn4, v040 @ N24
	.byte W24
	.byte Fs4, v044 @ N24
	.byte W24
	.byte Fn4, v048 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222cd4:
	.byte N24, En4, v052
	.byte W24
	.byte Gn3, v056 @ N24
	.byte W24
	.byte Ds4, v060 @ N24
	.byte W24
	.byte Dn4, v064 @ N24
	.byte W24
	.byte Cs4, v068 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222ce5:
	.byte N24, An3, v072
	.byte W24
	.byte Dn4, v076 @ N24
	.byte W24
	.byte Gn4, v080 @ N24
	.byte W24
	.byte Fs4, v084 @ N24
	.byte W24
	.byte Fn4, v088 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222cf6:
	.byte N24, En4, v092
	.byte W24
	.byte Gn3 @ N24, v092
	.byte W24
	.byte Ds4 @ N24, v092
	.byte W24
	.byte Dn4 @ N24, v092
	.byte W24
	.byte Cs4 @ N24, v092
	.byte W24
	.byte PEND
track_63_lbl_222d03:
	.byte N24, An3, v092
	.byte W24
	.byte Dn4 @ N24, v092
	.byte W24
	.byte Gn4 @ N24, v092
	.byte W24
	.byte Fs4 @ N24, v092
	.byte W24
	.byte Fn4 @ N24, v092
	.byte W24
	.byte PEND
track_63_lbl_222d10:
	.byte N24, En4, v092
	.byte W24
	.byte Gn3, v088 @ N24
	.byte W24
	.byte Ds4, v084 @ N24
	.byte W24
	.byte Dn4, v080 @ N24
	.byte W24
	.byte Cs4, v076 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222d21:
	.byte N24, An3, v072
	.byte W24
	.byte Dn4, v068 @ N24
	.byte W24
	.byte Gn4, v064 @ N24
	.byte W24
	.byte Fs4, v060 @ N24
	.byte W24
	.byte Fn4, v056 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222d32:
	.byte N24, En4, v052
	.byte W24
	.byte Gn3, v048 @ N24
	.byte W24
	.byte Ds4, v044 @ N24
	.byte W24
	.byte Dn4, v040 @ N24
	.byte W24
	.byte Cs4, v036 @ N24
	.byte W24
	.byte PEND
	.byte PATT
		.word track_63_lbl_222cc3
	.byte PATT
		.word track_63_lbl_222cd4
	.byte PATT
		.word track_63_lbl_222ce5
	.byte PATT
		.word track_63_lbl_222cf6
	.byte PATT
		.word track_63_lbl_222d03
	.byte PATT
		.word track_63_lbl_222d10
	.byte PATT
		.word track_63_lbl_222d21
	.byte PATT
		.word track_63_lbl_222d32
track_63_lbl_222d6b:
	.byte PAN, c_v+10
	.byte N24, An3, v032
	.byte W24
	.byte Dn4, v036 @ N24
	.byte W24
	.byte Gn4, v040 @ N24
	.byte W24
	.byte Fs4, v044 @ N24
	.byte W24
	.byte Fn4, v048 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222d7e:
	.byte PAN, c_v+20
	.byte N24, En4, v052
	.byte W24
	.byte Gn3, v056 @ N24
	.byte W24
	.byte Ds4, v060 @ N24
	.byte W24
	.byte Dn4, v064 @ N24
	.byte W24
	.byte Cs4, v068 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222d91:
	.byte PAN, c_v+10
	.byte N24, An3, v072
	.byte W24
	.byte Dn4, v076 @ N24
	.byte W24
	.byte Gn4, v080 @ N24
	.byte W24
	.byte Fs4, v084 @ N24
	.byte W24
	.byte Fn4, v088 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222da4:
	.byte PAN, c_v
	.byte N24, En4, v092
	.byte W24
	.byte Gn3 @ N24, v092
	.byte W24
	.byte Ds4 @ N24, v092
	.byte W24
	.byte Dn4 @ N24, v092
	.byte W24
	.byte Cs4 @ N24, v092
	.byte W24
	.byte PEND
track_63_lbl_222db3:
	.byte PAN, c_v-10
	.byte N24, An3, v092
	.byte W24
	.byte Dn4 @ N24, v092
	.byte W24
	.byte Gn4 @ N24, v092
	.byte W24
	.byte Fs4 @ N24, v092
	.byte W24
	.byte Fn4 @ N24, v092
	.byte W24
	.byte PEND
track_63_lbl_222dc2:
	.byte PAN, c_v-20
	.byte N24, En4, v092
	.byte W24
	.byte Gn3, v088 @ N24
	.byte W24
	.byte Ds4, v084 @ N24
	.byte W24
	.byte Dn4, v080 @ N24
	.byte W24
	.byte Cs4, v076 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222dd5:
	.byte PAN, c_v-10
	.byte N24, An3, v072
	.byte W24
	.byte Dn4, v068 @ N24
	.byte W24
	.byte Gn4, v064 @ N24
	.byte W24
	.byte Fs4, v060 @ N24
	.byte W24
	.byte Fn4, v056 @ N24
	.byte W24
	.byte PEND
track_63_lbl_222de8:
	.byte PAN, c_v
	.byte N24, En4, v052
	.byte W24
	.byte Gn3, v048 @ N24
	.byte W24
	.byte Ds4, v044 @ N24
	.byte W24
	.byte Dn4, v040 @ N24
	.byte W24
	.byte Cs4, v036 @ N24
	.byte W24
	.byte PEND
	.byte PATT
		.word track_63_lbl_222d6b
	.byte PATT
		.word track_63_lbl_222d7e
	.byte PATT
		.word track_63_lbl_222d91
	.byte PATT
		.word track_63_lbl_222da4
	.byte PATT
		.word track_63_lbl_222db3
	.byte PATT
		.word track_63_lbl_222dc2
	.byte PATT
		.word track_63_lbl_222dd5
	.byte PATT
		.word track_63_lbl_222de8
	.byte GOTO
		.word track_63_lbl_222d6b
	.byte FINE

track_63_3:
	.byte KEYSH, 0
	.byte VOICE, 47
	.byte VOL, 25
	.byte PRIO, 118
	.byte W96
	.byte W24
	.byte W12
	.byte N24, Fs5, v032
	.byte W24
	.byte Gs5, v036 @ N24
	.byte W24
	.byte Gn5, v040 @ N24
	.byte W24
	.byte As5, v044 @ N24
	.byte W24
	.byte Fs5, v048 @ N24
	.byte W12
	.byte W12
	.byte Gs5, v052 @ N24
	.byte W24
	.byte Gn5, v056 @ N24
	.byte W24
	.byte As5, v060 @ N24
	.byte W24
	.byte Fs5, v064 @ N24
	.byte W24
	.byte Gs5, v068 @ N24
	.byte W12
track_63_lbl_222e54:
	.byte W12
	.byte N24, Gn5, v044
	.byte W24
	.byte As5, v040 @ N24
	.byte W24
	.byte Fs5, v036 @ N24
	.byte W24
	.byte Gs5, v032 @ N24
	.byte W24
	.byte Gn5 @ N24, v032
	.byte W12
	.byte PEND
track_63_lbl_222e65:
	.byte W12
	.byte N24, As5, v032
	.byte W24
	.byte Fs5, v036 @ N24
	.byte W24
	.byte Gs5 @ N24, v036
	.byte W24
	.byte Gn5, v040 @ N24
	.byte W24
	.byte As5 @ N24, v040
	.byte W12
	.byte PEND
track_63_lbl_222e75:
	.byte W12
	.byte N24, Fs5, v044
	.byte W24
	.byte Gs5 @ N24, v044
	.byte W24
	.byte Gn5, v048 @ N24
	.byte W24
	.byte As5 @ N24, v048
	.byte W24
	.byte Fs5, v052 @ N24
	.byte W12
	.byte PEND
track_63_lbl_222e85:
	.byte W12
	.byte N24, Gs5, v052
	.byte W24
	.byte Gn5, v056 @ N24
	.byte W24
	.byte As5 @ N24, v056
	.byte W24
	.byte Fs5, v060 @ N24
	.byte W24
	.byte Gs5 @ N24, v060
	.byte W12
	.byte PEND
track_63_lbl_222e95:
	.byte W12
	.byte N24, Gn5, v064
	.byte W24
	.byte As5 @ N24, v064
	.byte W24
	.byte Fs5, v068 @ N24
	.byte W24
	.byte Gs5 @ N24, v068
	.byte W24
	.byte Gn5, v072 @ N24
	.byte W12
	.byte PEND
track_63_lbl_222ea5:
	.byte W12
	.byte N24, As5, v072
	.byte W24
	.byte Fs5 @ N24, v072
	.byte W24
	.byte Gs5 @ N24, v072
	.byte W24
	.byte Gn5 @ N24, v072
	.byte W24
	.byte As5 @ N24, v072
	.byte W12
	.byte PEND
	.byte W12
	.byte Fs5 @ N24, v072
	.byte W24
	.byte Gs5, v068 @ N24
	.byte W24
	.byte Gn5, v064 @ N24
	.byte W24
	.byte As5 @ N24, v064
	.byte W24
	.byte Fs5, v060 @ N24
	.byte W12
	.byte W12
	.byte Gs5, v056 @ N24
	.byte W24
	.byte Gn5, v052 @ N24
	.byte W24
	.byte As5 @ N24, v052
	.byte W24
	.byte Fs5, v048 @ N24
	.byte W24
	.byte Gs5, v044 @ N24
	.byte W12
	.byte PATT
		.word track_63_lbl_222e54
	.byte PATT
		.word track_63_lbl_222e65
	.byte PATT
		.word track_63_lbl_222e75
	.byte PATT
		.word track_63_lbl_222e85
	.byte PATT
		.word track_63_lbl_222e95
	.byte PATT
		.word track_63_lbl_222ea5
track_63_lbl_222eee:
	.byte PAN, c_v-10
	.byte W12
	.byte N24, Fs5, v072
	.byte W24
	.byte Gs5, v068 @ N24
	.byte W24
	.byte Gn5, v064 @ N24
	.byte W24
	.byte As5 @ N24, v064
	.byte W24
	.byte Fs5, v060 @ N24
	.byte W12
	.byte PEND
	.byte W24
	.byte VOICE, 27
	.byte VOL, 34
	.byte TIE, Ds4, v048
	.byte W96
	.byte W96
	.byte W24
	.byte W48
	.byte EOT @ Ds4, v048
	.byte TIE, Cn4, v052
	.byte W72
	.byte W72
	.byte EOT @ Cn4, v052
	.byte TIE, Cs4, v040
	.byte W48
	.byte W80
	.byte VOL, 31
	.byte W24
	.byte W01
	.byte 28 @ VOL
	.byte W15
	.byte W11
	.byte 26 @ VOL
	.byte W24
	.byte W02
	.byte 23 @ VOL
	.byte W24
	.byte W01
	.byte 21 @ VOL
	.byte W24
	.byte W02
	.byte 18 @ VOL
	.byte W24
	.byte W02
	.byte 16 @ VOL
	.byte W06
	.byte EOT @ Cs4, v040
	.byte VOICE, 47
	.byte VOL, 25
	.byte PAN, c_v
	.byte W12
	.byte N24, As5, v072
	.byte W24
	.byte Fs5 @ N24, v072
	.byte W24
	.byte Gs5 @ N24, v072
	.byte W24
	.byte Gn5 @ N24, v072
	.byte W24
	.byte As5 @ N24, v072
	.byte W12
	.byte PATT
		.word track_63_lbl_222eee
	.byte PAN, c_v-20
	.byte W12
	.byte N24, Gs5, v056
	.byte W24
	.byte Gn5, v052 @ N24
	.byte W24
	.byte As5 @ N24, v052
	.byte W24
	.byte Fs5, v048 @ N24
	.byte W24
	.byte Gs5, v044 @ N24
	.byte W12
	.byte PAN, c_v-10
	.byte W12
	.byte N24, Gn5 @ v044
	.byte W24
	.byte As5, v040 @ N24
	.byte W24
	.byte Fs5, v036 @ N24
	.byte W24
	.byte Gs5, v032 @ N24
	.byte W24
	.byte Gn5 @ N24, v032
	.byte W12
	.byte PAN, c_v
	.byte W12
	.byte N24, As5 @ v032
	.byte W24
	.byte Fs5, v036 @ N24
	.byte W24
	.byte Gs5 @ N24, v036
	.byte W24
	.byte Gn5, v040 @ N24
	.byte W24
	.byte As5 @ N24, v040
	.byte W12
	.byte PAN, c_v+10
	.byte W12
	.byte N24, Fs5, v044
	.byte W24
	.byte Gs5 @ N24, v044
	.byte W24
	.byte Gn5, v048 @ N24
	.byte W24
	.byte As5 @ N24, v048
	.byte W24
	.byte Fs5, v052 @ N24
	.byte W12
	.byte PAN, c_v+20
	.byte W12
	.byte N24, Gs5 @ v052
	.byte W24
	.byte Gn5, v056 @ N24
	.byte W24
	.byte As5 @ N24, v056
	.byte W24
	.byte Fs5, v060 @ N24
	.byte W24
	.byte Gs5 @ N24, v060
	.byte W12
	.byte PAN, c_v+10
	.byte W12
	.byte N24, Gn5, v064
	.byte W24
	.byte As5 @ N24, v064
	.byte W24
	.byte Fs5, v068 @ N24
	.byte W24
	.byte Gs5 @ N24, v068
	.byte W24
	.byte Gn5, v072 @ N24
	.byte W12
	.byte PAN, c_v
	.byte W12
	.byte N24, As5 @ v072
	.byte W24
	.byte Fs5 @ N24, v072
	.byte W24
	.byte Gs5 @ N24, v072
	.byte W24
	.byte Gn5 @ N24, v072
	.byte W24
	.byte As5 @ N24, v072
	.byte W12
	.byte GOTO
		.word track_63_lbl_222eee
	.byte W12
	.byte FINE

track_63_4:
	.byte KEYSH, 0
	.byte PRIO, 30
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
track_63_lbl_222fe7:
	.byte W96
	.byte W24
	.byte VOICE, 47
	.byte VOL, 25
	.byte PAN, c_v-20
	.byte W12
	.byte N24, Gs5, v056
	.byte W24
	.byte Gn5, v052 @ N24
	.byte W24
	.byte As5 @ N24, v052
	.byte W24
	.byte Fs5, v048 @ N24
	.byte W24
	.byte Gs5, v044 @ N24
	.byte W12
	.byte PAN, c_v-10
	.byte W12
	.byte N24, Gn5 @ v044
	.byte W24
	.byte As5, v040 @ N24
	.byte W24
	.byte Fs5, v036 @ N24
	.byte W24
	.byte Gs5, v032 @ N24
	.byte W24
	.byte Gn5 @ N24, v032
	.byte W12
	.byte PAN, c_v
	.byte W12
	.byte N24, As5 @ v032
	.byte W24
	.byte Fs5, v036 @ N24
	.byte W24
	.byte Gs5 @ N24, v036
	.byte W24
	.byte Gn5, v040 @ N24
	.byte W24
	.byte As5 @ N24, v040
	.byte W12
	.byte PAN, c_v+10
	.byte W12
	.byte N24, Fs5, v044
	.byte W24
	.byte Gs5 @ N24, v044
	.byte W24
	.byte Gn5, v048 @ N24
	.byte W24
	.byte As5 @ N24, v048
	.byte W24
	.byte Fs5, v052 @ N24
	.byte W12
	.byte PAN, c_v+20
	.byte W12
	.byte N24, Gs5 @ v052
	.byte W24
	.byte Gn5, v056 @ N24
	.byte W24
	.byte As5 @ N24, v056
	.byte W24
	.byte Fs5, v060 @ N24
	.byte W24
	.byte Gs5 @ N24, v060
	.byte W12
	.byte PAN, c_v+10
	.byte W12
	.byte N24, Gn5, v064
	.byte W24
	.byte As5 @ N24, v064
	.byte W24
	.byte Fs5, v068 @ N24
	.byte W24
	.byte Gs5 @ N24, v068
	.byte W24
	.byte Gn5, v072 @ N24
	.byte W12
	.byte PAN, c_v
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte W96
	.byte W24
	.byte GOTO
		.word track_63_lbl_222fe7
	.byte FINE

track_63_5:
	.byte KEYSH, 0
	.byte VOICE, 45
	.byte PRIO, 29
	.byte VOL, 18
	.byte N32, Cn3, v016, 3
	.byte W36
	.byte Cn3, v024, 3 @ N32
	.byte W36
	.byte N23, Cn3, v036
	.byte W24
	.byte Cn3, v044 @ N23
	.byte W24
track_63_lbl_223084:
	.byte N32, Cn3, v044, 3
	.byte W36
	.byte Cn3, v036, 3 @ N32
	.byte W36
	.byte N23, Cn3, v044
	.byte W24
	.byte Cn3, v036 @ N23
	.byte W24
	.byte PEND
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
track_63_lbl_2230e0:
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte PATT
		.word track_63_lbl_223084
	.byte GOTO
		.word track_63_lbl_2230e0
	.byte FINE

.align 2

track_63:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_63_0
	.word track_63_1
	.word track_63_2
	.word track_63_3
	.word track_63_4
	.word track_63_5

.align 2
