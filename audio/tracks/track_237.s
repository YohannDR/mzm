.align 2

.section .rodata
.global track_237

track_237_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 56
	.byte 191, 64, 232, 60, 80, 153, 177

track_237_1:
	.byte 188, 0, 189, 25, 190, 35, 191, 64
	.byte 193, 20, 186, 1, 192, 127, 212, 53
	.byte 52, 129, 192, 111, 129, 96, 129, 80
	.byte 129, 64, 129, 189, 24, 196, 40, 190
	.byte 49, 193, 12, 194, 80, 231, 63, 80
	.byte 3, 137, 190, 21, 192, 53, 137, 190
	.byte 7, 192, 43, 137, 177

.align 2

track_237:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_237_0
	.word track_237_1

.align 2
