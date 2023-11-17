.align 2

.section .rodata
.global track_236

track_236_0:
	.byte 188, 0, 187, 75, 189, 12, 190, 0
	.byte 191, 64, 135, 225, 60, 52, 131, 190
	.byte 53, 143, 177

track_236_1:
	.byte 188, 0, 189, 12, 190, 66, 191, 64
	.byte 192, 64, 217, 60, 80, 138, 189, 24
	.byte 190, 40, 193, 12, 226, 63, 52, 135
	.byte 190, 13, 192, 53, 135, 190, 3, 192
	.byte 43, 133, 177

.align 2

track_236:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_236_0
	.word track_236_1

.align 2
