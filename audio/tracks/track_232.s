.align 2

.global track_232

track_232_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte W07
	.byte N18, Cn3, v052
	.byte W03
	.byte VOL, 54
	.byte W15
	.byte FINE

track_232_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 68
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte VOICE, 24
	.byte VOL, 27
	.byte N07, Cn3, v052
	.byte W07
	.byte Bn2, v016 @ N07
	.byte W07
	.byte N05, An2, v008
	.byte W05
	.byte FINE

.align 2

track_232:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_232_0
	.word track_232_1

.align 2
