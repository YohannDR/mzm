.align 2

.global track_493

track_493_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 11
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N40
	.byte Cn3, Cn8
	.byte W02
	.byte VOL, 15
	.byte W02
	.byte AsM1
	.byte W02
	.byte Gs0
	.byte W02
	.byte Cs2
	.byte W02
	.byte Ds2
	.byte W02
	.byte En2
	.byte W02
	.byte En2
	.byte W02
	.byte Fn2
	.byte W08
	.byte En2
	.byte W01
	.byte En2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Cs2
	.byte W01
	.byte Bn1
	.byte W01
	.byte As1
	.byte W01
	.byte Gs1
	.byte W01
	.byte Fs1
	.byte W01
	.byte Ds1
	.byte W01
	.byte En0
	.byte W01
	.byte GsM1
	.byte W01
	.byte DnM1
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte FsM2
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_493:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group13
	.word track_493_0

.align 2
