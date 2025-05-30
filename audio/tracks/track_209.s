.align 2

.global track_209

track_209_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 45
	.byte PAN, c_v
	.byte N28, Cn3, v080
	.byte W24
	.byte VOL, 25
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte FINE

.align 2

track_209:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_209_0

.align 2
