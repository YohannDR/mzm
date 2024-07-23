.align 2

.global track_458

track_458_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 110
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Cn8
	.byte W02
	.byte VOICE, 7
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte En3, Gn8
	.byte W05
	.byte Dn3, Gs4
	.byte W05
	.byte VOICE, 8
	.byte N18
	.byte Cn3, Gs0
	.byte W18
	.byte VOICE, 6
	.byte N02
	.byte Cn3, En1
	.byte W02
	.byte VOICE, 7
	.byte N13
	.byte Dn3
	.byte W13
	.byte VOICE, 8
	.byte N18
	.byte Cn3, GsM1
	.byte W36
	.byte W01

	.byte FINE

track_458_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 6
	.byte VOL, 110
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gs4
	.byte W02
	.byte VOICE, 7
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, Gs4
	.byte W13
	.byte VOICE, 8
	.byte N18
	.byte Cn3, En1
	.byte W44
	.byte W01

	.byte FINE

track_458_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 33
	.byte N05
	.byte An2, Gs4
	.byte W05
	.byte N10
	.byte Gs2, En7
	.byte W12
	.byte N05
	.byte Gn2, En6
	.byte W08
	.byte N04
	.byte Fn2
	.byte W60
	.byte W02

	.byte FINE

.align 2

track_458:
	.byte 3
	.byte 0
	.byte 220
	.byte 0
	.word voice_group10
	.word track_458_0
	.word track_458_1
	.word track_458_2

.align 2
