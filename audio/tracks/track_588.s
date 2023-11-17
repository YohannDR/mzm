.align 2

.section .rodata
.global track_588

track_588_0:
	.byte 188, 0, 187, 75, 189, 10, 190, 90
	.byte 191, 64, 186, 1, 244, 60, 127, 1
	.byte 166, 60, 16, 1, 154, 152, 190, 90
	.byte 129, 55, 129, 38, 129, 27, 129, 20
	.byte 129, 14, 129, 10, 129, 7, 129, 4
	.byte 129, 3, 129, 1, 129, 0, 177

track_588_1:
	.byte 188, 0, 189, 10, 190, 90, 191, 64
	.byte 156, 244, 60, 36, 1, 164, 133, 177
	.byte 

.align 2

track_588:
	.byte 2
	.byte 0
	.byte 225
	.byte 0
	.word voice_group13
	.word track_588_0
	.word track_588_1

.align 2
