.align 2

.section .rodata
.global track_240

track_240_0:
	.byte 188, 0, 187, 75, 189, 19, 190, 0
	.byte 191, 64, 136, 225, 62, 52, 132, 190
	.byte 51, 142, 177

track_240_1:
	.byte 188, 0, 189, 19, 190, 68, 191, 64
	.byte 219, 60, 80, 140, 189, 24, 190, 41
	.byte 214, 60, 72, 135, 59, 28, 135, 212
	.byte 57, 12, 133, 177

.align 2

track_240:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_240_0
	.word track_240_1

.align 2
