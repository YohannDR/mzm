.align 2

.global track_655

track_655_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 86
	.byte PAN, c_v-20
	.byte TIE, Dn3, v100
	.byte W96
	.byte W54
	.byte VOL, 86
	.byte W02
	.byte 85 @ VOL
	.byte W06
	.byte 84 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W04
	.byte 82 @ VOL
	.byte W04
	.byte 81 @ VOL
	.byte W02
	.byte 80 @ VOL
	.byte W02
	.byte 78 @ VOL
	.byte W04
	.byte 77 @ VOL
	.byte W02
	.byte 75 @ VOL
	.byte W02
	.byte 73 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte EOT @ Dn3, v100
	.byte FINE

track_655_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 110
	.byte PAN, c_v-20
	.byte TIE, En2, v028
	.byte W96
	.byte W54
	.byte VOL, 86
	.byte W02
	.byte 85 @ VOL
	.byte W06
	.byte 84 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W04
	.byte 82 @ VOL
	.byte W04
	.byte 81 @ VOL
	.byte W02
	.byte 80 @ VOL
	.byte W02
	.byte 78 @ VOL
	.byte W04
	.byte 77 @ VOL
	.byte W02
	.byte 75 @ VOL
	.byte W02
	.byte 73 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte EOT @ En2, v028
	.byte FINE

.align 2

track_655:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group17
	.word track_655_0
	.word track_655_1

.align 2
