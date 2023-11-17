.align 2

.section .rodata
.global track_95

track_95_0:
	.byte 188, 0, 187, 75, 189, 0, 190, 0
	.byte 191, 64, 219, 72, 4, 140, 177

.align 2

track_95:
	.byte 1
	.byte 0
	.byte 0
	.byte 0
	.word voice_group1
	.word track_95_0

.align 2
