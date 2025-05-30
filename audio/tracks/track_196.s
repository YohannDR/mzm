.align 2

.global track_196

track_196_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 86
	.byte PAN, c_v
	.byte N02, Cn3, v120
	.byte W02
	.byte VOICE, 14
	.byte N05, Cn3, v100
	.byte W05
	.byte En3, v127 @ N05
	.byte W05
	.byte Dn3, v080 @ N05
	.byte W05
	.byte VOICE, 12
	.byte N18, Cn3, v032
	.byte W18
	.byte VOICE, 11
	.byte N02, Cn3, v120
	.byte W02
	.byte VOICE, 14
	.byte N13, Dn3, v080
	.byte W13
	.byte VOICE, 12
	.byte N18, Cn3, v040
	.byte W18
	.byte VOICE, 11
	.byte N02, Cn3, v100
	.byte W02
	.byte VOICE, 14
	.byte N13, Dn3 @ v100
	.byte W13
	.byte VOICE, 12
	.byte N18, Cn3, v060
	.byte W13
	.byte W32
	.byte W02
	.byte FINE

track_196_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 11
	.byte VOL, 86
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte VOICE, 14
	.byte N05, Cn3, v100
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v080
	.byte W13
	.byte VOICE, 12
	.byte N18, Cn3, v100
	.byte W18
	.byte VOICE, 11
	.byte VOL, 86
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte VOICE, 14
	.byte N05, Cn3, v100
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v080
	.byte W13
	.byte VOICE, 12
	.byte N18, Cn3, v040
	.byte W02
	.byte W32
	.byte W02
	.byte FINE

track_196_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 33
	.byte N05, An2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W12
	.byte N05, Gn2, v100
	.byte W08
	.byte N04, Fn2 @ v100
	.byte W21
	.byte N05, An2, v080
	.byte W05
	.byte Gs2, v112 @ N05
	.byte W05
	.byte Gn2, v100 @ N05
	.byte W07
	.byte Fn2, v120 @ N05
	.byte W32
	.byte W01
	.byte W32
	.byte W02
	.byte FINE

track_196_3:
	.byte KEYSH, 0
	.byte W03
	.byte VOICE, 23
	.byte VOL, 78
	.byte PAN, c_v
	.byte N22, Cn3, v096
	.byte W19
	.byte VOL, 28
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte N16, Bn2, v100
	.byte W13
	.byte VOL, 28
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte N20, An2, v080
	.byte W17
	.byte VOL, 28
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte N15, Bn2, v072
	.byte W12
	.byte VOL, 28
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W19
	.byte W32
	.byte W02
	.byte FINE

.align 2

track_196:
	.byte 4
	.byte 0
	.byte 228
	.byte 0
	.word voice_group5
	.word track_196_0
	.word track_196_1
	.word track_196_2
	.word track_196_3

.align 2
