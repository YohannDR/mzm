.align 2

.global track_9

track_9_0:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 18
	.byte VOL, 31
	.byte PAN, c_v+15
	.byte N72, Dn1, v080
	.byte W96
track_9_lbl_22e8f2:
	.byte N72, Dn1, v092
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
	.byte GOTO
		.word track_9_lbl_22e8f2
	.byte FINE

track_9_1:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 25
	.byte PAN, c_v-17
	.byte N80, An1, v044
	.byte W96
track_9_lbl_22e920:
	.byte N80, An1, v056
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
	.byte GOTO
		.word track_9_lbl_22e920
	.byte FINE

track_9_2:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 18
	.byte PAN, c_v
	.byte W96
track_9_lbl_22e94b:
	.byte W96
track_9_lbl_22e94c:
	.byte N16, Dn5, v080
	.byte W16
	.byte Dn5, v048 @ N16
	.byte W16
	.byte Dn5, v024 @ N16
	.byte W64
	.byte PEND
track_9_lbl_22e957:
	.byte N16, As5, v080
	.byte W16
	.byte As5, v048 @ N16
	.byte W16
	.byte As5, v024 @ N16
	.byte W64
	.byte PEND
	.byte Fn5, v080 @ N16
	.byte W16
	.byte Fn5, v048 @ N16
	.byte W16
	.byte Fn5, v024 @ N16
	.byte W64
	.byte W96
	.byte PATT
		.word track_9_lbl_22e94c
	.byte N16, Cn6, v080
	.byte W16
	.byte Cn6, v048 @ N16
	.byte W16
	.byte Cn6, v024 @ N16
	.byte W64
	.byte PATT
		.word track_9_lbl_22e957
	.byte W96
	.byte GOTO
		.word track_9_lbl_22e94b
	.byte FINE

.align 2

track_9:
	.byte 3
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_9_0
	.word track_9_1
	.word track_9_2

.align 2
