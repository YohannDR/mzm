.align 2

.section .rodata
.global track_423

track_423_0:
	.byte 188, 0, 187, 75, 189, 4, 190, 86
	.byte 191, 64, 217, 60, 80, 138, 64, 40
	.byte 138, 64, 12, 158, 129, 177

track_423_1:
	.byte 188, 0, 189, 2, 190, 62, 191, 64
	.byte 212, 60, 80, 133, 189, 3, 230, 57
	.byte 100, 163, 130, 177

track_423_2:
	.byte 188, 0, 189, 0, 190, 94, 191, 64
	.byte 186, 22, 209, 81, 80, 130, 189, 1
	.byte 211, 53, 112, 164, 129, 177

.align 2

track_423:
	.byte 3
	.byte 0
	.byte 218
	.byte 0
	.word voice_group9
	.word track_423_0
	.word track_423_1
	.word track_423_2

.align 2
