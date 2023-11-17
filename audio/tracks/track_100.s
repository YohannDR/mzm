.align 2

.section .rodata
.global track_100

track_100_0:
	.byte 188, 0, 187, 75, 189, 1, 190, 51
	.byte 191, 64, 209, 60, 112, 130, 177

.align 2

track_100:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_100_0

.align 2
