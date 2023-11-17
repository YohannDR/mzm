.align 2

.section .rodata
.global track_400

track_400_0:
	.byte 188, 0, 187, 75, 189, 0, 196, 40
	.byte 190, 78, 191, 64, 194, 80, 234, 30
	.byte 120, 155, 177

track_400_1:
	.byte 188, 0, 189, 7, 196, 20, 190, 78
	.byte 191, 64, 194, 10, 186, 23, 215, 55
	.byte 100, 136, 50, 136, 55, 80, 136, 50
	.byte 60, 136, 177

.align 2

track_400:
	.byte 2
	.byte 0
	.byte 226
	.byte 0
	.word voice_group6
	.word track_400_0
	.word track_400_1

.align 2
