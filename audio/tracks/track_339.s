.align 2

.global track_339

track_339_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte N23, Gn2, v092
	.byte W04
	.byte BEND, c_v+15
	.byte W04
	.byte c_v-4 @ BEND
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_339:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_339_0

.align 2
