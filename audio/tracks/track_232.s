.align 2

.section .rodata
.global track_232

track_232_0:
	.byte 188, 0, 187, 75, 189, 0, 190, 0
	.byte 191, 64, 135, 225, 60, 52, 131, 190
	.byte 54, 143, 177

track_232_1:
	.byte 188, 0, 189, 0, 190, 68, 191, 64
	.byte 217, 60, 80, 138, 189, 24, 190, 27
	.byte 214, 60, 52, 135, 59, 16, 135, 212
	.byte 57, 8, 133, 177

.align 2

track_232:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_232_0
	.word track_232_1

.align 2
