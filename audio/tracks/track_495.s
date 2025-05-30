.align 2

.global track_495

track_495_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 105
	.byte PAN, c_v-20
	.byte N05, Cn3, v120
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v060
	.byte W28
	.byte W01
	.byte N05, Dn3, v120
	.byte W05
	.byte N14, Cn3, v127
	.byte W14
	.byte N13, En3, v092
	.byte W28
	.byte W01
	.byte N05, En3, v120
	.byte W05
	.byte N14, Cn3, v127
	.byte W14
	.byte N13, Dn3, v080
	.byte W13
	.byte FINE

track_495_1:
	.byte KEYSH, 0
	.byte W24
	.byte VOICE, 12
	.byte VOL, 105
	.byte PAN, c_v-20
	.byte N03, Bn2, v120
	.byte W03
	.byte VOICE, 15
	.byte N06, Gn2, v127
	.byte W06
	.byte N21, Cn3, v092
	.byte W36
	.byte W03
	.byte VOICE, 12
	.byte N03, Bn2, v112
	.byte W03
	.byte VOICE, 14
	.byte N07, An2 @ v112
	.byte W07
	.byte N21, Bn2, v092
	.byte W14
	.byte W24
	.byte VOICE, 12
	.byte N03, Bn2, v112
	.byte W03
	.byte VOICE, 15
	.byte N07, An2, v127
	.byte W07
	.byte N20, Cn3, v112
	.byte W20
	.byte FINE

track_495_2:
	.byte KEYSH, 0
	.byte W04
	.byte VOICE, 16
	.byte MOD, 0
	.byte VOL, 105
	.byte LFOS, 0
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W42
	.byte W01
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W36
	.byte W03
	.byte W04
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W24
	.byte W01
	.byte Gs2, v080 @ N10
	.byte W10
	.byte FINE

track_495_3:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 105
	.byte PAN, c_v
	.byte PRIO, 1
	.byte BEND, c_v
	.byte W10
	.byte N56, Cn3, v120, 2
	.byte W14
	.byte MOD, 30
	.byte LFOS, 100
	.byte MODT, mod_tre
	.byte W72
	.byte MOD, 0
	.byte LFOS, 0
	.byte W07
	.byte N44, Fn3, v127
	.byte W44
	.byte Fn3, v052 @ N44
	.byte W44
	.byte Fn3, v028 @ N44
	.byte W01
	.byte W42
	.byte W01
	.byte FINE

.align 2

track_495:
	.byte 4
	.byte 0
	.byte 228
	.byte 0
	.word voice_group13
	.word track_495_0
	.word track_495_1
	.word track_495_2
	.word track_495_3

.align 2
