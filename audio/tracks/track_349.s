.align 2

.global track_349

track_349_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 44
	.byte PAN, c_v
	.byte W04
	.byte N04
	.byte En2, Gs4
	.byte W04
	.byte N05
	.byte Bn2, Gs2
	.byte W05
	.byte N08
	.byte Cs2
	.byte W08
	.byte N07
	.byte En2
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte DsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_349:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_349_0

.align 2
