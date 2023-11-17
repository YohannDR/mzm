.align 2

.section .rodata
.global track_420

track_420_0:
	.byte 188, 0, 187, 75, 189, 19, 190, 94
	.byte 191, 64, 134, 225, 60, 80, 164, 177
	.byte 

track_420_1:
	.byte 188, 0, 189, 14, 190, 94, 191, 64
	.byte 219, 60, 120, 140, 225, 60, 20, 162
	.byte 177

track_420_2:
	.byte 188, 0, 189, 0, 190, 94, 191, 64
	.byte 131, 212, 55, 100, 133, 211, 53, 163
	.byte 130, 177

.align 2

track_420:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group5
	.word track_420_0
	.word track_420_1
	.word track_420_2

.align 2
