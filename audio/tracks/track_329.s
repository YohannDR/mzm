.align 2

.global track_329

track_329_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 60
	.byte VOL, 35
	.byte PAN, c_v
	.byte LFOS, 70
	.byte W05
	.byte N36, Cn3, v080
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W10
	.byte FINE

.align 2

track_329:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_329_0

.align 2
