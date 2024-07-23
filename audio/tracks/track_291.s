.align 2

.global track_291

track_291_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 37
	.byte PAN, c_v-4
	.byte W04
	.byte N32
	.byte As3, En1
	.byte W32
	.byte VOICE, 20
	.byte N02
	.byte Bn3
	.byte W02
	.byte Cn4
	.byte W22
	.byte VOICE, 17
	.byte VOL, 28
	.byte N05
	.byte Cn3, GsM1
	.byte W05
	.byte En3, Gs0
	.byte W05
	.byte As3, En1
	.byte W05
	.byte Dn3, En2
	.byte W05
	.byte Gs3, Cn3
	.byte W05
	.byte Fs3
	.byte W05
track_291_lbl_20e698:
	.byte N05
	.byte Cn3, Cn3
	.byte W05
	.byte En3
	.byte W01
	.byte W04
	.byte As3
	.byte W05
	.byte Dn3
	.byte W05
	.byte Gs3
	.byte W05
	.byte Fs3
	.byte W05
	.byte Cn4
	.byte W05
	.byte Dn3
	.byte W05
	.byte As3
	.byte W05
	.byte Fs3
	.byte W05
	.byte Gs3
	.byte W05
	.byte Cn4
	.byte W05
	.byte Cn3
	.byte W05
	.byte En3
	.byte W05
	.byte As3
	.byte W05
	.byte Dn3
	.byte W05
	.byte Gs3
	.byte W05
	.byte Fs3
	.byte W05
	.byte Cn4
	.byte W05
	.byte Gs3
	.byte W05
	.byte As3
	.byte W02
	.byte W03
	.byte Dn3
	.byte W05
	.byte Gs3
	.byte W05
	.byte Cn4
	.byte W05
	.byte Cn3
	.byte W05
	.byte En3
	.byte W05
	.byte As3
	.byte W05
	.byte Dn3
	.byte W05
	.byte Gs3
	.byte W05
	.byte Fs3
	.byte W05
	.byte Cn4
	.byte W05
	.byte Cn3
	.byte W05
	.byte Fs3
	.byte W05
	.byte Gs3
	.byte W05
	.byte En3
	.byte W05
	.byte Cn4
	.byte W05
	.byte GOTO
		.word track_291_lbl_20e698

	.byte FINE

track_291_1:
	.byte KEYSH, 0
	.byte W96
	.byte W92
	.byte W02
	.byte VOICE, 21
	.byte MOD, 2
	.byte VOL, 50
	.byte PAN, c_v
	.byte LFOS, 120
	.byte TIE
	.byte Cn2, Cn3
	.byte W02
	.byte W96
	.byte W60
	.byte W02
	.byte EOT

	.byte FINE

.align 2

track_291:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_291_0
	.word track_291_1

.align 2
