.align 2

.global track_606

track_606_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-63
	.byte N30, Gn2, v080
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte 14 @ VOL
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte 40 @ VOL
	.byte BEND, c_v-51
	.byte W02
	.byte c_v-42 @ BEND
	.byte W02
	.byte c_v-27 @ BEND
	.byte W02
	.byte c_v-24 @ BEND
	.byte W02
	.byte c_v-27 @ BEND
	.byte W02
	.byte c_v-33 @ BEND
	.byte W02
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-47 @ BEND
	.byte W02
	.byte c_v-51 @ BEND
	.byte W01
	.byte VOL, 40
	.byte W01
	.byte 30 @ VOL
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte 16 @ VOL
	.byte BEND, c_v-58
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte 8 @ VOL
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 5
	.byte W01
	.byte 2 @ VOL
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_606:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_606_0

.align 2
