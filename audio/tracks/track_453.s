.align 2

.section .rodata
.global track_453

track_453_0:
	.byte 188, 0, 187, 75, 189, 10, 190, 62
	.byte 191, 44, 130, 218, 57, 80, 139, 57
	.byte 16, 139, 57, 8, 139, 177

track_453_1:
	.byte 188, 0, 189, 11, 190, 78, 191, 44
	.byte 215, 60, 80, 136, 177

.align 2

track_453:
	.byte 2
	.byte 0
	.byte 203
	.byte 0
	.word voice_group10
	.word track_453_0
	.word track_453_1

.align 2
