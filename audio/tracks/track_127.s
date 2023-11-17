.align 2

.section .rodata
.global track_127

track_127_0:
	.byte 188, 0, 187, 75, 189, 32, 190, 27
	.byte 191, 64, 208, 60, 80, 129, 177

.align 2

track_127:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group1
	.word track_127_0

.align 2
