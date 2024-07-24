.align 2

.global track_410

track_410_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 47
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N36
	.byte Dn3, En6, CsM2
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-53
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 58
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 64
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v-19
	.byte W01
	.byte Bn2
	.byte W01
	.byte Gn4
	.byte W01
	.byte Cs7
	.byte W01
	.byte Bn7
	.byte W01
	.byte Cs8
	.byte W02
	.byte Gn7
	.byte W01
	.byte Bn6
	.byte W01
	.byte Cs6
	.byte W01
	.byte Ds5
	.byte W01
	.byte En4
	.byte W01
	.byte Fn3
	.byte W01
	.byte Fn2
	.byte W01
	.byte Gn1
	.byte W01
	.byte Cs1
	.byte W01
	.byte Bn0
	.byte W01
	.byte An0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Ds1
	.byte W01
	.byte Bn1
	.byte W01
	.byte Fn2
	.byte W01
	.byte Cn3
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01

	.byte FINE

.align 2

track_410:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group6
	.word track_410_0

.align 2
