.align 2

.global track_502

track_502_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 18
	.byte PAN, c_v
	.byte N04, Fn4, v080
	.byte W04
	.byte Fn4, v040 @ N04
	.byte W04
	.byte Fn4, v020 @ N04
	.byte W04
	.byte FINE

.align 2

track_502:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_502_0

.align 2
