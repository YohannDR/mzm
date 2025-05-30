.align 2

.global track_527

track_527_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W24
	.byte W02
	.byte VOICE, 14
	.byte VOL, 56
	.byte PAN, c_v
	.byte N07, Fs3, v080
	.byte W11
	.byte N07 @ Fs3, v080
	.byte W11
	.byte N07 @ Fs3, v080
	.byte W07
	.byte FINE

track_527_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 2
	.byte BEND, c_v
	.byte N04, Gn2, v080
	.byte W04
	.byte BEND, c_v+5
	.byte N04, Bn2 @ v080
	.byte W05
	.byte N04 @ Bn2, v080
	.byte W05
	.byte Bn2, v060 @ N04
	.byte W05
	.byte Bn2, v040 @ N04
	.byte W05
	.byte Bn2, v012 @ N04
	.byte W04
	.byte FINE

.align 2

track_527:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_527_0
	.word track_527_1

.align 2
