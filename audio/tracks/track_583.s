.align 2

.global track_583

track_583_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte MOD, 30
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 60
	.byte MODT, mod_tre
	.byte BEND, c_v+63
	.byte TIE, Cn3, v080
	.byte W02
	.byte VOL, 70
	.byte W08
	.byte 69 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W04
	.byte 66 @ VOL
	.byte W06
	.byte 66 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W04
	.byte 60 @ VOL
	.byte W04
	.byte 59 @ VOL
	.byte W04
	.byte 57 @ VOL
	.byte W04
	.byte 55 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte EOT @ Cn3, v080
	.byte FINE

track_583_1:
	.byte KEYSH, 0
	.byte VOICE, 34
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+63
	.byte TIE, Cn2, v080
	.byte W02
	.byte VOL, 70
	.byte W08
	.byte 69 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W04
	.byte 66 @ VOL
	.byte W06
	.byte 66 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W04
	.byte 60 @ VOL
	.byte W04
	.byte 59 @ VOL
	.byte W04
	.byte 57 @ VOL
	.byte W04
	.byte 55 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte EOT @ Cn2, v080
	.byte FINE

.align 2

track_583:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_583_0
	.word track_583_1

.align 2
