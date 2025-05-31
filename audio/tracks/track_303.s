.align 2

.global track_303

track_303_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 86
	.byte PAN, c_v
	.byte N03, Cn3, v096
	.byte W03
	.byte VOICE, 20
	.byte N22 @ Cn3, v096
	.byte W56
	.byte W01
	.byte FINE

track_303_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 86
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N02, An4, v080
	.byte W02
	.byte VOICE, 2
	.byte N02, An2, v112
	.byte W56
	.byte W02
	.byte FINE

.align 2

track_303:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_303_0
	.word track_303_1

.align 2
