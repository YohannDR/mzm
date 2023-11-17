.align 2

.section .rodata
.global track_243

track_243_0:
	.byte 188, 0, 187, 75, 189, 21, 190, 56
	.byte 191, 64, 232, 60, 76, 149, 190, 56
	.byte 129, 47, 129, 40, 129, 35, 129, 31
	.byte 129, 30, 130, 177

track_243_1:
	.byte 188, 0, 189, 25, 190, 49, 191, 64
	.byte 193, 20, 186, 1, 192, 127, 129, 214
	.byte 53, 52, 129, 192, 116, 129, 105, 129
	.byte 95, 129, 84, 129, 74, 129, 64, 129
	.byte 189, 24, 190, 67, 216, 59, 80, 137
	.byte 57, 20, 137, 55, 12, 137, 177

.align 2

track_243:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_243_0
	.word track_243_1

.align 2
