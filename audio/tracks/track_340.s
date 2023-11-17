.align 2

.section .rodata
.global track_340

track_340_0:
	.byte 188, 0, 187, 75, 189, 2, 190, 37
	.byte 191, 64, 132, 211, 57, 127, 132, 64
	.byte 100, 132, 222, 60, 131, 190, 20, 131
	.byte 11, 131, 5, 131, 2, 130, 0, 129
	.byte 177

.align 2

track_340:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_340_0

.align 2
