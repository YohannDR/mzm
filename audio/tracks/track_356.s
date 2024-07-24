.align 2

.global track_356

track_356_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte MOD, 30
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 2
	.byte LFOS, 100
	.byte BEND, c_v-63
	.byte W04
	.byte N09
	.byte Fn2, Gs3
	.byte W02
	.byte BEND, c_v-47
	.byte W02
	.byte An0
	.byte W02
	.byte Cn2
	.byte W02
	.byte En3
	.byte W01
	.byte N04
	.byte Gn2, Cn2
	.byte W04
	.byte N03
	.byte Fn2, En0
	.byte W03

	.byte FINE

.align 2

track_356:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_356_0

.align 2
