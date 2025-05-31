.align 2

.global track_343

track_343_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte N21, Fn2, v080
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 43
	.byte W04
	.byte 41 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_343:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_343_0

.align 2
