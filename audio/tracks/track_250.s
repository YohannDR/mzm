.align 2

.section .rodata
.global track_250

track_250_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 95
	.byte 191, 64, 209, 60, 127, 130, 189, 12
	.byte 221, 142, 60, 32, 142, 225, 60, 12
	.byte 147, 177

track_250_1:
	.byte 188, 0, 189, 1, 190, 95, 191, 64
	.byte 186, 54, 136, 212, 56, 80, 133, 210
	.byte 56, 112, 156, 177

.align 2

track_250:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word voice_group5
	.word track_250_0
	.word track_250_1

.align 2
