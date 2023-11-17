.align 2

.section .rodata
.global track_309

track_309_0:
	.byte 188, 0, 187, 75, 189, 17, 190, 62
	.byte 191, 64, 213, 60, 127, 134, 221, 64
	.byte 100, 142, 210, 62, 40, 131, 177

track_309_1:
	.byte 188, 0, 189, 1, 190, 100, 191, 64
	.byte 209, 60, 127, 130, 177

.align 2

track_309:
	.byte 2
	.byte 0
	.byte 191
	.byte 0
	.word voice_group5
	.word track_309_0
	.word track_309_1

.align 2
