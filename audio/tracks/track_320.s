.align 2

.section .rodata
.global track_320

track_320_0:
	.byte 188, 0, 187, 75, 189, 23, 190, 56
	.byte 191, 64, 235, 60, 127, 156, 130, 177
	.byte 

.align 2

track_320:
	.byte 1
	.byte 0
	.byte 196
	.byte 0
	.word voice_group3
	.word track_320_0

.align 2
