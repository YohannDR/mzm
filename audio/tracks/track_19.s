.align 2

.global track_19

track_19_0:
	.byte KEYSH, 0
	.byte TEMPO, 69
	.byte W12
	.byte VOICE, 75
	.byte VOL, 94
	.byte PAN, c_v
	.byte TIE
	.byte Gn2, Gs5
	.byte W84
	.byte W96
	.byte W36
	.byte EOT
	.byte W60
	.byte W24

	.byte FINE

track_19_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 94
	.byte PAN, c_v
	.byte TIE
	.byte Gn1, En7
	.byte W72
	.byte VOICE, 28
	.byte W24
	.byte W96
	.byte EOT
	.byte W96
	.byte W24

	.byte FINE

track_19_2:
	.byte KEYSH, 0
	.byte VOICE, 71
	.byte VOL, 70
	.byte PAN, c_v+20
	.byte N48
	.byte Gn4, Gs4
	.byte W48
	.byte PAN, c_v-22
	.byte N48
	.byte Ds4, Gs5
	.byte W48
	.byte PAN, c_v+20
	.byte N48
	.byte Cn4, Gs6
	.byte W48
	.byte PAN, c_v-22
	.byte N48
	.byte As4, Gs7
	.byte W48
	.byte PAN, c_v+20
	.byte N48
	.byte Gs4, Gn8
	.byte W96
	.byte W24

	.byte FINE

track_19_3:
	.byte KEYSH, 0
	.byte VOICE, 71
	.byte VOL, 94
	.byte PAN, c_v+20
	.byte N06
	.byte Cn4, En7
	.byte W12
	.byte Ds4
	.byte W12
	.byte Dn4, Gs7
	.byte W12
	.byte Fn4, Cn8
	.byte W12
	.byte Ds4, En8
	.byte W12
	.byte Gs4
	.byte W12
	.byte Gn4, Gn8
	.byte W12
	.byte Dn4
	.byte W12
track_19_lbl_22f8c5:
	.byte N06
	.byte Cn4, En7
	.byte W12
	.byte Ds4
	.byte W12
	.byte Dn4, Gs7
	.byte W12
	.byte Fn4, Cn8
	.byte W12
	.byte Ds4, En8
	.byte W12
	.byte Gs4
	.byte W12
	.byte Gn4, Gn8
	.byte W12
	.byte Dn4
	.byte W12
	.byte PEND
	.byte PATT
		.word track_19_lbl_22f8c5
	.byte W24

	.byte FINE

track_19_4:
	.byte KEYSH, 0
	.byte VOICE, 52
	.byte VOL, 39
	.byte PAN, c_v-22
	.byte N12
	.byte Cn2, En3
	.byte W24
	.byte Cn2, Gs3
	.byte W24
	.byte Cn2, Cn4
	.byte W24
	.byte Cn2, Gs4
	.byte W24
	.byte Cn2, Cn5
	.byte W24
	.byte Cn2, Gs5
	.byte W24
	.byte PAN, c_v+20
	.byte N12
	.byte Cn2, Cn6
	.byte W24
	.byte Cn2, En6
	.byte W24
	.byte Cn2, Cn7
	.byte W96
	.byte W24

	.byte FINE

.align 2

track_19:
	.byte 5
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_19_0
	.word track_19_1
	.word track_19_2
	.word track_19_3
	.word track_19_4

.align 2
