.align 2

.global track_117

track_117_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 52
	.byte PAN, c_v
	.byte N40, Cn3, v080, 1
	.byte W24
	.byte VOL, 41
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_117:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_117_0

.align 2
