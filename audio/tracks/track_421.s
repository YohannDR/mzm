.align 2

.section .rodata
.global track_421

track_421_0:
	.byte 188, 0, 187, 75, 189, 12, 190, 94
	.byte 191, 64, 217, 60, 127, 138, 60, 40
	.byte 138, 225, 60, 16, 146, 177

track_421_1:
	.byte 188, 0, 189, 12, 190, 78, 191, 64
	.byte 134, 219, 57, 127, 140, 57, 40, 140
	.byte 225, 57, 16, 146, 177

.align 2

track_421:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group5
	.word track_421_0
	.word track_421_1

.align 2
