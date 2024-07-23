.align 2

.global track_114

track_114_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 47
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 47
	.byte W01
	.byte Fn1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fn0
	.byte W01
	.byte BnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_114:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_114_0

.align 2
