.align 2

.global track_237

track_237_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 56
	.byte PAN, c_v
	.byte N28, Cn3, v080
	.byte W28
	.byte FINE

track_237_1:
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
	.byte MOD, 40
	.byte VOL, 49
	.byte BENDR, 12
	.byte LFOS, 80
	.byte N24, Ds3, v080, 3
	.byte W09
	.byte VOL, 21
	.byte BEND, c_v-11
	.byte W09
	.byte VOL, 7
	.byte BEND, c_v-21
	.byte W09
	.byte FINE

.align 2

track_237:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_237_0
	.word track_237_1

.align 2
