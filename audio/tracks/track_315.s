.align 2

.section .rodata
.global track_315

track_315_0:
	.byte 188, 0, 187, 75, 189, 15, 190, 47
	.byte 191, 64, 217, 60, 80, 138, 226, 64
	.byte 40, 147, 177

track_315_1:
	.byte 188, 0, 189, 25, 190, 47, 191, 64
	.byte 193, 26, 192, 32, 220, 60, 80, 129
	.byte 192, 34, 129, 36, 129, 39, 129, 42
	.byte 129, 45, 129, 49, 129, 55, 129, 62
	.byte 129, 71, 129, 85, 129, 102, 129, 127
	.byte 130, 212, 60, 60, 134, 60, 32, 134
	.byte 60, 12, 133, 177

.align 2

track_315:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_315_0
	.word track_315_1

.align 2
