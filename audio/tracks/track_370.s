.align 2

.global track_370

track_370_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 29
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-8
	.byte N36
	.byte Cn3, Gs4
	.byte W02
	.byte BEND, c_v-7
	.byte W02
	.byte Bn2
	.byte W02
	.byte Cn3
	.byte W02
	.byte Cs3
	.byte W02
	.byte Ds3
	.byte W02
	.byte En3
	.byte W02
	.byte Fn3
	.byte W02
	.byte Gn3
	.byte W02
	.byte Gs3
	.byte W02
	.byte An3
	.byte W02
	.byte Bn3
	.byte W02
	.byte Cn4
	.byte W12

	.byte FINE

.align 2

track_370:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group3
	.word track_370_0

.align 2
