.align 2

.global track_544

track_544_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 32
	.byte VOL, 46
	.byte PAN, c_v
	.byte N18, Cn3, v080
	.byte W18
	.byte FINE

track_544_1:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 70
	.byte PAN, c_v
	.byte N04, Fn3, v080
	.byte W05
	.byte Dn3 @ N04, v080
	.byte W05
	.byte Bn2 @ N04, v080
	.byte W06
	.byte Bn2, v032 @ N04
	.byte W06
	.byte Bn2, v012 @ N04
	.byte W04
	.byte Gn3, v032 @ N04
	.byte W04
	.byte Fn3, v012 @ N04
	.byte W04
	.byte En3, v008 @ N04
	.byte W04
	.byte FINE

.align 2

track_544:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_544_0
	.word track_544_1

.align 2
