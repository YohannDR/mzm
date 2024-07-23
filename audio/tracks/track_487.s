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
	.byte TIE
	.byte Cn2, En6
	.byte W02
	.byte BEND, c_v-11
	.byte W02
	.byte Fn4
	.byte W02
	.byte As5
	.byte W02
	.byte As6
	.byte W02
	.byte Gn7
	.byte W02
	.byte Cs8
	.byte W02
	.byte Fn8
	.byte W02
	.byte Gn8
	.byte W04
	.byte Fs8
	.byte W02
	.byte Ds8
	.byte W01
	.byte MOD, 20
	.byte LFOS, 100
	.byte MODT, mod_tre
	.byte W01
track_487_lbl_215b96:
	.byte BEND, c_v+57
	.byte W02
	.byte An7
	.byte W02
	.byte Fn7
	.byte W02
	.byte Bn6
	.byte W02
	.byte Gn6
	.byte W02
	.byte Cs6
	.byte W02
	.byte An5
	.byte W02
	.byte En5
	.byte W02
	.byte Cn5
	.byte W02
	.byte An4
	.byte W02
	.byte Fs4
	.byte W02
	.byte En4
	.byte W02
	.byte Cs4
	.byte W02
	.byte Cn4
	.byte W02
	.byte Bn3
	.byte W02
	.byte As3
	.byte W02
	.byte An3
	.byte W04
	.byte As3
	.byte W02
	.byte Bn3
	.byte W02
	.byte Cs4
	.byte W02
	.byte Ds4
	.byte W02
	.byte Fn4
	.byte W02
	.byte An4
	.byte W02
	.byte Cs5
	.byte W02
	.byte Fn5
	.byte W02
	.byte As5
	.byte W02
	.byte Ds6
	.byte W02
	.byte An6
	.byte W02
	.byte Gn7
	.byte W02
	.byte Cs8
	.byte W02
	.byte Fn8
	.byte W02
	.byte Gn8
	.byte W04
	.byte Fs8
	.byte W02
	.byte Ds8
	.byte W02
	.byte GOTO
		.word track_487_lbl_215b96
	.byte W01
	.byte EOT, Cn2

	.byte FINE

track_487_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 103
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N24
	.byte Fn1, Cn8
	.byte W24
track_487_lbl_215bf2:
	.byte N72
	.byte Fn1, Cn8
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
	.byte N14
	.byte Gn2, Cn8
	.byte W14
track_487_lbl_215c0b:
	.byte N48
	.byte Gn2, Gn8
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
