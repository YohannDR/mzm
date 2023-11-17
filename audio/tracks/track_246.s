.align 2

.section .rodata
.global track_246

track_246_0:
	.byte 188, 0, 187, 75, 189, 29, 190, 0
	.byte 191, 64, 135, 225, 60, 52, 131, 196
	.byte 60, 190, 41, 194, 120, 197, 1, 143
	.byte 177

track_246_1:
	.byte 188, 0, 189, 29, 190, 75, 191, 64
	.byte 217, 60, 80, 138, 189, 24, 190, 21
	.byte 214, 60, 92, 129, 190, 30, 129, 38
	.byte 129, 46, 129, 54, 131, 214, 59, 52
	.byte 135, 212, 57, 20, 133, 177

.align 2

track_246:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_246_0
	.word track_246_1

.align 2
