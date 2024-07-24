.align 2

.global track_688

track_688_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte N15
	.byte Cn3, Gn8
	.byte W15
	.byte N24
	.byte An2, Gn8, DnM2
	.byte W24
	.byte W02
	.byte N15
	.byte Cn3, Gs4
	.byte W15
	.byte N24
	.byte An2, Gs4, DnM2
	.byte W40
	.byte W12

	.byte FINE

track_688_1:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte N15
	.byte Cn3, Gn8
	.byte W15
	.byte N24
	.byte An2, Gn8, CsM2
	.byte W24
	.byte W01
	.byte N15
	.byte An2, Gs4
	.byte W15
	.byte N24
	.byte Fn2, Gs4, CsM2
	.byte W32
	.byte W03
	.byte W12

	.byte FINE

track_688_2:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte N02
	.byte Cn3, Gn8
	.byte W02
	.byte VOICE, 20
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, En2
	.byte W13
	.byte VOICE, 19
	.byte VOL, 80
	.byte W02
	.byte VOICE, 20
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, En2
	.byte W13
	.byte VOICE, 21
	.byte N18
	.byte Cn3, GsM1
	.byte W28
	.byte W12

	.byte FINE

track_688_3:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte PRIO, 25
	.byte N02
	.byte An4, Gs4
	.byte W02
	.byte VOICE, 17
	.byte N02
	.byte An2, En7
	.byte W13
	.byte VOICE, 18
	.byte N02
	.byte Gn2, Gs4
	.byte W02
	.byte VOICE, 17
	.byte N09
	.byte Gn2, Cn8
	.byte W09
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte PRIO, 25
	.byte W02
	.byte VOICE, 17
	.byte N02
	.byte An2, En7
	.byte W13
	.byte VOICE, 18
	.byte N02
	.byte Gn2, Gs4
	.byte W02
	.byte VOICE, 17
	.byte N09
	.byte Gn2, Cn8
	.byte W52
	.byte W01
	.byte W12

	.byte FINE

.align 2

track_688:
	.byte 4
	.byte 0
	.byte 251
	.byte 0
	.word voice_group13
	.word track_688_0
	.word track_688_1
	.word track_688_2
	.word track_688_3

.align 2
