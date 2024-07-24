.align 2

.global track_4

track_4_0:
	.byte KEYSH, 0
	.byte TEMPO, 77
	.byte VOICE, 24
	.byte VOL, 75
	.byte PAN, c_v+20
	.byte PRIO, 30
	.byte N96
	.byte An3, Gs5
	.byte W96
	.byte Gs3, En6
	.byte W96
	.byte Gn3, En7
	.byte W96
	.byte Fs3, Cn8
	.byte W96
	.byte TIE
	.byte An5, Gs4
	.byte W96
	.byte W92
	.byte W01
	.byte EOT
	.byte W03
	.byte TIE
	.byte An4, En6
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT

	.byte FINE

track_4_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 75
	.byte PAN, c_v+20
	.byte PRIO, 29
	.byte N96
	.byte Fs3, Gs5
	.byte W96
	.byte Fs3, En6
	.byte W96
	.byte W96
	.byte Fs3, Cn8
	.byte W96
	.byte TIE
	.byte Ds5, Gs4
	.byte W96
	.byte W92
	.byte W02
	.byte EOT
	.byte W02
	.byte TIE
	.byte Ds4, En6
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT

	.byte FINE

track_4_2:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 75
	.byte PAN, c_v-22
	.byte PRIO, 28
	.byte N96
	.byte Ds3, Gs5
	.byte W96
	.byte Ds3, En6
	.byte W96
	.byte Ds3, En7
	.byte W96
	.byte Ds3, Cn8
	.byte W96
	.byte TIE
	.byte Fs4, Gs4
	.byte W96
	.byte W92
	.byte W02
	.byte EOT
	.byte W02
	.byte TIE
	.byte Fs3, En6
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT

	.byte FINE

track_4_3:
	.byte KEYSH, 0
	.byte VOICE, 85
	.byte VOL, 75
	.byte PAN, c_v-17
	.byte PRIO, 117
	.byte N84
	.byte Cn2, Gs5
	.byte W96
	.byte Cn2, En6
	.byte W96
	.byte Cn2, En7
	.byte W96
	.byte N84
	.byte W96
	.byte Cn2, Gs4
	.byte W96
	.byte N84
	.byte W96
	.byte N18
	.byte Cn2, En6
	.byte W24
	.byte Cn2, Cn7
	.byte W24
	.byte Cn2, En6
	.byte W24
	.byte N07
	.byte Cn2, En7
	.byte W08
	.byte Cn2, En6
	.byte W08
	.byte Cn2, Gs7
	.byte W08
	.byte N18
	.byte Cn2, En8
	.byte W24
	.byte Cn2, Cn7
	.byte W24
	.byte Cn2, Gs7
	.byte W24
	.byte N07
	.byte W08
	.byte Cn2, Gs5
	.byte W08
	.byte Cn2, Gs6
	.byte W08
	.byte N18
	.byte Cn2, Cn8
	.byte W24
	.byte Cn2, En7
	.byte W24
	.byte Cn2, Cn8
	.byte W24
	.byte N07
	.byte Cn2, Gs7
	.byte W08
	.byte Cn2, Cn7
	.byte W08
	.byte Cn2, En7
	.byte W08
	.byte N18
	.byte Cn2, En8
	.byte W24
	.byte Cn2, Gs7
	.byte W24
	.byte N18
	.byte W24
	.byte N07
	.byte Cn2, En7
	.byte W08
	.byte Cn2, Cn7
	.byte W08
	.byte Cn2, Cn8
	.byte W07

	.byte FINE

track_4_4:
	.byte KEYSH, 0
	.byte VOICE, 26
	.byte VOL, 75
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N08
	.byte Dn3, Gn8
	.byte W24
	.byte N07
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W24
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
track_4_lbl_22cb85:
	.byte N07
	.byte Cn3, Gn8
	.byte W24
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte PEND
track_4_lbl_22cb9c:
	.byte N07
	.byte Cn3, Gn8
	.byte W24
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W24
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte PEND
	.byte PATT
		.word track_4_lbl_22cb85
	.byte PATT
		.word track_4_lbl_22cb9c
	.byte PATT
		.word track_4_lbl_22cb85
	.byte PATT
		.word track_4_lbl_22cb9c
	.byte PATT
		.word track_4_lbl_22cb85
	.byte PATT
		.word track_4_lbl_22cb9c
	.byte N07
	.byte Cn3, Gn8
	.byte W24
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W08
	.byte Cn3
	.byte W08
	.byte Dn3
	.byte W07

	.byte FINE

track_4_5:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 75
	.byte PAN, c_v+15
	.byte PRIO, 119
	.byte N54
	.byte Cn3, Gn8
	.byte W96
	.byte W96
	.byte N54
	.byte W96
	.byte W96
	.byte N54
	.byte W96
	.byte W96
	.byte N54
	.byte W96
	.byte W96
	.byte N48
	.byte W48
	.byte N48
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W24
	.byte N24
	.byte W24

	.byte FINE

track_4_6:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 53
	.byte PAN, c_v
	.byte PRIO, 118
	.byte N08
	.byte Gn5, Gs0
	.byte W16
	.byte Gn5, Cn1
	.byte W08
	.byte Fs5
	.byte W08
	.byte Cn5, En1
	.byte W08
	.byte Fs5
	.byte W08
	.byte Gn5, Gs1
	.byte W08
	.byte Cn5
	.byte W08
	.byte Gn5, Cn2
	.byte W08
	.byte Fs5
	.byte W08
	.byte Cn5
	.byte W08
	.byte Fs5, En2
	.byte W08
	.byte Gn5
	.byte W16
	.byte Gn5, Gs2
	.byte W08
	.byte Fs5, Cn3
	.byte W08
	.byte Cn5
	.byte W08
	.byte Fs5, En3
	.byte W08
	.byte Gn5
	.byte W08
	.byte Cn5, Gs3
	.byte W08
	.byte Gn5
	.byte W08
	.byte Fs5, Cn4
	.byte W08
	.byte Cn5
	.byte W08
	.byte Fs5, En4
	.byte W08
	.byte Gn5
	.byte W16
	.byte Gn5, Gs4
	.byte W08
	.byte Fs5
	.byte W08
	.byte Cn5, Cn5
	.byte W08
	.byte Fs5
	.byte W08
	.byte Gn5, En5
	.byte W08
	.byte Cn5
	.byte W08
	.byte Gn5, Gs5
	.byte W08
	.byte Fs5
	.byte W08
	.byte Cn5, Cn6
	.byte W08
	.byte Fs5
	.byte W08
	.byte Gn5, En6
	.byte W08
	.byte Cn5, Cn7
	.byte W08
	.byte Gn5, Gs6
	.byte W08
	.byte Fs5
	.byte W08
	.byte Cn5, Cn7
	.byte W08
	.byte Fs5
	.byte W08
	.byte Gn5
	.byte W08
	.byte Cn5, En7
	.byte W08
	.byte Gn5
	.byte W08
	.byte Fs5, Gs7
	.byte W08
	.byte Cn5
	.byte W08
	.byte Fs5, Cn8
	.byte W08
track_4_lbl_22cc84:
	.byte N08
	.byte Gn5, En6
	.byte W16
	.byte Gn5, Gs6
	.byte W08
	.byte Fs5
	.byte W08
	.byte Cn5, Cn7
	.byte W08
	.byte Fs5
	.byte W08
	.byte Gn5
	.byte W08
	.byte Cn5, En7
	.byte W08
	.byte Gn5
	.byte W08
	.byte Fs5, Gs7
	.byte W08
	.byte Cn5
	.byte W08
	.byte Fs5, Cn8
	.byte W08
	.byte PEND
	.byte PATT
		.word track_4_lbl_22cc84
	.byte PATT
		.word track_4_lbl_22cc84
	.byte PATT
		.word track_4_lbl_22cc84
	.byte PATT
		.word track_4_lbl_22cc84
	.byte N08
	.byte Gn5, En6
	.byte W16
	.byte Gn5, Gs6
	.byte W08
	.byte Fs5
	.byte W08
	.byte Cn5, Cn7
	.byte W08
	.byte Fs5
	.byte W08
	.byte Gn5
	.byte W08
	.byte Cn5, En7
	.byte W08
	.byte Gn5
	.byte W08
	.byte Fs5, Gs7
	.byte W08
	.byte Cn5
	.byte W08

	.byte FINE

.align 2

track_4:
	.byte 7
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_4_0
	.word track_4_1
	.word track_4_2
	.word track_4_3
	.word track_4_4
	.word track_4_5
	.word track_4_6

.align 2
