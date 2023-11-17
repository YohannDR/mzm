.align 2

.section .rodata
.global track_490

track_490_0:
	.byte 188, 0, 187, 75, 189, 8, 190, 86
	.byte 191, 64, 224, 60, 100, 145, 177

track_490_1:
	.byte 188, 0, 189, 6, 190, 0, 191, 64
	.byte 224, 76, 80, 129, 190, 6, 129, 12
	.byte 129, 23, 129, 37, 129, 57, 129, 86
	.byte 129, 71, 129, 59, 129, 48, 129, 38
	.byte 129, 30, 129, 23, 129, 16, 129, 10
	.byte 129, 5, 129, 0, 129, 177

.align 2

track_490:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group13
	.word track_490_0
	.word track_490_1

.align 2
