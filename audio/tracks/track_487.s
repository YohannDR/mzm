.align 2

.global track_487

track_487_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 86
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-40
	.byte TIE, Cn2, v100
	.byte W02
	.byte BEND, c_v-11
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+30 @ BEND
	.byte W02
	.byte c_v+42 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+57 @ BEND
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+63 @ BEND
	.byte W04
	.byte c_v+62 @ BEND
	.byte W02
	.byte c_v+59 @ BEND
	.byte W01
	.byte MOD, 20
	.byte LFOS, 100
	.byte MODT, mod_tre
	.byte W01
track_487_lbl_215b96:
	.byte BEND, c_v+57
	.byte W02
	.byte c_v+53 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W02
	.byte c_v+43 @ BEND
	.byte W02
	.byte c_v+39 @ BEND
	.byte W02
	.byte c_v+33 @ BEND
	.byte W02
	.byte c_v+29 @ BEND
	.byte W02
	.byte c_v+24 @ BEND
	.byte W02
	.byte c_v+20 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+14 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+8 @ BEND
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+6 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W04
	.byte c_v+6 @ BEND
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+21 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W02
	.byte c_v+30 @ BEND
	.byte W02
	.byte c_v+35 @ BEND
	.byte W02
	.byte c_v+41 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+57 @ BEND
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+63 @ BEND
	.byte W04
	.byte c_v+62 @ BEND
	.byte W02
	.byte c_v+59 @ BEND
	.byte W02
	.byte GOTO
		.word track_487_lbl_215b96
	.byte W01
	.byte EOT, Cn2 @ v100
	.byte FINE

track_487_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 103
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N24, Fn1, v120
	.byte W24
track_487_lbl_215bf2:
	.byte N72, Fn1, v120
	.byte W72
	.byte GOTO
		.word track_487_lbl_215bf2
	.byte FINE

track_487_2:
	.byte KEYSH, 0
	.byte W10
	.byte VOICE, 2
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 127
	.byte N14, Gn2, v120
	.byte W14
track_487_lbl_215c0b:
	.byte N48, Gn2, v127
	.byte W72
	.byte GOTO
		.word track_487_lbl_215c0b
	.byte FINE

.align 2

track_487:
	.byte 3
	.byte 0
	.byte 227
	.byte 0
	.word voice_group13
	.word track_487_0
	.word track_487_1
	.word track_487_2

.align 2
