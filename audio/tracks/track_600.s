.align 2

.section .rodata
.global track_600

track_600_0:
	.byte 188, 0, 187, 75, 189, 13, 190, 44
	.byte 191, 64, 211, 72, 80, 132, 177

.align 2

track_600:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group5
	.word track_600_0

.align 2
