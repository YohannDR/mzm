.align 2

.global track_340

track_340_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 37
	.byte PAN, c_v
	.byte W04
	.byte N04, An2, v127
	.byte W04
	.byte En3, v100 @ N04
	.byte W04
	.byte N15, Cn3 @ v100
	.byte W03
	.byte VOL, 20
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_340:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_340_0

.align 2
