.align 2

.global track_209

track_209_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 45
	.byte PAN, c_v
	.byte N28
	.byte Cn3, Gs4
	.byte W24
	.byte VOL, 25
	.byte W01
	.byte DsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte FnM2
	.byte W01

	.byte FINE

.align 2

track_209:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_209_0

.align 2
