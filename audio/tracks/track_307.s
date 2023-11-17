.align 2

.section .rodata
.global track_307

track_307_0:
	.byte 188, 0, 187, 75, 189, 17, 190, 74
	.byte 191, 64, 129, 217, 60, 80, 138, 64
	.byte 40, 138, 64, 12, 155, 177

track_307_1:
	.byte 188, 0, 189, 11, 190, 78, 191, 64
	.byte 212, 60, 80, 133, 189, 20, 217, 60
	.byte 100, 138, 189, 0, 190, 78, 212, 53
	.byte 80, 156, 130, 177

.align 2

track_307:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_307_0
	.word track_307_1

.align 2
