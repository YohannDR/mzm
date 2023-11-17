.align 2

.section .rodata
.global track_440

track_440_0:
	.byte 188, 0, 187, 75, 189, 16, 190, 70
	.byte 191, 64, 214, 59, 80, 135, 57, 32
	.byte 135, 55, 8, 135, 177

.align 2

track_440:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group9
	.word track_440_0

.align 2
