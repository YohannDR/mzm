.align 2

.section .rodata
.global track_310

track_310_0:
	.byte 188, 0, 187, 75, 189, 16, 196, 20
	.byte 190, 66, 191, 64, 194, 100, 207, 60
	.byte 80, 129, 175, 131, 178, 206, 4, 33
	.byte 8, 129, 206, 60, 177

.align 2

track_310:
	.byte 1
	.byte 0
	.byte 190
	.byte 0
	.word voice_group5
	.word track_310_0

.align 2
