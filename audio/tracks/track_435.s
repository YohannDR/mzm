.align 2

.section .rodata
.global track_435

track_435_0:
	.byte 188, 0, 187, 75, 189, 4, 190, 94
	.byte 191, 64, 221, 60, 100, 142, 223, 60
	.byte 52, 144, 225, 60, 12, 158, 177

track_435_1:
	.byte 188, 0, 189, 7, 190, 94, 191, 64
	.byte 211, 65, 80, 133, 62, 133, 59, 134
	.byte 59, 32, 134, 59, 12, 132, 67, 32
	.byte 132, 65, 12, 132, 64, 8, 156, 130
	.byte 177

track_435_2:
	.byte 188, 0, 189, 8, 190, 94, 191, 64
	.byte 211, 53, 120, 135, 211, 135, 211, 135
	.byte 53, 100, 160, 131, 177

.align 2

track_435:
	.byte 3
	.byte 0
	.byte 212
	.byte 0
	.word voice_group9
	.word track_435_0
	.word track_435_1
	.word track_435_2

.align 2
