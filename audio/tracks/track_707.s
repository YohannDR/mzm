.align 2

.global track_707

track_707_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 82
	.byte PAN, c_v
	.byte N03, An2, v092
	.byte W03
	.byte VOICE, 19
	.byte N21, Bn2 @ v092
	.byte W44
	.byte W01
	.byte FINE

track_707_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 86
	.byte PAN, c_v
	.byte PRIO, 55
	.byte W02
	.byte N03, Fn2, v112
	.byte W44
	.byte W02
	.byte FINE

.align 2

track_707:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word voice_group5
	.word track_707_0
	.word track_707_1

.align 2
