.align 2

.section .rodata
.global track_450

track_450_0:
	.byte 188, 0, 187, 75, 189, 9, 190, 70
	.byte 191, 44, 193, 14, 134, 192, 17, 226
	.byte 60, 112, 129, 192, 22, 129, 27, 129
	.byte 33, 129, 38, 129, 43, 129, 48, 129
	.byte 54, 129, 59, 129, 64, 129, 69, 129
	.byte 74, 129, 80, 129, 85, 129, 90, 129
	.byte 95, 129, 190, 29, 192, 101, 129, 190
	.byte 12, 192, 106, 129, 190, 0, 192, 111
	.byte 129, 177

.align 2

track_450:
	.byte 1
	.byte 0
	.byte 201
	.byte 0
	.word voice_group10
	.word track_450_0

.align 2
