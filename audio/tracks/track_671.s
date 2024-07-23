.align 2

.global track_671

track_671_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v+6
	.byte W02
	.byte N32
	.byte Bn2, Gs4
	.byte W32

	.byte FINE

track_671_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N36
	.byte Bn2, En6
	.byte W36

	.byte FINE

.align 2

track_671:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_671_0
	.word track_671_1

.align 2
