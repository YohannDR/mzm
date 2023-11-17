.align 2

.section .rodata
.global track_21

track_21_0:
	.byte 188, 0, 187, 28, 189, 27, 190, 75
	.byte 191, 64, 219, 43, 112, 168, 189, 28
	.byte 177

track_21_1:
	.byte 188, 0, 189, 14, 190, 75, 191, 64
	.byte 219, 67, 112, 140, 177

.align 2

track_21:
	.byte 2
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_21_0
	.word track_21_1

.align 2
