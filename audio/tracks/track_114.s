.align 2

.global track_114

track_114_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 47
	.byte PAN, c_v
	.byte N10, Cn3, v080
	.byte W01
	.byte VOL, 47
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_114:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_114_0

.align 2
