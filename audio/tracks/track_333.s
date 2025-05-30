.align 2

.global track_333

track_333_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 39
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte N05, Fn2, v080
	.byte W05
	.byte N15, Cn3, v060
	.byte W06
	.byte BEND, c_v-8
	.byte W05
	.byte VOL, 19
	.byte BEND, c_v-24
	.byte W02
	.byte VOL, 9
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_333:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_333_0

.align 2
