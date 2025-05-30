.align 2

.global track_194

track_194_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 94
	.byte PAN, c_v
	.byte N03, Dn3, v100
	.byte W03
	.byte VOICE, 20
	.byte N22, Cn3 @ v100
	.byte W48
	.byte W01
	.byte FINE

track_194_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 50
	.byte N02, An2, v080
	.byte W02
	.byte VOICE, 2
	.byte N02, Gn2, v112
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
