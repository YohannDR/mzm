.align 2

.global track_233

track_233_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 56
	.byte PAN, c_v
	.byte N28, Cn3, v080, 1
	.byte W03
	.byte MOD, 25
	.byte LFOS, 110
	.byte MODT, mod_tre
	.byte W21
	.byte MOD, 0
	.byte W05
	.byte FINE

track_233_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 35
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte N05, Fn2, v052
	.byte W01
	.byte BEND, c_v+47
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte VOICE, 24
	.byte VOL, 49
	.byte N09, Bn2, v080
	.byte W09
	.byte An2, v020 @ N09
	.byte W09
	.byte Gn2, v008 @ N09
	.byte W09
	.byte FINE

.align 2

track_233:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_233_0
	.word track_233_1

.align 2
