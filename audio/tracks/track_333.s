.align 2

.section .rodata
.global track_333

track_333_0:
	.byte 188, 0, 187, 75, 189, 2, 190, 39
	.byte 191, 64, 193, 12, 132, 212, 53, 80
	.byte 133, 222, 60, 60, 134, 192, 56, 133
	.byte 190, 19, 192, 40, 130, 190, 9, 129
	.byte 0, 129, 177

.align 2

track_333:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_333_0

.align 2
