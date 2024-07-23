.align 2

.global track_237

track_237_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 56
	.byte PAN, c_v
	.byte N28
	.byte Cn3, Gs4
	.byte W28

	.byte FINE

track_237_1:
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
	.byte MOD, 40
	.byte VOL, 49
	.byte BENDR, 12
	.byte LFOS, 80
	.byte N24
	.byte Ds3, Gs4, DsM2
	.byte W09
	.byte VOL, 21
	.byte BEND, c_v-11
	.byte W09
	.byte VOL, 7
	.byte BEND, c_v-21
	.byte W09

	.byte FINE

.align 2

track_237:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_237_0
	.word track_237_1

.align 2
