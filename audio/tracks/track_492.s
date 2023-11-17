.align 2

.section .rodata
.global track_492

track_492_0:
	.byte 188, 0, 187, 75, 150, 189, 4, 190
	.byte 78, 192, 64, 215, 60, 80, 136, 60
	.byte 32, 136, 217, 60, 12, 138, 177

track_492_1:
	.byte 188, 0, 189, 8, 190, 78, 191, 64
	.byte 231, 60, 100, 2, 133, 57, 32, 2
	.byte 152, 130, 177

.align 2

track_492:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word voice_group13
	.word track_492_0
	.word track_492_1

.align 2
