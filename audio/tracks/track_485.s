.align 2

.global track_485

track_485_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 4
	.byte BEND, c_v
	.byte N30
	.byte Cn3, Cn8
	.byte W04
	.byte VOL, 15
	.byte W02
	.byte AnM1
	.byte W01
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 37
	.byte W03
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte BEND, c_v-3
	.byte W02
	.byte VOL, 17
	.byte BEND, c_v-7
	.byte W01
	.byte Fn2
	.byte W01
	.byte VOL, 10
	.byte W02
	.byte FnM2
	.byte W02
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_485:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group13
	.word track_485_0

.align 2
