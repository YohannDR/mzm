.align 2

.global track_457

track_457_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 110
	.byte PAN, c_v
	.byte N02, Cn3, v120
	.byte W02
	.byte VOICE, 7
	.byte N05, Cn3, v100
	.byte W05
	.byte En3, v127 @ N05
	.byte W05
	.byte Dn3, v080 @ N05
	.byte W05
	.byte VOICE, 8
	.byte N10, Cn3, v032
	.byte W10
	.byte VOICE, 6
	.byte N02, Cn3, v020
	.byte W02
	.byte VOICE, 7
	.byte N09, Dn3, v040
	.byte W09
	.byte VOICE, 8
	.byte N12, Cn3, v020
	.byte W36
	.byte FINE

track_457_1:
	.byte KEYSH, 0
	.byte W04
	.byte VOICE, 6
	.byte VOL, 110
	.byte PAN, c_v
	.byte N02, Cn3, v052
	.byte W02
	.byte VOICE, 7
	.byte N05, Cn3, v100
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v080
	.byte W13
	.byte VOICE, 8
	.byte N18, Cn3, v040
	.byte W36
	.byte FINE

track_457_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 33
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gn2, v112
	.byte W12
	.byte N05, Fn2, v100
	.byte W56
	.byte W01
	.byte FINE

.align 2

track_457:
	.byte 3
	.byte 0
	.byte 220
	.byte 0
	.word voice_group10
	.word track_457_0
	.word track_457_1
	.word track_457_2

.align 2
