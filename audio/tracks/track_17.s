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
	.byte N04, Cn4, v127
	.byte W06
	.byte N08, Dn4 @ v127
	.byte W06
	.byte N05, En4 @ v127
	.byte W06
	.byte N02, Fn4 @ v127
	.byte W06
	.byte N96, Fs4, v112
	.byte W96
	.byte W72
	.byte N04, Fs4, v127
	.byte W06
	.byte N08, Fn4 @ v127
	.byte W06
	.byte N05, En4 @ v127
	.byte W06
	.byte N02, Ds4 @ v127
	.byte W06
	.byte N72, Dn4, v112
	.byte W96
	.byte W96
	.byte W48
	.byte FINE

track_17_1:
	.byte KEYSH, 0
	.byte VOICE, 71
	.byte VOL, 31
	.byte PAN, c_v+20
	.byte N96, Gn2, v104
	.byte W96
	.byte N92, Gs2, v096
	.byte W96
	.byte N96, Fs2, v104
	.byte W96
	.byte N96 @ Fs2, v104
	.byte W96
	.byte TIE, Gn1 @ v104
	.byte W96
	.byte W48
	.byte EOT @ Gn1, v104
	.byte W48
	.byte W48
	.byte FINE

track_17_2:
	.byte KEYSH, 0
	.byte VOICE, 71
	.byte VOL, 31
	.byte PAN, c_v-22
	.byte N96, Gn4, v104
	.byte W96
	.byte N92, Gs4, v096
	.byte W96
	.byte W96
	.byte N96, Fs4, v104
	.byte W96
	.byte TIE, Gn3 @ v104
	.byte W96
	.byte W48
	.byte EOT @ Gn3, v104
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
	.byte N48, Ds2, v127
	.byte N48, Fs2 @ v127
	.byte N48, Cn3 @ v127
	.byte W24
	.byte W48
	.byte FINE

track_17_4:
	.byte KEYSH, 0
	.byte VOICE, 47
	.byte VOL, 62
	.byte PAN, c_v
	.byte N12, Cn2, v100
	.byte W12
	.byte As1, v080 @ N12
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte Gs1, v080 @ N12
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte As1, v080 @ N12
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte Gs1, v080 @ N12
	.byte W12
track_17_lbl_22f5ea:
	.byte N12, Cn2, v100
	.byte W12
	.byte As1, v080 @ N12
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte Gs1, v080 @ N12
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte As1, v080 @ N12
	.byte W12
	.byte Cn2, v100 @ N12
	.byte W12
	.byte Gs1, v080 @ N12
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
	.byte N24, Cn2, v100
	.byte W48
	.byte N24 @ Cn2, v100
	.byte W48
	.byte N24 @ Cn2, v100
	.byte W48
	.byte N24 @ Cn2, v100
	.byte W48
	.byte N24 @ Cn2, v100
	.byte W48
	.byte N24 @ Cn2, v100
	.byte W48
	.byte N24 @ Cn2, v100
	.byte W48
	.byte N24 @ Cn2, v100
	.byte W48
	.byte Cn2, v060 @ N24
	.byte W48
	.byte Cn2, v072 @ N24
	.byte W48
	.byte Cn2, v080 @ N24
	.byte W48
	.byte Cn2, v100 @ N24
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
