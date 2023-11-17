.align 2

.section .rodata
.global track_605

track_605_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 67
	.byte 191, 64, 210, 57, 92, 131, 189, 19
	.byte 228, 59, 159, 129, 177

track_605_1:
	.byte 188, 0, 189, 0, 190, 70, 191, 64
	.byte 186, 55, 130, 210, 53, 112, 159, 130
	.byte 177

.align 2

track_605:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group5
	.word track_605_0
	.word track_605_1

.align 2
