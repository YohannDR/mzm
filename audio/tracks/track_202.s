.align 2

.section .rodata
.global track_202

track_202_0:
	.byte 188, 0, 187, 75, 189, 10, 190, 37
	.byte 191, 64, 225, 60, 80, 146, 177

.align 2

track_202:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_202_0

.align 2
