.align 2

.global track_262

track_262_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 37
	.byte VOL, 62
	.byte PAN, c_v
	.byte N05, Dn3, v080
	.byte W05
	.byte Dn3, v032 @ N05
	.byte W05
	.byte Dn3, v012 @ N05
	.byte W05
	.byte FINE

.align 2

track_262:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group2
	.word track_262_0

.align 2
