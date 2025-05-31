.align 2

.global track_602

track_602_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 18
	.byte PRIO, 1
	.byte BEND, c_v-47
	.byte W12
	.byte N28, Cn3, v080
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-46
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v-43
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-39
	.byte W02
	.byte VOL, 30
	.byte BEND, c_v-35
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v-22
	.byte W02
	.byte c_v-15 @ BEND
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v+23
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte VOL, 20
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_602_1:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v-47
	.byte W12
	.byte N28, Fn3, v100
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-46
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v-43
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-39
	.byte W02
	.byte VOL, 30
	.byte BEND, c_v-35
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v-22
	.byte W02
	.byte c_v-15 @ BEND
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v+23
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte VOL, 20
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_602:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_602_0
	.word track_602_1

.align 2
