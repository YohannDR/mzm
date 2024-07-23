.align 2

.global track_461

track_461_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 78
	.byte PAN, c_v-20
	.byte BENDR, 16
	.byte BEND, c_v-32
	.byte N32
	.byte Gn3, Cn8, CsM2
	.byte W03
	.byte BEND, c_v-9
	.byte W03
	.byte As3
	.byte W03
	.byte Fn4
	.byte W03
	.byte Gn4
	.byte W03
	.byte Ds4
	.byte W03
	.byte VOL, 57
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 43
	.byte W02
	.byte Gn0
	.byte W02
	.byte AsM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte GsM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_461:
	.byte 1
	.byte 0
	.byte 202
	.byte 0
	.word voice_group10
	.word track_461_0

.align 2
