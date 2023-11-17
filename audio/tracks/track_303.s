.align 2

.section .rodata
.global track_303

track_303_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 86
	.byte 191, 64, 210, 60, 96, 131, 189, 20
	.byte 229, 163, 129, 177

track_303_1:
	.byte 188, 0, 189, 0, 190, 86, 191, 64
	.byte 186, 55, 209, 81, 80, 130, 189, 2
	.byte 209, 57, 112, 163, 130, 177

.align 2

track_303:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_303_0
	.word track_303_1

.align 2
