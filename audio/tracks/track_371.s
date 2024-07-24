.align 2

.global track_371

track_371_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 50
	.byte PAN, c_v
	.byte N04
	.byte Cn3, Gs5
	.byte W04
	.byte VOICE, 33
	.byte BENDR, 4
	.byte BEND, c_v-32
	.byte N18
	.byte Fn2
	.byte W02
	.byte BEND, c_v-29
	.byte W02
	.byte Ds1
	.byte W02
	.byte Gn1
	.byte W02
	.byte Bn1
	.byte W02
	.byte Dn2
	.byte W02
	.byte Fs2
	.byte W02
	.byte VOL, 50
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte BnM2
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v
	.byte W01
	.byte VOL, 0
	.byte W24
	.byte W02

	.byte FINE

track_371_1:
	.byte KEYSH, 0
	.byte VOICE, 35
	.byte VOL, 75
	.byte PAN, c_v
	.byte W04
	.byte N04
	.byte An4, Cn8
	.byte W44

	.byte FINE

.align 2

track_371:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_371_0
	.word track_371_1

.align 2
