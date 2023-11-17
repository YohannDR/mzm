.align 2

.section .rodata
.global track_508

track_508_0:
	.byte 188, 0, 187, 75, 189, 2, 190, 25
	.byte 191, 64, 209, 65, 80, 130, 62, 130
	.byte 69, 130, 72, 132, 72, 32, 132, 72
	.byte 12, 130, 177

.align 2

track_508:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_508_0

.align 2
