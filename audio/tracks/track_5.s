.align 2

.global track_5

track_5_0:
	.byte KEYSH, 0
track_5_lbl_22ccfa:
	.byte TEMPO, 28
	.byte VOICE, 27
	.byte VOL, 47
	.byte PAN, c_v+10
	.byte N12
	.byte Gn1, En7
	.byte W12
	.byte Dn2
	.byte W12
	.byte N36
	.byte W48
	.byte VOICE, 28
	.byte N08
	.byte W08
	.byte En2
	.byte W08
	.byte Dn2
	.byte W08
	.byte N12
	.byte Cn2
	.byte W12
	.byte Dn2
	.byte W12
	.byte As1
	.byte W12
	.byte Cn2
	.byte W12
	.byte N60
	.byte An1
	.byte W48
	.byte W24
	.byte N12
	.byte Gn1
	.byte W12
	.byte Dn2
	.byte W12
	.byte N36
	.byte W48
	.byte N08
	.byte W08
	.byte En2
	.byte W08
	.byte Dn2
	.byte W08
	.byte VOICE, 27
	.byte N12
	.byte Cn2
	.byte W12
	.byte Dn2
	.byte W12
	.byte As1
	.byte W12
	.byte Cn2
	.byte W12
	.byte N60
	.byte Dn2
	.byte W24
	.byte VOICE, 28
	.byte W48
	.byte N84
	.byte Gn1
	.byte W48
	.byte W48
	.byte N84
	.byte W48
	.byte W48
	.byte Gn1, Cn7
	.byte W48
	.byte W72
	.byte GOTO
		.word track_5_lbl_22ccfa

	.byte FINE

track_5_1:
	.byte KEYSH, 0
track_5_lbl_22cd50:
	.byte VOICE, 14
	.byte VOL, 47
	.byte PAN, c_v-10
	.byte N12
	.byte Gn3, En7
	.byte W12
	.byte N48
	.byte Dn4
	.byte W60
	.byte N24
	.byte W24
	.byte N20
	.byte Cn4, Cn4
	.byte W24
	.byte As3
	.byte W24
	.byte N60
	.byte An3, Cn3
	.byte W48
	.byte W24
	.byte N12
	.byte Gn3, En7
	.byte W12
	.byte N48
	.byte Dn4
	.byte W60
	.byte N24
	.byte Dn4, Cn3
	.byte W24
	.byte N20
	.byte Cn4, En1
	.byte W24
	.byte As3, Cn3
	.byte W24
	.byte N60
	.byte Dn4, En2
	.byte W24
	.byte W48
	.byte N84
	.byte Dn3, En7
	.byte W48
	.byte W48
	.byte N84
	.byte W48
	.byte W48
	.byte Dn3, Cn7
	.byte W48
	.byte W72
	.byte GOTO
		.word track_5_lbl_22cd50

	.byte FINE

.align 2

track_5:
	.byte 2
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_5_0
	.word track_5_1

.align 2
