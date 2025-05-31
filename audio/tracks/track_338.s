.align 2

.global track_338

track_338_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 12
	.byte N20, Fn1, v112
	.byte W07
	.byte VOL, 27
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W14
	.byte FINE

track_338_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 47
	.byte PAN, c_v
	.byte N04, An2, v120
	.byte W32
	.byte W01
	.byte FINE

.align 2

track_338:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_338_0
	.word track_338_1

.align 2
