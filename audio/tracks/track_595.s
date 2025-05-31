.align 2

.global track_595

track_595_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte PAN, c_v
	.byte W72
	.byte VOICE, 12
	.byte VOL, 110
	.byte BENDR, 6
	.byte BEND, c_v-63
	.byte TIE, Cn2, v127
	.byte W03
	.byte BEND, c_v-62
	.byte W01
	.byte c_v-61 @ BEND
	.byte W03
	.byte c_v-60 @ BEND
	.byte W01
	.byte c_v-59 @ BEND
	.byte W02
	.byte c_v-58 @ BEND
	.byte W01
	.byte c_v-57 @ BEND
	.byte W03
	.byte c_v-56 @ BEND
	.byte W01
	.byte c_v-55 @ BEND
	.byte W02
	.byte c_v-54 @ BEND
	.byte W01
	.byte c_v-53 @ BEND
	.byte W02
	.byte c_v-52 @ BEND
	.byte W01
	.byte c_v-51 @ BEND
	.byte W02
	.byte c_v-50 @ BEND
	.byte W01
	.byte c_v-49 @ BEND
	.byte W02
	.byte c_v-48 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W02
	.byte c_v-46 @ BEND
	.byte W01
	.byte c_v-45 @ BEND
	.byte W01
	.byte c_v-44 @ BEND
	.byte W01
	.byte c_v-43 @ BEND
	.byte W02
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-39 @ BEND
	.byte W02
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-18 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W18
	.byte c_v-15 @ BEND
	.byte W03
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W14
	.byte c_v-18 @ BEND
	.byte W02
	.byte c_v-19 @ BEND
	.byte W13
	.byte c_v-18 @ BEND
	.byte W02
	.byte c_v-17 @ BEND
	.byte W04
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W09
	.byte W03
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W09
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W11
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W09
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W02
	.byte c_v-14 @ BEND
	.byte W07
	.byte c_v-15 @ BEND
	.byte W09
	.byte EOT @ Cn2, v127
	.byte FINE

track_595_1:
	.byte KEYSH, 0
	.byte W44
	.byte W02
	.byte VOICE, 33
	.byte VOL, 86
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v
	.byte N60, Bn2, v127
	.byte W36
	.byte W02
	.byte VOL, 85
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_595_2:
	.byte KEYSH, 0
	.byte W22
	.byte VOICE, 35
	.byte VOL, 77
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 36
	.byte N07 @ Cn3, v127
	.byte W07
	.byte Cn3, v052 @ N07
	.byte W07
	.byte Cn3, v012 @ N07
	.byte W03
	.byte VOICE, 34
	.byte VOL, 60
	.byte N05, Cn4, v080
	.byte W05
	.byte As4 @ N05, v080
	.byte W05
	.byte Gs4 @ N05, v080
	.byte W07
	.byte Gs4, v040 @ N05
	.byte W07
	.byte N05 @ Gs4, v040
	.byte W07
	.byte Gs4, v020 @ N05
	.byte W07
	.byte N05 @ Gs4, v020
	.byte W05
	.byte FINE

.align 2

track_595:
	.byte 3
	.byte 0
	.byte 252
	.byte 0
	.word voice_group17
	.word track_595_0
	.word track_595_1
	.word track_595_2

.align 2
