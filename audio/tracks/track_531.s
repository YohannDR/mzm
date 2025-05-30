.align 2

.global track_531

track_531_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W14
	.byte VOICE, 15
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 0
	.byte N60, Gn1, v100, 1
	.byte N60, Cn2, v100, 1
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_531_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 42
	.byte PAN, c_v
	.byte N05, Cn3, v080
	.byte W05
	.byte En3 @ N05, v080
	.byte W05
	.byte Bn3 @ N05, v080
	.byte W05
	.byte Bn3, v032 @ N05
	.byte W05
	.byte Bn3, v012 @ N05
	.byte W05
	.byte FINE

.align 2

track_531:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group16
	.word track_531_0
	.word track_531_1

.align 2
