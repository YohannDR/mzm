.align 2

.section .rodata
.global track_384

track_384_0:
	.byte 188, 0, 187, 75, 189, 5, 190, 74
	.byte 191, 64, 192, 64, 131, 211, 55, 100
	.byte 132, 189, 42, 193, 24, 219, 59, 80
	.byte 129, 192, 53, 129, 43, 129, 35, 129
	.byte 27, 129, 21, 129, 17, 129, 13, 129
	.byte 9, 129, 190, 35, 192, 5, 129, 190
	.byte 14, 192, 3, 129, 190, 0, 192, 1
	.byte 129, 177

.align 2

track_384:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_384_0

.align 2
