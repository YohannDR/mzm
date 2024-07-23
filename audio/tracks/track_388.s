.align 2

.global track_388

track_388_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 10
	.byte VOL, 42
	.byte PAN, c_v
	.byte BENDR, 4
	.byte LFOS, 127
	.byte BEND, c_v+63
	.byte N16
	.byte Fn3, Cn3
	.byte W16

	.byte FINE

.align 2

track_388:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_388_0

.align 2
