.align 2

.global track_631

track_631_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 63
	.byte PAN, c_v
	.byte N19
	.byte Cn3, Gs5
	.byte W28
	.byte W01

	.byte FINE

track_631_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N04
	.byte Fn2, En7
	.byte W28
	.byte W01

	.byte FINE

.align 2

track_631:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group5
	.word track_631_0
	.word track_631_1

.align 2
