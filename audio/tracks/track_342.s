.align 2

.global track_342

track_342_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N19, Bn1, v072
	.byte W02
	.byte BEND, c_v-22
	.byte W02
	.byte c_v-37 @ BEND
	.byte W02
	.byte c_v-46 @ BEND
	.byte W02
	.byte c_v-53 @ BEND
	.byte W02
	.byte c_v-57 @ BEND
	.byte W02
	.byte c_v-61 @ BEND
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte 22 @ VOL
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W32
	.byte W03
	.byte FINE

track_342_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte PAN, c_v
	.byte PRIO, 2
	.byte W02
	.byte VOL, 62
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N11, An4, v100
	.byte W01
	.byte BEND, c_v-4
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W44
	.byte W03
	.byte FINE

.align 2

track_342:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_342_0
	.word track_342_1

.align 2
