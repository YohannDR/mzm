.align 2

.global track_465

track_465_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W96
	.byte W24
	.byte VOICE, 20
	.byte VOL, 127
	.byte PAN, c_v-20
	.byte N15, Cn3, v127
	.byte W15
	.byte N24, An2, v127, 2
	.byte W56
	.byte W01
	.byte W15
	.byte FINE

track_465_1:
	.byte KEYSH, 0
	.byte W96
	.byte W30
	.byte VOICE, 19
	.byte VOL, 127
	.byte PAN, c_v-20
	.byte N15, Cn3, v127
	.byte W15
	.byte N24, An2, v127, 1
	.byte W48
	.byte W03
	.byte W15
	.byte FINE

track_465_2:
	.byte KEYSH, 0
	.byte W96
	.byte W24
	.byte VOICE, 2
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 25
	.byte N02, An4, v080
	.byte W02
	.byte VOICE, 21
	.byte N02, An2, v112
	.byte W13
	.byte VOICE, 2
	.byte N02, Gn2, v080
	.byte W02
	.byte VOICE, 21
	.byte N09, Gn2, v120
	.byte W54
	.byte W01
	.byte W15
	.byte FINE

.align 2

track_465:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group10
	.word track_465_0
	.word track_465_1
	.word track_465_2

.align 2
