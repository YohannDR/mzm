.align 2

.global track_387

track_387_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 10
	.byte VOL, 14
	.byte PAN, c_v
	.byte BENDR, 4
	.byte LFOS, 127
	.byte BEND, c_v
	.byte N96, Fn3, v060
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+3
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+12
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+63
	.byte W02
	.byte VOL, 30
	.byte W02
	.byte 42 @ VOL
	.byte W84
	.byte W02
	.byte FINE

.align 2

track_387:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_387_0

.align 2
