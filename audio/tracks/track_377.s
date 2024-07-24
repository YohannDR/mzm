.align 2

.global track_377

track_377_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 38
	.byte VOL, 12
	.byte PAN, c_v
	.byte BENDR, 4
	.byte LFOS, 100
	.byte BEND, c_v
	.byte N96
	.byte Cn3, Cn3
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+3
	.byte W01
	.byte Bn3
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+12
	.byte W01
	.byte Gn5
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+63
	.byte W02
	.byte VOL, 27
	.byte W02
	.byte Cs1
	.byte W84
	.byte W02

	.byte FINE

.align 2

track_377:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_377_0

.align 2
