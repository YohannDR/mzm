.align 2

.section .rodata
.global track_380

track_380_0:
	.byte 188, 0, 187, 75, 189, 41, 190, 7
	.byte 191, 64, 193, 12, 192, 64, 216, 64
	.byte 80, 129, 190, 15, 192, 72, 129, 190
	.byte 23, 192, 80, 129, 190, 31, 192, 87
	.byte 129, 95, 129, 103, 129, 111, 129, 190
	.byte 23, 192, 119, 129, 190, 15, 192, 127
	.byte 129, 177

.align 2

track_380:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_380_0

.align 2
