.align 2

.global track_496

track_496_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 127
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte N24, An2, v127, 2
	.byte W80
	.byte W01
	.byte FINE

track_496_1:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte N24, An2, v127, 1
	.byte W72
	.byte W03
	.byte FINE

track_496_2:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 25
	.byte N02, An4, v080
	.byte W02
	.byte VOICE, 17
	.byte N02, An2, v112
	.byte W13
	.byte VOICE, 18
	.byte N02, Gn2, v080
	.byte W02
	.byte VOICE, 17
	.byte N09, Gn2, v120
	.byte W78
	.byte W01
	.byte FINE

.align 2

track_496:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group13
	.word track_496_0
	.word track_496_1
	.word track_496_2

.align 2
