.align 2

.section .rodata
.global track_255

track_255_0:
	.byte 188, 0, 187, 75, 189, 12, 190, 78
	.byte 191, 64, 225, 60, 127, 159, 130, 177
	.byte 

track_255_1:
	.byte 188, 0, 189, 1, 190, 100, 191, 64
	.byte 136, 221, 56, 80, 156, 130, 177

.align 2

track_255:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_255_0
	.word track_255_1

.align 2
