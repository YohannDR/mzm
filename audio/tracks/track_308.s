.align 2

.section .rodata
.global track_308

track_308_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 74
	.byte 191, 64, 210, 59, 92, 131, 189, 19
	.byte 213, 134, 228, 60, 72, 160, 131, 177
	.byte 

track_308_1:
	.byte 188, 0, 189, 21, 196, 80, 190, 62
	.byte 191, 64, 194, 127, 219, 72, 40, 135
	.byte 190, 62, 129, 37, 129, 22, 129, 14
	.byte 129, 7, 129, 189, 0, 196, 0, 190
	.byte 62, 191, 64, 186, 55, 211, 55, 80
	.byte 160, 177

.align 2

track_308:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_308_0
	.word track_308_1

.align 2
