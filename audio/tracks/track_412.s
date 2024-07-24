.align 2

.global track_412

track_412_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 44
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N36
	.byte Cn3, En6, CsM2
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-53
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v-19
	.byte W02
	.byte Gn4
	.byte W02
	.byte Bn7
	.byte W03
	.byte Gn7
	.byte W02
	.byte Cs6
	.byte W02
	.byte En4
	.byte W02
	.byte Fn2
	.byte W02
	.byte Cs1
	.byte W02
	.byte An0
	.byte W02
	.byte Ds1
	.byte W02
	.byte Cn2
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte AnM1
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte AsM2
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte DnM2
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01

	.byte FINE

.align 2

track_412:
	.byte 1
	.byte 0
	.byte 228
	.byte 0
	.word voice_group6
	.word track_412_0

.align 2
