.align 2

.section .rodata
.global track_433

track_433_0:
	.byte 188, 0, 187, 75, 189, 4, 190, 78
	.byte 191, 64, 225, 60, 80, 146, 177

track_433_1:
	.byte 188, 0, 189, 7, 190, 62, 191, 64
	.byte 211, 65, 80, 133, 62, 133, 59, 134
	.byte 59, 32, 134, 59, 12, 132, 67, 32
	.byte 132, 65, 12, 132, 64, 8, 132, 177
	.byte 

.align 2

track_433:
	.byte 2
	.byte 0
	.byte 212
	.byte 0
	.word voice_group9
	.word track_433_0
	.word track_433_1

.align 2
