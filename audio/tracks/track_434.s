.align 2

.section .rodata
.global track_434

track_434_0:
	.byte 188, 0, 187, 75, 189, 4, 190, 78
	.byte 191, 64, 221, 60, 100, 142, 225, 60
	.byte 32, 146, 177

track_434_1:
	.byte 188, 0, 189, 7, 190, 78, 191, 64
	.byte 211, 65, 80, 133, 62, 133, 59, 134
	.byte 59, 32, 134, 59, 12, 132, 190, 62
	.byte 211, 67, 32, 132, 65, 12, 132, 64
	.byte 8, 132, 177

.align 2

track_434:
	.byte 2
	.byte 0
	.byte 212
	.byte 0
	.word voice_group9
	.word track_434_0
	.word track_434_1

.align 2
