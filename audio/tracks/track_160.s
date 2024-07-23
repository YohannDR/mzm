.align 2

.global track_160

track_160_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 50
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Gs4
	.byte W03
	.byte VOICE, 35
	.byte N13
	.byte W13
	.byte Cn3, Gs0
	.byte W13

	.byte FINE

track_160_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 12
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v+63
	.byte N16
	.byte En3, En2
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+38
	.byte W01
	.byte An5
	.byte W01
	.byte Cs5
	.byte W01
	.byte Fn4
	.byte W01
	.byte Gs3
	.byte W01
	.byte Cn3
	.byte W01
	.byte Ds2
	.byte W01
	.byte Gn1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Dn0
	.byte W01
	.byte FsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte CsM2
	.byte W01

	.byte FINE

.align 2

track_160:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_160_0
	.word track_160_1

.align 2
