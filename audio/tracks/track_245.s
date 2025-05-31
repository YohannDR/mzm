.align 2

.global track_245

track_245_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 56
	.byte PAN, c_v
	.byte MODT, mod_tre
	.byte N28, Cn3, v080
	.byte W03
	.byte MOD, 30
	.byte LFOS, 100
	.byte W17
	.byte MOD, 0
	.byte W02
	.byte VOL, 55
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W02
	.byte FINE

track_245_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 35
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte N07, Fn2, v052
	.byte W01
	.byte BEND, c_v+52
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte VOICE, 24
	.byte VOL, 14
	.byte N09, Bn2, v080
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W06
	.byte N09, An2, v032
	.byte W09
	.byte Gn2, v012 @ N09
	.byte W09
	.byte FINE

.align 2

track_245:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_245_0
	.word track_245_1

.align 2
