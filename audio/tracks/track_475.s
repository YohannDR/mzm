.align 2

.global track_475

track_475_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N12, Cn4, v080
	.byte N12, Ds4 @ v080
	.byte W14
	.byte Cn4, v052 @ N12
	.byte N12, Ds4 @ v052
	.byte W14
	.byte Cn4, v024 @ N12
	.byte N12, Ds4 @ v024
	.byte W12
	.byte VOICE, 6
	.byte N17, Cn3, v100
	.byte W17
	.byte FINE

.align 2

track_475:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group12
	.word track_475_0

.align 2
