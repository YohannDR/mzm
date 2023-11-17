.align 2

.section .rodata
.global track_234

track_234_0:
	.byte 188, 0, 187, 75, 189, 10, 190, 0
	.byte 191, 64, 135, 225, 60, 52, 131, 190
	.byte 40, 143, 177

track_234_1:
	.byte 188, 0, 189, 10, 190, 66, 191, 64
	.byte 217, 60, 80, 138, 189, 24, 190, 46
	.byte 214, 60, 72, 135, 59, 28, 135, 212
	.byte 57, 12, 133, 177

.align 2

track_234:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_234_0
	.word track_234_1

.align 2
