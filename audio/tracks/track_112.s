.align 2

.global track_112

track_112_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 52
	.byte PAN, c_v
	.byte N12, Cn3, v080
	.byte W03
	.byte VOL, 38
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte FINE

.align 2

track_112:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_112_0

.align 2
