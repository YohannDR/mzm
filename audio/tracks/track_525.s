.align 2

.global track_525

track_525_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 31
	.byte PAN, c_v
	.byte W03
	.byte N19
	.byte Cn3, Gs4
	.byte W54

	.byte FINE

track_525_1:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 47
	.byte PAN, c_v
	.byte W03
	.byte N19
	.byte Fn2, En6
	.byte W54

	.byte FINE

track_525_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 31
	.byte PAN, c_v
	.byte N02
	.byte Gn3, Gs4
	.byte W02
	.byte Ds3
	.byte W02
	.byte Cn3
	.byte W02
	.byte Cn3, Gs0
	.byte W04
	.byte Cn3, CnM1
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
