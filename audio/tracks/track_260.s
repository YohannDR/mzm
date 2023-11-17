.align 2

.section .rodata
.global track_260

track_260_0:
	.byte 188, 0, 187, 75, 189, 38, 190, 37
	.byte 191, 64, 217, 60, 80, 138, 60, 32
	.byte 138, 60, 12, 138, 177

.align 2

track_260:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group2
	.word track_260_0

.align 2
