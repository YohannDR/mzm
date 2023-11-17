.align 2

.section .rodata
.global track_371

track_371_0:
	.byte 188, 0, 187, 75, 189, 34, 190, 50
	.byte 191, 64, 211, 60, 92, 132, 189, 33
	.byte 193, 4, 192, 32, 225, 53, 130, 192
	.byte 35, 130, 39, 130, 43, 130, 47, 130
	.byte 50, 130, 54, 130, 190, 50, 192, 58
	.byte 129, 190, 23, 129, 11, 192, 62, 129
	.byte 190, 4, 192, 64, 129, 190, 0, 152
	.byte 130, 177

track_371_1:
	.byte 188, 0, 189, 35, 190, 75, 191, 64
	.byte 132, 211, 81, 120, 159, 177

.align 2

track_371:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_371_0
	.word track_371_1

.align 2
