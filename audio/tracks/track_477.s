.align 2

.global track_477

track_477_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 78
	.byte PAN, c_v
	.byte N03
	.byte An2, Cn6
	.byte W03
	.byte VOICE, 20
	.byte N22
	.byte W44
	.byte W01

	.byte FINE

track_477_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 55
	.byte W02
	.byte VOICE, 2
	.byte N02
	.byte An2, En7
	.byte W44
	.byte W02

	.byte FINE

.align 2

track_477:
	.byte 2
	.byte 0
	.byte 227
	.byte 0
	.word voice_group5
	.word track_477_0
	.word track_477_1

.align 2
