.align 2

.global track_246

track_246_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 29
	.byte VOL, 0
	.byte PAN, c_v
	.byte W07
	.byte N18, Cn3, v052
	.byte W03
	.byte MOD, 60
	.byte VOL, 41
	.byte LFOS, 120
	.byte MODT, mod_tre
	.byte W15
	.byte FINE

track_246_1:
	.byte KEYSH, 0
	.byte VOICE, 29
	.byte VOL, 75
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte VOICE, 24
	.byte VOL, 21
	.byte N07, Cn3, v092
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W03
	.byte N07, Bn2, v052
	.byte W07
	.byte N05, An2, v020
	.byte W05
	.byte FINE

.align 2

track_246:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_246_0
	.word track_246_1

.align 2
