.align 2

.section .rodata
.global track_386

track_386_0:
	.byte 188, 0, 187, 75, 189, 3, 190, 40
	.byte 191, 64, 193, 12, 192, 64, 132, 231
	.byte 52, 64, 1, 133, 190, 50, 192, 94
	.byte 138, 190, 40, 192, 79, 134, 190, 30
	.byte 129, 20, 129, 10, 129, 0, 129, 177
	.byte 

.align 2

track_386:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_386_0

.align 2
