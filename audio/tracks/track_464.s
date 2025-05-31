.align 2

.global track_464

track_464_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W32
	.byte W02
	.byte VOICE, 15
	.byte VOL, 98
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte PRIO, 1
	.byte BEND, c_v
	.byte N48, Cn3, v127, 1
	.byte W12
	.byte BEND, c_v+31
	.byte W06
	.byte c_v+63 @ BEND
	.byte W30
	.byte W01
	.byte VOL, 82
	.byte BEND, c_v
	.byte TIE, En3, v108
	.byte W13
	.byte W96
	.byte W10
	.byte EOT @ En3, v108
	.byte BENDR, 6
	.byte BEND, c_v+56
	.byte TIE, Cn3 @ v108
	.byte W03
	.byte BEND, c_v+51
	.byte W03
	.byte c_v+47 @ BEND
	.byte W03
	.byte c_v+43 @ BEND
	.byte W03
	.byte c_v+37 @ BEND
	.byte W03
	.byte c_v+33 @ BEND
	.byte W03
	.byte c_v+27 @ BEND
	.byte W03
	.byte c_v+21 @ BEND
	.byte W03
	.byte c_v+15 @ BEND
	.byte W03
	.byte c_v+7 @ BEND
	.byte W03
	.byte c_v-1 @ BEND
	.byte W03
	.byte c_v-9 @ BEND
	.byte W03
	.byte c_v-18 @ BEND
	.byte W03
	.byte c_v-29 @ BEND
	.byte W03
	.byte c_v-39 @ BEND
	.byte W03
	.byte c_v-46 @ BEND
	.byte W03
	.byte c_v-49 @ BEND
	.byte W03
	.byte c_v-51 @ BEND
	.byte W03
	.byte c_v-49 @ BEND
	.byte W03
	.byte c_v-45 @ BEND
	.byte W03
	.byte c_v-40 @ BEND
	.byte W03
	.byte c_v-32 @ BEND
	.byte W03
	.byte c_v-23 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-5 @ BEND
	.byte W03
	.byte c_v+3 @ BEND
	.byte W03
	.byte c_v+9 @ BEND
	.byte W03
	.byte c_v+13 @ BEND
	.byte W03
	.byte c_v+16 @ BEND
	.byte W01
	.byte W02
	.byte c_v+19 @ BEND
	.byte W06
	.byte c_v+21 @ BEND
	.byte W03
	.byte c_v+20 @ BEND
	.byte W03
	.byte c_v+19 @ BEND
	.byte W01
	.byte VOL, 63
	.byte W03
	.byte 49 @ VOL
	.byte W02
	.byte BEND, c_v+18
	.byte W01
	.byte VOL, 38
	.byte W02
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 30
	.byte W02
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 22
	.byte W02
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 17
	.byte W02
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 11
	.byte W02
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 7
	.byte W02
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 2
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ Cn3, v108
	.byte FINE

track_464_1:
	.byte KEYSH, 0
	.byte W96
	.byte W20
	.byte VOICE, 7
	.byte VOL, 100
	.byte PAN, c_v-20
	.byte N05, Cn3, v112
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v060
	.byte W28
	.byte W01
	.byte N05, Dn3, v112
	.byte W05
	.byte N14, Cn3, v127
	.byte W14
	.byte N13, En3, v060
	.byte W09
	.byte W20
	.byte N05, En3, v112
	.byte W05
	.byte N14, Cn3, v127
	.byte W14
	.byte N13, Dn3, v060
	.byte W28
	.byte W01
	.byte N05, Cn3, v112
	.byte W05
	.byte N14, Dn3, v127
	.byte W14
	.byte N13, En3, v060
	.byte W09
	.byte W15
	.byte VOL, 79
	.byte W03
	.byte 62 @ VOL
	.byte W02
	.byte N05, Dn3, v112
	.byte W01
	.byte VOL, 49
	.byte W03
	.byte 38 @ VOL
	.byte W01
	.byte N14, En3, v127
	.byte W02
	.byte VOL, 29
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte N02, Cn3, v060
	.byte W02
	.byte VOL, 0
	.byte W01
	.byte FINE

track_464_2:
	.byte KEYSH, 0
	.byte W96
	.byte W44
	.byte VOICE, 6
	.byte VOL, 90
	.byte PAN, c_v-20
	.byte N03, Bn2, v092
	.byte W03
	.byte VOICE, 19
	.byte N06 @ Bn2, v092
	.byte W06
	.byte N21, Cn3, v072
	.byte W36
	.byte W03
	.byte VOICE, 6
	.byte N03, Bn2, v092
	.byte W03
	.byte VOICE, 19
	.byte N07, An2 @ v092
	.byte W01
	.byte W06
	.byte N21, Bn2, v072
	.byte W36
	.byte W02
	.byte VOICE, 6
	.byte N03, Bn2, v092
	.byte W03
	.byte VOICE, 19
	.byte N07, Dn3 @ v092
	.byte W07
	.byte N21, Cn3, v072
	.byte W36
	.byte W02
	.byte VOICE, 6
	.byte N03, Bn2, v092
	.byte W03
	.byte VOICE, 19
	.byte N07, Cn3 @ v092
	.byte W01
	.byte W06
	.byte N21, Bn2, v072
	.byte W21
	.byte FINE

track_464_3:
	.byte KEYSH, 0
	.byte W24
	.byte VOICE, 17
	.byte MOD, 30
	.byte VOL, 78
	.byte PAN, c_v
	.byte LFOS, 80
	.byte PRIO, 25
	.byte N48, Fn2, v060
	.byte W48
	.byte LFOS, 100
	.byte N48, Fn2, v080
	.byte W24
	.byte W24
	.byte VOICE, 18
	.byte MOD, 0
	.byte VOL, 100
	.byte LFOS, 0
	.byte N05, Gs2 @ v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W42
	.byte W01
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W19
	.byte W24
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W42
	.byte W01
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W19
	.byte W24
	.byte N03, Gs2, v080
	.byte W03
	.byte FINE

.align 2

track_464:
	.byte 4
	.byte 0
	.byte 228
	.byte 0
	.word voice_group10
	.word track_464_0
	.word track_464_1
	.word track_464_2
	.word track_464_3

.align 2
