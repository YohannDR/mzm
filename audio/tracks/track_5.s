.align 2

.global track_5

track_5_0:
	.byte KEYSH, 0
track_5_lbl_22ccfa:
	.byte TEMPO, 28
	.byte VOICE, 27
	.byte VOL, 47
	.byte PAN, c_v+10
	.byte N12, Gn1, v112
	.byte W12
	.byte Dn2 @ N12, v112
	.byte W12
	.byte N36 @ Dn2, v112
	.byte W48
	.byte VOICE, 28
	.byte N08 @ Dn2, v112
	.byte W08
	.byte En2 @ N08, v112
	.byte W08
	.byte Dn2 @ N08, v112
	.byte W08
	.byte N12, Cn2 @ v112
	.byte W12
	.byte Dn2 @ N12, v112
	.byte W12
	.byte As1 @ N12, v112
	.byte W12
	.byte Cn2 @ N12, v112
	.byte W12
	.byte N60, An1 @ v112
	.byte W48
	.byte W24
	.byte N12, Gn1 @ v112
	.byte W12
	.byte Dn2 @ N12, v112
	.byte W12
	.byte N36 @ Dn2, v112
	.byte W48
	.byte N08 @ Dn2, v112
	.byte W08
	.byte En2 @ N08, v112
	.byte W08
	.byte Dn2 @ N08, v112
	.byte W08
	.byte VOICE, 27
	.byte N12, Cn2 @ v112
	.byte W12
	.byte Dn2 @ N12, v112
	.byte W12
	.byte As1 @ N12, v112
	.byte W12
	.byte Cn2 @ N12, v112
	.byte W12
	.byte N60, Dn2 @ v112
	.byte W24
	.byte VOICE, 28
	.byte W48
	.byte N84, Gn1 @ v112
	.byte W48
	.byte W48
	.byte N84 @ Gn1, v112
	.byte W48
	.byte W48
	.byte Gn1, v108 @ N84
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
	.byte N12, Gn3, v112
	.byte W12
	.byte N48, Dn4 @ v112
	.byte W60
	.byte N24 @ Dn4, v112
	.byte W24
	.byte N20, Cn4, v072
	.byte W24
	.byte As3 @ N20, v072
	.byte W24
	.byte N60, An3, v060
	.byte W48
	.byte W24
	.byte N12, Gn3, v112
	.byte W12
	.byte N48, Dn4 @ v112
	.byte W60
	.byte N24, Dn4, v060
	.byte W24
	.byte N20, Cn4, v040
	.byte W24
	.byte As3, v060 @ N20
	.byte W24
	.byte N60, Dn4, v052
	.byte W24
	.byte W48
	.byte N84, Dn3, v112
	.byte W48
	.byte W48
	.byte N84 @ Dn3, v112
	.byte W48
	.byte W48
	.byte Dn3, v108 @ N84
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
