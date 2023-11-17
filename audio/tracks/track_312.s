.align 2

.section .rodata
.global track_312

track_312_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 78
	.byte 191, 64, 210, 60, 96, 131, 189, 20
	.byte 215, 60, 100, 136, 57, 136, 189, 19
	.byte 222, 60, 92, 136, 190, 62, 129, 47
	.byte 129, 31, 129, 15, 129, 7, 129, 3
	.byte 129, 0, 155, 131, 177

track_312_1:
	.byte 188, 0, 189, 0, 190, 94, 191, 64
	.byte 186, 55, 209, 81, 80, 131, 212, 57
	.byte 112, 135, 53, 100, 163, 130, 177

.align 2

track_312:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_312_0
	.word track_312_1

.align 2
