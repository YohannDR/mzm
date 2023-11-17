.align 2

.section .rodata
.global track_510

track_510_0:
	.byte 188, 0, 187, 75, 189, 6, 190, 27
	.byte 191, 64, 193, 14, 192, 111, 218, 62
	.byte 60, 129, 192, 101, 129, 90, 129, 80
	.byte 129, 69, 129, 59, 129, 48, 129, 190
	.byte 27, 192, 38, 129, 190, 11, 192, 27
	.byte 129, 190, 4, 192, 17, 129, 190, 0
	.byte 129, 177

.align 2

track_510:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_510_0

.align 2
