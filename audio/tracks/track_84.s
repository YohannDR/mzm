.align 2

.section .rodata
.global track_84

track_84_0:
	.byte 188, 0, 187, 28, 189, 102, 191, 64
	.byte 186, 120, 190, 11, 254, 47, 120, 3
	.byte 254, 53, 120, 3, 131, 190, 13, 131
	.byte 16, 131, 18, 131, 21, 131, 23, 131
	.byte 26, 131, 29, 131, 32, 156, 131, 29
	.byte 132, 27, 133, 25, 133, 22, 133, 20
	.byte 133, 17, 133, 15, 131, 13, 129, 178
	.byte 70, 185, 34, 8, 177

.align 2

track_84:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_84_0

.align 2
