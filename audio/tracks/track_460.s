.align 2

.section .rodata
.global track_460

track_460_0:
	.byte 188, 0, 187, 75, 189, 0, 190, 74
	.byte 191, 44, 222, 60, 112, 143, 189, 1
	.byte 226, 60, 92, 158, 177

track_460_1:
	.byte 188, 0, 189, 2, 190, 86, 191, 36
	.byte 212, 53, 100, 163, 129, 177

.align 2

track_460:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group10
	.word track_460_0
	.word track_460_1

.align 2
