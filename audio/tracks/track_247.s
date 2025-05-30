.align 2

.global track_247

track_247_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 60
	.byte PAN, c_v
	.byte N28, Cn3, v080
	.byte W05
	.byte MOD, 28
	.byte LFOS, 127
	.byte MODT, mod_tre
	.byte W15
	.byte MOD, 0
	.byte W08
	.byte FINE

track_247_1:
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
	.byte BENDR, 12
	.byte N30, Dn3, v092
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W05
	.byte 46 @ VOL
	.byte W01
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 36
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte BEND, c_v-16
	.byte W02
	.byte VOL, 12
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W01
	.byte FINE

.align 2

track_247:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_247_0
	.word track_247_1

.align 2
