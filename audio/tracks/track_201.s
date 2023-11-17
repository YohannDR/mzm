.align 2

.section .rodata
.global track_201

track_201_0:
	.byte 188, 0, 187, 75, 189, 1, 190, 49
	.byte 191, 64, 232, 60, 80, 1, 153, 129
	.byte 177

.align 2

track_201:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_201_0

.align 2
