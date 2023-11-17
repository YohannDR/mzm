.align 2

.section .rodata
.global track_120

track_120_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 41
	.byte 191, 64, 209, 60, 80, 130, 177

.align 2

track_120:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group1
	.word track_120_0

.align 2
