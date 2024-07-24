.align 2

.global track_497

track_497_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v-63
	.byte N24
	.byte En1, En6, CsM2
	.byte W02
	.byte BEND, c_v-31
	.byte W02
	.byte Gn2
	.byte W02
	.byte Bn3
	.byte W02
	.byte VOL, 77
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 73
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 65
	.byte BEND, c_v+18
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 20
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 5
	.byte BEND, c_v-2
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v-8
	.byte W32
	.byte W03

	.byte FINE

track_497_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 94
	.byte PAN, c_v
	.byte N12
	.byte Gn2, En6
	.byte W56
	.byte W03

	.byte FINE

.align 2

track_497:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word voice_group13
	.word track_497_0
	.word track_497_1

.align 2
