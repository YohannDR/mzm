.align 2

.global track_244

track_244_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 0
	.byte PAN, c_v
	.byte W07
	.byte N18, Cs3, v060
	.byte W03
	.byte VOL, 13
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W11
	.byte FINE

track_244_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 68
	.byte PAN, c_v
	.byte N11, Cn3, v080
	.byte W11
	.byte VOICE, 24
	.byte MOD, 20
	.byte LFOS, 40
	.byte VOL, 37
	.byte N07, Cn3, v072
	.byte W07
	.byte Bn2, v028 @ N07
	.byte W07
	.byte N05, An2, v012
	.byte W05
	.byte FINE

.align 2

track_244:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_244_0
	.word track_244_1

.align 2
