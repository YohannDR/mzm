.align 2

.global track_177

track_177_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 0
	.byte PAN, c_v-14
	.byte BENDR, 8
	.byte BEND, c_v-63
	.byte N60, An3, v112
	.byte W03
	.byte VOL, 28
	.byte W03
	.byte 46 @ VOL
	.byte BEND, c_v-62
	.byte W03
	.byte VOL, 58
	.byte BEND, c_v-61
	.byte W03
	.byte VOL, 64
	.byte BEND, c_v-59
	.byte W03
	.byte VOL, 68
	.byte BEND, c_v-57
	.byte W03
	.byte VOL, 69
	.byte BEND, c_v-55
	.byte W03
	.byte VOL, 68
	.byte BEND, c_v-53
	.byte W03
	.byte VOL, 64
	.byte BEND, c_v-51
	.byte W03
	.byte VOL, 54
	.byte BEND, c_v-49
	.byte W03
	.byte VOL, 44
	.byte BEND, c_v-47
	.byte W03
	.byte VOL, 35
	.byte BEND, c_v-43
	.byte W03
	.byte VOL, 28
	.byte BEND, c_v-41
	.byte W03
	.byte VOL, 23
	.byte BEND, c_v-37
	.byte W03
	.byte VOL, 18
	.byte BEND, c_v-33
	.byte W03
	.byte VOL, 14
	.byte BEND, c_v-29
	.byte W03
	.byte VOL, 10
	.byte BEND, c_v-23
	.byte W03
	.byte VOL, 6
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 4
	.byte BEND, c_v-11
	.byte W03
	.byte VOL, 1
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01
	.byte FINE

.align 2

track_177:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group7
	.word track_177_0

.align 2
