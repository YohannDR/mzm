.align 2

.section .rodata
.global track_193

track_193_0:
	.byte 188, 0, 187, 75, 189, 19, 190, 78
	.byte 191, 64, 220, 60, 100, 141, 213, 57
	.byte 80, 134, 189, 4, 190, 86, 212, 55
	.byte 68, 155, 129, 177

track_193_1:
	.byte 188, 0, 189, 11, 190, 94, 191, 64
	.byte 212, 60, 88, 133, 189, 23, 190, 78
	.byte 232, 57, 92, 148, 190, 44, 129, 28
	.byte 129, 19, 129, 13, 129, 8, 129, 5
	.byte 129, 2, 129, 0, 148, 177

.align 2

track_193:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group5
	.word track_193_0
	.word track_193_1

.align 2
