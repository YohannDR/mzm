.align 2

.global track_475

track_475_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N12
	.byte Cn4, Gs4
	.byte N12
	.byte Ds4
	.byte W14
	.byte Cn4, En2
	.byte N12
	.byte Ds4
	.byte W14
	.byte Cn4, Cn0
	.byte N12
	.byte Ds4
	.byte W12
	.byte VOICE, 6
	.byte N17
	.byte Cn3, En6
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
