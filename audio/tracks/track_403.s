.align 2

.section .rodata
.global track_403

track_403_0:
	.byte 188, 0, 187, 75, 189, 13, 190, 110
	.byte 191, 64, 219, 57, 127, 140, 226, 60
	.byte 68, 147, 177

.align 2

track_403:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group5
	.word track_403_0

.align 2
