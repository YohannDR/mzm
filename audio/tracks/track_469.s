.align 2

.global track_469

track_469_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 70
	.byte PAN, c_v
	.byte N72, Cn3, v064
	.byte W42
	.byte W01
	.byte VOL, 70
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W16
	.byte FINE

track_469_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N40, Cn4, v100
	.byte W03
	.byte VOL, 0
	.byte W01
	.byte BEND, c_v-62
	.byte W01
	.byte c_v-61 @ BEND
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte 2 @ VOL
	.byte BEND, c_v-60
	.byte W01
	.byte c_v-59 @ BEND
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v-57
	.byte W02
	.byte c_v-56 @ BEND
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-55
	.byte W01
	.byte c_v-54 @ BEND
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-53
	.byte W01
	.byte c_v-51 @ BEND
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-41
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W09
	.byte N12, Cn4, v040
	.byte W12
	.byte Cn4, v012 @ N12
	.byte W32
	.byte W03
	.byte FINE

.align 2

track_469:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group12
	.word track_469_0
	.word track_469_1

.align 2
