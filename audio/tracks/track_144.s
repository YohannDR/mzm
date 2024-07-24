.align 2

.global track_144

track_144_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 78
	.byte PAN, c_v
	.byte N12
	.byte Cn3, Gn8
	.byte W12
	.byte Cn3, En1
	.byte W12
	.byte Cn3, CnM1
	.byte W12

	.byte FINE

.align 2

track_144:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group5
	.word track_144_0

.align 2
