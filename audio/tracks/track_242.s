.align 2

.section .rodata
.global track_242

track_242_0:
	.byte 188, 0, 187, 75, 189, 22, 190, 0
	.byte 191, 64, 134, 225, 60, 52, 131, 190
	.byte 41, 143, 177

track_242_1:
	.byte 188, 0, 189, 22, 190, 75, 191, 64
	.byte 217, 60, 80, 138, 189, 24, 190, 20
	.byte 214, 60, 72, 129, 190, 27, 129, 34
	.byte 129, 47, 132, 214, 59, 28, 135, 212
	.byte 57, 12, 133, 177

.align 2

track_242:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_242_0
	.word track_242_1

.align 2
