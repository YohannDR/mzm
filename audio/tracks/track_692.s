.align 2

.global track_692

track_692_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 113
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
	.byte VOL, 93
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 87
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 78
	.byte BEND, c_v+18
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 38
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 24
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 14
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 6
	.byte BEND, c_v-2
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v-8
	.byte W32
	.byte W03

	.byte FINE

track_692_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 113
	.byte PAN, c_v
	.byte N12
	.byte Gn2, En6
	.byte W56
	.byte W03

	.byte FINE

.align 2

track_692:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word voice_group13
	.word track_692_0
	.word track_692_1

.align 2
