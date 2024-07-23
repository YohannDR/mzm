.align 2

.global track_173

track_173_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v+16
	.byte N36
	.byte Cn3, En6, DsM2
	.byte W36
	.byte W03

	.byte FINE

.align 2

track_173:
	.byte 1
	.byte 0
	.byte 199
	.byte 0
	.word voice_group7
	.word track_173_0

.align 2
