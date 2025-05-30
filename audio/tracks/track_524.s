.align 2

.global track_524

track_524_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 31
	.byte PAN, c_v
	.byte N02, Gs3, v080
	.byte W02
	.byte En3 @ N02, v080
	.byte W02
	.byte Fs3 @ N02, v080
	.byte W02
	.byte As3 @ N02, v080
	.byte W02
	.byte Cn4 @ N02, v080
	.byte W04
	.byte Cn4, v032 @ N02
	.byte W04
	.byte N02 @ Cn4, v032
	.byte W04
	.byte N02 @ Cn4, v032
	.byte W04
	.byte Cn4, v012 @ N02
	.byte W02
	.byte FINE

.align 2

track_524:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_524_0

.align 2
