.align 2

.section .rodata
.global track_694

track_694_0:
	.byte 188, 0, 187, 75, 189, 43, 190, 94
	.byte 191, 50, 132, 212, 60, 72, 133, 64
	.byte 133, 67, 60, 133, 67, 20, 133, 177
	.byte 

track_694_1:
	.byte 188, 0, 189, 42, 190, 120, 191, 50
	.byte 132, 212, 67, 120, 133, 68, 133, 69
	.byte 80, 133, 69, 36, 133, 177

.align 2

track_694:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_694_0
	.word track_694_1

.align 2
