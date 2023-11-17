.align 2

.section .rodata
.global track_387

track_387_0:
	.byte 188, 0, 187, 75, 189, 7, 196, 10
	.byte 190, 14, 191, 64, 193, 4, 194, 127
	.byte 192, 64, 255, 65, 60, 129, 192, 65
	.byte 129, 190, 16, 192, 67, 129, 71, 129
	.byte 190, 19, 192, 76, 129, 91, 129, 190
	.byte 23, 192, 127, 130, 190, 30, 130, 42
	.byte 172, 130, 177

.align 2

track_387:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_387_0

.align 2
