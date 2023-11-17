.align 2

.section .rodata
.global track_507

track_507_0:
	.byte 188, 0, 187, 75, 189, 8, 190, 31
	.byte 191, 64, 210, 60, 60, 132, 209, 62
	.byte 130, 210, 59, 52, 132, 189, 2, 190
	.byte 19, 209, 72, 32, 132, 72, 12, 130
	.byte 177

track_507_1:
	.byte 188, 0, 189, 2, 190, 19, 191, 64
	.byte 209, 65, 80, 130, 62, 130, 69, 130
	.byte 72, 134, 196, 5, 190, 31, 194, 127
	.byte 219, 57, 60, 140, 196, 0, 177

.align 2

track_507:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_507_0
	.word track_507_1

.align 2
