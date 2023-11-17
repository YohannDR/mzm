.align 2

.section .rodata
.global track_314

track_314_0:
	.byte 188, 0, 187, 75, 189, 19, 190, 78
	.byte 191, 64, 217, 60, 100, 138, 189, 18
	.byte 226, 60, 80, 163, 177

track_314_1:
	.byte 188, 0, 189, 0, 190, 78, 191, 64
	.byte 186, 55, 130, 211, 53, 112, 136, 211
	.byte 163, 177

.align 2

track_314:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_314_0
	.word track_314_1

.align 2
