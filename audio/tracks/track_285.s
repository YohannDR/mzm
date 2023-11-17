.align 2

.section .rodata
.global track_285

track_285_0:
	.byte 188, 0, 187, 75, 189, 17, 190, 22
	.byte 191, 64, 193, 10, 192, 1, 130, 211
	.byte 108, 80, 129, 192, 43, 129, 85, 129
	.byte 127, 130, 1, 211, 108, 32, 129, 192
	.byte 43, 129, 85, 129, 127, 130, 1, 211
	.byte 108, 12, 129, 192, 43, 129, 84, 129
	.byte 127, 129, 177

track_285_1:
	.byte 188, 0, 189, 18, 190, 55, 191, 64
	.byte 211, 72, 80, 132, 72, 32, 132, 72
	.byte 12, 132, 177

.align 2

track_285:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_285_0
	.word track_285_1

.align 2
