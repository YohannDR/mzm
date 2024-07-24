.align 2

.global track_17

track_17_0:
	.byte KEYSH, 0
	.byte TEMPO, 42
	.byte VOICE, 71
	.byte VOL, 56
	.byte PAN, c_v
	.byte W96
	.byte W72
	.byte N04
	.byte Cn4, Gn8
	.byte W06
	.byte N08
	.byte Dn4
	.byte W06
	.byte N05
	.byte En4
	.byte W06
	.byte N02
	.byte Fn4
	.byte W06
	.byte N96
	.byte Fs4, En7
	.byte W96
	.byte W72
	.byte N04
	.byte Fs4, Gn8
	.byte W06
	.byte N08
	.byte Fn4
	.byte W06
	.byte N05
	.byte En4
	.byte W06
	.byte N02
	.byte Ds4
	.byte W06
	.byte N72
	.byte Dn4, En7
	.byte W96
	.byte W96
	.byte W48

	.byte FINE

track_17_1:
	.byte KEYSH, 0
	.byte VOICE, 71
	.byte VOL, 31
	.byte PAN, c_v+20
	.byte N96
	.byte Gn2, Gs6
	.byte W96
	.byte N92
	.byte Gs2, Cn6
	.byte W96
	.byte N96
	.byte Fs2, Gs6
	.byte W96
	.byte N96
	.byte W96
	.byte TIE
	.byte Gn1
	.byte W96
	.byte W48
	.byte EOT
	.byte W48
	.byte W48

	.byte FINE

track_17_2:
	.byte KEYSH, 0
	.byte VOICE, 71
	.byte VOL, 31
	.byte PAN, c_v-22
	.byte N96
	.byte Gn4, Gs6
	.byte W96
	.byte N92
	.byte Gs4, Cn6
	.byte W96
	.byte W96
	.byte N96
	.byte Fs4, Gs6
	.byte W96
	.byte TIE
	.byte Gn3
	.byte W96
	.byte W48
	.byte EOT
	.byte W48
	.byte W48

	.byte FINE

track_17_3:
	.byte KEYSH, 0
	.byte VOICE, 72
	.byte VOL, 80
	.byte PAN, c_v
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte N48
	.byte Ds2, Gn8
	.byte N48
	.byte Fs2
	.byte N48
	.byte Cn3
	.byte W24
	.byte W48

	.byte FINE

track_17_4:
	.byte KEYSH, 0
	.byte VOICE, 47
	.byte VOL, 62
	.byte PAN, c_v
	.byte N12
	.byte Cn2, En6
	.byte W12
	.byte As1, Gs4
	.byte W12
	.byte Cn2, En6
	.byte W12
	.byte Gs1, Gs4
	.byte W12
	.byte Cn2, En6
	.byte W12
	.byte As1, Gs4
	.byte W12
	.byte Cn2, En6
	.byte W12
	.byte Gs1, Gs4
	.byte W12
track_17_lbl_22f5ea:
	.byte N12
	.byte Cn2, En6
	.byte W12
	.byte As1, Gs4
	.byte W12
	.byte Cn2, En6
	.byte W12
	.byte Gs1, Gs4
	.byte W12
	.byte Cn2, En6
	.byte W12
	.byte As1, Gs4
	.byte W12
	.byte Cn2, En6
	.byte W12
	.byte Gs1, Gs4
	.byte W12
	.byte PEND
	.byte PATT
		.word track_17_lbl_22f5ea
	.byte PATT
		.word track_17_lbl_22f5ea
	.byte W96
	.byte W96
	.byte W48

	.byte FINE

track_17_5:
	.byte KEYSH, 0
	.byte VOICE, 52
	.byte VOL, 50
	.byte PAN, c_v
	.byte N24
	.byte Cn2, En6
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W48
	.byte Cn2, Cn3
	.byte W48
	.byte Cn2, Cn4
	.byte W48
	.byte Cn2, Gs4
	.byte W48
	.byte Cn2, En6
	.byte W48
	.byte W48

	.byte FINE

.align 2

track_17:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_17_0
	.word track_17_1
	.word track_17_2
	.word track_17_3
	.word track_17_4
	.word track_17_5

.align 2
