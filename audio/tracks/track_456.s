.align 2

.global track_456

track_456_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v-20
	.byte N03, Cn3, v080
	.byte W03
	.byte VOICE, 13
	.byte N12, Cn2, v092
	.byte W04
	.byte VOL, 70
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W24
	.byte FINE

track_456_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 56
	.byte PAN, c_v-20
	.byte PRIO, 72
	.byte W10
	.byte N06, An4, v080
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_456:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group10
	.word track_456_0
	.word track_456_1

.align 2
