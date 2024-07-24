.align 2

.global track_239

track_239_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 56
	.byte PAN, c_v
	.byte N28
	.byte Cn3, Gs4
	.byte W05
	.byte MOD, 60
	.byte LFOS, 50
	.byte W15
	.byte MOD, 0
	.byte W08

	.byte FINE

track_239_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 35
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte N05
	.byte Fn2, En2
	.byte W01
	.byte BEND, c_v+47
	.byte W01
	.byte Cn6
	.byte W01
	.byte Gs4
	.byte W01
	.byte En3
	.byte W01
	.byte VOICE, 24
	.byte VOL, 56
	.byte BENDR, 8
	.byte LFOS, 80
	.byte BEND, c_v
	.byte N36
	.byte Cn3, Gs4
	.byte W03
	.byte BEND, c_v-4
	.byte W03
	.byte An2
	.byte W03
	.byte Fn2
	.byte W02
	.byte VOL, 56
	.byte W01
	.byte BEND, c_v-14
	.byte W02
	.byte VOL, 41
	.byte W01
	.byte BEND, c_v-18
	.byte W02
	.byte VOL, 31
	.byte W01
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 22
	.byte W01
	.byte BEND, c_v-25
	.byte W02
	.byte VOL, 16
	.byte W01
	.byte BEND, c_v-28
	.byte W02
	.byte VOL, 10
	.byte W01
	.byte BEND, c_v-32
	.byte W02
	.byte VOL, 6
	.byte W03
	.byte DsM2
	.byte W03
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_239:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_239_0
	.word track_239_1

.align 2
