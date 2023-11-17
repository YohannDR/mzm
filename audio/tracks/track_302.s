.align 2

.section .rodata
.global track_302

track_302_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 74
	.byte 191, 64, 210, 59, 92, 131, 189, 19
	.byte 213, 134, 228, 60, 72, 159, 131, 177
	.byte 

track_302_1:
	.byte 188, 0, 189, 0, 190, 78, 191, 64
	.byte 186, 55, 209, 72, 80, 130, 189, 2
	.byte 211, 55, 120, 162, 177

.align 2

track_302:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_302_0
	.word track_302_1

.align 2
