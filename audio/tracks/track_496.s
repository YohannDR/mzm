.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_496

track_496_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 127
	.byte PAN, c_v
	.byte N15
	.byte Cn3, Gn8
	.byte W15
	.byte N24
	.byte An2, Gn8, DnM2
	.byte W80
	.byte W01

	.byte FINE

track_496_1:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v
	.byte N15
	.byte Cn3, Gn8
	.byte W15
	.byte N24
	.byte An2, Gn8, CsM2
	.byte W72
	.byte W03

	.byte FINE

track_496_2:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 25
	.byte N02
	.byte An4, Gs4
	.byte W02
	.byte VOICE, 17
	.byte N02
	.byte An2, En7
	.byte W13
	.byte VOICE, 18
	.byte N02
	.byte Gn2, Gs4
	.byte W02
	.byte VOICE, 17
	.byte N09
	.byte Gn2, Cn8
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
