.align 2

.global track_194

track_194_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 94
	.byte PAN, c_v
	.byte N03
	.byte Dn3, En6
	.byte W03
	.byte VOICE, 20
	.byte N22
	.byte Cn3
	.byte W48
	.byte W01

	.byte FINE

track_194_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 50
	.byte N02
	.byte An2, Gs4
	.byte W02
	.byte VOICE, 2
	.byte N02
	.byte Gn2, En7
	.byte W48
	.byte W02

	.byte FINE

.align 2

track_194:
	.byte 2
	.byte 0
	.byte 201
	.byte 0
	.word voice_group5
	.word track_194_0
	.word track_194_1

.align 2
