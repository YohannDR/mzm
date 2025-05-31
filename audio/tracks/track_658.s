.align 2

.global track_658

track_658_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 6
	.byte PRIO, 1
	.byte BEND, c_v
	.byte N64, Cn3, v080, 1
	.byte W66
	.byte BEND, c_v-16
	.byte N56, Cn3, v016, 2
	.byte W30
	.byte W16
	.byte VOL, 33
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_658_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v
	.byte W36
	.byte c_v-8 @ BEND
	.byte N64, Cn3, v028, 1
	.byte W60
	.byte W05
	.byte FINE

.align 2

track_658:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group13
	.word track_658_0
	.word track_658_1

.align 2
