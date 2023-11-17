.align 2

.section .rodata
.global track_382

track_382_0:
	.byte 188, 0, 187, 75, 189, 8, 190, 40
	.byte 191, 64, 220, 41, 72, 134, 190, 40
	.byte 129, 24, 129, 13, 129, 8, 129, 4
	.byte 129, 1, 129, 0, 140, 177

track_382_1:
	.byte 188, 0, 189, 40, 190, 40, 191, 64
	.byte 212, 59, 80, 152, 177

.align 2

track_382:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_382_0
	.word track_382_1

.align 2
