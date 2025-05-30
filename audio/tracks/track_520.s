.align 2

.global track_520

track_520_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 34
	.byte PAN, c_v
	.byte N02, Fs3, v080
	.byte W02
	.byte Dn3 @ N02, v080
	.byte W02
	.byte An3 @ N02, v080
	.byte W04
	.byte An3, v032 @ N02
	.byte W04
	.byte An3, v012 @ N02
	.byte W02
	.byte FINE

.align 2

track_520:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_520_0

.align 2
