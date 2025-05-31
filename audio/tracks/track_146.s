.align 2

.global track_146

track_146_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 0
	.byte PAN, c_v
	.byte N16, Cn3, v080
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_146:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_146_0

.align 2
