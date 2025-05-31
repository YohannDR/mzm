.align 2

.global track_466

track_466_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 82
	.byte PAN, c_v-20
	.byte BENDR, 6
	.byte PRIO, 1
	.byte BEND, c_v+13
	.byte TIE, Cn3, v108
	.byte W03
	.byte BEND, c_v+16
	.byte W03
	.byte c_v+19 @ BEND
	.byte W06
	.byte c_v+21 @ BEND
	.byte W03
	.byte c_v+20 @ BEND
	.byte W03
	.byte c_v+19 @ BEND
	.byte W06
	.byte c_v+18 @ BEND
	.byte W03
	.byte c_v+17 @ BEND
	.byte W03
	.byte c_v+15 @ BEND
	.byte W03
	.byte c_v+13 @ BEND
	.byte W03
	.byte c_v+12 @ BEND
	.byte W03
	.byte c_v+10 @ BEND
	.byte W03
	.byte c_v+8 @ BEND
	.byte W03
	.byte c_v+5 @ BEND
	.byte W03
	.byte c_v+3 @ BEND
	.byte W03
	.byte c_v+1 @ BEND
	.byte W13
	.byte VOICE, 16
	.byte VOL, 78
	.byte BEND, c_v
	.byte TIE, En3, v112
	.byte W32
	.byte W48
	.byte W02
	.byte EOT, Cn3 @ v112
	.byte W14
	.byte VOL, 69
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W04
	.byte EOT, En3 @ v112
	.byte VOICE, 15
	.byte VOL, 78
	.byte BENDR, 12
	.byte N72, Cn3, v112, 3
	.byte W06
	.byte BEND, c_v+15
	.byte W02
	.byte W04
	.byte c_v+31 @ BEND
	.byte W06
	.byte c_v+62 @ BEND
	.byte W56
	.byte W01
	.byte c_v+47 @ BEND
	.byte N92 @ Cn3, v112
	.byte W12
	.byte BEND, c_v+31
	.byte W17
	.byte W13
	.byte c_v+15 @ BEND
	.byte W06
	.byte c_v @ BEND
	.byte W32
	.byte VOL, 60
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 98 @ VOL
	.byte BENDR, 24
	.byte N48, Cn3, v127, 1
	.byte W12
	.byte BEND, c_v+31
	.byte W06
	.byte c_v+63 @ BEND
	.byte W15
	.byte W16
	.byte N36, Cn3, v032, 2
	.byte W36
	.byte W02
	.byte Cn3, v008, 2 @ N36
	.byte W36
	.byte W02
	.byte FINE

track_466_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 100
	.byte PAN, c_v-20
	.byte N08, En3, v060
	.byte W24
	.byte N05, Dn3, v112
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Cn3, v060
	.byte W28
	.byte W01
	.byte N05, En3, v112
	.byte W05
	.byte N14, Dn3, v127
	.byte W14
	.byte N13, Cn3, v060
	.byte W05
	.byte W24
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
	.byte W05
	.byte W24
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
	.byte W05
	.byte W24
	.byte N05, Dn3, v112
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Cn3, v060
	.byte W28
	.byte W01
	.byte N05, En3, v112
	.byte W05
	.byte N14, Dn3, v127
	.byte W14
	.byte N13, Cn3, v060
	.byte W05
	.byte W08
	.byte FINE

track_466_2:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 90
	.byte PAN, c_v-20
	.byte N03, Bn2, v092
	.byte W03
	.byte VOICE, 19
	.byte N07, Cn3 @ v092
	.byte W07
	.byte N21, Bn2, v072
	.byte W36
	.byte W02
	.byte VOICE, 6
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
	.byte N07, Dn3 @ v092
	.byte W07
	.byte N21, Cn3, v072
	.byte W36
	.byte W02
	.byte VOICE, 6
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
	.byte W07
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
	.byte W07
	.byte N21, Bn2, v072
	.byte W36
	.byte W02
	.byte VOICE, 6
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
	.byte N07, Dn3 @ v092
	.byte W07
	.byte N21, Cn3, v072
	.byte W21
	.byte FINE

track_466_3:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 25
	.byte W28
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W42
	.byte W01
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W15
track_466_lbl_214fd1:
	.byte W28
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W42
	.byte W01
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W15
	.byte PEND
	.byte PATT
		.word track_466_lbl_214fd1
	.byte PATT
		.word track_466_lbl_214fd1
	.byte W07
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W10
	.byte FINE

.align 2

track_466:
	.byte 4
	.byte 0
	.byte 228
	.byte 0
	.word voice_group10
	.word track_466_0
	.word track_466_1
	.word track_466_2
	.word track_466_3

.align 2
