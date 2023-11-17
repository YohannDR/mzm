.align 2

.section .rodata
.global track_360

track_360_0:
	.byte 188, 0, 187, 75, 189, 26, 190, 47
	.byte 191, 64, 233, 60, 100, 154, 177

.align 2

track_360:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_360_0

.align 2
