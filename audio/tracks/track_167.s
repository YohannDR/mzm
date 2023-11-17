.align 2

.section .rodata
.global track_167

track_167_0:
	.byte 188, 0, 187, 75, 189, 39, 190, 59
	.byte 191, 64, 217, 60, 112, 138, 189, 10
	.byte 222, 60, 92, 143, 226, 60, 40, 155
	.byte 129, 177

track_167_1:
	.byte 188, 0, 189, 25, 190, 75, 191, 64
	.byte 209, 57, 100, 133, 212, 53, 127, 161
	.byte 129, 177

.align 2

track_167:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_167_0
	.word track_167_1

.align 2
