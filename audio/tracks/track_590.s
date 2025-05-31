.align 2

.global track_590

track_590_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 56
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N03, Gn4, v084
	.byte W03
	.byte VOICE, 24
	.byte BENDR, 4
	.byte N36, Fn4, v068
	.byte W03
	.byte VOL, 62
	.byte W01
	.byte 59 @ VOL
	.byte BEND, c_v
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v-41
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-53
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte 11 @ VOL
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 11
	.byte W01
	.byte 10 @ VOL
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 8
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_590:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_590_0

.align 2
