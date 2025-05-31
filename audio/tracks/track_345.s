.align 2

.global track_345

track_345_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v-63
	.byte W04
	.byte N12, En3, v080
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte 38 @ VOL
	.byte BEND, c_v-50
	.byte W01
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v-38
	.byte W02
	.byte c_v-25 @ BEND
	.byte W02
	.byte VOL, 40
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte 15 @ VOL
	.byte BEND, c_v
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte FINE

.align 2

track_345:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_345_0

.align 2
