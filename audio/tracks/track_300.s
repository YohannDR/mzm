.align 2

.global track_300

track_300_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 56
	.byte PAN, c_v
	.byte N19
	.byte Cn3, Gs5
	.byte W28
	.byte W01

	.byte FINE

track_300_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N04
	.byte Fn2, En7
	.byte W28
	.byte W01

	.byte FINE

.align 2

track_300:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word voice_group5
	.word track_300_0
	.word track_300_1

.align 2
