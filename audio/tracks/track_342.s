.align 2

.section .rodata
.global track_342

track_342_0:
	.byte 188, 0, 187, 75, 189, 8, 190, 62
	.byte 191, 64, 193, 8, 192, 64, 226, 47
	.byte 72, 130, 192, 42, 130, 27, 130, 18
	.byte 130, 11, 130, 7, 130, 3, 129, 190
	.byte 37, 129, 22, 192, 1, 129, 190, 13
	.byte 129, 7, 129, 2, 129, 0, 155, 131
	.byte 177

track_342_1:
	.byte 188, 0, 189, 9, 191, 64, 186, 2
	.byte 130, 190, 62, 193, 12, 192, 64, 218
	.byte 81, 100, 129, 192, 60, 129, 56, 129
	.byte 52, 129, 48, 159, 131, 177

.align 2

track_342:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_342_0
	.word track_342_1

.align 2
