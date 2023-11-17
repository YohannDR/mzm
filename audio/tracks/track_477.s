.align 2

.section .rodata
.global track_477

track_477_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 78
	.byte 191, 64, 210, 57, 96, 131, 189, 20
	.byte 229, 159, 129, 177

track_477_1:
	.byte 188, 0, 189, 0, 190, 78, 191, 64
	.byte 186, 55, 130, 189, 2, 209, 57, 112
	.byte 159, 130, 177

.align 2

track_477:
	.byte 2
	.byte 0
	.byte 227
	.byte 0
	.word voice_group5
	.word track_477_0
	.word track_477_1

.align 2
