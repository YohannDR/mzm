.align 2

.section .rodata
.global track_496

track_496_0:
	.byte 188, 0, 187, 75, 189, 15, 190, 127
	.byte 191, 64, 222, 60, 127, 143, 231, 57
	.byte 127, 2, 171, 129, 177

track_496_1:
	.byte 188, 0, 134, 189, 14, 190, 127, 191
	.byte 64, 222, 60, 127, 143, 231, 57, 127
	.byte 1, 168, 131, 177

track_496_2:
	.byte 188, 0, 189, 18, 190, 127, 191, 64
	.byte 186, 25, 209, 81, 80, 130, 189, 17
	.byte 209, 57, 112, 141, 189, 18, 209, 55
	.byte 80, 130, 189, 17, 216, 55, 120, 170
	.byte 129, 177

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
