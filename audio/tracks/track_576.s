.align 2

.global track_576

track_576_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 25
	.byte VOL, 100
	.byte PAN, c_v-20
	.byte N05, Cn3, v112
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v060
	.byte W23
	.byte VOL, 84
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte N05, En3, v112
	.byte W02
	.byte VOL, 44
	.byte W02
	.byte 37 @ VOL
	.byte W01
	.byte N14, Dn3, v127
	.byte W01
	.byte VOL, 32
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W01
	.byte N13, Fn3, v060
	.byte W01
	.byte VOL, 5
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W24
	.byte N05, En3, v112
	.byte W05
	.byte N14, Cn3, v127
	.byte W14
	.byte FINE

track_576_1:
	.byte KEYSH, 0
	.byte W24
	.byte VOICE, 24
	.byte VOL, 100
	.byte PAN, c_v-20
	.byte N03, Bn2, v112
	.byte W03
	.byte VOICE, 27
	.byte N06 @ Bn2, v112
	.byte W06
	.byte N21, Cn3, v092
	.byte W09
	.byte VOL, 84
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte VOICE, 24
	.byte VOL, 0
	.byte N03, Cn3, v112
	.byte W03
	.byte VOICE, 27
	.byte N07 @ Cn3, v112
	.byte W07
	.byte N21, Dn3, v092
	.byte W14
	.byte W07
	.byte FINE

track_576_2:
	.byte KEYSH, 0
	.byte W04
	.byte VOICE, 26
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 22
	.byte N05, Gs2, v100
	.byte W05
	.byte N10, Gs2, v127
	.byte W10
	.byte FINE

track_576_3:
	.byte KEYSH, 0
	.byte W32
	.byte W02
	.byte VOICE, 29
	.byte VOL, 87
	.byte PAN, c_v
	.byte N14, Cn3, v127
	.byte W08
	.byte VOL, 84
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte N14, Cn3, v032
	.byte W02
	.byte VOL, 44
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte N18, Cn3, v012
	.byte W02
	.byte VOL, 11
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W10
	.byte VOICE, 29
	.byte N14, Cn3, v127
	.byte W14
	.byte Cn3, v032 @ N14
	.byte W14
	.byte N18, Cn3, v012
	.byte W18
	.byte FINE

track_576_4:
	.byte KEYSH, 0
	.byte W15
	.byte VOICE, 30
	.byte VOL, 87
	.byte PAN, c_v
	.byte N05, Cn3, v100
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v052
	.byte W08
	.byte VOL, 84
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte VOICE, 29
	.byte N18, Cn3, v020
	.byte W01
	.byte VOL, 52
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W01
	.byte VOICE, 30
	.byte N05, Cn3, v100
	.byte W01
	.byte VOL, 5
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v052
	.byte W10
	.byte W03
	.byte VOICE, 29
	.byte N18, Cn3, v020
	.byte W18
	.byte FINE

track_576_5:
	.byte KEYSH, 0
	.byte W07
	.byte VOICE, 28
	.byte VOL, 100
	.byte PAN, c_v
	.byte N24, An2, v127, 3
	.byte W24
	.byte W03
	.byte An2, v120, 3 @ N24
	.byte W08
	.byte VOL, 84
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W01
	.byte N24, An2, v080, 3
	.byte W01
	.byte VOL, 11
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W18
	.byte FINE

.align 2

track_576:
	.byte 6
	.byte 0
	.byte 228
	.byte 0
	.word voice_group17
	.word track_576_0
	.word track_576_1
	.word track_576_2
	.word track_576_3
	.word track_576_4
	.word track_576_5

.align 2
