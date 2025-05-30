.align 2

.global track_426

track_426_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte MOD, 0
	.byte VOL, 34
	.byte PAN, c_v
	.byte BENDR, 14
	.byte LFOS, 127
	.byte BEND, c_v-63
	.byte N60, En2, v080
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte 40 @ VOL
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte 49 @ VOL
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 57
	.byte W01
	.byte 69 @ VOL
	.byte BEND, c_v-41
	.byte W02
	.byte c_v-33 @ BEND
	.byte W02
	.byte c_v-26 @ BEND
	.byte W02
	.byte MOD, 40
	.byte BEND, c_v-19
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v+4 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W02
	.byte MOD, 20
	.byte BEND, c_v+26
	.byte W02
	.byte c_v+33 @ BEND
	.byte W02
	.byte c_v+41 @ BEND
	.byte W02
	.byte c_v+48 @ BEND
	.byte W02
	.byte c_v+56 @ BEND
	.byte W02
	.byte c_v+63 @ BEND
	.byte W02
	.byte MOD, 10
	.byte W12
	.byte VOL, 69
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte N15, En2, v020
	.byte W06
	.byte VOL, 25
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_426:
	.byte 1
	.byte 0
	.byte 219
	.byte 0
	.word voice_group9
	.word track_426_0

.align 2
