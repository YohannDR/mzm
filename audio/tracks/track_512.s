.align 2

.section .rodata
.global track_512

track_512_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 37
	.byte 191, 64, 208, 60, 80, 129, 177

.align 2

track_512:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_512_0

.align 2
