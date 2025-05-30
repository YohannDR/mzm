.align 2

.global track_419

track_419_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 110
	.byte PAN, c_v
	.byte W32
	.byte N32, Cn2, v072
	.byte W32
	.byte N24, Dn2, v052
	.byte W24
	.byte N20, En2, v060
	.byte W08
	.byte W12
	.byte N16, Fn2, v072
	.byte W16
	.byte N12, Gn2, v080
	.byte W12
	.byte N08, An2, v092
	.byte W08
	.byte N23, Gn3, v100
	.byte W23
	.byte FINE

track_419_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 60
	.byte PAN, c_v
	.byte W32
	.byte N32, Cn1, v072
	.byte W24
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte N24, Dn1, v060
	.byte W16
	.byte VOL, 37
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte N20, En1, v068
	.byte W08
	.byte W03
	.byte VOL, 43
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte N16, Fn1, v072
	.byte W09
	.byte VOL, 39
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte N12, Gn1, v076
	.byte W06
	.byte VOL, 37
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte N08, An1, v080
	.byte W05
	.byte VOL, 20
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W04
	.byte 80 @ VOL
	.byte N10, Cn2, v092
	.byte W03
	.byte VOL, 65
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_419:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group8
	.word track_419_0
	.word track_419_1

.align 2
