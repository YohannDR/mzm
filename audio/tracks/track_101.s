.align 2

.section .rodata
.global track_101

track_101_0:
	.byte 188, 0, 187, 75, 189, 1, 190, 39
	.byte 191, 64, 209, 60, 108, 130, 177

.align 2

track_101:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_101_0

.align 2
