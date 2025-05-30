.align 2

.global track_493

track_493_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 11
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N40, Cn3, v120
	.byte W02
	.byte VOL, 15
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W08
	.byte 52 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte 6 @ VOL
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_493:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group13
	.word track_493_0

.align 2
