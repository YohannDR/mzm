.align 2

.section .rodata
.global track_278

track_278_0:
	.byte 188, 0, 187, 75, 189, 20, 190, 62
	.byte 192, 64, 210, 60, 80, 133, 211, 57
	.byte 60, 132, 177

track_278_1:
	.byte 188, 0, 189, 21, 190, 39, 191, 64
	.byte 138, 232, 60, 60, 150, 190, 47, 129
	.byte 37, 129, 28, 129, 18, 129, 9, 129
	.byte 0, 129, 177

.align 2

track_278:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_278_0
	.word track_278_1

.align 2
