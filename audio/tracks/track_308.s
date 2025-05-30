.align 2

.global track_308

track_308_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 74
	.byte PAN, c_v
	.byte N03, Bn2, v092
	.byte W03
	.byte VOICE, 19
	.byte N06 @ Bn2, v092
	.byte W06
	.byte N21, Cn3, v072
	.byte W48
	.byte W03
	.byte FINE

track_308_1:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte MOD, 80
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 127
	.byte N12, Cn4, v040
	.byte W07
	.byte VOL, 62
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte VOICE, 0
	.byte MOD, 0
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N04, Gn2, v080
	.byte W48
	.byte FINE

.align 2

track_308:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_308_0
	.word track_308_1

.align 2
