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
	.byte N32, Fs0, v120
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
	.byte N08, Gn2, v100
	.byte W08
	.byte Dn2 @ N08, v100
	.byte W08
	.byte Gn2, v080 @ N08
	.byte W08
	.byte Dn2, v060 @ N08
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
