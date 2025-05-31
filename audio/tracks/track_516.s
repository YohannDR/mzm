.align 2

.global track_516

track_516_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 44
	.byte PAN, c_v
	.byte N02, En4, v060
	.byte W03
	.byte Fn4, v080 @ N02
	.byte W02
	.byte FINE

.align 2

track_516:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_516_0

.align 2
