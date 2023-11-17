.align 2

.section .rodata
.global track_350

track_350_0:
	.byte 188, 0, 187, 75, 189, 20, 196, 45
	.byte 190, 37, 191, 64, 194, 127, 234, 69
	.byte 80, 130, 190, 25, 130, 20, 129, 18
	.byte 130, 27, 130, 42, 130, 33, 130, 8
	.byte 130, 6, 130, 9, 130, 19, 130, 29
	.byte 130, 27, 129, 24, 130, 14, 130, 7
	.byte 130, 2, 130, 177

.align 2

track_350:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_350_0

.align 2
