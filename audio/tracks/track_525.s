.align 2

.global track_525

track_525_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 31
	.byte PAN, c_v
	.byte W03
	.byte N19, Cn3, v080
	.byte W54
	.byte FINE

track_525_1:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 47
	.byte PAN, c_v
	.byte W03
	.byte N19, Fn2, v100
	.byte W54
	.byte FINE

track_525_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 31
	.byte PAN, c_v
	.byte N02, Gn3, v080
	.byte W02
	.byte Ds3 @ N02, v080
	.byte W02
	.byte Cn3 @ N02, v080
	.byte W02
	.byte Cn3, v032 @ N02
	.byte W04
	.byte Cn3, v012 @ N02
	.byte W44
	.byte W03
	.byte FINE

.align 2

track_525:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_525_0
	.word track_525_1
	.word track_525_2

.align 2
