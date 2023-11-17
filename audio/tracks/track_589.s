.align 2

.section .rodata
.global track_589

track_589_0:
	.byte 188, 0, 187, 75, 160, 130, 189, 20
	.byte 190, 70, 192, 64, 210, 60, 80, 131
	.byte 211, 57, 60, 158, 129, 144, 189, 7
	.byte 212, 77, 68, 133, 216, 77, 20, 137
	.byte 189, 4, 219, 53, 92, 139, 190, 23
	.byte 129, 7, 129, 0, 177

track_589_1:
	.byte 188, 0, 160, 130, 189, 21, 190, 47
	.byte 191, 64, 138, 232, 60, 60, 150, 190
	.byte 47, 129, 37, 129, 28, 129, 18, 129
	.byte 9, 129, 0, 129, 177

.align 2

track_589:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_589_0
	.word track_589_1

.align 2
