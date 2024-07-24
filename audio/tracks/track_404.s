.align 2

.global track_404

track_404_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 30
	.byte VOL, 63
	.byte PAN, c_v
	.byte BENDR, 9
	.byte LFOS, 40
	.byte BEND, c_v+8
	.byte N42
	.byte Cn3, En6
	.byte W02
	.byte BEND, c_v+4
	.byte W02
	.byte En3
	.byte W02
	.byte Cn3
	.byte W02
	.byte Gs2
	.byte W02
	.byte En2
	.byte W02
	.byte Cn2
	.byte W02
	.byte Gs1
	.byte W02
	.byte En1
	.byte W02
	.byte Cn1
	.byte W02
	.byte Gs0
	.byte W02
	.byte En0
	.byte W02
	.byte Cn0
	.byte W02
	.byte GsM1
	.byte W02
	.byte EnM1
	.byte W02
	.byte CnM1
	.byte W02
	.byte GsM2
	.byte W02
	.byte EnM2
	.byte W02
	.byte CsM2
	.byte W06

	.byte FINE

track_404_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte MOD, 30
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 6
	.byte LFOS, 120
	.byte BEND, c_v+8
	.byte N24
	.byte Fn2, En6
	.byte W02
	.byte BEND, c_v+4
	.byte W02
	.byte En3
	.byte W02
	.byte Cn3
	.byte W02
	.byte Gs2
	.byte W02
	.byte En2
	.byte W02
	.byte Cn2
	.byte W02
	.byte Gs1
	.byte W02
	.byte En1
	.byte W02
	.byte Cn1
	.byte W02
	.byte Gs0
	.byte W02
	.byte En0
	.byte W02
	.byte Cn0
	.byte N18
	.byte W02
	.byte BEND, c_v-44
	.byte W02
	.byte EnM1
	.byte W02
	.byte CnM1
	.byte W02
	.byte GsM2
	.byte W02
	.byte EnM2
	.byte W02
	.byte CsM2
	.byte W06

	.byte FINE

.align 2

track_404:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group6
	.word track_404_0
	.word track_404_1

.align 2
