.align 2

.global track_324

track_324_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 15
	.byte VOL, 13
	.byte PAN, c_v
	.byte BENDR, 2
	.byte LFOS, 100
	.byte BEND, c_v
	.byte N96
	.byte An2, Cn3
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+3
	.byte W01
	.byte Bn3
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+12
	.byte W01
	.byte Gn5
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v+63
	.byte W02
	.byte VOL, 28
	.byte W02
	.byte En1
	.byte W84
	.byte W02

	.byte FINE

.align 2

track_324:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_324_0

.align 2
