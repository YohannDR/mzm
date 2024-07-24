.align 2

.global track_54

track_54_0:
	.byte KEYSH, 0
	.byte TEMPO, 45
	.byte VOICE, 24
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 120
	.byte N22
	.byte Dn3, Gs3
	.byte W24
	.byte N24
	.byte Fn3, Cn1
	.byte W24
	.byte Dn3, Gs3
	.byte W24
	.byte Cn3
	.byte W24
	.byte VOICE, 89
	.byte N36
	.byte An2
	.byte W48
	.byte N40
	.byte W48
	.byte W24
	.byte 0xB6

track_54_1:
	.byte KEYSH, 0
	.byte VOICE, 90
	.byte VOL, 55
	.byte PAN, c_v-10
	.byte PRIO, 119
	.byte N03
	.byte Gn4, Cn4
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte An4, Gs2
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte Fn4, Cn3
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte En4, Cn4
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte Dn4
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte W24
	.byte 0xB6

track_54_2:
	.byte KEYSH, 0
	.byte VOICE, 90
	.byte VOL, 55
	.byte PAN, c_v-34
	.byte PRIO, 119
	.byte W03
	.byte N03
	.byte Cn4, Cn4
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte Cn4, Gs2
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte As3, Cn4
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte An3
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W03
	.byte W03
	.byte En3
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte Fs3
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W03
	.byte W24
	.byte 0xB6

track_54_3:
	.byte KEYSH, 0
	.byte VOICE, 91
	.byte VOL, 78
	.byte PAN, c_v+10
	.byte PRIO, 118
	.byte N22
	.byte Ds2, Cn5
	.byte W24
	.byte N24
	.byte Dn2, Gs3
	.byte W24
	.byte W01
	.byte N23
	.byte Cn2, En4
	.byte W24
	.byte An1, Cn5
	.byte W23
	.byte W01
	.byte N92
	.byte Dn1, Cn5, DsM2
	.byte W92
	.byte W03
	.byte W24
	.byte 0xB6

track_54_4:
	.byte KEYSH, 0
	.byte VOICE, 91
	.byte VOL, 62
	.byte PAN, c_v-10
	.byte PRIO, 30
	.byte W96
	.byte N96
	.byte Dn2, Cn4
	.byte W96
	.byte W24
	.byte 0xB6

track_54_5:
	.byte KEYSH, 0
	.byte VOICE, 92
	.byte VOL, 55
	.byte PAN, c_v+36
	.byte PRIO, 29
	.byte N48
	.byte Cn3, Gs1
	.byte W48
	.byte N24
	.byte As2
	.byte W24
	.byte An2
	.byte W24
	.byte En2
	.byte W24
	.byte N72
	.byte Fs2
	.byte W72
	.byte W24
	.byte 0xB6

.align 2

track_54:
	.byte 6
	.byte 0
	.byte 130
	.byte 128
	.word voice_group20
	.word track_54_0
	.word track_54_1
	.word track_54_2
	.word track_54_3
	.word track_54_4
	.word track_54_5

.align 2
