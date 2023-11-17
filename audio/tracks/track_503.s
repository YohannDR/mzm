.align 2

.section .rodata
.global track_503

track_503_0:
	.byte 188, 0, 187, 75, 189, 2, 190, 59
	.byte 191, 64, 211, 55, 80, 132, 59, 60
	.byte 132, 66, 40, 132, 177

.align 2

track_503:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_503_0

.align 2
