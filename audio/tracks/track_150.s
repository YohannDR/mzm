.align 2

.section .rodata
.global track_150

track_150_0:
	.byte 188, 0, 187, 75, 189, 44, 190, 34
	.byte 191, 64, 209, 69, 112, 130, 177

.align 2

track_150:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_150_0

.align 2
