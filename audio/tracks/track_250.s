.align 2

.global track_250

track_250_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 95
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gn8
	.byte W02
	.byte VOICE, 12
	.byte N14
	.byte W14
	.byte Cn3, Gs0
	.byte W14
	.byte N18
	.byte Cn3, CnM1
	.byte W19

	.byte FINE

track_250_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 95
	.byte PAN, c_v
	.byte PRIO, 54
	.byte W08
	.byte N05
	.byte Gs2, Gs4
	.byte W05
	.byte N03
	.byte Gs2, En7
	.byte W36

	.byte FINE

.align 2

track_250:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word voice_group5
	.word track_250_0
	.word track_250_1

.align 2
