.align 2

.section .rodata
.global track_123

track_123_0:
	.byte 188, 0, 187, 75, 189, 4, 190, 56
	.byte 191, 64, 212, 60, 80, 132, 190, 39
	.byte 132, 189, 2, 210, 131, 177

.align 2

track_123:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_123_0

.align 2
