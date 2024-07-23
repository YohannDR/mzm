.align 2

.global track_400

track_400_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 40
	.byte VOL, 78
	.byte PAN, c_v
	.byte LFOS, 80
	.byte N32
	.byte Fs0, Cn8
	.byte W32

	.byte FINE

track_400_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte MOD, 20
	.byte VOL, 78
	.byte PAN, c_v
	.byte LFOS, 10
	.byte PRIO, 23
	.byte N08
	.byte Gn2, En6
	.byte W08
	.byte Dn2
	.byte W08
	.byte Gn2, Gs4
	.byte W08
	.byte Dn2, Cn3
	.byte W08

	.byte FINE

.align 2

track_400:
	.byte 2
	.byte 0
	.byte 226
	.byte 0
	.word voice_group6
	.word track_400_0
	.word track_400_1

.align 2
